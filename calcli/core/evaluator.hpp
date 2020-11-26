/**
 * @file evaluator.hpp
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

#pragma once

#include <vector>

#include <calcli/core/token.hpp>


namespace calcli
{
	/**
	 * @brief Convert vector of tokens which represent infix expression into 
	 *			other vector of token which correspond to postfix expression
	 *
	 * @details We implement it with Shunting yard algorithm by Edgar Dijkstra.
	 * @param tokens Vector of token corresponding to infix expression
	 * @return Vector of token which represent postfix expression
	 */
	std::vector<calcli::token> infix_to_postfix(const std::vector<calcli::token>& tokens);

	/**
	 * @brief Evaluation of postfix expression
	 * @details The algorithm use a stack containing operands. 
	 * If token is a number, we push it in stack.
	 * If token is a operator, we pop two operands and we push result of operation in stack
	 * If token is a function, we pop one operand and we push result of function in stack
	 * At the end, the stack contains only the result of expression.
	 *
	 * @param tokens Vector of token corresponding to postfix expression
	 * @return Value of expression
	 */
	double postfix_evaluation(const std::vector<calcli::token>& tokens);
}
