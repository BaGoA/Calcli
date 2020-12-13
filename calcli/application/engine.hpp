/**
 * @file engine.hpp
 * @brief Calcli evaluation engine
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

#include <string_view>
#include <vector>

#include <calcli/core/token.hpp>


namespace calcli
{
	/**
	 * @class engine
	 * @brief Calcli evaluation engine
	 */
	class engine
	{
	public:
		/** 
		 * @brief Parse expression 
		 * @param expression String view containing expression to parse
		 * @return Reference on this engine
		 */
		calcli::engine& parse(const std::string_view& expression);

		/** 
		 * @brief Evaluation
		 * @return Value corresponding to evaluation
		 */
		double evaluate() const;

	private:
		std::vector<calcli::token> m_tokens;	/** Vector of tokens containing parse result */
	};
}
