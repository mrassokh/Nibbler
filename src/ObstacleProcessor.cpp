/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleProcessor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:06:04 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/09 12:06:06 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObstacleProcessor.hpp"

ObstacleProcessor::ObstacleProcessor()
{
	m_obstacleDirector = &ObstacleDirector::Instance();
	m_dotObstacleBuilder = new DotObstacleBuilder();
	m_zetObstacleBuilder = new ZetObstacleBuilder();
	m_lObstacleBuilder = new LObstacleBuilder();
	m_builders[0] = m_dotObstacleBuilder;
	m_builders[1] = m_zetObstacleBuilder;
	m_builders[2] = m_lObstacleBuilder;
}


ObstacleProcessor::~ObstacleProcessor()
{

}


ObstacleProcessor	&ObstacleProcessor::Instance()
{
	static ObstacleProcessor instance;
	return instance;
}

void 				ObstacleProcessor::initObstacleList(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
									GameField *gameField)
{
	int obstacleListSize = gameField->getSize() / 20 ;

	for (int i = 0; i < obstacleListSize ; ++i) {
		m_obstacleDirector->setObstacleBuilder(m_builders[i % 3]);
		createObstacle(obstacleList, gameField);
	}
}


void 				ObstacleProcessor::createObstacle(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
									GameField *gameField)
{
	if (!obstacleList)
		return;

	int positionX = rand() % gameField->getWidth();
	int positionY = rand() % gameField->getHeight();

	while (positionY == (gameField->getHeight() / 2) || positionX == gameField->getWidth() / 2
			|| !m_obstacleDirector->constructObstacle(gameField, positionX, positionY)){
		positionX = rand() % gameField->getWidth();
		positionY = rand() % gameField->getHeight();
	}
	std::shared_ptr<Obstacle> newObstacle = std::shared_ptr<Obstacle>(m_obstacleDirector->getObstacle());
	obstacleList->push_back(newObstacle);
}
