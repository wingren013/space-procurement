Component_Base*		ComponentBuilder::Component_Builder(Component_Base template_component)
{
	Component_Base	*new_component = new Component_Base;
	
	return (new_component);
}

//	in maufactuer:
//array_of_techs_this_has_access_to[i]->Component_Builder(this);
Weapon_Base*			WeaponBuilder::Component_Builder(Weapon_Base *template_component)
{
	Weapon_Base		*new_weapon = new Weapon_Base(g_componentsWeapons[0], id_manufacturer);
	float			tonnage_factor = GenMeth::random_float_in_range(0.75, 1.5); //move this out of asset_io

	//for now all this does is just make weapons that scale with size. For the future modifiers like heavy (slower firing better punch), or high-tech (improved all over but expensive), or fragile (less hp and a bit cheaper and lighter)
	//also weapons should be modified by manufacturer's techs but since manufacturers aren't implemented yet that can't be done.
	new_weapon->multiply_all_costs(tonnage_factor);
	new_weapon->multiply_all_attributes(tonnage_factor);
	//new_weapon.descr += "made by " += g_manufacturers[manufacturer_id]->name();
	return (new_weapon);
}