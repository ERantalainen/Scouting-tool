#pragma once

#include "Colours.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <cstring>
#include <algorithm>

using namespace std;

#define SAVEDATA	"./data/save.dat"

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
		const	vector<string>	_maps = { "ANTARCTIC", "BUSAN", "ILIOS", "LIJAG", "NEPAL",
		"OASIS", "SAMOA", "CIRCUIT", "DORADO", "HAVANA", "JUNKERTOWN", "RIALTO", "ROUTE",
		"SHAMBALI", "GIB", "AATLIS", "NJC", "SURA", "BLIZZ", "EICH", "HOLLYWOOD",  "KR",
		"MIDTOWN", "NUMBANI", "PARAISO", "COLOSSEO", "ESPERANCA", "NQS", "RUNASAPI" };
		vector<map<string, string>>	_teamComps;
		vector<unsigned int>	_heroCount;
		enum	heroes	_hero;
		bool	_dps = false;
		bool	_supp = false;
		size_t	_comps = 0;
		void	calcStats();
		void	sortComp(int i);
	public:
		Team();
		Team(string name);
		~Team();
		void	getStats();
		void	resetStats();
		void	getHeroes();
		void	addHeroes(size_t i);
		void	newComp();
		void	addComp(string heroes[5]);
		void	deleteTeam();
		void	updateTime();
		void	printComp(size_t i);
		void	printAllComps();
		void	printTanks();
		void	printSupps();
		void	printDps();
		void	newTeam();
		void	saveTeam();
		void	selectMap(int i);
		void	displayMapStats();
		vector<map<string, string>> getComps() const;
		string	getName() const;
		string	getSaveName() const;
		time_t	getCreated() const;
		time_t	getUpdated() const;
};

std::ostream & operator<<(std::ostream &stream, const Team &object);