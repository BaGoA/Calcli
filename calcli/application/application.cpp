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

#include <calcli/application/application.hpp>

#include <iostream>
#include <algorithm>
#include <cstring>


void calcli::application::print_header() const
{
	std::cout <<  "Calcli  Copyright (C) 2020 Bastian Gonzalez Acevedo\n"
		"This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
		"This is free software, and you are welcome to redistribute it "
		"under certain conditions; type `show c' for details.\n\n"
		"If you want quit Calcli, enter quit.\n\n";
}

void calcli::application::run()
{
	while(true)
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
			break;
		}
		else
		{
			try
			{
				const double result = m_engine.parse(expression).evaluate();
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
