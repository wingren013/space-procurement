#include "Asset_IO.h"

float						random_float_in_range(float a, float b)
{
	float r = (float)rand() / (float)RAND_MAX
	r *= b - a;
	return (a + r);
}

std::queue<std::string>		*split_input(std::string read)
{
	std::queue<std::string> *split_input = new std::queue<std::string>;
	bool open_paren = false;
	std::string	buf;
	//i've never done IO on windows but I remember something about EOF being different so might as well check
	for (int i = 0; read[i] != '\n' && read[i] != ';' && read != EOF; i++)
	{
		if (read[i] == '"')
		{
			if (open_paren == true)
			{
				split_input->push(buf);
				open_paren = false;
				buf.clear();
			}
			else
			{
				open_paren = true;
			}
		}
		else if (read[i] == ' ' && open_paren != true)
		{
			split_input->push(buf);
			buf.clear();
		}
		else
		{
			buf.push_back(read[i]);
		}
	}
	//catch things at the end
	split_input->push(buf);
	return (split_input);
}

void			handle_component_token(std::string token, std::queue<std::string> *value_input, Component_Base *component)
{
	//I hate this giant switch I should figure out a good way to use regex here.
	if (token == "name")
		component->setname(value_input->pop());
	else if (token == "effectiveness")
		component->set_base_effectiveness = random_float_in_range(strtof(value_input->pop()), strtof(value_input->pop()));
	else if (token == "base_build_cost")
		component->set_build_cost(stoi(value_input->pop()));
	else if (token == "buildCostFactor")
		component->set_buildCostFactor(random_float_in_range(strtof(value_input->pop()), strtof(value_input->pop())));
	else if (token == "base_buy_cost")
		component->set_buy_cost(stoi(value_input->pop()));
	else if (token = "buyCostFactor")
		component->set_buyCostFactor(random_float_in_range(strtof(value_input->pop()), strtof(value_input->pop())));
	else if (token = "max_hp")
		component->set_max_hp(stoi(value_input->pop()));
	else if (token == "effectiveness_hp")
		component->set_effectiveness_hp(random_float_in_range(strtof(value_input->pop()), strtof(value_input->pop)));
	else if (token == "tonnage")
		component->set_tonnage(stoi(value_input->pop()));
	else if (token == "effectiveness_tonnage")
		component->set_effectiveness_tonnage(random_float_in_range(strtof(value_input->pop(), strtof(value_input->pop()))));

void			handle_weapon_token(std::string token, std::queue<string> *value_input, Weapon_Base *component)
{
	
}

//for weapons
void			read_to_component(std::string read, Weapon_Base *component)
{
			//this doesn't need to be a pointer but I'm too lazy to change it and it doesn't break anything
			std::queue<string>	*split_input = split_input(read);
			std::string			token;
			
			token = split_input->pop();
			for (int i = 0; Component_Base.attributesComponents[i] != 0; i++)
			{
				if (token == Component_Base.attributesComponents[i])
				{
					handle_component_token(token, split_input, component);
					delete split_input;
					return ;
				}
			}
			for (int i = 0; Component_Base.attributesWeapons[i] != 0; i++)
			{
				if (token == Component_Base.attributesWeapons[i])
				{
					handle_weapon_token(token, split_input, component);
					delete split_input;
					return ;
				}
			}
			delete split_input;
}

//for shields
/*void			read_to_component(std::string str, Shield_Base component)
{
	
}*/

void			Asset_IO::read_component(std::ifstream file)
{
	//this is hacky but it just needs to work for now
	//just realised everything is case sensitive. Should be an easy fix to just convert lines we read to lower case
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
				for (size_t i = 1; line[i] != ' ' && line[i] != ';' && line[i] != '\n' && line[i] != EOF; i++)
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
							for (size_t i = 1; line[i] != '\n' && line[i] != ';' && line[i] != EOF; i++)
							{
								read += line[i];
							}
							read_to_component(read, weapon);
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
