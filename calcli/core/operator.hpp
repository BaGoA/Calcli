/**
 * @file operator.hpp
 * @brief Operator utilities
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

#include <map>
#include <string>
#include <functional>
#include <cmath>


namespace calcli
{
	/** @brief Association between operator and its precedence value */
	const std::map<std::string, int> precedence{
		{"+", 2},
		{"-", 2},
		{"*", 3},
		{"/", 3},
		{"^", 4}
	};

	/** @brief Map returning true if operator is left associative */
	const std::map<std::string, bool> is_left_associative{
		{"+", true},
		{"-", true},
		{"*", true},
		{"/", true},
		{"^", false}
	};

	/** @brief Association between string representing an operator and operator function */
	const std::map< std::string, std::function<double(double, double)> > operation{
		{"+", std::plus<double>()},
		{"-", std::minus<double>()},
		{"*", std::multiplies<double>()},
		{"/", std::divides<double>()},
		{"^", [](double x, double p){ return std::pow(x, p); }}
	};
}
