/**
 * @file lexer.cpp
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

#include <calcli/core/lexer.hpp>

#include <cctype>


inline bool is_digit(char c) { return std::isdigit(c) != 0; }
inline bool is_not_end_expression(char c) { return c != '\0'; }

std::string extract_number(std::string_view::iterator& it_char)
{
	std::string value;
	value.reserve(10);

	while(is_not_end_expression(*it_char) && (is_digit(*it_char) || *it_char == '.'))
	{
		value.push_back(*it_char);
		++it_char;
	}

	return value;
}


std::vector<calcli::token> calcli::lexing(const std::string_view& expression)
{
	std::vector<calcli::token> tokens;
	tokens.reserve(expression.size());

	auto it_char = std::begin(expression);

	while(it_char != std::end(expression))
	{
		if(is_digit(*it_char))
		{
			tokens.push_back(calcli::token{calcli::token::Number, extract_number(it_char)});
		}
	}

	return tokens;
}