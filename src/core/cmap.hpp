/**
 * @file cmap.hpp
 * @brief Constexpr map
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

#include <array>
#include <utility>
#include <algorithm>

#include "error.hpp"


namespace pinky
{
	/**
	 * @class cmap
	 * @brief constexpr map version
	 */
	template<typename Key, typename Value, std::size_t Size>
	struct cmap
	{
		std::array<std::pair<Key, Value>, Size> data;	/**< map data */

		/**
		 * @brief Access to value from key
		 * @param t_key The key that we want value
		 * @return The value coresponding to key. If key does not exist, we throw an exception
		 */
		const Value& at(const Key& t_key) const
		{
			const auto it_pair = std::find_if(std::cbegin(data), std::cend(data), 
												[&t_key](const auto& elem) { return elem.first == t_key; });

			if(it_pair == std::cend(data))
			{
				throw pinky::key_does_not_exist();
			}

			return it_pair->second;
		}	
	};
}
