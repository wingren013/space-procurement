#include "Weapon_Base.h"

Weapon_Base::Weapon_Base()
{
	
}

Weapon_Base::~Weapon_Base()
{
	
}

int				Component_Base::get_damage(int range)
{
	if (this->effectivenessModifiedByBase_damage)
		return ((this->effectiveness_damage + this->base_effectivenss / 2.0) * this->damage[range]);
	return (this->effectiveness_damage * this->damage[range]);
}

Weapon_Base	*Weapon_Base::Component_Builder(Manufactuer_Base *manufacturer)
{
	return (manufacturer->WeaponBuilder(this));
}