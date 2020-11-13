/**
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

#include <iostream>
#include <algorithm>
#include <cstring>

#include <calcli/app/calcli.hpp>


int main() 
{
	std::cout << calcli::header.c_str() << "\n\n";
	std::cout << "If you want quit Calcli, enter quit.\n\n";

	std::string buffer(1024, '\0');
	bool is_running = true;

	while(is_running)
	{
		std::cout << ">>> ";
		std::cin.getline(buffer.data(), buffer.size());

		const std::string_view expression(buffer.data(), std::strlen(buffer.c_str()));

		if(expression == "quit")
		{
			is_running = false;
		}
		else
		{
			const double value = calcli::compute(expression);
			std::cout << value << "\n";

			std::fill(std::begin(buffer), std::end(buffer), '\0');
		}
	}

	return 0;
}
