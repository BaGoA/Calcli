/**
 * @file calci.cpp
 * @brief Basic functionnalities of Calcli application
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

#include <calcli/app/calcli.hpp>

#include <iostream>

#include <calcli/core/lexer.hpp>
#include <calcli/core/evaluator.hpp>


double calcli::compute(const std::string_view& expression)
{
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	std::cout << "Lexer output:\n";
	
	for(const auto& token : tokens)
	{
		std::cout << "Type = " << token.type << " Value = " << token.value.c_str() << "\n";
	}

	std::cout << "\n";
	std::cout << "Convertion to postfix output:\n";

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	for(const auto& token : tokens_postfix)
	{
		std::cout << "Type = " << token.type << " Value = " << token.value.c_str() << "\n";
	}

	std::cout << "\n";

	return 0.0;
}
