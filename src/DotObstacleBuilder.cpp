/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DotObstacleBuilder.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:20:00 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/03 11:20:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DotObstacleBuilder.hpp"

DotObstacleBuilder::DotObstacleBuilder()
{

}

DotObstacleBuilder::~DotObstacleBuilder()
{

}

int 		DotObstacleBuilder::checkObstacleToGameField(GameField *gamefield,
													int const & x, int const & y)
{
	if (gamefield->getFieldElement(x, y)){
		return (0);
	} else {
		return (1);
	}
}

void 		DotObstacleBuilder::setFirstX(int const & x)
{
	m_obstacle->setFirstX(x);
}

void 		DotObstacleBuilder::setFirstY(int const & y)
{
	m_obstacle->setFirstY(y);
}

void 		DotObstacleBuilder::setSize()
{
	m_obstacle->setSize(1);
}

void 		DotObstacleBuilder::setObstacleSegments(GameField *gamefield,
													int const & x, int const & y)
{
	setOneSegment(gamefield, x, y);
}
