/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlWindow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:08:52 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 14:09:00 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_WINDOW_HPP
# define SDL_WINDOW_HPP
# include "IWindow.hpp"
# include "../sdllib/SDL2.framework/Headers/SDL.h"
# define SQUARE_SIZE 40
class SdlWindow : public IWindow
{
public:
	SdlWindow(int width, int height);
	virtual ~SdlWindow();
	virtual EVENTS 					getEvent(void);
	virtual void 					drawSquare(int x, int y, eType type);
	virtual void 					startCycl(void);
	virtual void 					endCycl(void);
	virtual void 					init(void);
	virtual void 					quit(void);

	EVENTS 							handleKeyDown(int key) const;
private:
	SdlWindow();

	int 					m_width;
	int 					m_height;
	SDL_Event 				m_event;
	SDL_Window 				*m_window;
	SDL_Renderer 			*m_renderer;
	bool 					m_quit;


};

extern "C" {
	SdlWindow		*createWindow(int width, int height);
	void 			deleteWindow(SdlWindow *sdlWindow);
}

#endif
