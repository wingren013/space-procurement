#pragma once
#ifndef SHIP_BASE_HPP
# define SHIP_BASE_HPP

#include <vector>
#include Ship_Class_Base.h
#include Ship_Hull_Base.h
#include Weapon_Base.h
#include Shield_Base.h
#include Engine_Base.h
#include Sensors_Base.h
#include Crew_Base.h
#include Support_Base.h

//our ship class contains all the info about a given ship class. This class is for individual instances of ships.
class Ship_Base
{
public:
	Ship_Base();
	Ship_Base(Ship_Class_Base *ship_class);
	~Ship_Base();
	
	int	Refit(Ship_Class_Base *ship_class);
	void	hp_to_max();
protected:
	//so save file size is going to be a concern here. Remember keep it memory light.
	//component hp, assume components with hp == 0 are destroyed while components with hp < 0 are inactive.
	//if components are inactive damage needs to be added rather than subtracted for obvious reasons.
	//Flipping components to active means just multiplying by -1
	//this saves a dword per component. You're welcome.
	std::vector<int>	componentHP_shields;
	std::vector<int>	componentHP_weapons;
	std::vector<int>	componentHP_engines;
	std::vector<int>	componentHP_sensors; //because EWar
	std::vector<int>	componentHP_crew; //crew quarters always 0. No need to simulate seperate crew quarters aside from VIP suites
	std::vector<int>	componentHP_support; //misc stuff like aux reactors, science labs, cargo holds, EWar suites, etc...
	
	int					hull_hp[5]; //center 0, starboard 1, port 2, forward 3, aft 4
	int					shield_hp[5]; //center 0, starboard 1, port 2, forward 3, aft 4

	std::vector<int>	componentHP_shields_max;
	std::vector<int>	componentHP_weapons_max;
	std::vector<int>	componentHP_engines_max;
	std::vector<int>	componentHP_sensors_max;
	std::vector<int>	componentHP_crew_max; //crew quarters always 0. No need to simulate seperate crew quarters aside from VIP suites
	std::vector<int>	componentHP_support_max;

	int					hull_hp_max[5]; //center 0, starboard 1, port 2, forward 3, aft 4
	int					shield_hp_max[5]; //center 0, starboard 1, port 2, forward 3, aft 4

	double				ablative_threshold //represents the percent of hull remaining at which point component damage becomes possible. check if (double)hull_hp[x] >= ablative_threshold * hull_hp_max[x];

	//componentREF_foo[0] matches up with componentHP_foo[0] and componentHP_foo_max[0]
	//we store a pointer to the component rather than its id for ease of use. On second thought it might be better to do it via id.
	/*
	std::vector<Shield_Base*>	componentREF_shields;
	std::vector<Weapon_Base*>	componentREF_weapons;
	std::vector<Engine_Base*>	componentREF_engines;
	std::vector<Sensor_Base*>	componentREF_sensors;
	std::vector<Crew_Base*>		componentREF_crew;
	std::vector<Support_Base*>	componentREF_support;
	*/
	
	//if anybodies game break because they've reached UINT_MAX components I will personally refactor the entire codebase to change it to longs.
	std::vector<unsigned int>	componentREF_shields;
	std::vector<unsigned int>	componentREF_weapons;
	std::vector<unsigned int>	componentREF_engines;
	std::vector<unsigned int>	componentREF_sensors;
	std::vector<unsigned int>	componentREF_crew;
	std::vector<unsigned int>	componentREF_support;
	
	Ship_Hull_Base				*hull_model;
	/*	std::vector<Character*>		characterREF;
		std::vector<Culture*>		crew_cultureREF;
		std::vector<double>			crew_culturePER // percentage of the crew for each culture
	future stuff */
	//ship status is denoted by which array it is in i.e. status_array_refit. status is changed by switching arrays. This saves memory.
	
//not sure what functions needed yet beyond a bunch of stuff to check things and set things.
private:
	Ship_Class_Base	*ship_class; //use this to populate our design, can be changed to accomodate for refits.
}
Ship_Base::Ship_Base()
{
}

Ship_Base::Ship_Base(Ship_Class_Base ship_class)
{
	this.ship_class = ship_class;
	
	//shields
	for(int i = 0; i < ship_class.get_shields().size; i++)
	{
		this.componentREF_shields.push_back(ship_class.get_shields()[i]);
		this.componentHP_shields.push_back(0);
		this.componentHP_shields_max.push_back(g_components[ship_class.getshields()[i]]->get_hp());
	}
	//weapons
	for(int i = 0; i < ship_class.get_weapons().size; i++)
	{
		this.componentREF_weapons.push_back(ship_class.get_weapons()[i]);
		this.componentHP_weapons.push_back(0);
		this.componentHP_weapons_max.push_back(g_components[ship_class.get_weapons()[i]]->get_hp());
	}
	//engines
	for(int i = 0; i < ship_class.get_engines().size; i++)
	{
		this.componentREF_engines.push_back(ship_class.get_engines()[i]);
		this.componentHP_engines.push_back(0);
		this.componentHP_engines_max.push_back(g_components[ship_class.get_engines()[i]]->get_hp());
	}
	//sensors
	for(int i = 0; i < ship_class.get_sensors().size; i++)
	{
		this.componentREF_sensors.push_back(ship_class.get_sensors()[i]);
		this.componentHP_sensors.push_back(0);
		this.componentHP_sensors_max.push_back(g_components[ship_class.get_sensors()[i]]->get_hp());
	}
	//crew
	for(int i = 0; i < ship_class.get_crew().size; i++)
	{
		this.componentREF_crew.push_back(ship_class.get_crew()[i]);
		this.componentHP_crew.push_back(0);
		this.componentHP_crew_max.push_back(g_components[ship_class.get_crew()[i]]->get_hp());
	}
	//support
	for(int i = 0; i < ship_class.get_support().size; i++)
	{
		this.componentREF_support.push_back(ship_class.get_support()[i]);
		this.componentHP_support.push_back(0);
		this.componentHP_support_max.push_back(g_components[ship_class.get_support()[i]]->get_hp());
	}
}

Ship_Base::~Ship_Base()
{
}

int		Ship_Base::Refit(Ship_Class_Base *refit_class)
{
	if (refit_class.get_hull_model() == this.hull_model)
	{
		//do refit
		//refit logic: check for damaged components and repair first one, if no damaged components found then check if all components match class. If yes refit is done. If no change first component to match class and set component hp to 0.
		this.ship_class = refit_class; //components will get changed over time to this standard.
		return (1);
	}
	return (0);
}

void	Ship_Base::hp_to_max(void)
{
}


Ship_Base::~
#endif // !1

