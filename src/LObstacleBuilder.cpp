/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LObstacleBuilder.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:11:58 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 12:12:00 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LObstacleBuilder.hpp"

LObstacleBuilder::LObstacleBuilder()
{

}

LObstacleBuilder::~LObstacleBuilder()
{

}

int 		LObstacleBuilder::checkObstacleToGameField(GameField *gamefield, int const & x, int const & y)
{
	if (x > gamefield->getWidth() - 2 || y > gamefield->getHeight() - 3)
		return (0);

	if (gamefield->getFieldElement(x, y)){
		return (0);
	} else  if (gamefield->getFieldElement(x + 1, y)){
		return (0);
	} else  if (gamefield->getFieldElement(x, y + 1)){
		return (0);
	} else  if (gamefield->getFieldElement(x, y + 2)){
		return (0);
	} else {
		return (1);
	}
}

void 		LObstacleBuilder::setFirstX(int const & x)
{
	m_obstacle->setFirstX(x);
}

void 		LObstacleBuilder::setFirstY(int const & y)
{
	m_obstacle->setFirstY(y);
}

void 		LObstacleBuilder::setSize()
{
	m_obstacle->setSize(4);
}

void 		LObstacleBuilder::setObstacleSegments(GameField *gamefield, int const & x, int const & y)
{
	setOneSegment(gamefield, x, y);
	setOneSegment(gamefield, x + 1, y);
	setOneSegment(gamefield, x, y + 1);
	setOneSegment(gamefield, x, y + 2);
}
