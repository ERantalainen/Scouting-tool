#include "mainwindow.h"
#include "Team.hpp"
#include <QApplication>

vector<Team *>	teams;
void loadTeams(vector<Team *> &teams);

int main(int argc, char *argv[])
{
    loadTeams(teams);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "Team.hpp"

void	listTeams(vector<Team *> teams)
{
    for (size_t i = 0; i < teams.size(); i++)
    {
        cout <<  HIGREEN << i + 1 << ": " << (*teams[i]).getName() << RESET << "\n";
    }
}

void loadTeams(vector<Team *> &teams)
{
    ifstream		save;
    string			team;
    string          name;
    string			heroes[6];
    string			hero;
	string			notes;
    unsigned int	i = 0;

    save.open(SAVEDATA);
    if (!save.is_open())
        qDebug() << HIRED << "Unable to open/create save file\n" << RESET;
    while (getline(save, team))
    {
        ifstream teamData(team);
        if (!teamData.is_open())
        {
            std::cerr << HIRED << "Unable to load team data from file: " << team << "\n" << RESET;
            continue;
        }
        name = team.substr(team.find_last_of("/") + 1);
        name = name.substr(0, name.find("."));
        teams.push_back(new Team(name));
        while (getline(teamData, hero))
        {
			if (hero.starts_with("NOTES:") == 0)
			{
				while (getline(teamData, hero) && hero.compare("EOF") != 0)
				{
					notes.append(hero);
				}
				teams[CURRTEAM]->setNotes(notes);
				continue ;
			}
			if (hero.starts_with("ban:"))
			{
				teams[CURRTEAM]->addBan(hero.substr(hero.find(":") + 1));
				continue;
			}
            heroes[i] = hero;
            i++;
            if (i == 6)
            {
                teams[CURRTEAM]->addComp(heroes);
                for (int j = 0; j < 6; j++)
                    heroes[j].clear();
                i = 0;
            }
        }
    }
}
