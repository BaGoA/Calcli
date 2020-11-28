/**
 * @file application.cpp
 * @brief Calcli application
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

#include <calcli/app/application.hpp>

#include <iostream>
#include <algorithm>
#include <cstring>

#include <calcli/core/lexer.hpp>
#include <calcli/core/evaluator.hpp>


void calcli::application::run()
{
	std::cout << m_header.c_str() << "\n\n";

	while(m_is_running)
	{
		std::cout << ">>> ";
		std::cin.getline(m_buffer.data(), m_buffer.size());

		const std::string_view expression(m_buffer.data(), std::strlen(m_buffer.c_str()));

		if(expression.empty())	// user push ENTER, then go to newline
		{
			continue;
		}
		else if(expression == "quit")
		{
			m_is_running = false;
		}
		else
		{
			try
			{
				const std::vector<calcli::token> tokens = calcli::tokenize(expression);
				const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);
				const double result  = calcli::postfix_evaluation(tokens_postfix);

				std::cout << result << "\n";
			}
			catch(const std::exception& error)
			{
				std::cout << "Error: " << error.what() << "\n";
			}

			std::fill(std::begin(m_buffer), std::end(m_buffer), '\0');
		}
	}
}
