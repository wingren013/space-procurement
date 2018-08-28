//build ships out of multiple specializations. i.e. the AI is designing a ship. It chooses the defense specialization then the defense specialization again and finally the speed specialization. This would result in a well defended ship with light armarment and above average speed.
#ifndef SHIPBUILDER_H
# define SHIPBUILDER_H

#include "Component_Base.h"
#include "Weapon_Base.h"
#include "Ship_Class_Base.h"
#include <bits/random.h>

class	ShipBuilder
{
public:
	void	all_weapon_specialization(Ship_Class_Base *ship, unsigned int availaible_tonnage);
	Ship_Class_Base	*Ship_Builder(unsigned int specs, unsigned int tonnage);

};

#endif
