#include "Team.hpp"

#include <chrono>
#include <fstream>
#include <ctime>
#include <filesystem>

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
	if (!filesystem::remove(_save))
		std::cerr << "Unable to delete file " << _save << "\n";
}

void	Team::addHeroes()
{
	string	input;
	std::cout << "Input heroes: "
}