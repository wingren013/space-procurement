#include "Asset_IO.h"
#include "Component_Base.h"
#include "Game.h"
#include "Weapon_Base.h"
#include "Manufacturer_Base.h"
#include "ShipBuilder.h"

//yes yes I know this global is bad. This is a hacky build to build a proof of concept for the design AI so take your complaints to people who have code that isn't going to be rewritten
extern std::vector<Weapon_Base*>	*g_componentsWeapons;

int			main(void)
{
	Game newgame;
	
	newgame.initialize();
	
	Manufacturer_Base::Manufacturer_Base	*m = new Manufacturer_Base::Manufacturer_Base();
	
	g_componentsWeapons = newgame.get_weapons();
	for (int i = 0; i < 10; i++)
	{
		newgame.get_weapons();
		g_componentsWeapons->operator [](0)->Component_Builder((Manufacturer_Base*)m);
	}
	display_ship(ShipBuilder::ShipBuilder(5, 1000));

	Weapon_Base	weapon = g_componentsWeapons[0]; //eclipse is dumb.
//fucking what? m is a valid argument.
	weapon.Component_Builder(m);
}
