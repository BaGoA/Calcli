/**
 * @file evaluation.cpp
 * @brief Evaluation functionnalities
 *
 * Calcli is a simple C++ command line calculator
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

#include <calcli/processing/evaluation.hpp>

#include <calcli/core/constant.hpp>
#include <calcli/core/operator.hpp>
#include <calcli/core/function.hpp>


double calcli::postfix_evaluation(const std::vector<calcli::token>& tokens)
{
	std::vector<double> stack_operand;
	stack_operand.reserve(10);

	for(const calcli::token& token : tokens)
	{
		switch(token.type)
		{
			case calcli::token::Number:
			{
				stack_operand.push_back(std::stod(token.value));
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
			case calcli::token::Unary_Operator:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(calcli::unary_operation(token.value, arg));
				break;
			}
			case calcli::token::Function:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(calcli::apply_function(token.value, arg));
				break;
			}
			case calcli::token::Constant:
			{
				stack_operand.push_back(calcli::constant.at(token.value));
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
