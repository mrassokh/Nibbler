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

int 		DotObstacleBuilder::checkObstacleToGameField(GameField *gamefield)
{
	if (gamefield->getFieldElement(m_X, m_Y))
		return (0);
	return (1);
}

void 		DotObstacleBuilder::setFirstX()
{
	m_obstacle->setFirstX(m_X);
}

void 		DotObstacleBuilder::setFirstY()
{
	m_obstacle->setFirstY(m_Y);
}

void 		DotObstacleBuilder::setSize()
{
	m_obstacle->setSize(1);
}

void 		DotObstacleBuilder::setObstacleSegments()
{
	auto obstacles = m_obstacle->getObstacleSegments();
	auto segment = std::shared_ptr<SquareSegment>(new SquareSegment(m_obstacle->getFirstX(),
										m_obstacle->getFirstY(), OBSTACLE));
	obstacles->push_back(segment);
}
