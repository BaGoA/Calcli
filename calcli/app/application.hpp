/**
 * @file application.hpp
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

#include <string>
#include <string_view>


namespace calcli
{
	/**
	 * @class application
	 * @brief Manage Calcli application
	 */
	class application
	{
	public:
		/** @brief Run of application */
		void run();

	private:
		bool m_is_running{true};							/**< Run status of application */
		std::string m_buffer = std::string(1024, '\0');		/**< String buffer containing succesive expression given by user */

		const std::string m_header{
			"Calcli  Copyright (C) 2020 Bastian Gonzalez Acevedo\n"
			"This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
			"This is free software, and you are welcome to redistribute it "
			"under certain conditions; type `show c' for details.\n\n"
			"If you want quit Calcli, enter quit."
		};
	};
}