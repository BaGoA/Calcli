/**
 * @file lexer.hpp
 * @brief Lexing functionnalities
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

#include <string>
#include <string_view>
#include <vector>


namespace calcli
{
	/** @brief Token structure */
	struct token
	{
		enum
		{
			Number
		} type;

		std::string value;
	};


	/**
	 * @brief Lexing of expression given in argument
	 * @param expression string_view containing expression to evaluate
	 * @return Vector of tokens
	 */
	std::vector<calcli::token> lexing(const std::string_view& expression);
}
