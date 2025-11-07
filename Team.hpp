#pragma once

using namespace std;
#include <iostream>
#include <vector>

class Team
{
	private:
		string	_name;
		string	_save;
		time_t	_created;
		time_t	_updated;
		const vector<string>	_heroes = { "DVA", "DOOM", "HAZ", "JQ", "MAUGA", "ORI", "RAM", "REIN",
		"HOG", "SIG", "WINSTON", "BALL", "ZARYA", "ASHE", "BASTION", "CASS", "ECHO",
		"FREJA", "GENJI", "HANZO", "JUNK", "MEI", "PHARAH", "REAPER", "SOJ", "SOLDIER",
		"SOMBRA", "SYM", "TORB", "TRACER", "VENTURE", "WIDOW", "ANA", "BAP",
		"BRIG", "ILLARI", "JUNO", "KIRI", "LW", "LUCIO", "MERCY", "MOIRA", "WU", "ZEN"};
	public:
		Team();
		Team(string name);
		~Team();
		void	getStats();
		void	resetStats();
		void	getHeroes();
		void	addHeroes();
		string	getName();
		string	getSaveName();
		time_t	getCreated();
		time_t	getUpdated();
};

enum	heroes
{
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

