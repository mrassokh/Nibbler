/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SquareSegment.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:16:43 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 17:16:44 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "../includes/SquareSegment.hpp"

 SquareSegment::SquareSegment()
 {
	 setGridX(0);
	 setGridY(0);
	 setType(DEF);
 }

 SquareSegment::SquareSegment(const int & x, const int & y, const eType & type)
 {
	 setGridX(x);
	 setGridY(y);
	 setType(type);
 }

 SquareSegment::SquareSegment(SquareSegment const & rhs)
 {
	 setType(rhs.getType());
	 setGridX(rhs.getGridX());
	 setGridY(rhs.getGridY());
 }

 SquareSegment & SquareSegment::operator = (SquareSegment const & rhs)
 {
	 if (this == &rhs)
	 	 return *this;

	 setType(rhs.getType());
	 setGridX(rhs.getGridX());
	 setGridY(rhs.getGridY());

	 return *this;
 }

 SquareSegment::~SquareSegment()
 {

 }


 int 		SquareSegment::getGridX() const
 {
	 return 	m_gridX;
 }

 int 		SquareSegment::getGridY() const
 {
	 return 	m_gridY;
 }

 void 		SquareSegment::setGridX(const int & x)
 {
	 if (x < 0)
		 return;
	 m_gridX = x;
 }

 void 		SquareSegment::setGridY(const int & y)
 {
	if (y < 0)
	 	return;
	m_gridY = y;
 }

eType		SquareSegment::getType() const
{
	return m_type;
}

void 		SquareSegment::setType(eType type)
{
   m_type = type;
}
