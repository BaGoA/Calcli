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

#include "operator.hpp"

#include <cmath>

#include "error.hpp"


double pinky::binary_operation(const std::string& t_str_operator, double t_left_operand, double t_right_operand)
{
	double result{0.0};

	if(t_str_operator == "+") 
	{ 
		result = t_left_operand + t_right_operand; 
	}
	else if(t_str_operator == "-") 
	{ 
		result = t_left_operand - t_right_operand; 
	}
	else if(t_str_operator == "*") 
	{ 
		result = t_left_operand * t_right_operand; 
	}
	else if(t_str_operator == "/") 
	{ 
		if(t_right_operand == 0.0)
		{
			throw pinky::division_by_zero();
		}

		result = t_left_operand / t_right_operand; 
	}
	else if(t_str_operator == "^") 
	{ 
		result = std::pow(t_left_operand, t_right_operand); 
	}
	else 
	{ 
		throw pinky::binary_operator_is_not_defined(); 
	}

	return result;
}

double pinky::unary_operation(const std::string& t_str_operator, double t_operand)
{
	double result{0.0};

	if(t_str_operator == "+") 
	{ 
		result = t_operand; 
	}
	else if(t_str_operator == "-") 
	{ 
		result = -t_operand; 
	}
	else 
	{ 
		throw pinky::unary_operator_is_not_defined(); 
	}

	return result;
}
