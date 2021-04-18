/**
 * @file parse.cpp
 * @brief Parse functionnalities
 *
 * Pinky is a simple C++ command line calculator
 * Copyright (C) 2020-2021 Bastian Gonzalez Acevedo

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "parse.hpp"

#include "error.hpp"
#include "extraction.hpp"
#include "constant.hpp"
#include "operator.hpp"


std::vector<pinky::token> pinky::tokenize(const std::string_view& t_expression)
{
	std::vector<pinky::token> tokens;
	tokens.reserve(t_expression.size());

	std::string_view::const_iterator it_char = std::cbegin(t_expression);

	while(it_char != std::cend(t_expression))
	{
		if(pinky::is_digit(*it_char))
		{
			const auto [number, shift] = pinky::extract_number(it_char, std::cend(t_expression));

			tokens.push_back(pinky::token{pinky::token::Number, number});
			it_char += shift;
		}
		else if(pinky::is_operator(*it_char))
		{
			const bool is_unary_operator = tokens.empty() || (tokens.back().type == pinky::token::Left_Parenthesis);	
			const pinky::token::etype token_type = is_unary_operator ? pinky::token::Unary_Operator : pinky::token::Binary_Operator;

			tokens.push_back(pinky::token{token_type, std::string{*it_char}});
			++it_char;
		}
		else if(*it_char == '(')
		{
			tokens.push_back(pinky::token{pinky::token::Left_Parenthesis, std::string{*it_char}});
			++it_char;
		}
		else if(*it_char == ')')
		{
			tokens.push_back(pinky::token{pinky::token::Right_Parenthesis, std::string{*it_char}});
			++it_char;
		}
		else if(pinky::is_alpha(*it_char))
		{
			const auto [name, shift] = pinky::extract_name(it_char, std::cend(t_expression));
			const pinky::token::etype token_type = pinky::is_constant(name) ? pinky::token::Constant : pinky::token::Function;

			tokens.push_back(pinky::token{token_type, name});
			it_char += shift;
		}
		else
		{
			++it_char;
		}
	}

	return tokens;
}


static bool last_operator_is_primary(const pinky::token& t_last, const pinky::token& t_current)
{
	if(t_last.type == pinky::token::Left_Parenthesis)
	{
		return false;
	}

	const int last_precedence = pinky::precedence.at(t_last.value);
	const int current_precedence = pinky::precedence.at(t_current.value);

	const bool is_primary = (last_precedence > current_precedence);
	const bool is_left_associativity = (last_precedence == current_precedence) && pinky::is_left_associative.at(t_current.value);

	return  is_primary || is_left_associativity || (t_last.type == pinky::token::Unary_Operator);
}

std::vector<pinky::token> pinky::infix_to_postfix(const std::vector<pinky::token>& t_tokens)
{
	std::vector<pinky::token> tokens_postfix;
	tokens_postfix.reserve(t_tokens.size());

	std::vector<pinky::token> stack_operator;
	stack_operator.reserve(t_tokens.size());

	for(const pinky::token& token : t_tokens)
	{
		switch(token.type)
		{
			case pinky::token::Number:
			case pinky::token::Constant:
			{
				tokens_postfix.push_back(token);
				break;
			}
			case pinky::token::Binary_Operator:
			{
				// Pop stack operator according to last operators precedence
				while(!stack_operator.empty() && last_operator_is_primary(stack_operator.back(), token))
				{
					tokens_postfix.push_back(stack_operator.back());
					stack_operator.pop_back();
				}

				stack_operator.push_back(token);
				break;
			}
			case pinky::token::Unary_Operator:
			case pinky::token::Function:
			case pinky::token::Left_Parenthesis:
			{
				stack_operator.push_back(token);
				break;
			}
			case pinky::token::Right_Parenthesis:
			{
				// Pop stack operator between left and right parenthesis
				while(!stack_operator.empty() && stack_operator.back().type != pinky::token::Left_Parenthesis)
				{
					tokens_postfix.push_back(stack_operator.back());
					stack_operator.pop_back();
				}

				if(stack_operator.empty())
				{
					throw pinky::mismatched_parenthesis();
				}

				// Pop left parenthesis and function from stack operator
				stack_operator.pop_back();
					
				if(!stack_operator.empty() && stack_operator.back().type == pinky::token::Function)
				{
					tokens_postfix.push_back(stack_operator.back());
					stack_operator.pop_back();
				}

				break;
			}
			default:
			{
				break;
			}
		}
	}

	// Push rest of operator. If stack operator contains left parenthesis, then there is an error
	if(!stack_operator.empty())
	{
		const auto find_it = std::find_if(std::cbegin(stack_operator), std::cend(stack_operator),
											[](const auto& token) { return token.type == pinky::token::Left_Parenthesis; });

		if(find_it != std::cend(stack_operator))
		{
			throw pinky::mismatched_parenthesis();
		}

		tokens_postfix.insert(std::cend(tokens_postfix), std::rbegin(stack_operator), std::rend(stack_operator));
	}

	return tokens_postfix;
}
