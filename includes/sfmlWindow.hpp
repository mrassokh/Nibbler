//
// Created by Roman Malkevych on 6/9/18.
//

#ifndef NIBLER_SFMLWINDOW_HPP
#define NIBLER_SFMLWINDOW_HPP

# include "IWindow.hpp"
# include "SFML/Graphics.hpp"
# include "SFML/Window.hpp"

# define SQUARE_SIZE 40
class SfmlWindow : public IWindow
{
public:
	SfmlWindow(int width, int height);
	virtual ~SfmlWindow();

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
	SfmlWindow();

	int 					m_width;
	int 					m_height;
	sf::RenderWindow		*m_window;
	sf::Event 				*m_event;
	bool 					m_quit;


};

extern "C" {
	SfmlWindow		*createWindow(int width, int height);
	void 			deleteWindow(SfmlWindow *sfmlWindow);
}
#endif
