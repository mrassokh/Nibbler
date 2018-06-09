/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursWindow.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:29:37 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 13:29:41 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NCURS_WINDOW_HPP
# define NCURS_WINDOW_HPP
# include "IWindow.hpp"
#include <ncurses.h>
# define SQUARE_SIZE 40
class NcursWindow : public IWindow
{
public:
	NcursWindow(int width, int height);
	virtual ~NcursWindow();
	virtual EVENTS 					getEvent(void);
	virtual void 					drawSquare(int x, int y, eType type);
	virtual void 					startCycl(void);
	virtual void 					endCycl(void);
	virtual void 					init(void);
	virtual void 					quit(void);

	EVENTS 							handleKeyDown(int key) const;
private:
	NcursWindow();

	int 					m_width;
	int 					m_height;
	bool 					m_quit;
};

extern "C" {
	NcursWindow		*createWindow(int width, int height);
	void 			deleteWindow(NcursWindow *ncursWindow);
}

#endif
