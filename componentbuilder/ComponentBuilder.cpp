Component_Base*		ComponentBuilder::Component_Builder(Component_Base template)
{
	Component_Base	new_component = new Component_Base;
	
	return (new_component);
}

Weapon_Base*		CommponentBuilder::Component_Builder(unsigned int template_id, unsigned int manufacturer_id, unsigned int type)
{
	Weapon_Base		*new_weapon = new Weapon_Base(g_components[template_id], manufacturer_id);
	float			tonnage_factor = Asset_IO::random_float_in_range(0.75, 1.5); //move this out of asset_io
	
	new_weapon->multiply_all_costs(tonnage_factor);
	new_weapon->multiply_all_attributes(tonnage_factor);
	//new_weapon.descr += "made by " += g_manufacturers[manufacturer_id]->name();
	return (new_component);
}