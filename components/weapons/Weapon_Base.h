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
	
protected:
	//range
	unsigned int	range_band[4]; //defines the end of each range band 0 min range, 1 point blank, 2, mid, 3 max range
	bool			range_effectiveness_modified_by_base; //denotes whether this is modified by a components base effectiveness. will default to true if not assigned.
	double			range_effectiveness_min; //used if modified by base is false
	double			range_effectiveness_max; //ditto
	
	//damage
	int				damage;
	bool			damage_effectveness_modified_by_base;
	double			damage_effectiveness_min;
	double			damage_effectivenss_max;
	
	//shots
	int				shots;
	bool			shot_effectiveness_modified_by_base;
	double			damage_effectiveness_min;
	double			damage_effectiveness_max;
	
private:
}

Weapon_Base::Weapon_Base()
{
	
}

Weapon_Base::~Weapon_Base()
{
	
}

#endif