class Ship_Class_Base
{
public:
	Ship_Class_Base();
	~Ship_Class_Base();
	
	std::vector<unsigned int>	get_shields();
	std::vector<unsigned int>	get_weapons();
	std::vector<unsigned int>	get_engines();
	std::vector<unsigned int>	get_sensors();
	std::vector<unsigned int>	get_crew();
	std::vector<unsigned int>	get_support();
	
	unsigned int				tonnage_used();
protected:
	String						class_name;
	unsigned int				id;
	unsigned int				hull_model; //this is an index in the global ship_class array that represents the original model. For variants and refits this would be the base class, i.e. a T72-B1 would have T-72 for this or a Bradley Linebacker have Bradley IFV
	std::vector<unsigned int>	componentREF_shields;
	std::vector<unsigned int>	componentREF_weapons;
	std::vector<unsigned int>	componentREF_engines;
	std::vector<unsigned int>	componentREF_sensors;
	std::vector<unsigned int>	componentREF_crew;
	std::vector<unsigned int>	componentREF_support;
	
	int							hull_hp_max[5]; //center 0, starboard 1, port 2, forward 3, aft 4
	//int							shield_hp_max[5]; we can calculate this in Ship_Base
	
	unsigned int				tonnage; //each section of the ship gets 1/5th the tonnage to use. Dreadnaught moment techs can change this. The ratio of external to internal tonnage depends on tech
	
	//ai stuff
	//role
private:
}

Ship_Class_Base::Ship_Class_Base()
{
	
}

Ship_Class_Base::~Ship_Class_Base()
{
	
}

Ship_Class_Base::std::vector<unsigned int>	get_shields()
{
	return (this->componentREF_shields);
}

Ship_Class_Base::std::vector<unsigned int>	get_weapons()
{
	return (this->componentREF_weapons);
}

Ship_Class_Base::std::vector<unsigned int>	get_engines()
{
	return (this->componentREF_engines);
}

Ship_Class_Base::std::vector<unsigned int>	get_sensors()
{
	return (this->componentREF_sensors);
}

Ship_Class_Base::std::vector<unsigned int>	get_crew()
{
	return (this->componentREF_crew);
}

Ship_Class_Base::std::vector<unsigned int>	get_support()
{
	return (this->componentREF_support);
}

Ship_Class_Base::unsigned int	tonnage_used()
{
	
}