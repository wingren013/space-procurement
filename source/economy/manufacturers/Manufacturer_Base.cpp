#include "Manufacturer_Base.h"
#include "Weapon_Base.h"

extern std::vector<Weapon_Base*>	g_componentsWeapons;

Manufacturer_Base::Manufacturer_Base() {
	// TODO Auto-generated constructor stub

}

Manufacturer_Base::~Manufacturer_Base() {
	// TODO Auto-generated destructor stub
}

void	Manufacturer_Base::new_component()
{
	std::random_device 	r;
	std::mt19937		mers(r);
	std::uniform_int_distribution<> rand1(0, 6);

	switch (rand1)
	{
	case 0: {
				new_weapon();
			}
	}
}

void	Manufacturer_Base::new_weapon()
{
	std::random_device	r;
	std::mt19937		mers(r);
	std::uniform_int_distribution<>	rand1(0, this->manufacturer_tech[1].size());

	//this->manufactured_components[1].push_back(((Weapon_Base*)g_componentsWeapons[rand1])->Component_Builder(this));
	//this->manufactured_components[1].push_back(*(g_componentsWeapons[rand1]).Component_Builder(this));
	Weapon_Base *weapon = g_componentsWeapons[rand1];
	this->manufactured_components[1].push_back(weapon->Component_Builder(this));
}
