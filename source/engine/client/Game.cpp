#include "Game.h"

void		Game::initialize(void) //overload this with other game setup options like taking a mod or a save game
{
	loaded_weapons = Asset_IO::load_weapons();
}

//void		Game::intialize(string modpath)

//void		Game::initialize(string modpath, unsigned int options)

//void		Game::initializae(unsigned int options)

//void		Game::initialize(string savepath)

std::vector<Weapon_Base*>	Game::get_weapons()
{
	return (this->loaded_weapons);
}
