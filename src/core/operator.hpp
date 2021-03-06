/**
 * @file operator.hpp
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

#pragma once

#include <string>

#include "cmap.hpp"


using namespace std::literals::string_view_literals;

namespace pinky
{
	/** @brief Number of operators */
	constexpr std::size_t nb_operator = 5;

	/** @brief Operator list */
	constexpr std::array<std::string_view, nb_operator> operator_list{
		"+"sv, 
		"-"sv, 
		"*"sv, 
		"/"sv, 
		"^"sv
	};

	/** @brief Association between operator and its precedence */
	constexpr pinky::cmap<std::string_view, int, nb_operator> precedence{
		{{
			{"+"sv, 2},
			{"-"sv, 2},
			{"*"sv, 3},
			{"/"sv, 3},
			{"^"sv, 4}
		}}
	};

	/** @brief Association between operator and boolean corresponding to left associativity */
	constexpr pinky::cmap<std::string_view, bool, nb_operator> is_left_associative{
		{{
			{"+"sv, true},
			{"-"sv, true},
			{"*"sv, true},
			{"/"sv, true},
			{"^"sv, false}
		}}
	};

	/**
	 * @brief Check if character correspond to operator
	 * @param t_char The character to test
	 * @return True if character is an operator
	 */
	inline bool is_operator(const char t_char)
	{
		return std::find(std::cbegin(operator_list), std::cend(operator_list), std::string(1, t_char)) != std::cend(operator_list);
	}

	/**
	 * @brief Apply binary operator function according to operator string representation
	 * @param t_str_operator The operator string representation
	 * @param t_left_operand The left operand
	 * @param t_right_operand The right operand
	 * @return The result of operation
	 */
	double binary_operation(const std::string& t_str_operator, const double t_left_operand, const double t_right_operand);

	/**
	 * @brief Apply unary operator function according to operator string representation
	 * @param t_str_operator The operator string representation
	 * @param t_operand The operand
	 * @return The result of operation
	 */
	double unary_operation(const std::string& t_str_operator, const double t_operand);
}
