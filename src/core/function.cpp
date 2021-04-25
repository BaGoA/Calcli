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
	if(t_str_function == "abs") { return std::abs(t_x); }
	if(t_str_function == "sqrt") { return std::sqrt(t_x); }
	if(t_str_function == "cbrt") { return std::cbrt(t_x); }
	if(t_str_function == "exp") { return std::exp(t_x); }
	if(t_str_function == "log") { return std::log(t_x); }
	if(t_str_function == "logten") { return std::log10(t_x); }
	if(t_str_function == "logtwo") { return std::log2(t_x); }
	if(t_str_function == "sin") { return std::sin(t_x); }
	if(t_str_function == "cos") { return std::cos(t_x); }
	if(t_str_function == "tan") { return std::tan(t_x); }
	if(t_str_function == "asin") { return std::asin(t_x); }
	if(t_str_function == "acos") { return std::acos(t_x); }
	if(t_str_function == "atan") { return std::atan(t_x); }
	if(t_str_function == "sinh") { return std::sinh(t_x); }
	if(t_str_function == "cosh") { return std::cosh(t_x); }
	if(t_str_function == "tanh") { return std::tanh(t_x); }
	if(t_str_function == "asinh") { return std::asinh(t_x); }
	if(t_str_function == "acosh") { return std::acosh(t_x); }
	if(t_str_function == "atanh") { return std::atanh(t_x); }
	if(t_str_function == "degtorad") { return t_x * deg2rad_factor; }

	throw pinky::function_is_not_defined();
}
