#include "Ship_Class_Base.h"

Ship_Class_Base::Ship_Class_Base()
{
	
}

Ship_Class_Base::~Ship_Class_Base()
{
	
}

std::vector<unsigned int>	Ship_Class_Base::get_shields()
{
	return (this->componentREF_shields);
}

std::vector<unsigned int>	Ship_Class_Base::get_weapons()
{
	return (this->componentREF_weapons);
}

std::vector<unsigned int>	Ship_Class_Base::get_engines()
{
	return (this->componentREF_engines);
}

std::vector<unsigned int>	Ship_Class_Base::get_sensors()
{
	return (this->componentREF_sensors);
}

std::vector<unsigned int>	Ship_Class_Base::get_crew()
{
	return (this->componentREF_crew);
}

std::vector<unsigned int>	Ship_Class_Base::get_support()
{
	return (this->componentREF_support);
}

unsigned int				Ship_Class_Base::tonnage_used()
{
	return (this->tonnage);
}