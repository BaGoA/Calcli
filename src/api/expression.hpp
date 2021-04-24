/**
 * @file expression.hpp
 * @brief API for expression and it processing
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

#include <vector>
#include <string_view>

#include "../core/token.hpp"


namespace pinky
{
	/**
	 * @class expression
	 * @brief Define expression to evaluate
	 */
	class expression
	{
	public:
		/** @brief Default constructor */
		expression() = default;

		/**
		 * @brief Constructor
		 * @param t_expression The expression to evaluate
		 */
		expression(const std::string_view& t_expression);

		/**
		 * @brief Constructor
		 * t_expression The expression to evaluate
		 * t_length The expression length
		 */
		expression(const char* t_expression, std::size_t t_length);


		/**
		 * @brief Check if expression is empty
		 * @return True if expression is empty
		 */
		bool is_empty() const;

		/**
		 * @brief Check if expression is an exit expression
		 * @return True if expression correspond to 'quit' or 'exit'
		 */
		bool is_exit_expression() const;

		/**
		 * @brief Evaluation of expression
		 * @return The result of expression
		 */
		double evaluate() const;

	private:
		std::string_view m_expression;	/**< String view on raw expression */
	};
}
