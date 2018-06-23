/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:52:22 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 16:52:24 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP
# include <list>
# include "SquareSegment.hpp"
# include "SnakeHead.hpp"

class Snake
{
public:
	Snake();
	Snake(Snake const & rhs);
	Snake & operator = (Snake const & rhs);
	virtual ~Snake();

	std::shared_ptr<std::list<std::shared_ptr<SquareSegment>>>	getSnake();
	int 														getEating() const;
	void 														setEating(int const & eating);
	int 														getScore() const;
	void 														setScore(int const & score);
	int 														getNextIsNotObstacle() const;
	void 														setNextIsNotObstacle(int const & nextIsNotObstacle);

private:
	std::shared_ptr<std::list<std::shared_ptr<SquareSegment>>> 	m_snake;
	int															m_eating;
	int 														m_score;
	int 														m_nextIsNotObstacle;
};

#endif
