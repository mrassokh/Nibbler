/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameField.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:01:14 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 12:01:17 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_FIELD_HPP
# define GAME_FIELD_HPP
# include "SquareSegment.hpp"
# include "CustomExeptions.hpp"
# include <iostream>

class GameField
{
public:
	static GameField				&Instance(int const & width, int const & height);

	int								getWidth() const;
	int								getHeight() const;
	int								getSize() const;
	std::shared_ptr<SquareSegment>	getFieldElement(int const & grid_x, int const & grid_y) const;
	void 							setFieldElement(int const & grid_x, int const & grid_y,
														std::shared_ptr<SquareSegment> square);
	void 							clear();

private:
	GameField() = delete;
	GameField(int const & width, int const & height);
	GameField(GameField const & rhs) = delete;
	GameField & operator = (GameField const & rhs) = delete;
	virtual ~GameField();

	std::shared_ptr<SquareSegment>  *m_field;
	int								m_width;
	int								m_height;
	int								m_size;
};
#endif
