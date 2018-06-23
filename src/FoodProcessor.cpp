/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FoodProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:17:52 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/01 13:17:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FoodProcessor.hpp"

FoodProcessor	&FoodProcessor::Instance()
{
	static FoodProcessor instance;
	return instance;
}

FoodProcessor::FoodProcessor()
{

}

FoodProcessor::~FoodProcessor()
{

}
void 		FoodProcessor::initFoodList(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
									GameField *gameField)
{
	int foodListSize = gameField->getSize() / 20;

	for (int i = 0; i < foodListSize; ++i) {
		createFoodSegment(foodList, gameField);
	}
}

void 		FoodProcessor::timeUpdateFoodList(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
									GameField *gameField)
{
	if (!foodList)
		return;
	auto it = foodList->begin();

	while (it != foodList->end())
	{
		std::shared_ptr<FoodSegment> food = *it;
		double currentTime = static_cast<double>(clock()) / CLOCKS_PER_SEC;
		double liveTime = currentTime - food->getBornTime();
		if (food->getLiveTime() <= liveTime) {
				gameField->setFieldElement(food->getGridX(), food->getGridY(), NULL);
				it = foodList->erase(it);
				continue ;
		}
		it++;
	}
	while (foodList->size() < 3)
		createFoodSegment(foodList, gameField);
}

void 		FoodProcessor::createFoodSegment(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
									GameField *gameField)
{
	if (!foodList)
		return;

	int positionX = rand() % gameField->getWidth();
	int positionY = rand() % gameField->getHeight();

	while (gameField->getFieldElement(positionX, positionY))
	{
		positionX = rand() % gameField->getWidth();
		positionY = rand() % gameField->getHeight();
	}
	std::shared_ptr<FoodSegment> newFood = std::shared_ptr<FoodSegment>(new FoodSegment(positionX, positionY));
	foodList->push_back(newFood);
	gameField->setFieldElement(newFood->getGridX(), newFood->getGridY(), newFood);
}
