/**
 * @file function.cpp
 * @brief Function utilities
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

#include "function.hpp"

#include <cmath>

#include "error.hpp"
#include "cmap.hpp"


double pinky::apply_function(const std::string& t_str_function, const double t_x)
{
	double result{0.0};

	if(t_str_function == "abs") { result = std::abs(t_x); }
	else if(t_str_function == "sqrt") { result = std::sqrt(t_x); }
	else if(t_str_function == "cbrt") { result = std::cbrt(t_x); }
	else if(t_str_function == "exp") { result = std::exp(t_x); }
	else if(t_str_function == "log") { result = std::log(t_x); }
	else if(t_str_function == "logten") { result = std::log10(t_x); }
	else if(t_str_function == "logtwo") { result = std::log2(t_x); }
	else if(t_str_function == "sin") { result = std::sin(t_x); }
	else if(t_str_function == "cos") { result = std::cos(t_x); }
	else if(t_str_function == "tan") { result = std::tan(t_x); }
	else if(t_str_function == "asin") { result = std::asin(t_x); }
	else if(t_str_function == "acos") { result = std::acos(t_x); }
	else if(t_str_function == "atan") { result = std::atan(t_x); }
	else if(t_str_function == "sinh") { result = std::sinh(t_x); }
	else if(t_str_function == "cosh") { result = std::cosh(t_x); }
	else if(t_str_function == "tanh") { result = std::tanh(t_x); }
	else if(t_str_function == "asinh") { result = std::asinh(t_x); }
	else if(t_str_function == "acosh") { result = std::acosh(t_x); }
	else if(t_str_function == "atanh") { result = std::atanh(t_x); }
	else { throw pinky::function_is_not_defined(); }

	return result;
}
