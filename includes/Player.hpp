#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include "IEntity.hpp"
#include <ncurses.h>
//# include <SDL2/SDL.h>
//# include "SDL.h"
//extern "C" {
//# include "../sdllib/Headers/SDL.h"
//# include "../sdllib/SDL2-2.0.8/include/SDL.h"
//# include "../sdllib/sdl_Headers/SDL.h"
# include "../sdllib/SDL2.framework/Headers/SDL.h"
//}

// extern "C" {
// # include "../sdllib/SDL.h"
// }

class Player : public IEntity
{
private:
	std::string		m_name;
	int				m_score;
	Player(void);
public:
	Player(std::string name);
	virtual ~Player(void);

	std::string 	getName(void) const;
	int 			getScore(void) const;
	void 			markPoint(void);
	void 			announces(void) const;
	void 			draw(void) const;
};

extern "C" {
	Player		*createPlayer(const std::string & name);
	void 		deletePlayer(Player *player);
	void  		hello();
}
int menu();
int info();
#endif
