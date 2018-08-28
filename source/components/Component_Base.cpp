#include "Component_Base.h"

Component_Base::Component_Base()
{
	
}

Component_Base::~Component_Base()
{
	
}

int				Component_Base::get_hp(void)
{
	if (this->effectivenessModifiedByBase_hp)
		return ((this->effectiveness_hp + this->base_effectiveness / 2.0) * this->max_hp);
	return (this->effectiveness_hp * this->max_hp);
}

void			Component_Base::multiply_all_costs(float factor)
{
	this->base_build_cost *= factor;
	this->base_buy_cost *= factor;
}

void			Component_Base::multiply_all_attributes(float factor)
{
	this->max_hp *= factor;
	this->tonnage *= factor;
}

/*
Component_Base	*Component_Base::Component_Builder(Manufacturer_Base *manufacturer)
{
	return (manufacturer->ComponentBuilder(this));
}
*/
