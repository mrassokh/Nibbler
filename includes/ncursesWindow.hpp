/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesWindow.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:21:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/06/30 14:21:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBLER_NCURSESWINDOW_HPP
#define NIBLER_NCURSESWINDOW_HPP

# include "IWindow.hpp"
# define SQUARE_SIZE 20
# include <ncurses.h>

class ncursesWindow : public IWindow
{
public:
	ncursesWindow(int width, int height);
	virtual ~ncursesWindow();

	virtual EVENTS			getEvent(void);
	virtual void 			drawSquare(int x, int y, eType type);
	virtual void 			drawScore(int score, int velocity, eType type, int mult);
	virtual void 			drawStart();
	virtual void 			drawGameOver(std::string const & finishMessage);
	virtual void 			startCycl(void);
	virtual void 			endCycl(void);
	virtual void 			init(void);
	virtual void 			quit(std::string const & finishMessage);

	EVENTS 					handleKeyDown() const;
private:
	ncursesWindow();

	int 					m_width;
	int 					m_height;
	WINDOW					*m_window;
	int 					m_event;
};

extern "C" {
	ncursesWindow		*createWindow(int width, int height);
	void 			deleteWindow(ncursesWindow *ncursesWindow);
}

#endif //NIBLER_NCURSESWINDOW_HPP

