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

#include <string>


namespace calcli
{
	/**
	 * @brief Apply binary operator function according to operator string representation
	 * @param str_operator Operator string representation
	 * @param left_operand Left operand
	 * @param right_operand Right operand
	 * @return The result of operation
	 */
	double binary_operation(const std::string& str_operator, double left_operand, double right_operand);

	/**
	 * @brief Apply unary operator function according to operator string representation
	 * @param str_operator Operator string representation
	 * @param operand Operand
	 * @return The result of operation
	 */
	double unary_operation(const std::string& str_operator, double operand);
}
