/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameField.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:02:20 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 12:02:24 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameField.hpp"


GameField::GameField(int const & width, int const & height)
											: m_width(width), m_height(height), m_size(width * height)
{
	m_field = new std::shared_ptr<SquareSegment> [m_size];
}


GameField::~GameField()

{
	delete [] m_field;
}

GameField	&GameField::Instance(int const & width, int const & height)
{
	static GameField instance(width, height);
	return instance;
}

int					GameField::getWidth() const
{
	return m_width;
}

int					GameField::getHeight() const
{
	return m_height;
}

int					GameField::getSize() const
{
	return m_size;
}

std::shared_ptr<SquareSegment>		GameField::getFieldElement(int const & grid_x,
	 																int const & grid_y) const
{
	int position = grid_x + m_width* grid_y;

	if (position < 0 || position > m_size) {
		throw CustomExeption("OutOf FIELD!!!");
	}
	return 	m_field[position];
}

void 				GameField::setFieldElement(int const & grid_x,
													int const & grid_y,
														std::shared_ptr<SquareSegment> square)
{
	int position = grid_x + m_width* grid_y;

	if (position < 0 || position > m_size) {
		throw CustomExeption("OutOf FIELD!!!");
	}
	m_field[position] = square;
}

void 				GameField::clear()
{
	for (int i = 0; i < m_size; i++)
	{
		m_field[i] = NULL;
	}
}
