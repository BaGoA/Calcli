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

#include <algorithm>

#include <calcli/core/operator.hpp>


static bool last_operator_is_primary(const calcli::token& last, const calcli::token& current)
{
	return (calcli::precedence.at(last.value) > calcli::precedence.at(current.value)) ||
			((calcli::precedence.at(last.value) == calcli::precedence.at(current.value)) && calcli::is_left_associative.at(current.value));
}

std::vector<calcli::token> calcli::shunting_yard(const std::vector<calcli::token>& tokens)
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
			case calcli::token::Operator:
			{
				while(!stack_operator.empty() && last_operator_is_primary(stack_operator.back(), token))
				{
					tokens_postfix.push_back(stack_operator.back());
					stack_operator.pop_back();
				}

				stack_operator.push_back(token);
				break;
			}
			default:
			{
				break;
			}
		}
	}

	if(!stack_operator.empty())
	{
		tokens_postfix.insert(std::cend(tokens_postfix), std::rbegin(stack_operator), std::rend(stack_operator));
	}

	return tokens_postfix;
}
