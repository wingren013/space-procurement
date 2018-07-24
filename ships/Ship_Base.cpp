#include "Ship_Base.h"

Ship_Base::Ship_Base()
{
}

Ship_Base::~Ship_Base()
{
}

/*each ship must have their own unique component arrays to support partial refits. Must decide if this gameplay feature is worth it.
if I decide its not worth it I can rip out the componentRefs and just grab them from its ship_class */
Ship_Base::Ship_Base(Ship_Class_Base ship_class)
{
	this->ship_class = ship_class;
	
	//hull
	this->hull_hp_max
	
	//shields
	for(int i = 0; i < ship_class.get_shields().size; i++)
	{
		this->componentREF_shields.push_back(ship_class.get_shields()[i]);
		this->componentHP_shields.push_back(0);
		this->componentHP_shields_max.push_back(g_components[ship_class.getshields()[i]]->get_hp());
	}
	//weapons
	for(int i = 0; i < ship_class.get_weapons().size; i++)
	{
		this->componentREF_weapons.push_back(ship_class.get_weapons()[i]);
		this->componentHP_weapons.push_back(0);
		this->componentHP_weapons_max.push_back(g_components[ship_class.get_weapons()[i]]->get_hp());
	}
	//engines
	for(int i = 0; i < ship_class.get_engines().size; i++)
	{
		this->componentREF_engines.push_back(ship_class.get_engines()[i]);
		this->componentHP_engines.push_back(0);
		this->componentHP_engines_max.push_back(g_components[ship_class.get_engines()[i]]->get_hp());
	}
	//sensors
	for(int i = 0; i < ship_class.get_sensors().size; i++)
	{
		this->componentREF_sensors.push_back(ship_class.get_sensors()[i]);
		this->componentHP_sensors.push_back(0);
		this->componentHP_sensors_max.push_back(g_components[ship_class.get_sensors()[i]]->get_hp());
	}
	//crew
	for(int i = 0; i < ship_class.get_crew().size; i++)
	{
		this->componentREF_crew.push_back(ship_class.get_crew()[i]);
		this->componentHP_crew.push_back(0);
		this->componentHP_crew_max.push_back(g_components[ship_class.get_crew()[i]]->get_hp());
	}
	//support
	for(int i = 0; i < ship_class.get_support().size; i++)
	{
		this->componentREF_support.push_back(ship_class.get_support()[i]);
		this->componentHP_support.push_back(0);
		this->componentHP_support_max.push_back(g_components[ship_class.get_support()[i]]->get_hp());
	}
}

int		Ship_Base::Refit(Ship_Class_Base *refit_class)
{
	if (refit_class.get_hull_model() == this->hull_model)
	{
		//do refit
		//refit logic: check for damaged components and repair first one, if no damaged components found then check if all components match class. If yes refit is done. If no change first component to match class and set component hp to 0.
		this->ship_class = refit_class; //components will get changed over time to this standard.
		return (1);
	}
	return (0);
}

void	Ship_Base::hp_to_max(void)
{
}