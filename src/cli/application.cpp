/**
 * @file application.cpp
 * @brief Pinky application
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

#include "application.hpp"

#include <iostream>
#include <algorithm>
#include <cstring>

#include "../api/expression.hpp"


void pinky::application::print_header()
{
	std::cout <<  "Pinky  Copyright (C) 2020 Bastian Gonzalez Acevedo\n"
		"This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
		"This is free software, and you are welcome to redistribute it "
		"under certain conditions; type `show c' for details.\n\n"
		"If you want quit Pinky, enter quit.\n\n";
}

void pinky::application::replace_last_result()
{
	const std::string str_last_result = std::to_string(m_last_result);
	const std::string str_last{"last"};

	std::size_t pos = m_buffer.find(str_last);

	while(pos != std::string::npos)
	{
		m_buffer.replace(pos, str_last.size(), str_last_result);
		pos = m_buffer.find(str_last, pos);
	}
}

void pinky::application::run()
{
	while(true)
	{
		std::cout << ">>> ";
		std::cin.getline(m_buffer.data(), static_cast<std::streamsize>(m_buffer.size()));

		replace_last_result();

		const pinky::expression expression(m_buffer.data(), std::strlen(m_buffer.c_str()));

		if(expression.is_empty())	// user push ENTER, then go to newline
		{
			continue;
		}

		if(expression.is_exit_expression())
		{
			break;	// quit the application
		}

		try
		{
			m_last_result = expression.evaluate();
			std::cout << m_last_result << "\n";
		}
		catch(const std::exception& error)
		{
			std::cout << "Error: " << error.what() << "\n";
		}

		std::fill(std::begin(m_buffer), std::end(m_buffer), '\0');
	}
}
