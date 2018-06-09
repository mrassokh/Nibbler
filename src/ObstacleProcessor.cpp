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
	m_dotObstacleBuilder = std::shared_ptr<DotObstacleBuilder>(new DotObstacleBuilder);
}


ObstacleProcessor::~ObstacleProcessor()
{

	delete m_dotObstacleBuilder ;
}


ObstacleProcessor	&ObstacleProcessor::Instance()
{
	static ObstacleProcessor instance;
	return instance;
}

void 				ObstacleProcessor::initObstacleList(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
									GameField *gameField)
{
	int obstacleListSize = gameField->getSize() / 50;

	for (int i = 0; i < obstacleListSize; ++i) {
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

	m_obstacleDirector->setObstacleBuilder(m_dotObstacleBuilder)
	// while (gameField->getFieldElement(positionX, positionY))
	// {
	// 	positionX = rand() % gameField->getWidth();
	// 	positionY = rand() % gameField->getHeight();
	// }
	std::shared_ptr<FoodSegment> newFood = std::shared_ptr<FoodSegment>(new FoodSegment(positionX, positionY));
	foodList->push_back(newFood);
	gameField->setFieldElement(newFood->getGridX(), newFood->getGridY(), newFood);
}
