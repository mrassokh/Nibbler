/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeHead.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:02:57 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 16:03:00 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HEAD_HPP
# define SNAKE_HEAD_HPP

# include "SnakeSegment.hpp"
# include <iostream>
class SnakeHead : public SnakeSegment
{
public:
	SnakeHead();
	SnakeHead(const int & x, const int & y, const int & prev_x,
		 	const int & prev_y, const int & dirX, const int & dirY, eType type);
	SnakeHead(SnakeHead const & rhs);
	SnakeHead & operator = (SnakeHead const & rhs);
	virtual ~SnakeHead();

	int 			getDirX() const;
	int 			getDirY() const;
	float 			getDelta() const;
	int 			getLeftRotationCondition() const;
	int 			getRightRotationCondition() const;
	int				getFinish() const;
	std::string 	getFinishMessage() const;

	void 			setDirX(const int & x);
	void 			setDirY(const int & y);
	void 			setDelta(const float & delta);
	void 			setLeftRotationCondition(const int & condition);
	void 			setRightRotationCondition(const int & condition);
	void 			setFinish(const int & finish);
	void 			setFinishMessage(const std::string & finishMessage);


private:
	int				m_dirX;
	int 			m_dirY;
	float			m_delta;
	int				m_leftRotateCondition;
	int				m_rightRotateCondition;
	int				m_finish;
	std::string		m_finishMessage;
};

#endif
