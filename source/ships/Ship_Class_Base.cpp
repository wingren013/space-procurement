#include "Ship_Class_Base.h"

Ship_Class_Base::Ship_Class_Base()
{
	
}

Ship_Class_Base::~Ship_Class_Base()
{
	
}

std::vector<unsigned int>	Ship_Class_Base::get_shields()
{
	return (this->componentREF[0]);
}

std::vector<unsigned int>	Ship_Class_Base::get_weapons()
{
	return (this->componentREF[1]);
}

std::vector<unsigned int>	Ship_Class_Base::get_engines()
{
	return (this->componentREF[2]);
}

std::vector<unsigned int>	Ship_Class_Base::get_sensors()
{
	return (this->componentREF[3]);
}

std::vector<unsigned int>	Ship_Class_Base::get_crew()
{
	return (this->componentREF[4]);
}

std::vector<unsigned int>	Ship_Class_Base::get_support()
{
	return (this->componentREF[5]);
}

unsigned int				Ship_Class_Base::tonnage_used()
{
	return (this->tonnage);
}
