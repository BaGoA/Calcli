/**
 * @file error.hpp
 * @brief Error occuring in Calcli
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

#include <exception>


namespace calcli
{
	/** @brief cmap access error */
	struct key_does_not_exist : public std::exception
	{
		const char* what() const noexcept override
		{
			return "cmap access error, the key does not exist";
		}
	};

	/** @brief Division by zero */
	struct division_by_zero : public std::exception
	{
		const char* what() const noexcept override
		{
			return "division by zero";
		}
	};

	/** @brief Binary operator is not defined */
	struct binary_operator_is_not_defined : public std::exception
	{
		const char* what() const noexcept override
		{
			return "binary operator is not defined";
		}
	};

	/** @brief Unary operator is not defined */
	struct unary_operator_is_not_defined : public std::exception
	{
		const char* what() const noexcept override
		{
			return "unary operator is not defined";
		}
	};

	/** @brief Function is not defined */
	struct function_is_not_defined : public std::exception
	{
		const char* what() const noexcept override
		{
			return "function is not defined";
		}
	};

	/** @brief Mismatched parenthesis error */
	struct mismatched_parenthesis : public std::exception
	{
		const char* what() const noexcept override
		{
			return "there are mismatched parenthesis in your expression";
		}
	};
}
