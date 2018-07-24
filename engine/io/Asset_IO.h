#include "Component_Base.h"
#include <iostream>
#include <fstream>

class Asset_IO
{
	public:
		static Component_Base	read_component(std::ifstream file);
	protected:
		static std::string		attributesComponents[] = 
		{
			"name", "effectiveness_min", "effectiveness_max", "base_build_cost",
			"buildCostFactor_min", "buildCostFactor_max", "base_buy_cost", "buyCostFactor_min",
			"buyCostFactor_max", "max_hp", "hp_mod", "effectiveness_hp_min", "effectiveness_hp_max",
			"tonnage", "tonnage_mod", "effectiveness_tonnage_min", "effectiveness_tonnage_max",
			"descr"
		};
		static std::string		attributesWeapons[] =
		{
			"range_band", "range_band_mod", "effectiveness_range_min", "effectiveness_range_max",
			"accuracy", "accuracy_mod", "effectiveness_accuracy_min", "effectiveness_accuracy_max",
			"damage", "damage_mod", "effectiveness_damage_min", "effectiveness_damage_max",
			"fire_rate", "fire_rate_mod", "effectiveness_fire_rate_min", "effectiveness_fire_rate_max",
			"armor_pen", "armor_pen_mod", "effectiveness_armor_pen_min", "effectiveness_armor_pen_max",
			"allowed_mountings"
		};
	private:
}