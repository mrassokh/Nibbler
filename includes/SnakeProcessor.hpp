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
#include <vector>


class SnakeProcessor
{
public:
	static SnakeProcessor		&Instance();
	void 						initSnake(Snake &snake, GameField *gameField);
	void 						updateSnake(Snake &snake, int velocity,
		 									double deltaTime);
	void 						configure(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
											GameField *gameField,IWindow *window, int *loopCondition);
	void 						setFoodList(std::shared_ptr<std::vector
														<std::shared_ptr<FoodSegment>>> foodList);
	void 						setGameField(GameField	*gameField);
	void 						setWindow(IWindow *window);
	void 						setLoopCondition(int *loopCondition);
	void 						setFirstScore(int *firstScore);
	void 						setSecondScore(int *secondScore);

private:
	SnakeProcessor();
	SnakeProcessor(SnakeProcessor const & rhs) = delete;
	SnakeProcessor& operator = (SnakeProcessor const & rhs) = delete;
	virtual ~SnakeProcessor();

	void 								checkHit(int const & nextX, int const & nextY);
	void 								checkBorderHit(int const & nextX, int const & nextY);
	void 								checkSnakeSegmentHit(int const & nextX, int const & nextY);
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
};
#endif
