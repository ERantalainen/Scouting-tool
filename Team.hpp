#pragma once

#include "Colours.hpp"
#include <iostream>
#include <vector>
#include <map>


using namespace std;

enum	heroes
{
	EMPTY,
	DVA,
	DOOM,
	HAZ,
	JQ,
	MAUGA,
	ORI,
	RAM,
	REIN,
	HOG,
	SIG,
	WINSTON,
	BALL,
	ZARYA,
	ASHE,
	BASTION,
	CASS,
	ECHO,
	FREJA,
	GENJI,
	HANZO,
	JUNK,
	MEI,
	PHARAH,
	REAPER,
	SOJ,
	SOLDIER,
	SOMBRA,
	SYM,
	TORB,
	TRACER,
	VENTURE,
	WIDOW,
	ANA,
	BAP,
	BRIG,
	ILLARI,
	JUNO,
	KIRI,
	LW,
	LUCIO,
	MERCY,
	MOIRA,
	WU,
	ZEN
};

class Team
{
	private:
		string	_name;
		string	_save;
		time_t	_created;
		time_t	_updated;
		const 	vector<string>	_heroes = { "DVA", "DOOM", "HAZ", "JQ", "MAUGA", "ORI", "RAM", "REIN",
		"HOG", "SIG", "WINSTON", "BALL", "ZARYA", "ASHE", "BASTION", "CASS", "ECHO",
		"FREJA", "GENJI", "HANZO", "JUNK", "MEI", "PHARAH", "REAPER", "SOJ", "SOLDIER",
		"SOMBRA", "SYM", "TORB", "TRACER", "VENTURE", "WIDOW", "ANA", "BAP",
		"BRIG", "ILLARI", "JUNO", "KIRI", "LW", "LUCIO", "MERCY", "MOIRA", "WU", "ZEN"};
		vector<map<string, string>>	_teamComps;
		enum	heroes	_hero;
		bool	_dps = false;
		bool	_supp = false;
		size_t	_comps = 0;
	public:
		Team();
		Team(string name);
		~Team();
		void	getStats();
		void	resetStats();
		void	getHeroes();
		void	addHeroes(size_t i);
		void	newComp();
		void	deleteTeam();
		void	updateTime();
		void	printComp(size_t i);
		void	newTeam();
		vector<map<string, string>> getComps() const;
		string	getName() const;
		string	getSaveName() const;
		time_t	getCreated() const;
		time_t	getUpdated() const;
};

std::ostream & operator<<(std::ostream &stream, const Team &object);