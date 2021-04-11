/**
 * @file types.hpp
 * @brief Type utilities
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

#pragma once

#include <cctype>


namespace pinky
{
	inline bool is_digit(const char t_char) { return std::isdigit(t_char) != 0; }
	inline bool is_alpha(const char t_char) { return std::isalpha(t_char) != 0; }
}
