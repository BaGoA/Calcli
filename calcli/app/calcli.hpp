/**
 * @file calci.hpp
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

#include <string>
#include <string_view>


namespace calcli
{
	/** @brief String containing header message when we launch Calcli */
	const std::string header = "Calcli  Copyright (C) 2020 Bastian Gonzalez Acevedo\n"
														 "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
														 "This is free software, and you are welcome to redistribute it "
														 "under certain conditions; type `show c' for details.";

	/**
	 * @brief Compute result of expression given in argument
	 * @param expression string_view containing expression to evaluate
	 * @return The result of expression
	 */
	double compute(const std::string_view& expression);
}