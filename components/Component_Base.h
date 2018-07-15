#ifndef Component_Base
# define Component_Base

class Component_Base
{
	//pretty simple class. just serves to group all our components under one roof.
public:
	Component_Base();
	~Component_Base();
	
protected:
	
	double			base_effectiveness; //the key to our little game, this will be randomized. 1.5 means 50% more effective
	double			effectiveness_min;
	double			effectiveness_max;
	double			base_build_cost; //how much production does it take
	double			build_cost_factor_min;
	double			build_cost_factor_max;
	double			base_buy_cost;	//how many space ducats does it cost. Space florins not supported currency due to ongoing market fluctuations. Real cost will include labor charges as well.
	double			buy_cost_factor_min;
	double			buy_cost_factor_max;
	unsigned int	id; //this is important. its the order in which its stored in the global component array and the key used to access it.
	
private:
}

Component_Base::Component_Base()
{
	
}

Component_Base::~Component_Base()
{
	
}

#endif