#pragma once
#ifndef SHIP_BASE_HPP
# define SHIP_BASE_HPP

#include <vector>
#include Ship_Class_Base.hpp

class Ship_Base
{
public:
	Ship_Base();
	~Ship_Base();
	Ship_Class_Base	*ship_class;

private:
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
	std::vector<int>	componentHP_support; //misc stuff like science labs, cargo holds, EWar suites, etc...

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

//not sure what functions needed yet beyond a bunch of stuff to check things and set things.
Ship_Base::Ship_Base()
{
}

Ship_Base::~Ship_Base()
{
}
#endif // !1

