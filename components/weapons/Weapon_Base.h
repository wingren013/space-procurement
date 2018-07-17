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
	
	unsigned int	*get_range();
	float			*get_accuracy();
	int				get_damage();
	float			get_fire_rate();
protected:
	//getter functions will modify the attribute by effectiveness.
	//range
	unsigned int	range_band[4]; //defines the end of each range band 0 min range, 1 point blank, 2, mid, 3 max range
	bool			range_effectiveness_modified_by_base = true; //denotes whether this is modified by a components base effectiveness. will default to true if not assigned.
	//float			range_effectiveness_min; //used to introduce some variability. Found only in the text file defining the weapon. Included here for structural purposes
	//float			range_effectiveness_max; //ditto
	float			range_effectiveness; //the randomized effectiveness of this stat. if using base effectiveness then take the median of the two. The AI needs to look at this which is why weapon designs don't have a seperate class
	
	//accuracy
	float			accuracy_at_range[4]; //accuracy at corresponding range band;
	bool			accuracy_effectiveness_modified_by_base = true;
	//float			accuracy_effectiveness_min;
	//float			accuracy_effectiveness_max;
	float			accuracy_effectiveness;
	
	//damage
	int				damage;
	bool			damage_effectveness_modified_by_base;
	//float			damage_effectiveness_min;
	//float			damage_effectivenss_max;
	float			damage_effectiveness;
	
	//shots
	float			fire_rate; // 1 means 1 shot per turn. 0.5 means 2 shots per turn. 1.2 means ne shot a turn skipping the a turn every first of five, etc...
	bool			fire_rate_effectiveness_modified_by_base = true;
	//float			fire_rate_effectiveness_min;
	//float			fire_rate_effectiveness_max;
	float			fire_rate_effectiveness;
	
	//ammo consumption
	/*int			ammo_use;
	bool			ammo_use_effectiveness_modified_by_base = true;
	float			ammo_use_effectiveness_min;
	float			ammo_use_effectiveness_max;*/
	
	//ammo type
	
	//shield pen
	float			shield_pen; //0 shield pen means 100% pen. 0.5 means 50% pen. effects of pen defined by shields. real shield pen is (1 - shield_pen + shield_mitigation)
	bool			shield_pen_effectiveness_modified_by_base = true;
	//float			shield_pen_effectiveness_min;
	//float			shield_pen_effectiveness_max;
	float			shield_pen effectiveness;
	
	//armor pen
	float			armor_pen; // multiply ablative threshold by (1 - armor_pen + armor_mitigation). simpler than shield pen
	bool			armor_pen_effectiveness_modified_by_base = true;
	//float			armor_pen_effectiveness_min;
	//float			armor_pen_effectiveness_max;
	float			armor_pen_effectiveness;
	
	//shield damage bonus
	
	//armor damage bonus
	
	//hull damage bonus
	
	//turret cost factor
	
	char			allowed_mountings // bitmask. 1 for internal fixed, 2 for external fixed, 4 for turreted. 8 for silo. fixed mounts have a 45 degree angle. Turrets have a 90 degree angle. Silos are for launched weapons and can be fit in the center section unlike other weapons
	
private:
}

Weapon_Base::Weapon_Base()
{
	
}

Weapon_Base::~Weapon_Base()
{
	
}

int				Component_Base::get_damage(void)
{
	if (this->damage_effectiveness_modified_by_base)
		return ((this->damage_effectiveness + this->base_effectivenss / 2.0) * this->damage);
	return (this->damage_effectiveness * this->damage);
}

#endif