/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZetObstacleBuilder.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:15:39 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 11:15:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZetObstacleBuilder.hpp"

ZetObstacleBuilder::ZetObstacleBuilder()
{

}

ZetObstacleBuilder::~ZetObstacleBuilder()
{

}

int 		ZetObstacleBuilder::checkObstacleToGameField(GameField *gamefield, int const & x, int const & y)
{
	if (x > gamefield->getWidth() - 3 || y > gamefield->getHeight() - 2)
		return (0);

	if (gamefield->getFieldElement(x, y)){
		return (0);
	} else  if (gamefield->getFieldElement(x + 1, y)){
		return (0);
	} else  if (gamefield->getFieldElement(x + 1, y + 1)){
		return (0);
	} else  if (gamefield->getFieldElement(x + 2, y + 1)){
		return (0);
	} else {
		return (1);
	}
}

void 		ZetObstacleBuilder::setFirstX(int const & x)
{
	m_obstacle->setFirstX(x);
}

void 		ZetObstacleBuilder::setFirstY(int const & y)
{
	m_obstacle->setFirstY(y);
}

void 		ZetObstacleBuilder::setSize()
{
	m_obstacle->setSize(4);
}

void 		ZetObstacleBuilder::setObstacleSegments(GameField *gamefield, int const & x, int const & y)
{
	setOneSegment(gamefield, x, y);
	setOneSegment(gamefield, x + 1, y);
	setOneSegment(gamefield, x + 1 , y + 1);
	setOneSegment(gamefield, x + 2 , y + 1);
}
