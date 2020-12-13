/**
 * @file engine.cpp
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

#include <calcli/application/engine.hpp>

#include <calcli/processing/parse.hpp>
#include <calcli/processing/evaluation.hpp>


calcli::engine& calcli::engine::parse(const std::string_view& expression)
{
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);
	std::vector<calcli::token> postfix_tokens = calcli::infix_to_postfix(tokens);

	std::swap(m_tokens, postfix_tokens);

	return *this;
}

double calcli::engine::evaluate() const
{
	return calcli::postfix_evaluation(m_tokens);
}
