#include "Weapon_Base.h"
#include "Manufacturer_Base.h"

extern std::vector<Weapon_Base*>	g_componentsWeapons;

Weapon_Base::Weapon_Base()
{
	
}

Weapon_Base::~Weapon_Base()
{
	
}

int				Weapon_Base::get_damage(int range)
{
	if (this->effectivenessModifiedByBase_damage)
		return ((this->effectiveness_damage + this->Component_Base::base_effectiveness / 2.0) * this->damage[range]);
	return (this->effectiveness_damage * this->damage[range]);
}

void			Weapon_Base::multiply_all_costs(float factor)
{
	this->Component_Base::base_build_cost *= factor;
	this->Component_Base::base_buy_cost *= factor;
}

void			Weapon_Base::multiply_all_attributes(float factor)
{
	this->Component_Base::max_hp *= factor;
	this->Component_Base::tonnage *= factor;

	this->fire_rate *= factor;
	//shield pen and armor pen aren't modified because these are special attributes of weapons that should remain static for all weapons of that type aside from effectiveness modifiers.

	for (int i = 0; i < 4; i++)
	{
		this->accuracy[i] *= factor;
		this->range_band[i] *= factor;
		this->damage[i] *= factor;
	}
}

Weapon_Base*			WeaponBuilder(Weapon_Base *template_component, Manufacturer_Base *manufacturer)
{
	Weapon_Base		*new_weapon = new Weapon_Base(template_component, manufacturer);
	float			tonnage_factor = GenMeth::random_float_in_range(0.75, 1.5); //move this out of asset_io

	//for now all this does is just make weapons that scale with size. For the future modifiers like heavy (slower firing better punch), or high-tech (improved all over but expensive), or fragile (less hp and a bit cheaper and lighter)
	//also weapons should be modified by manufacturer's techs but since manufacturers aren't implemented yet that can't be done.
	new_weapon->multiply_all_costs(tonnage_factor);
	new_weapon->multiply_all_attributes(tonnage_factor);
	//new_weapon.descr += "made by " += g_manufacturers[manufacturer_id]->name();
	return (new_weapon);
}

unsigned int	Weapon_Base::Component_Builder(void *m)
{
	Weapon_Base	*new_weapon = WeaponBuilder(this, (Manufacturer_Base*)m);

	g_componentsWeapons.push_back(new_weapon);
	return (g_componentsWeapons.size());
}
