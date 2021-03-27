/**
 * @file constant.hpp
 * @brief Mathematical constants
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

#pragma once

#include <pinky/cmap.hpp>


using namespace std::literals::string_view_literals;

namespace pinky
{
	/** @brief Number of constant */
	constexpr std::size_t nb_constant = 3;

	/** @brief Constant list */
	constexpr std::array<std::string_view, nb_constant> constant_list{
		"pi"sv, 
		"e"sv, 
		"c"sv
	};

	/** @brief Association between mathematical constant string and its value */
	constexpr pinky::cmap<std::string_view, double, nb_constant> constant{
		{{
			{"pi"sv, 3.14159265358979323846},
			{"e"sv, 2.71828182845904523536},
			{"c"sv, 299792458.0}
		}}
	};

	/**
	 * @brief Check if string corresponds to constant
	 * @param str String to check
	 * @return True if string is a constant
	 */
	inline bool is_constant(const std::string& str) 
	{ 
		return std::find(std::cbegin(constant_list), std::cend(constant_list), str) != std::cend(constant_list); 
	}
}
