#ifndef Component_Base
# define Component_Base

class Component_Base
{
	//pretty simple class. just serves to group all our components under one roof.
	public:
	
	protected:
	
	double			base_effectiveness; //the key to our little game, this will be randomized.
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