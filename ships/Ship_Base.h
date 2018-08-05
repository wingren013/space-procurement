#pragma once
#ifndef SHIP_BASE_HPP
# define SHIP_BASE_HPP

#include <vector>
#include "Ship_Class_Base.h"
#include "Ship_Hull_Base.h"
#include "Weapon_Base.h"
#include "Shield_Base.h"
#include "Engine_Base.h"
#include "Sensors_Base.h"
#include "Crew_Base.h"
#include "Support_Base.h"

//our ship class contains all the info about a given ship class. This class is for individual instances of ships.
class Ship_Base
{
public:
	Ship_Base();
	Ship_Base(Ship_Class_Base *ship_class);
	~Ship_Base();
	
	int	Refit(Ship_Class_Base *ship_class);
	void	hp_to_max();
	
	std::vector<int>	get_shield_hp();
	int					get_shield_hp(size_t i);
protected:
	//so save file size is going to be a concern here. Remember keep it memory light.
	String				name;
	
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

	//we need our own copy of max hp because of partial refits
	std::vector<int>	componentHP_shields_max;
	std::vector<int>	componentHP_weapons_max;
	std::vector<int>	componentHP_engines_max;
	std::vector<int>	componentHP_sensors_max;
	std::vector<int>	componentHP_crew_max; //crew quarters always 0. No need to simulate seperate crew quarters aside from VIP suites
	std::vector<int>	componentHP_support_max;

	int					hull_hp_max[5]; //center 0, starboard 1, port 2, forward 3, aft 4. if you lose two out of three sections the ship is destroyed
	int					shield_hp_max[5]; //center 0, starboard 1, port 2, forward 3, aft 4

	float				ablative_threshold //represents the amount of armor. percent of hull remaining at which point component damage becomes possible. check if (double)hull_hp[x] >= ablative_threshold * hull_hp_max[x];
	unsigned int		componentREF_armor; //unused for the moment, pending decision on how I want armor to work. Sots2 damage grid would be cool. As would a crit slot system.

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
	
	//if anybodies game breaks because they've reached UINT_MAX components I will personally refactor the entire codebase to change it to longs.
	std::vector<unsigned int>	componentREF_shields;
	std::vector<unsigned int>	componentREF_weapons;
	std::vector<unsigned int>	componentREF_engines;
	std::vector<unsigned int>	componentREF_sensors;
	std::vector<unsigned int>	componentREF_crew;
	std::vector<unsigned int>	componentREF_support;
	
	unsigned int				hull_model; //this is an index in the global ship_class array that represents the original model. For variants and refits this would be the base class, i.e. a T72-B1 would have T-72 for this
	/*	std::vector<Character*>		characterREF;
		std::vector<Culture*>		crew_cultureREF;
		std::vector<float>			crew_culturePER // percentage of the crew for each culture
	future stuff */
	//ship status is denoted by which array it is in i.e. status_array_refit. status is changed by switching arrays. This saves memory.
	
//not sure what functions needed yet beyond a bunch of stuff to check things and set things.
	Ship_Class_Base	*ship_class; //use this to populate our design, can be changed to accomodate for refits.
private:
	
}


#endif // !1

