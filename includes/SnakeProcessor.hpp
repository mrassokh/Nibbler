/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeProcessor.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:18:05 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/01 15:18:07 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_PROCESSOR_HPP
# define SNAKE_PROCESSOR_HPP
#include "GameField.hpp"
#include "Snake.hpp"
#include "CustomExeptions.hpp"
#include "FoodSegment.hpp"
#include "IWindow.hpp"
#include "Obstacle.hpp"
#include <vector>


class SnakeProcessor
{
public:
	static SnakeProcessor				&Instance();
	void 								initSnake(Snake &snake, GameField *gameField, int isSecondSnake, int multMode);
	void 								updateSnake(Snake &snake, int velocity,
		 										double deltaTime);
	void 								checkFinish(Snake &firstSnake, Snake &secondSnake);
	void 								configure(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
												GameField *gameField,IWindow *window, int *loopCondition, int multMode);
	void 								setFoodList(std::shared_ptr<std::vector
														<std::shared_ptr<FoodSegment>>> foodList);
	void 								setGameField(GameField	*gameField);
	void 								setWindow(IWindow *window);
	void 								setLoopCondition(int *loopCondition);
	void 								setFirstScore(int *firstScore);
	void 								setSecondScore(int *secondScore);

private:
	SnakeProcessor();
	SnakeProcessor(SnakeProcessor const & rhs) = delete;
	SnakeProcessor& operator = (SnakeProcessor const & rhs) = delete;
	virtual ~SnakeProcessor();

	int 								checkHit(int const & nextX, int const & nextY, Snake &snake, std::shared_ptr<SnakeHead> headSquare);
	int 								checkBorderHit(int const & nextX, int const & nextY, std::shared_ptr<SnakeHead> headSquare);
	int 								checkObstacleHit(int const & nextX, int const & nextY, Snake &snake, std::shared_ptr<SnakeHead> headSquare);
	int 								checkSnakeSegmentHit(int const & nextX, int const & nextY, std::shared_ptr<SnakeHead> headSquare);
	void 								checkAchieveFinisScore(Snake &firstSnake, Snake &secondSnake);
	void 								update(int const & nextX, int const & nextY,
											Snake &snake,
											std::shared_ptr<SnakeHead> headSquare,
										 	int velocity, double deltaTime);
	void 								updateSnakeBody(Snake &snake);
	void 								increaseSnakeBody(std::shared_ptr<SnakeSegment> lastSegment,
													Snake &snake);

	std::shared_ptr<std::vector
		<std::shared_ptr<FoodSegment>>> m_foodList;
	GameField							*m_gameField;
	IWindow								*m_window;
	int 								*m_loopCondition;
	int 								m_multMode;
};
#endif
