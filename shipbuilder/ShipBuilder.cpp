void				all_weapon_specialization(Ship_Class_Base *ship, unsigned int available_tonnage)
{
	std::random_device	r;
	std::mt19937		mer(r());
	std::uniform_int_distribution<>	weapon_range(1, g_componentsWeapons.size() - 1);
	while (available_tonnage)
	{
		weapon = g__componentsWeapons[weapon_range(mer)]
		if (weapon->get_tonnage() <= available_tonnage && weapon->get_manufacturer() != 0)
		{
			available_tonnage -= weapon->get_tonnage();
			ship->add_component(weapon);
		}
		if (available_tonnage < g_minVal_tonnageWeapon)
			break ;
	}
}

Ship_Class_Base*		ShipBuilder::Ship_Builder(unsigned int specs, unsigned int max_tonnage)
{
	Ship_Class_Base	*new_ship = new Ship_Class_Base;
	unsigned int	tonnage_per_spec = max_tonnage / specs;
	
	//this is temporary obviously and isn't really how the final design will work at all.
	for (int i = 0; i < specs)
	{
		int		r = 1;
		switch(r)
		{
			case 1:	all_weapon_specialization(new_ship, max_tonnage);
					break ; //all weapons
		}
	}
	return (new_ship);
}