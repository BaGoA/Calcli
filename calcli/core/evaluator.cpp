/**
 * @file evaluator.cpp
 * @brief Evaluation functionnalities
 *
 * Calcli is a simple C++ command line calculator
 * Copyright (C) 2020 Bastian Gonzalez Acevedo

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

#include <calcli/core/evaluator.hpp>

#include <calcli/core/error.hpp>
#include <calcli/core/cmap.hpp>
#include <calcli/core/operator.hpp>
#include <calcli/core/function.hpp>


using namespace std::literals::string_view_literals;

constexpr calcli::cmap<std::string_view, int, 5> precedence{
	{{
		{"+"sv, 2},
		{"-"sv, 2},
		{"*"sv, 3},
		{"/"sv, 3},
		{"^"sv, 4}
	}}
};

constexpr calcli::cmap<std::string_view, bool, 5> is_left_associative{
	{{
		{"+"sv, true},
		{"-"sv, true},
		{"*"sv, true},
		{"/"sv, true},
		{"^"sv, false}
	}}
};

static bool last_operator_is_primary(const calcli::token& last, const calcli::token& current)
{
	if(last.type == calcli::token::Left_Parenthesis)
	{
		return false;
	}

	const int last_precedence = precedence.at(last.value);
	const int current_precedence = precedence.at(current.value);

	const bool is_primary = (last_precedence > current_precedence);
	const bool is_primary_from_left_associativity = (last_precedence == current_precedence) && is_left_associative.at(current.value);

	return  is_primary || is_primary_from_left_associativity || (last.type == calcli::token::Unary_Operator);
}

std::vector<calcli::token> calcli::infix_to_postfix(const std::vector<calcli::token>& tokens)
{
	std::vector<calcli::token> tokens_postfix;
	tokens_postfix.reserve(tokens.size());

	std::vector<calcli::token> stack_operator;
	stack_operator.reserve(tokens.size());

	for(const calcli::token& token : tokens)
	{
		switch(token.type)
		{
			case calcli::token::Number:
			{
				tokens_postfix.push_back(token);
				break;
			}
			case calcli::token::Unary_Operator:
			{
				stack_operator.push_back(token);
				break;
			}
			case calcli::token::Binary_Operator:
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
			case calcli::token::Function:
			{
				stack_operator.push_back(token);
				break;
			}
			case calcli::token::Left_Parenthesis:
			{
				stack_operator.push_back(token);
				break;
			}
			case calcli::token::Right_Parenthesis:
			{
				// Pop stack operator between left and right parenthesis
				while(!stack_operator.empty() && stack_operator.back().type != calcli::token::Left_Parenthesis)
				{
					tokens_postfix.push_back(stack_operator.back());
					stack_operator.pop_back();
				}

				if(stack_operator.empty())
				{
					throw calcli::mismatched_parenthesis();
				}

				// Pop left parenthesis and function from stack operator
				stack_operator.pop_back();
					
				if(!stack_operator.empty() && stack_operator.back().type == calcli::token::Function)
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
		auto compare_token_type = [](const calcli::token& token) { return token.type == calcli::token::Left_Parenthesis; };
		const bool contain_left_parenthesis = std::find_if(std::cbegin(stack_operator), std::cend(stack_operator), compare_token_type) != std::cend(stack_operator);

		if(contain_left_parenthesis)
		{
			throw calcli::mismatched_parenthesis();
		}

		tokens_postfix.insert(std::cend(tokens_postfix), std::rbegin(stack_operator), std::rend(stack_operator));
	}

	return tokens_postfix;
}

double calcli::postfix_evaluation(const std::vector<calcli::token>& tokens)
{
	std::vector<double> stack_operand;
	stack_operand.reserve(10);

	for(auto token : tokens)
	{
		switch(token.type)
		{
			case calcli::token::Number:
			{
				stack_operand.push_back(std::stod(token.value));
				break;
			}
			case calcli::token::Unary_Operator:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(calcli::unary_operation(token.value, arg));
				break;
			}
			case calcli::token::Binary_Operator:
			{
				const double right = stack_operand.back();
				stack_operand.pop_back();

				const double left = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(calcli::binary_operation(token.value, left, right));
				break;
			}
			case calcli::token::Function:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(calcli::apply_function(token.value, arg));
				break;
			}
			default:
			{
				break;
			}
		}
	}

	return stack_operand.at(0);
}
