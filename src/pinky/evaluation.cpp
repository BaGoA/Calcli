/**
 * @file evaluation.cpp
 * @brief Evaluation functionnalities
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

#include "evaluation.hpp"

#include "constant.hpp"
#include "operator.hpp"
#include "function.hpp"


double pinky::postfix_evaluation(const std::vector<pinky::token>& t_tokens)
{
	constexpr unsigned int stack_reserved_size = 10;

	std::vector<double> stack_operand;
	stack_operand.reserve(stack_reserved_size);

	for(const pinky::token& token : t_tokens)
	{
		switch(token.type)
		{
			case pinky::token::Number:
			{
				stack_operand.push_back(std::stod(token.value));
				break;
			}
			case pinky::token::Binary_Operator:
			{
				const double right = stack_operand.back();
				stack_operand.pop_back();

				const double left = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(pinky::binary_operation(token.value, left, right));
				break;
			}
			case pinky::token::Unary_Operator:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(pinky::unary_operation(token.value, arg));
				break;
			}
			case pinky::token::Function:
			{
				const double arg = stack_operand.back();
				stack_operand.pop_back();

				stack_operand.push_back(pinky::apply_function(token.value, arg));
				break;
			}
			case pinky::token::Constant:
			{
				stack_operand.push_back(pinky::constant.at(token.value));
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
