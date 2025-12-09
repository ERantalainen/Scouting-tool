#include "Team.hpp"



static	void	clearScreen()
{
	cout << "\033c";
	cout.flush();
}


void	Team::addComp(string heroes[6])
{
	string	role;

	this->newComp();
	for (size_t i = 0; i < 6; i++)
	{
		if (heroes[i].find(":") == string::npos)
		{
			std::cerr << HIRED << "Invalid/Corrupted save file\n" << RESET;
		}
		role = heroes[i].substr(0, heroes[i].find(":"));
		_teamComps[_comps - 1][role] = heroes[i].substr(heroes[i].find(":") + 1);
	}
    saveTeam();
}

Team::Team()
{
	ofstream	save;

	save.open(SAVEDATA, ios_base::app);
	if (!save.is_open())
	{
		std::cerr << HIRED << "Unable to open/create save file\n" << RESET;
	}
	_name = "empty";
	auto time = chrono::system_clock::now();
	_created = chrono::system_clock::to_time_t(time);
	_updated = _created;
	_save = "test";
	_heroCount.resize(_heroes.size());
	ofstream team_file(_save, ios_base::app);
	if (!team_file.is_open())
		std::cerr << "Could not open team file: " << _save << "\n";
	else
		team_file.close();
	for (size_t i = 0; i < _heroCount.size(); i++)
		_heroCount[i] = 0;
	save << _save << "\n";
	save.close();
}

Team::Team(string name) : _name(name)
{
	ifstream		save;
	ofstream		test;
	string		check;

    _save = "./data/" + _name + ".txt";
	filesystem::create_directory("./data");
	save.open(SAVEDATA);
	if (!save.is_open())
	{
        std::cerr << "Unable to open/create save file\n";
	}
    std::cout << "created team: " << _name << "\n";
	auto time = chrono::system_clock::now();
	_created = chrono::system_clock::to_time_t(time);
	_updated = _created;
	_heroCount.resize(_heroes.size());

	ofstream team_file(_save, ios_base::app);
	if (!team_file.is_open())
		std::cerr << "Could not open team file: " << _save << "\n";
	else
		team_file.close();
	for (size_t i = 0; i < _heroCount.size(); i++)
		_heroCount[i] = 0;
	while(getline(save, check))
	{
		if (check.compare(_save) == 0)
		{
			save.close();
			return ;
		}
	}
	save.close();
	test.open(SAVEDATA, ios_base::app);
	test << _save << "\n";
	test.close();
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
/*
	Predefined target order:
	MAP:
	TANK:
	DPS1:
	DPS2:
	SUPP1:
	SUPP2:
*/
void	Team::sortComp(int i)
{
    if (i < 0 || i > _teamComps.size())
        return ;
	auto itA = _teamComps[i].begin();
	if (itA->first != "MAP")
	{
		auto itB = _teamComps[i].find("MAP");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
	itA++;
	if (itA->first != "TANK")
	{
		auto itB = _teamComps[i].find("TANK");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
	itA++;
	if (itA->first != "DPS1")
	{
		auto itB = _teamComps[i].find("DPS1");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
	itA++;
	if (itA->first != "DPS2")
	{
		auto itB = _teamComps[i].find("DPS2");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
	itA++;
	if (itA->first != "SUPP1")
	{
		auto itB = _teamComps[i].find("SUPP1");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
	itA++;
	if (itA->first != "SUPP2")
	{
		auto itB = _teamComps[i].find("SUPP2");
		if (itB != _teamComps[i].end())
			std::swap(itA, itB);
	}
}

void	Team::newTeam()
{
	string	input;
	size_t	index;
	newComp();
	sortComp(_comps - 1);
	selectMap(_comps - 1);
	clearScreen();
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
		clearScreen();
	}
	clearScreen();
	saveTeam();
}

vector<map<string, string>>	Team::getComps() const
{
	return _teamComps;
}

void	Team::saveTeam()
{
	fstream	team(_save);

	if (!team.is_open())
	{
		std::cerr << HIRED << "Unable to open/create file: " << strerror(errno) << "\n";
		return ;
	}
	for (size_t i = 0; i < _teamComps.size(); i++)
	{
		auto it = _teamComps[i].begin();
		while (it != _teamComps[i].end())
		{
			team << it->first << ":" << it->second << "\n";
			it++;
		}
	}
	team.close();
}

void	Team::newComp()
{
	updateTime();
	_teamComps.resize(_comps + 1);
	_teamComps[_comps].emplace("TANK", "EMPTY");
	_teamComps[_comps].emplace("DPS1", "EMPTY");
	_teamComps[_comps].emplace("DPS2", "EMPTY");
	_teamComps[_comps].emplace("SUPP1", "EMPTY");
	_teamComps[_comps].emplace("SUPP2", "EMPTY");
	_teamComps[_comps].emplace("MAP", "EMPTY");
	sortComp(_comps);
	_comps++;
}

void	Team::printComp(size_t i)
{
	cout << HIWHITE << "	MAP: " << _teamComps[i]["MAP"] << RESET << "\n";
	cout << BGREEN << "	TANK: " << RESET << HIGREEN << _teamComps[i]["TANK"] << RESET << "\n";
	cout << BBLUE << "	DPS: " << RESET << HIBLUE << _teamComps[i]["DPS1"] << "\n" << RESET;
	cout << BBLUE << "	DPS: " << RESET << HIBLUE << _teamComps[i]["DPS2"] << "\n" << RESET;
	cout << BPURPLE << "	SUPP: " << RESET << HIPURPLE << _teamComps[i]["SUPP1"] << "\n" << RESET;
	cout << BPURPLE << "	SUPP: " << RESET << HIPURPLE << _teamComps[i]["SUPP2"] << "\n" << RESET;
}

string  Team::returnComp(size_t i)
{
    stringstream    res;

    res << "	MAP: " << _teamComps[i]["MAP"]  << "\n";
    res << "	TANK: " <<  _teamComps[i]["TANK"]  << "\n";
    res  << "	DPS: " <<  _teamComps[i]["DPS1"] << "\n" ;
    res  << "	DPS: " <<  _teamComps[i]["DPS2"] << "\n" ;
    res  << "	SUPP: " <<  _teamComps[i]["SUPP1"] << "\n";
    res  << "	SUPP: " <<  _teamComps[i]["SUPP2"] << "\n";

    return res.str();
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
	saveTeam();
	clearScreen();
}

void	Team::calcStats()
{
	int	index;
	for (size_t i = 0; i < _teamComps.size(); i++)
	{
		auto mit = _teamComps[i].begin();
			while (mit != _teamComps[i].end())
			{
				auto it = find(_heroes.begin(), _heroes.end(), mit->second);
				if (it != _heroes.end())
				{
					index = distance(_heroes.begin(), it);
					_heroCount[index]++;
				}
				mit++;
			}
	}
}

static	void	print_vector(vector<string>	vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << HIGREEN << i + 1 << ": " << vec[i] << "\n" << RESET;
	}
}

void	Team::selectMap(int i)
{
	string	input;
	int		index;

	print_vector(_maps);
	cout << HIYELLOW << "Select  a map: " << RESET;
	while (1)
	{
		std::cin >> input;
		if (input.empty())
			return ;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		auto it = find(_maps.begin(), _maps.end(), input);
		if (it == _maps.end())
			std::cout << BRED << input << " is not a valid map\n" << RESET;
		else
		{
			index = distance(_maps.begin(), it);
			break ;
		}
	}
	_teamComps[i]["MAP"] = _maps[index];
}

void	Team::printAllComps()
{
	vector<pair<double, int>>	mostCommon;
	calcStats();
	for (size_t i = 0; i < _teamComps.size(); i++)
	{
		printComp(i);
		std::cout << std::endl;
	}
	std::cout << HIGREEN << "Overall: " << RESET << "\n";
	double	percentage = 0;
	for (size_t i = 0; i < 13; i++)
	{
		if (_heroCount[i] == 0)
			continue ;
		std::cout <<  BCYAN << "	" << _heroes[i] << RESET << HICYAN " picked: " << _heroCount[i];
		percentage = ((static_cast<double>(_heroCount[i]) / static_cast<double>(_comps)) * 100);
		std::cout << " (" << setprecision(3) << percentage << "%)\n" << RESET;
		if (_heroCount[i] > _comps / 3)
			mostCommon.push_back(make_pair(percentage, i));
	}
	for (size_t i = 13; i < _heroes.size(); i++)
	{
		if (_heroCount[i] == 0)
			continue ;
		std::cout << BCYAN << "	" << _heroes[i] << RESET << HICYAN << " picked: " << _heroCount[i];
		percentage = ((static_cast<double>(_heroCount[i]) / (static_cast<double>(_comps))) * 100);
		std::cout << " (" << setprecision(3) << percentage << "%)\n" << RESET;
		if (_heroCount[i] > (_comps / 3))
			mostCommon.push_back(make_pair(percentage, i));
	}
	std::cout << HIGREEN << "Most common: \n" << RESET;
	sort(mostCommon.begin(), mostCommon.end());
	for (size_t i = 0; i < mostCommon.size(); i++)
	{
		std::cout << HIWHITE << setw(10) << _heroes[mostCommon[i].second] << " " << _heroCount[mostCommon[i].second] << " (" << mostCommon[i].first << "%)\n" << RESET;
	}
}

string  Team::retStats()
{
    vector<pair<double, int>>	mostCommon;
    stringstream                result;
    calcStats();
    for (size_t i = 0; i < _teamComps.size(); i++)
    {
        result << returnComp(i);
        result << "\n";
    }
    result << "Overall: " << "\n";
    double	percentage = 0;
    for (size_t i = 0; i < 13; i++)
    {
        if (_heroCount[i] == 0)
            continue ;
        result << "	" << _heroes[i] << " picked: " << _heroCount[i];
        percentage = ((static_cast<double>(_heroCount[i]) / static_cast<double>(_comps)) * 100);
        result << " (" << setprecision(3) << percentage << "%)\n";
        if (_heroCount[i] > _comps / 3)
            mostCommon.push_back(make_pair(percentage, i));
    }
    for (size_t i = 13; i < _heroes.size(); i++)
    {
        if (_heroCount[i] == 0)
            continue ;
        result << "	" << _heroes[i] << " picked: " << _heroCount[i];
        percentage = ((static_cast<double>(_heroCount[i]) / (static_cast<double>(_comps))) * 100);
        result << " (" << setprecision(3) << percentage << "%)\n";
        if (_heroCount[i] > (_comps / 3))
            mostCommon.push_back(make_pair(percentage, i));
    }
    result << "Most common: \n";
    sort(mostCommon.begin(), mostCommon.end());
    for (size_t i = 0; i < mostCommon.size(); i++)
    {
        result << setw(10) << _heroes[mostCommon[i].second] << " " << _heroCount[mostCommon[i].second] << " (" << mostCommon[i].first << "%)\n";
    }
    return result.str();
}

void	Team::printTanks()
{
		for (size_t i = 0; i < _teamComps.size(); i++)
	{
        cout << "	TANK: " << _teamComps[i]["TANK"] << "\n";
		std::cout << std::endl;
	}
}

void	Team::displayMapStats()
{
	string	input;
	int		index;

	print_vector(_maps);
	while (1)
	{
		cout << HIYELLOW << "Select  a map: " << RESET;
		std::cin >> input;
		if (input.empty())
			return ;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		auto it = find(_maps.begin(), _maps.end(), input);
		if (it == _maps.end())
			std::cout << BRED << input << " is not a valid map\n" << RESET;
		else
		{
			index = distance(_maps.begin(), it);
			break ;
		}
	}
	string map = _maps[index]; 
	for (size_t i = 0; i < _comps; i++)
	{
		if (_teamComps[i]["MAP"] == map)
		{
			printComp(i);
			std::cout << "\n";
		}
	}
}

string  Team::retMapStats(int i)
{
    string map = _maps[i];
    unsigned int count = 1;
    stringstream result;

    for (size_t i = 0; i < _comps; i++)
    {
        qDebug() << _teamComps[i]["MAP"];
        if (_teamComps[i]["MAP"] == map)
        {
            result << "Comp " << count << ":\n";
            result << " " << _teamComps[i]["TANK"] << "\n";
            result << " " << _teamComps[i]["DPS1"] << "\n";
            result << " " << _teamComps[i]["DPS2"] << "\n";
            result << " " << _teamComps[i]["SUPP1"] << "\n";
            result << " " << _teamComps[i]["SUPP2"] << "\n\n";
        }
        count++;
    }
    return result.str();
}

size_t Team::getCompAmt()
{
    return _comps;
}

string  *Team::getComp(size_t i)
{
    string  *comp = new string[6];

    sortComp(i);
    qDebug() << _teamComps[i];
    auto it = _teamComps[i].begin();
    for (size_t j = 0; j < 6; j++)
    {
        comp[j] = it->second;
        it++;
    }
    return comp;
}

void    Team::changeComp(int heroes[5], int index)
{
    qDebug() << heroes << " " << index << "\n";
    _teamComps[index]["TANK"] = _heroes[heroes[0]];
    _teamComps[index]["DPS1"] = _heroes[heroes[1] + 13];
    _teamComps[index]["DPS2"] = _heroes[heroes[2] + 13];
    _teamComps[index]["SUPP1"] = _heroes[heroes[3] + 32];
    _teamComps[index]["SUPP2"] = _heroes[heroes[4] + 32];
    sortComp(index);
    saveTeam();
    updateTime();
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
		stream << BWHITE << "Composition: " << i + 1 << "\n"  << RESET << HIYELLOW << "	MAP: " << comps[i]["MAP"] << "\n" << RESET;
		stream << HIGREEN << "	TANK: " << comps[i]["TANK"] << RESET << "\n";
		stream << HIBLUE << "	DPS: " << comps[i]["DPS1"] << "\n";
		stream << "	DPS: " << comps[i]["DPS2"] << "\n" << RESET;
		stream << HIPURPLE << "	SUPP: " << comps[i]["SUPP1"] << "\n";
		stream << "	SUPP: " << comps[i]["SUPP2"] << "\n" << RESET;
	}
	return stream;
}
