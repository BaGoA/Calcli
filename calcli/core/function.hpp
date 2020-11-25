/**
 * @file function.hpp
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

#pragma once

#include <map>
#include <string>
#include <functional>
#include <cmath>


namespace calcli
{
	/** @brief Association between string representing a funtion and this function */
	const std::map< std::string, std::function<double(double)> > function{
		{"abs", [](double x){ return std::abs(x); }},
		{"sqrt", [](double x){ return std::sqrt(x); }},
		{"cbrt", [](double x){ return std::cbrt(x); }},
		{"exp", [](double x){ return std::exp(x); }},
		{"log", [](double x){ return std::log(x); }},
		{"log10", [](double x){ return std::log10(x); }},
		{"log2", [](double x){ return std::log2(x); }},
		{"sin", [](double x){ return std::sin(x); }},
		{"cos", [](double x){ return std::cos(x); }},
		{"tan", [](double x){ return std::tan(x); }},
		{"asin", [](double x){ return std::asin(x); }},
		{"acos", [](double x){ return std::acos(x); }},
		{"atan", [](double x){ return std::atan(x); }},
		{"sinh", [](double x){ return std::sinh(x); }},
		{"cosh", [](double x){ return std::cosh(x); }},
		{"tanh", [](double x){ return std::tanh(x); }},
		{"asinh", [](double x){ return std::asinh(x); }},
		{"acosh", [](double x){ return std::acosh(x); }},
		{"atanh", [](double x){ return std::atanh(x); }},
	};
}
