/*
 * ShieldBase.h
 *
 *  Created on: Aug 23, 2018
 *      Author: Sawyer
 */

#ifndef SHIELD_BASE_H
#define SHIELD_BASE_H

#include <Component_Base.h>

class Shield_Base: public Component_Base {
public:
	Shield_Base();
	virtual ~Shield_Base();

protected:
	//shields cover their section plus the adjacent sections. Example a starboard shield generator would cover forward, starboard, and rear. Center generators cover the whole ship. Damage is spread evenly between all shields in a section.
	unsigned int	shield_hp;
	bool			effectivenessModifiedByBase_shield_hp = true;
	float			effectiveness_shield;

	//shield coverage is hardcoded for now.
	//unsigned int	coverage; //1 for covering the side that is equipped, 2 for covering that side plus adjacent sides, 4 for covering the whole ship

	unsigned int	equalization_rate; //rate at which the shield can transfer damage to connected shields. Only shields with an equalization_rate over 0 are a valid target for this
	bool			effectivenessModifiedByBase_equalization_rate = true;
	float			effectiveness_equalization_rate;

	float			shield_mitigation;
	bool			effectivenessModifiedByBase_shield_mitigation = true;
	float			effectiveness_shield_mitigation;
	unsigned int	mitigaion_mode; //bitmask : 1 for leaky shields (percentage of damage equal to pen goes through shields), 2 for damage bonus equal to pen, 4 for damage reduction equal to mitigation (so negative pen); defined in weapon file

};

#endif /* SOURCE_COMPONENTS_SHIELDS_SHIELDBASE_H_ */
