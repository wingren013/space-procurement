#ifndef Weapon_Base
# define Weapon_Base

#include Component_Base.h

class	Weapon_Base : public Component_Base()
{
/* this class acts as the codifier for our weapons. 
Individual base weapons i.e. plasma guns, missile launchers, etc... will be defined in text files 
and loaded into the program as one of these. Components based on these i.e. Raytheon Fusion Gun
will also be instaces of this class */
public:
	Weapon_Base();
	~Weapon_Base();
	
	unsigned int	get_range();
	float			get_accuracy();
	int				get_damage();
	float			get_fire_rate();
protected:
	//getter functions will modify the attribute by effectiveness.
	//range
	unsigned int	range_band[4]; //defines the end of each range band 0 min range, 1 point blank, 2, mid, 3 max range
	bool			effectivenessModifiedByBase_range = true; //denotes whether this is modified by a components base effectiveness. will default to true if not assigned.
	//float			range_effectiveness_min; //used to introduce some variability. Found only in the text file defining the weapon. Included here for structural purposes
	//float			range_effectiveness_max; //ditto
	float			effectiveness_range; //the randomized effectiveness of this stat. if using base effectiveness then take the median of the two. The AI needs to look at this which is why weapon designs don't have a seperate class
	
	//accuracy
	float			accuracy[4]; //accuracy at corresponding range band;
	bool			effectivenessModifiedByBase_accuracy = true;
	//float			accuracy_effectiveness_min;
	//float			accuracy_effectiveness_max;
	float			effectiveness_accuracy;
	
	//damage
	int				damage[4]; //damage corresponding to range band
	bool			effectivenessModifiedByBase_ = true;
	//float			damage_effectiveness_min;
	//float			damage_effectivenss_max;
	float			effectiveness_damage;
	
	//shots
	float			fire_rate = 1.0; // 1 means 1 shot per turn. 0.5 means 2 shots per turn. 1.2 means ne shot a turn skipping the a turn every first of five, etc...
	bool			effectivenessModifiedByBase_fire_rate = true;
	//float			fire_rate_effectiveness_min;
	//float			fire_rate_effectiveness_max;
	float			effectiveness_fire_rate;
	
	//ammo consumption
	/*int			ammo_use;
	bool			ammo_use_effectiveness_modified_by_base = true;
	float			ammo_use_effectiveness_min;
	float			ammo_use_effectiveness_max;*/
	
	//ammo type
	
	//shield pen
	float			shield_pen; //0 shield pen means 100% pen. 0.5 means 50% pen. effects of pen defined by shields. real shield pen is (1 - shield_pen + shield_mitigation)
	bool			effectivenessModifiedByBase_shield_pen = true;
	//float			shield_pen_effectiveness_min;
	//float			shield_pen_effectiveness_max;
	float			effectiveness_shield_pen;
	
	//armor pen
	float			armor_pen; // multiply ablative threshold by (1 - armor_pen + armor_mitigation). simpler than shield pen
	bool			effectivenessModifiedByBase_armor_pen = true;
	//float			armor_pen_effectiveness_min;
	//float			armor_pen_effectiveness_max;
	float			effectiveness_armor_pen;
	
	//shield damage bonus
	
	//armor damage bonus
	
	//hull damage bonus
	
	/*
	So turrets should be their own thing. Basically a weapon that holds another weapon with its own armor. I'll decide how that should work in a future version
	//turret buy cost factor
	float			buyCostFactor_turret = 2.0; //multiply cost by this if its a turret. Defaults to double
	bool			effectivenessModifiedByBase_buyCostFactor_turret = true;
	//float			turret_cost_factor_effectiveness_min;
	//float			turret_cost_factor_effectiveness_max;
	float			effectiveness_buyCostFactor_turret;
	
	//turret build cost factor
	float			buildCostFactor_turret = 2.0; //multiply cost by this if its a turret. Defaults to double
	bool			effectivenessModifiedByBase_buildCostFactor_turret = true;
	//float			turret_cost_factor_effectiveness_min;
	//float			turret_cost_factor_effectiveness_max;
	float			effectiveness_buildCostFactor_turret;
	
	float			tonnageFactor_turret = 2.0; //multiply tonnage by this if a turret. Defaults to double.
	*/
	char			allowed_mountings // bitmask. 1 for internal fixed, 2 for external fixed, 4 for turreted. 8 for silo. fixed mounts have a 45 degree angle. Turrets have a 90 degree angle. Silos are for launched weapons and can be fit in the center section unlike other weapons
	
private:
}

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

#endif