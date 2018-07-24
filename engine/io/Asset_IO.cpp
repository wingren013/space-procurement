#include "Asset_IO.h"

//for weapons
void			read_to_component(std::string str, Weapon_Base component)
{
	
}

//for shields
/*void			read_to_component(std::string str, Shield_Base component)
{
	
}*/

void			Asset_IO::read_component(std::ifstream file)
{
	//this is hacky but it just needs to work for now
	std::string	line;
	std::string	read;
	if (!file.is_open)
	{
		while (!file.eof)
		{
			getline(file, line);
			if (line[0] == '#')
			{
				read = "";
				for (size_t i = 1; line[i] != ' ' || line[i] != ';'; i++)
				{
					read += line[i];
				}
				if (read == "weapon")
				{
					Weapon_Base	*weapon = new Weapon_Base
					g_components_weapons.push_back(weapon);
					weapon->set_id(g_components_weapons.size() - 1)
					while (!file.eof)
					{
						getline(file, line);
						if (line[0] == '#')
						{
							read.clear();
							for (size_t i = 1; line[i] != '\n' || line[i] != ';'; i++)
							{
								read += line[i];
							}
							read_to_component(line, weapon);
						}
					}
					file.close();
					return ;
				}
				else
				{
					//error message
					file.close();
					return ;
				}
			}
		}
	}
}