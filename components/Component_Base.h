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
	
	float			base_effectiveness; //the key to our little game, this will be randomized. 1.5 means 50% more effective
	float			effectiveness;
	float			effectiveness_min;
	float			effectiveness_max;
	unsigned long	base_build_cost; //how much production does it take
	float			build_cost_factor;
	float			build_cost_factor_min;
	float			build_cost_factor_max;
	unsigned long	base_buy_cost;	//how many space ducats does it cost. Real cost will include labor charges as well.
	float			buy_cost_factor;
	float			buy_cost_factor_min;
	float			buy_cost_factor_max;
	unsigned int	id; //this is important. its the order in which its stored in the global component array and the key used to access it.
	unsigned int	manufacturer_id; //who made it.
	std::string		descr; //description.
	
	//hp ; see weapon_base class for documentation on attributes
	int				max_hp;
	bool			hp_effectiveness_modified_by_base = true;
	//float			hp_effectiveness_min;
	//float			hp_effectiveness_max;
	float			hp_effectiveness;
	
private:
}

Component_Base::Component_Base()
{
	
}

Component_Base::~Component_Base()
{
	
}

int				Component_Base::get_hp(void)
{
	if (this->hp_effectiveness_modified_by_base)
		return ((this->hp_effectiveness + this->base_effectivenss / 2.0) * this->max_hp);
	return (this->hp_effectiveness * this->max_hp);
}

#endif