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
	initscr();
    curs_set(0);
    nodelay(stdscr, true);
    noecho();
    keypad(stdscr, true);
    int loop = 1;
    while (loop)
        loop = menu();
}

Player		*createPlayer(const std::string & name)
{
	return new Player(name);
}

void 		deletePlayer(Player *player)
{
	delete player;
}


int menu()
{
    int cur_pos = 1;
    int loop = 0;
    while ( true )
    {
        clear();
        mvwprintw(stdscr,  cur_pos, 6, "%s", ">");
        mvwprintw(stdscr,  0, 8, "%s", "FT_RETRO (Battlestar Galactica)");
        mvwprintw(stdscr,  1, 8, "%s", "START GAME");
        mvwprintw(stdscr,  2, 8, "%s", "INFO");
        mvwprintw(stdscr,  3, 8, "%s", "EXIT");
        switch ( getch() )
        {
            case KEY_UP:
                if (cur_pos > 1)
                    cur_pos -= 1;
                break;
            case KEY_DOWN:
                if (cur_pos < 3)
                    cur_pos += 1;
                break;
            case KEY_RIGHT:
                if (cur_pos == 1)
                   loop = 1;
                if (cur_pos == 2)
                    info();
                if (cur_pos == 3)
                    return 0;
                break;
            case 27:
                return 0;
        }
        refresh();
    }
}

int info()
{
    while ( true )
    {
        clear();
        mvwprintw(stdscr,  1, 8, "%s", "Press ESC to exit");
        mvwprintw(stdscr,  5, 0, "%s", "Battlestar Galactica is an American science fiction franchise created by Glen A.\n"
                "Larson. The franchise began with the original television series in 1978 and was\n"
                "later followed by a short-run sequel series (Galactica 1980), a line of book\n"
                "adaptations, original novels, comic books, a board game, and video games. A\n"
                "re-imagined version of Battlestar Galactica aired as a two-part, three-hour\n"
                "miniseries developed by Ronald D. Moore and David Eick in 2003. That miniseries\n"
                "led to a weekly television series, which later aired up until 2009. A prequel\n"
                "series, Caprica, aired in 2010. A two-hour pilot for a second spin-off prequel\n"
                "series, Blood & Chrome, aired in 2013 though this did not lead to a series as\n"
                "originally planned.\n");
        switch ( getch() )
        {
            case 27:
                return 0;
        }
    }
}
