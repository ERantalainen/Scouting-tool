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
#include <QDebug>
#include <QSignalBlocker>
#include <QTimer>

using namespace std;

#define SAVEDATA	"./data/save.dat"
#define TANKAMT 13
#define DPSAMT 20
#define SUPPAMT 12
#define TOTAL 45

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
    VENDETTA,
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

const 	vector<string>	_heroes = { "DVA", "DOOM", "HAZ", "JQ", "MAUGA", "ORI", "RAM", "REIN",
                                "HOG", "SIG", "WINSTON", "BALL", "ZARYA", "ASHE", "BASTION", "CASS", "ECHO",
                                "FREJA", "GENJI", "HANZO", "JUNK", "MEI", "PHARAH", "REAPER", "SOJ", "SOLDIER",
                                "SOMBRA", "SYM", "TORB", "TRACER", "VENTURE", "VENDETTA", "WIDOW", "ANA", "BAP",
                                "BRIG", "ILLARI", "JUNO", "KIRI", "LW", "LUCIO", "MERCY", "MOIRA", "WU", "ZEN"};
const	vector<string>	_maps = { "ANTARCTIC", "BUSAN", "ILIOS", "LIJANG", "NEPAL",
                              "OASIS", "SAMOA", "CIRCUIT", "DORADO", "HAVANA", "JUNKERTOWN", "RIALTO", "ROUTE",
                              "SHAMBALI", "GIB", "AATLIS", "NEW JUNK CITY", "SURAVASA", "BLIZZ", "EICH", "HOLLYWOOD",  "KR",
                              "MIDTOWN", "NUMBANI", "PARAISO", "COLOSSEO", "ESPERANCA", "NQS", "RUNASAPI" };

class Team
{
	private:
		string	_name;
		string	_save;
		time_t	_created;
		time_t	_updated;
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
        size_t     getCompAmt();
        string	retStats();
		void	resetStats();
		void	getHeroes();
		void	addHeroes(size_t i);
		void	newComp();
        void	addComp(string heroes[6]);
        void	addComp(int heroes[6]);
        void    changeComp(int heroes[5], int index);
		void	deleteTeam();
		void	updateTime();
		void	printComp(size_t i);
        string    returnComp(size_t i);
		void	printAllComps();
		void	printTanks();
		void	printSupps();
		void	printDps();
		void	newTeam();
		void	saveTeam();
		void	selectMap(int i);
		void	displayMapStats();
        string  retMapStats(int map);
		vector<map<string, string>> getComps() const;
		string	getName() const;
        string  *getComp(size_t i);
		string	getSaveName() const;
		time_t	getCreated() const;
		time_t	getUpdated() const;
};

void	listTeams(vector<Team *> teams);
std::ostream & operator<<(std::ostream &stream, const Team &object);
