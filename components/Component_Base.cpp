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
		return ((this->effectiveness_hp + this->base_effectivenss / 2.0) * this->max_hp);
	return (this->effectiveness_hp * this->max_hp);
}