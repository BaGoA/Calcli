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


std::vector<calcli::token> calcli::shunting_yard(const std::vector<calcli::token>& tokens)
{
	std::vector<calcli::token> tokens_postfix;
	tokens_postfix.reserve(tokens.size());

	std::vector<calcli::token> stack_operation;
	stack_operation.reserve(tokens.size());

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
				stack_operation.push_back(token);
				break;
			}
			default:
			{
				break;
			}
		}
	}

	if(!stack_operation.empty())
	{
		tokens_postfix.insert(std::cend(tokens_postfix), std::begin(stack_operation), std::end(stack_operation));
	}

	return tokens_postfix;
}
