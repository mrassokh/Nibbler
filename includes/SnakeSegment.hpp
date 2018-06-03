/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeSegment.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:49:05 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 14:49:14 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_SEGMENT_HPP
# define SNAKE_SEGMENT_HPP

# include "SquareSegment.hpp"

class SnakeSegment : public SquareSegment
{
public:
	SnakeSegment();
	SnakeSegment(const int & x, const int & y, const int & prev_x,
		 					const int & prev_y);
	SnakeSegment(SnakeSegment const & rhs);
	SnakeSegment & operator = (SnakeSegment const & rhs);
	virtual ~SnakeSegment();

	int 		getPrevGridX() const;
	int 		getPrevGridY() const;
	void 		setPrevGridX(const int & x);
	void 		setPrevGridY(const int & y);

private:
	int			m_prevGridX;
	int 		m_prevGridY;
};


#endif
