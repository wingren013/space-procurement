#ifndef MANUFACTURER_BASE_H_
# define MANUFACTURER_BASE_H_

#include <string>
#include <vector>
#include "Component_Base.h"
#include <bits/random.h> //this is <random> , blame eclipse

class Manufacturer_Base {
public:
	Manufacturer_Base();
	virtual ~Manufacturer_Base();

	void	new_component();
	void	new_shield();
	void	new_weapon();
	void	new_engine();
	void	new_sensor();
	void	new_crew();
	void	new_support();
	void	new_ship();
protected:
	std::vector<unsigned int>	manufactured_components[6]; //0 for shields, 1 for weapons, 2 engines, 3 sensors, 4 for crew, 5 support
	std::vector<unsigned int>	ships_manufactured;

	std::vector<unsigned int>	manufacturer_tech[6]; //so this takes a bit of explaining. Problem is that I'm not quite sure how it should work right now. Basically this is where the manufacturers capabilities in regards to techs are stored.

	unsigned int 				wealth; //manufacturers use this to buy shit like factories and pay for shit like research
};

#endif /* ECONOMY_MANUFACTURERS_MANUFACTURER_BASE_H_ */
