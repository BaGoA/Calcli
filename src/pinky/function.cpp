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


double pinky::apply_function(const std::string& str_function, double x)
{
	double result{0.0};

	if(str_function == "abs") { result = std::abs(x); }
	else if(str_function == "sqrt") { result = std::sqrt(x); }
	else if(str_function == "cbrt") { result = std::cbrt(x); }
	else if(str_function == "exp") { result = std::exp(x); }
	else if(str_function == "log") { result = std::log(x); }
	else if(str_function == "logten") { result = std::log10(x); }
	else if(str_function == "logtwo") { result = std::log2(x); }
	else if(str_function == "sin") { result = std::sin(x); }
	else if(str_function == "cos") { result = std::cos(x); }
	else if(str_function == "tan") { result = std::tan(x); }
	else if(str_function == "asin") { result = std::asin(x); }
	else if(str_function == "acos") { result = std::acos(x); }
	else if(str_function == "atan") { result = std::atan(x); }
	else if(str_function == "sinh") { result = std::sinh(x); }
	else if(str_function == "cosh") { result = std::cosh(x); }
	else if(str_function == "tanh") { result = std::tanh(x); }
	else if(str_function == "asinh") { result = std::asinh(x); }
	else if(str_function == "acosh") { result = std::acosh(x); }
	else if(str_function == "atanh") { result = std::atanh(x); }
	else { throw pinky::function_is_not_defined(); }

	return result;
}
