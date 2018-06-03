/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SquareSegment.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:56:09 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 16:56:11 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_SEGMENT_HPP
# define SQUARE_SEGMENT_HPP

// typedef struct			s_color
// {
// 	unsigned char		red;
// 	unsigned char		green;
// 	unsigned char		blue;
// 	unsigned char		alpha;
// }						t_color;

enum eType
{
	DEF,
	OBSTACLE,
	FOOD,
	SNAKE_SEGMENT,
	SNAKE_HEAD
};

class SquareSegment
{
public:
	SquareSegment();
	SquareSegment(const int & x, const int & y, const eType & type);
	SquareSegment(SquareSegment const & rhs);
	SquareSegment & operator = (SquareSegment const & rhs);
	virtual ~SquareSegment();

	int 		getGridX() const;
	int 		getGridY() const;
	eType		getType() const;
	void 		setGridX(const int & x);
	void 		setGridY(const int & y);
	void		setType(eType type);

private:
	int			m_gridX;
	int 		m_gridY;
	eType		m_type;
};
#endif
