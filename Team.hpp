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
#include <QTextStream>
#include <QTextEdit>
#include <QfileInfo>
#include <QResource>

using namespace std;

#define ICONS "./icons/"
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
const	vector<string>	_maps = { "ANTARCTIC - ICEBREAKER", "ANTARCTIC - LABS", "ANTARCTIC - SUBLEVEL",
	"BUSAN - DOWNTOWN", "BUSAN - SANCTUARY", "BUSAN - MEKABASE",
	"ILIOS - LIGHTHOUSE", "ILIOS - WELL", "ILIOS - RUINS",
	"LIJANG - NIGHTMARKET", "LIJANG - GARDENS", "LIJANG - CONTROL CENTER"
	"NEPAL - VILLAGE", "NEPAL - SHRINE", "NEPAL - SANCTUM",
	"OASIS - CITY CENTER", "OASIS - GARDENS", "OASIS - UNIVERSITY",
	"SAMOA - BEACH", "SAMOA - DOWNTOWN", "SAMOA - VOLCANO", "CIRCUIT",
	"DORADO", "HAVANA", "JUNKERTOWN", "RIALTO", "ROUTE",
	"SHAMBALI", "GIB", "AATLIS", "NEW JUNK CITY", "SURAVASA", "BLIZZ", "EICH", "HOLLYWOOD",  "KR",
	"MIDTOWN", "NUMBANI", "PARAISO", "COLOSSEO", "ESPERANCA", "NQS", "RUNASAPI" };

#define MAPAMT _maps.size()


class Team
{
	private:
		string	_name;
		string	_save;
		string	_notes;
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
		size_t	 getCompAmt();
		string	retStats();
		/*
			Applies a teams stats info to QTextEdit in view stats page
			@param pointer to the QTextEdit box
		*/
		QString retQstats(QTextEdit *info);
		void	resetStats();
		void	getHeroes();
		void	setNotes(string notes);
		void	addHeroes(size_t i);
		void	newComp();
		void	addComp(string heroes[6]);
		/*
			Adds a full team composition based on indexes
			@param array of 6 indexes corresponding to TANK, DPS, DPS, SUPP, SUPP, MAP
		*/
		void	addComp(int heroes[6]);
		/*
			Adjusts a previously made team composition
			@param Array of new hero indexes for all roles
			@param Index of comp inside class
		*/
		void	changeComp(int heroes[5], int index);
		void	deleteTeam();
		void	updateTime();
		void	printComp(size_t i);
		string  returnComp(size_t i);
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
