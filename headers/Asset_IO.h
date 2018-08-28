#ifndef ASSET_IO_H
# define ASSET_IO_H

#include "Component_Base.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <cstdio>
#include <cstdlib>

class Asset_IO
{
	public:
		static Component_Base	read_component(std::ifstream file);
	protected:
		static std::string		attributesComponents[] = 
		{
			"name", "effectiveness", "base_build_cost",
			"buildCostFactor", "base_buy_cost", "buyCostFactor",
			"max_hp", "hp_mod", "effectiveness_hp", "tonnage", "tonnage_mod",
			"effectiveness_tonnage", "descr", 0
		};
		static std::string		attributesWeapons[] =
		{
			"range_band", "range_band_mod", "effectiveness_range",
			"accuracy", "accuracy_mod", "effectiveness_accuracy",
			"damage", "damage_mod", "effectiveness_damage",
			"fire_rate", "fire_rate_mod", "effectiveness_fire_rate",
			"armor_pen", "armor_pen_mod", "effectiveness_armor_pen",
			"allowed_mountings", 0
		};
	private:
};

#endif
