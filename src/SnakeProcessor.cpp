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

void 				SnakeProcessor::setWindow(IWindow *window)
{
	m_window = window;
}

void 				SnakeProcessor::setLoopCondition(int *loopCondition)
{
	m_loopCondition = loopCondition;
}

void 				SnakeProcessor::configure(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
										GameField *gameField,IWindow *window, int *loopCondition, int multMode)
{
	setFoodList(foodList);
	setGameField(gameField);
	setWindow(window);
	setLoopCondition(loopCondition);
	m_multMode = multMode;
}

void 				SnakeProcessor::initSnake(Snake &snake, GameField *gameField, int isSecondSnake, int multMode)
{
	int x = gameField->getWidth() / 2;
	int y;
	if (multMode)
		y = isSecondSnake ? gameField->getHeight() / 2 - 2 :  gameField->getHeight() / 2 + 2;
	else
		y = gameField->getHeight() / 2;
	int prev_x = x - 1;
	int prev_y = y;
	int dir_x = 1;
	int dir_y = 0;
	int lenght = 4;
	eType type = isSecondSnake ? SNAKE_SECOND_HEAD : SNAKE_HEAD;
	std::shared_ptr<SquareSegment> head = std::shared_ptr<SquareSegment>(
				static_cast<SquareSegment*>(new SnakeHead(x, y, prev_x, prev_y, dir_x, dir_y, type)));
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

	if (!checkHit(nextX, nextY, snake, headSquare))
		return ;
	update(nextX, nextY, snake, headSquare, velocity, deltaTime);
}

int 				SnakeProcessor::checkHit(int const & nextX, int const & nextY, Snake &snake, std::shared_ptr<SnakeHead> headSquare)
{
	snake.setNextIsNotObstacle(1);
	if (!checkBorderHit(nextX, nextY, headSquare)
		|| !checkObstacleHit(nextX, nextY,snake, headSquare)
		|| !checkSnakeSegmentHit(nextX, nextY, headSquare))
			return (0);
	return (1);
}

int 				SnakeProcessor::checkBorderHit(int const & nextX, int const & nextY, std::shared_ptr<SnakeHead> headSquare)
{
	if (nextX >= m_gameField->getWidth() || nextX < 0 || nextY < 0 || nextY >= m_gameField->getHeight())
	{
		headSquare->setFinish(1);
		headSquare->setFinishMessage("hit border!!!");
		return (0);
	}
	return (1);
}

int 				SnakeProcessor::checkObstacleHit(int const & nextX, int const & nextY, Snake &snake, std::shared_ptr<SnakeHead> headSquare)
{
	std::shared_ptr<SquareSegment> nextSegment = m_gameField->getFieldElement(nextX, nextY);
	if (nextSegment && nextSegment->getType()== OBSTACLE)
	{
		int sideFirstX;
		int sideFirstY;
		int sideSecondX;
		int sideSecondY;

		snake.setNextIsNotObstacle(0);
		if (headSquare->getDirX()) {
			sideFirstX = headSquare->getGridX();
			sideFirstY = headSquare->getGridY() + 1;
			sideSecondX = headSquare->getGridX();
			sideSecondY = headSquare->getGridY() - 1;
		} else {
			sideFirstX = headSquare->getGridX() + 1;
			sideFirstY = headSquare->getGridY();
			sideSecondX = headSquare->getGridX() - 1;
			sideSecondY = headSquare->getGridY();
		}
		std::shared_ptr<SquareSegment> sideFirstSegment = m_gameField->getFieldElement(sideFirstX, sideFirstY);
		std::shared_ptr<SquareSegment> sideSecondSegment = m_gameField->getFieldElement(sideSecondX, sideSecondY);

		if (sideFirstSegment && sideFirstSegment->getType()== OBSTACLE
			&& sideSecondSegment && sideSecondSegment->getType()== OBSTACLE){
				headSquare->setFinish(1);
				headSquare->setFinishMessage("in the TRAP!!!");
				return (0);
		}
	}
	return (1);
}

int 				SnakeProcessor::checkSnakeSegmentHit(int const & nextX, int const & nextY, std::shared_ptr<SnakeHead> headSquare)
{
	std::shared_ptr<SquareSegment> nextSegment = m_gameField->getFieldElement(nextX, nextY);
	if (nextSegment && (nextSegment->getType()== SNAKE_SEGMENT
						|| nextSegment->getType() == SNAKE_HEAD || nextSegment->getType() == SNAKE_SECOND_HEAD))
	{
		headSquare->setFinish(1);
		headSquare->setFinishMessage("hit snake segment!!!");
		return (0);
	}
	return (1);
}

void 				SnakeProcessor::checkFinish(Snake &firstSnake, Snake &secondSnake)
{
	auto firstHead = firstSnake.getSnake()->begin();
	auto firstHeadSquare = std::dynamic_pointer_cast<SnakeHead>(*firstHead);
	std::string firstHeadMessage = "First snake " + firstHeadSquare->getFinishMessage() + "\n";

	if (m_multMode){
		auto secondHead = secondSnake.getSnake()->begin();
		auto secondHeadSquare = std::dynamic_pointer_cast<SnakeHead>(*secondHead);

		std::string secondHeadMessage = "Second snake " + secondHeadSquare->getFinishMessage() + "\n";
		if (firstHeadSquare->getFinish() && secondHeadSquare->getFinish()){
			throw CustomExeption(firstHeadMessage +  secondHeadMessage + "DEAD HEAT!!!");
		} else if(firstHeadSquare->getFinish()) {
				throw CustomExeption(firstHeadMessage + "SECOND SNAKE WIN!!!");
		} else if(secondHeadSquare->getFinish()){
				throw CustomExeption(secondHeadMessage + "FIRST SNAKE WIN!!!");
		}
	} else {
		if (firstHeadSquare->getFinish()) {
			throw CustomExeption("Snake " + firstHeadSquare->getFinishMessage() + "\n");
		}
	}
	checkAchieveFinisScore(firstSnake, secondSnake);
}

void 				SnakeProcessor::checkAchieveFinisScore(Snake &firstSnake, Snake &secondSnake)
{
	if (m_multMode){
		if (firstSnake.getScore() >= 3 && secondSnake.getScore() >= 3)
		{
			throw CustomExeption("First and second snakes achives score " +  std::to_string(firstSnake.getScore()) + "\n DEAD HEAT !!!\n");
		} else if (firstSnake.getScore() >= 3) {
			throw CustomExeption("First snake achives score " +  std::to_string(firstSnake.getScore()) + " and WIN!!!\n");
		} else if (secondSnake.getScore() >= 3) {
			throw CustomExeption("Second snake achives score " +  std::to_string(secondSnake.getScore()) + " and WIN!!!\n");
		}
	} else {
		if (firstSnake.getScore() >= 3) {
			throw CustomExeption("Snake achives score " +  std::to_string(firstSnake.getScore()) + " and WIN!!!\n");
		}
	}
}

void 				SnakeProcessor::update(int const & nextX,	int const & nextY, Snake &snake,
									std::shared_ptr<SnakeHead> headSquare,
									int velocity, double deltaTime)
{
	headSquare->setDelta(headSquare->getDelta() + velocity * deltaTime * snake.getNextIsNotObstacle());
	if (headSquare->getDelta() >=1.0)
	{
		headSquare->setLeftRotationCondition(0);
		headSquare->setRightRotationCondition(0);
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

void 				SnakeProcessor::updateSnakeBody(Snake &snake)
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

void 				SnakeProcessor::increaseSnakeBody(std::shared_ptr<SnakeSegment> lastSegment, Snake &snake)
{
		snake.setEating(0);
		std::shared_ptr<SquareSegment> square = std::shared_ptr<SquareSegment>(
						static_cast<SquareSegment*>(new SnakeSegment(lastSegment->getPrevGridX(),
													lastSegment->getPrevGridY(), -1, -1)));
		snake.getSnake()->push_back(square);
		m_gameField->setFieldElement(square->getGridX(), square->getGridY(), square);
}
