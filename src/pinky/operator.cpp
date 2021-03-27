/**
 * @file operator.cpp
 * @brief Operator utilities
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

#include <pinky/operator.hpp>

#include <cmath>

#include <pinky/error.hpp>


double pinky::binary_operation(const std::string& str_operator, double left_operand, double right_operand)
{
	if(str_operator == "+") 
	{ 
		return left_operand + right_operand; 
	}
	else if(str_operator == "-") 
	{ 
		return left_operand - right_operand; 
	}
	else if(str_operator == "*") 
	{ 
		return left_operand * right_operand; 
	}
	else if(str_operator == "/") 
	{ 
		if(right_operand == 0.0)
		{
			throw pinky::division_by_zero();
		}

		return left_operand / right_operand; 
	}
	else if(str_operator == "^") 
	{ 
		return std::pow(left_operand, right_operand); 
	}
	else 
	{ 
		throw pinky::binary_operator_is_not_defined(); 
	}
}

double pinky::unary_operation(const std::string& str_operator, double operand)
{
	if(str_operator == "+") 
	{ 
		return operand; 
	}
	else if(str_operator == "-") 
	{ 
		return -operand; 
	}
	else 
	{ 
		throw pinky::unary_operator_is_not_defined(); 
	}
}
