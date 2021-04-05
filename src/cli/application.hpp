/**
 * @file application.hpp
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

#include <string>


namespace pinky
{
	/**
	 * @class application
	 * @brief Manage Pinky application
	 */
	class application
	{
	public:
		/** @brief Print application header */
		static void print_header();

		/** @brief Run of application */
		void run();

	private:
		static constexpr unsigned int m_buffer_size = 1024;			/**< String buffer size */
		std::string m_buffer = std::string(m_buffer_size, '\0');	/**< String buffer containing succesive expression given by user */
	};
}
