#ifndef Component_Base
# define Component_Base

#include <string>

class Component_Base
{
	//pretty simple class. just serves to group all our components under one roof.
public:
	Component_Base();
	~Component_Base();
	
	int				get_hp();
	
protected:
	std::string		name;
	
	float			base_effectiveness; //the key to our little game, this will be randomized. 1.5 means 50% more effective
	float			effectiveness;
	//float			effectiveness_min;
	//float			effectiveness_max;
	unsigned long	base_build_cost; //how much production does it take
	float			buildCostFactor_base;
	//float			buildCostFactor_min;
	//float			buildCostFactor_max;
	unsigned long	base_buy_cost;	//how many space ducats does it cost. Real cost will include labor charges as well.
	float			buyCostFactor_base;
	//float			buyCostFactor_min;
	//float			buyCostFactor_max;
	
	//hp ; see weapon_base class for documentation on attributes
	int				max_hp;
	bool			effectivenessModifiedByBase_hp = true;
	//float			hp_effectiveness_min;
	//float			hp_effectiveness_max;
	float			effectiveness_hp;
	
	unsigned int	tonnage; //the space used.
	bool			effectivenessModifiedByBase_tonnage = true;
	//float			effectiveness_tonnage_min;
	//float			effectiveness_tonnage_max;
	float			effectiveness_tonnage;
	
	unsigned int	id; //this is important. its the order in which its stored in the global component array and the key used to access it.
	unsigned int	manufacturer_id; //who made it.
	std::string		descr; //description.
	
private:
}

#endif