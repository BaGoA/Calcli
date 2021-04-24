/**
 * @file expression.cpp
 * @brief API for expression
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

#include "expression.hpp"

#include "../core/processing.hpp"


pinky::expression::expression(const std::string_view& t_expression)
	: m_expression{t_expression}
{}

pinky::expression::expression(const char* t_expression, std::size_t t_length)
	: m_expression{t_expression, t_length}
{}

bool pinky::expression::is_empty() const
{
	return m_expression.empty();
}

bool pinky::expression::is_exit_expression() const
{
	return m_expression == "quit" || m_expression == "exit";
}

double pinky::expression::evaluate() const
{
	return pinky::postfix_evaluation(
				pinky::infix_to_postfix(
					pinky::tokenize(m_expression)
				)
			);
}
