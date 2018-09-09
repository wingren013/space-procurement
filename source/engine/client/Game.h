#ifndef GAME_H
# define GAME_H

#include "Asset_IO.h"

class	Game
{
	//edit:  I'm dumb and I forgot I wasn't writing C. Everything is always in scope so no pointers needed. Now there is an interesting discussion to be had over not having everything loaded into memory but to get this working quickly I'm ignoring that for now.
	public:
		void						initialize();
		std::vector<Weapon_Base*>	get_weapons();
	
	protected:
		std::vector<Weapon_Base*>	*loaded_weapons;
	
	private:
};

#endif
