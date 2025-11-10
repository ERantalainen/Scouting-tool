#include "Team.hpp"

#include <chrono>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <algorithm>

Team::Team()
{
	_name = "empty";
	auto time = chrono::system_clock::now();
	_created = chrono::system_clock::to_time_t(time);
	_updated = _created;
	_save = "test";

	ofstream team_file(_save);
	if (!team_file.is_open())
		std::cerr << "Could not open team file: " << _save << "\n";
	else
		team_file.close();

}

Team::Team(string name) : _name(name), _save(name)
{
	std::cout << BYELLOW << "created team: " << _name << "\n" << RESET;
	auto time = chrono::system_clock::now();
	_created = chrono::system_clock::to_time_t(time);
	_updated = _created;
	ofstream team_file(_save);
	if (!team_file.is_open())
		std::cerr << "Could not open team file: " << _save << "\n";
	else
		team_file.close();
}

Team::~Team()
{
}

void	Team::getStats()
{
	_hero = DVA;
}

void	Team::resetStats()
{
	_teamComps.clear();
}

void	Team::getHeroes()
{
	for (size_t i = 0; i < _heroes.size(); i++)
	{
		std::cout << WHITE << "	" << _heroes[i] << RESET << "\n";
	}
}

void	Team::deleteTeam()
{

}

string	Team::getName() const
{
	return _name;
}

string	Team::getSaveName() const
{
	return _save;
}

time_t	Team::getCreated() const
{
	return _created;
}

time_t	Team::getUpdated() const
{
	return _updated;
}

void	Team::updateTime()
{
	auto time = chrono::system_clock::now();
	_updated = chrono::system_clock::to_time_t(time);
}

void	Team::newTeam()
{
	string	input;
	size_t	index;
	newComp();
	for (int j = 0; j < 5; j++)
	{
		cout <<"\n";
		printComp(_comps - 1);
		cout << "\n";
		getHeroes();
		while (1)
		{
			std::cout << HIYELLOW << "\nChoose HERO to add: " << RESET;
			std::cin >> input;
			if (input.empty())
				return ;
			std::transform(input.begin(), input.end(), input.begin(), ::toupper);
			auto it = find(_heroes.begin(), _heroes.end(), input);
			if (it == _heroes.end())
				std::cout << BRED << input << " is not a valid hero\n" << RESET;
			else
			{
				index = distance(_heroes.begin(), it);
				break ;
			}
		}
		if (index < 13)
		{
			_teamComps[_comps - 1]["TANK"] = input;
		}
		else if (index > 12 && index < 32)
		{
			if (_dps == false)
			{
				_teamComps[_comps - 1]["DPS1"] = input;
				_dps = true;
			}
			else
			{
				_teamComps[_comps - 1]["DPS2"] = input;
				_dps = false;
			}
		}
		else
		{
			if (_supp == false)
			{
				_teamComps[_comps - 1]["SUPP1"] = input;
				_supp = true;
			}
			else
			{
				_teamComps[_comps - 1]["SUPP2"] = input;
				_supp = false;
			}
		}
		cout << "\033c";
		cout.flush();
	}
}

vector<map<string, string>>	Team::getComps() const
{
	return _teamComps;
}

void	Team::newComp()
{
	_teamComps.resize(_comps + 1);
	_teamComps[_comps].emplace("TANK", "EMPTY");
	_teamComps[_comps].emplace("DPS1", "EMPTY");
	_teamComps[_comps].emplace("DPS2", "EMPTY");
	_teamComps[_comps].emplace("SUPP1", "EMPTY");
	_teamComps[_comps].emplace("SUPP2", "EMPTY");
	_comps++;
}

void	Team::printComp(size_t i)
{
	cout << BGREEN << "	TANK: " << RESET << HIGREEN << _teamComps[i]["TANK"] << RESET << "\n";
	cout << BBLUE << "	DPS: " << RESET << HIBLUE << _teamComps[i]["DPS1"] << "\n" << RESET;
	cout << BBLUE << "	DPS: " << RESET << HIBLUE << _teamComps[i]["DPS2"] << "\n" << RESET;
	cout << BPURPLE << "	SUPP: " << RESET << HIPURPLE << _teamComps[i]["SUPP1"] << "\n" << RESET;
	cout << BPURPLE << "	SUPP: " << RESET << HIPURPLE << _teamComps[i]["SUPP2"] << "\n" << RESET;
}

void	Team::addHeroes(size_t i)
{
	size_t	index;
	updateTime();
	if (i >= _comps)
		newComp();
	string	input;
	std::cout << HIGREEN << "Adding heroes to: " << getName() << "\nCurrent comp: \n";
	printComp(i);
	std::cout << HIWHITE << "Input heroes: \n" << RESET;
	for (size_t i = 0; i < _heroes.size(); i++)
	{
		std::cout << WHITE << "	" << _heroes[i] << RESET << "\n";
	}
	std::cout << HIYELLOW << "\nChoose HERO to add: " << RESET;
	while (1)
	{
		std::cin >> input;
		if (input.empty())
			return ;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		auto it = find(_heroes.begin(), _heroes.end(), input);
		if (it == _heroes.end())
			std::cout << BRED << input << " is not a valid hero\n" << RESET;
		else
		{
			index = distance(_heroes.begin(), it);
			break ;
		}
	}
	if (index < 13)
	{
		_teamComps[i]["TANK"] = input;
	}
	else if (index > 12 && index < 32)
	{
		if (_dps == false)
		{
			_teamComps[i]["DPS1"] = input;
			_dps = true;
		}
		else
		{
			_teamComps[i]["DPS2"] = input;
			_dps = false;
		}
	}
	else
	{
		if (_supp == false)
		{
			_teamComps[i]["SUPP1"] = input;
			_supp = true;
		}
		else
		{
			_teamComps[i]["SUPP2"] = input;
			_supp = false;
		}
	}
	cout << "\033c";
	cout.flush();

}

std::ostream & operator<<(std::ostream &stream, const Team &object)
{
	string	created;
	string	updated;
	time_t	stamp;
	vector<map<string, string>>	comps = object.getComps();

	stamp = object.getCreated();
	created = ctime(&stamp);
	stamp = object.getUpdated();
	updated = ctime(&stamp);
	stream << BWHITE << object.getName() << "\nCreated: " << created <<  "Updated: " << updated << "\n" << RESET;
	stream << BCYAN << "Team Comps:\n" << RESET;
	for (size_t i = 0; i < comps.size(); i++)
	{
		stream << BWHITE << "Composition: " << i + 1 << "\n";
		stream << HIGREEN << "	TANK: " << comps[i]["TANK"] << RESET << "\n";
		stream << HIBLUE << "	DPS: " << comps[i]["DPS1"] << "\n";
		stream << "	DPS: " << comps[i]["DPS2"] << "\n" << RESET;
		stream << HIPURPLE << "	SUPP: " << comps[i]["SUPP1"] << "\n";
		stream << "	SUPP: " << comps[i]["SUPP2"] << "\n" << RESET;
	}
	return stream;
}
