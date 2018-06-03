#include "Player.hpp"

Player::Player(std::string name) :  m_name(name), m_score(0) {}

Player::~Player(void){}

std::string 	Player::getName(void) const
{
	return m_name;
}

int 			Player::getScore(void) const
{
	return m_score;
}

void 			Player::markPoint(void)
{
	m_score++;
}

void 			Player::announces(void) const
{
	std::cout << "My name is " << this->m_name << "and I have destroyed ";
	std::cout << m_score << " enemies so far" << std::endl;
}

void 			Player::draw(void) const
{
	// if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	// {
	// 	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
	// 	return ;
	// }
	// //auto window =
	// SDL_CreateWindow("NIBBLER", SDL_WINDOWPOS_UNDEFINED,
	// 	SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_OPENGL);
	// 		SDL_Delay(2000);

			// variables

	      bool quit = false;
	      SDL_Event event;

	      // init SDL

	      SDL_Init(SDL_INIT_VIDEO);
	      SDL_Window * window = SDL_CreateWindow("SDL2 line drawing",
	          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	      SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

	      // handle events

	      while (!quit)
	      {
	          SDL_Delay(10);
	          SDL_PollEvent(&event);

	          switch (event.type)
	          {
	              case SDL_QUIT:
	                  quit = true;
	                  break;
	              // TODO input handling code goes here
	          }

	          // clear window

	          SDL_SetRenderDrawColor(renderer, 42, 242, 242, 255);
	          SDL_RenderClear(renderer);

	          // TODO rendering code goes here

	          // render window

	          SDL_RenderPresent(renderer);
	      }

	      // cleanup SDL

	      SDL_DestroyRenderer(renderer);
	      SDL_DestroyWindow(window);
	      SDL_Quit();

	     // return 0;
	//auto gl_context = SDL_GL_CreateContext(window);
}

Player		*createPlayer(const std::string & name)
{
	return new Player(name);
}

void 		deletePlayer(Player *player)
{
	delete player;
}
