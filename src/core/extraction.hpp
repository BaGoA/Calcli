/**
 * @file extraction.hpp
 * @brief Extraction of number or string from expression
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

#include <string>
#include <string_view>
#include <utility>
#include <type_traits>

#include "types.hpp"


namespace pinky
{
	/**
	 * @brief Extract a number (for example 2.045 or 10) from expression
	 * @param t_start The iterator where we start extract in expression
	 * @param t_end The iterator corresponding to maximum position where extraction can work.
	 * @return The string containing the number and the iterator deplacement
	 */
	template<class StringIterator>
	std::pair<std::string, std::size_t> extract_number(StringIterator t_start, StringIterator t_end)
	{
		// Check if StringIterator is an iterator on char sequence
		constexpr bool is_string_iterator = std::is_same<StringIterator, std::string_view::iterator>::value ||
			std::is_same<StringIterator, std::string_view::const_iterator>::value ||
			std::is_same<StringIterator, std::string::iterator>::value ||
			std::is_same<StringIterator, std::string::const_iterator>::value;	

		static_assert(is_string_iterator);

		constexpr std::size_t reserved_size = 21;

		std::string value;
		value.reserve(reserved_size);

		std::size_t shift = 0;
		StringIterator it_char = t_start;

		while((it_char != t_end) && (pinky::is_digit(*it_char) || *it_char == '.'))
		{
			value.push_back(*it_char);
			++it_char;
			++shift;
		}

		return {value, shift};
	}

	/**
	 * @brief Extract a name (function, constant, ...) from expression
	 * @param t_start The iterator where we start extract in expression
	 * @param t_end The iterator corresponding to maximum position where extraction can work.
	 * @return The string containing the name and the iterator deplacement
	 */
	template<class StringIterator>
	std::pair<std::string, std::size_t> extract_name(StringIterator t_start, StringIterator t_end)
	{
		// Check if StringIterator is an iterator on char sequence
		constexpr bool is_string_iterator = std::is_same<StringIterator, std::string_view::iterator>::value ||
			std::is_same<StringIterator, std::string_view::const_iterator>::value ||
			std::is_same<StringIterator, std::string::iterator>::value ||
			std::is_same<StringIterator, std::string::const_iterator>::value;	

		static_assert(is_string_iterator);

		constexpr std::size_t reserved_size = 10;

		std::string value;
		value.reserve(reserved_size);

		std::size_t shift = 0;
		StringIterator it_char = t_start;

		while((it_char != t_end) && pinky::is_alpha(*it_char))
		{
			value.push_back(*it_char);
			++it_char;
			++shift;
		}

		return {value, shift};
	}
}
