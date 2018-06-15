/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeProcessor.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:18:43 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/01 15:18:45 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/SnakeProcessor.hpp"

SnakeProcessor::SnakeProcessor()
{

}

SnakeProcessor::~SnakeProcessor()
{

}

SnakeProcessor		&SnakeProcessor::Instance()
{
	static SnakeProcessor instance;
	return instance;
}

void 				SnakeProcessor::setFoodList(std::shared_ptr<std::vector
													<std::shared_ptr<FoodSegment>>> foodList)
{
	m_foodList = foodList;
}

void 				SnakeProcessor::setGameField(GameField	*gameField)
{
	m_gameField = gameField;
}

void 					SnakeProcessor::setWindow(IWindow *window)
{
	m_window = window;
}

void 					SnakeProcessor::setLoopCondition(int *loopCondition)
{
	m_loopCondition = loopCondition;
}

void 						SnakeProcessor::configure(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
										GameField *gameField,IWindow *window, int *loopCondition)
{
	setFoodList(foodList);
	setGameField(gameField);
	setWindow(window);
	setLoopCondition(loopCondition);
}

void 				SnakeProcessor::initSnake(Snake &snake, GameField *gameField)
{
	int x = gameField->getWidth() / 2;
	int y = gameField->getHeight() / 2;
	int prev_x = x - 1;
	int prev_y = y;
	int dir_x = 1;
	int dir_y = 0;
	int lenght = 4;

	std::shared_ptr<SquareSegment> head = std::shared_ptr<SquareSegment>(
				static_cast<SquareSegment*>(new SnakeHead(x, y, prev_x, prev_y, dir_x, dir_y)));
	snake.getSnake()->push_back(head);
	gameField->setFieldElement(head->getGridX(), head->getGridY(), head);
	while (--lenght > 0)
	{
		x--;
		prev_x--;
		std::shared_ptr<SquareSegment> bodySegment = std::shared_ptr<SquareSegment>(
				static_cast<SquareSegment*>(new SnakeSegment(x, y, prev_x, prev_y)));
		snake.getSnake()->push_back(bodySegment);
		gameField->setFieldElement(bodySegment->getGridX(), bodySegment->getGridY(), bodySegment);
	}
}

void 				SnakeProcessor::updateSnake(Snake &snake, int velocity,
	 											double deltaTime)
{
	auto head = snake.getSnake()->begin();
	auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*head);
	int nextX = headSquare->getGridX() + 1 * headSquare->getDirX();
	int nextY = headSquare->getGridY() + 1 * headSquare->getDirY();

	checkHit(nextX, nextY);
	update(nextX, nextY, snake, headSquare, velocity, deltaTime);
}

void 			SnakeProcessor::checkHit(int const & nextX, int const & nextY)
{
	checkBorderHit(nextX, nextY);
	checkSnakeSegmentHit(nextX, nextY);
}

void 			SnakeProcessor::checkBorderHit(int const & nextX, int const & nextY)
{
	if (nextX >= m_gameField->getWidth() || nextX < 0 || nextY < 0 || nextY >= m_gameField->getHeight())
	{
		*m_loopCondition = 0;
		m_window->quit();
		throw CustomExeption("Snake hit border!!! So GAME OVER!!!");
	}
}

void 			SnakeProcessor::checkSnakeSegmentHit(int const & nextX, int const & nextY)
{
	std::shared_ptr<SquareSegment> nextSegment = m_gameField->getFieldElement(nextX, nextY);
	if (nextSegment && nextSegment->getType()== SNAKE_SEGMENT)
	{
		*m_loopCondition = 0;
		m_window->quit() ;
		throw CustomExeption("Snake eat itself!!! GAME OVER!!!");
	}
}

void 			SnakeProcessor::update(int const & nextX,	int const & nextY, Snake &snake,
									std::shared_ptr<SnakeHead> headSquare,
									int velocity, double deltaTime)
{
	//printf("Update with velocity = %d deltaTime = %f!!!\n", velocity, deltaTime);
	headSquare->setDelta(headSquare->getDelta() + velocity * deltaTime);
	if (headSquare->getDelta() >=1.0)
	{
	//	printf("New position!!!");
		headSquare->setRotationCondition(1);
	//	printf("AFTER FORWARD RotationCondition %d", headSquare->getRotationCondition());
		std::shared_ptr<SquareSegment> checkSegment = m_gameField->getFieldElement(nextX, nextY);

		headSquare->setDelta(headSquare->getDelta() - 1);
		headSquare->setPrevGridX(headSquare->getGridX());
		headSquare->setPrevGridY(headSquare->getGridY());
		headSquare->setGridX(nextX);
		headSquare->setGridY(nextY);
		updateSnakeBody(snake);

		if (checkSegment &&	checkSegment->getType() == FOOD)
		{
			snake.setEating(1);
			snake.setScore(snake.getScore() + 1);
			auto it = find_if(m_foodList->begin(), m_foodList->end(),
							[&nextX, &nextY](std::shared_ptr<SquareSegment> obj)
							{return obj->getGridX() == nextX && obj->getGridY() == nextY;});
			if (it != m_foodList->end()) {
				m_foodList->erase(it);
			}
		}
		m_gameField->setFieldElement(nextX, nextY,
					std::dynamic_pointer_cast<SquareSegment>(headSquare));
	}
}



void 			SnakeProcessor::updateSnakeBody(Snake &snake)
{
	auto headSegment = snake.getSnake()->begin();
	auto bodySegment = ++(snake.getSnake()->begin());
	while (bodySegment != snake.getSnake()->end())
	{
		auto headSegmentSquare = std::dynamic_pointer_cast<SnakeSegment>(*headSegment);
		auto bodySegmentSquare = std::dynamic_pointer_cast<SnakeSegment>(*bodySegment);

		bodySegmentSquare->setPrevGridX(bodySegmentSquare->getGridX());
		bodySegmentSquare->setPrevGridY(bodySegmentSquare->getGridY());
		m_gameField->setFieldElement(bodySegmentSquare->getGridX(),
								bodySegmentSquare->getGridY(), NULL);

		bodySegmentSquare->setGridX(headSegmentSquare->getPrevGridX());
		bodySegmentSquare->setGridY(headSegmentSquare->getPrevGridY());
		m_gameField->setFieldElement(bodySegmentSquare->getGridX(),
								bodySegmentSquare->getGridY(),
								std::dynamic_pointer_cast<SquareSegment>(bodySegmentSquare));
		bodySegment++;
		headSegment++;
	}
	if (snake.getEating())
		increaseSnakeBody(std::dynamic_pointer_cast<SnakeSegment>(*headSegment), snake);
}

void 										SnakeProcessor::increaseSnakeBody(std::shared_ptr<SnakeSegment> lastSegment, Snake &snake)
{
		snake.setEating(0);
		std::shared_ptr<SquareSegment> square = std::shared_ptr<SquareSegment>(
						static_cast<SquareSegment*>(new SnakeSegment(lastSegment->getPrevGridX(),
													lastSegment->getPrevGridY(), -1, -1)));
		snake.getSnake()->push_back(square);
		m_gameField->setFieldElement(square->getGridX(), square->getGridY(), square);
}
