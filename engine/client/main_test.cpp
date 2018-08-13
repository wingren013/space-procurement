#include "Asset_IO.h"
#include "Component_Base.h"

//yes yes I know this global is bad. This is a hacky build to build a proof of concept for the design AI so take your complaints to people who have code that isn't going to be rewritten
std::vector<Weapon_Base*>	*g_componentsWeapons;

int			main(void)
{
	Game newgame;
	
	newgame.initialize();
	
	Manufacturer_Base	*m = new Manufacturer_Base::Manufacturer();
	
	g_componentsWeapons = newgame.get_weapons();
	for (int i = 0; i < 10; i++)
	{
		g_componentsWeapons.push_back(g_componentsWeapons[0]->Component_Builder(m));
	}
	display_ship(ShipBuilder::ShipBuilder(5, 1000));
}