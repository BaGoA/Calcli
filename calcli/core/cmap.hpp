/**
 * @file cmap.hpp
 * @brief Constexpr map
 *
 * Calcli is a simple C++ command line calculator
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

#include <calcli/core/error.hpp>


namespace calcli
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
		 * @param key Key that we want value
		 * @return The value coresponding to key. If key does not exist, we throw an exception
		 */
		const Value& at(const Key& key) const
		{
			const auto compare_key = [&key](const std::pair<Key, Value> elem) { return elem.first == key; };
			const auto it_pair = std::find_if(std::cbegin(data), std::cend(data), compare_key);

			if(it_pair == std::cend(data))
			{
				throw calcli::key_does_not_exist();
			}

			return it_pair->second;
		}	
	};
}
