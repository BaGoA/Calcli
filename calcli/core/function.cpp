/**
 * @file function.cpp
 * @brief Function utilities
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

#include <calcli/core/function.hpp>

#include <cmath>

#include <calcli/core/error.hpp>
#include <calcli/core/cmap.hpp>


double calcli::apply_function(const std::string& str_function, double x)
{
	if(str_function == "abs") { return std::abs(x); }
	else if(str_function == "sqrt") { return std::sqrt(x); }
	else if(str_function == "cbrt") { return std::cbrt(x); }
	else if(str_function == "exp") { return std::exp(x); }
	else if(str_function == "log") { return std::log(x); }
	else if(str_function == "logten") { return std::log10(x); }
	else if(str_function == "logtwo") { return std::log2(x); }
	else if(str_function == "sin") { return std::sin(x); }
	else if(str_function == "cos") { return std::cos(x); }
	else if(str_function == "tan") { return std::tan(x); }
	else if(str_function == "asin") { return std::asin(x); }
	else if(str_function == "acos") { return std::acos(x); }
	else if(str_function == "atan") { return std::atan(x); }
	else if(str_function == "sinh") { return std::sinh(x); }
	else if(str_function == "cosh") { return std::cosh(x); }
	else if(str_function == "tanh") { return std::tanh(x); }
	else if(str_function == "asinh") { return std::asinh(x); }
	else if(str_function == "acosh") { return std::acosh(x); }
	else if(str_function == "atanh") { return std::atanh(x); }
	else { throw calcli::function_is_not_defined(); }
}
