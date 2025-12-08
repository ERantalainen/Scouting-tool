#include "mainwindow.h"
#include "Team.hpp"
#include <QApplication>

vector<Team *>	teams;
void loadTeams(vector<Team *> &teams);

int main(int argc, char *argv[])
{

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
    string			heroes[6];
    string			hero;
    unsigned int	i = 0;

    save.open(SAVEDATA);
    if (!save.is_open())
        std::cerr << HIRED << "Unable to open/create save file\n" << RESET;
    while (getline(save, team))
    {
        ifstream teamData(team);
        if (!teamData.is_open())
        {
            std::cerr << HIRED << "Unable to load team data from file: " << team << "\n" << RESET;
            continue;
        }
        teams.push_back(new Team(team.substr(team.find_last_of("/") + 1, team.find_last_of("."))));
        while (getline(teamData, hero))
        {
            heroes[i] = hero;
            i++;
            if (i == 6)
            {
                teams[teams.size() - 1]->addComp(heroes);
                for (int j = 0; j < 6; j++)
                    heroes[j].clear();
                i = 0;
            }
        }
    }
}

int core ()
{

    cout << HIGREEN << "WELCOME TO THE SCOUTING MANAGER\n\n\n" << RESET;
    while (1)
    {
        string	input;
        int		option;

        cout << BWHITE << "Choose an OPTION:\n";
        cout <<	"	1. Create new team\n" << "	2. Edit team\n" << "	3. Delete team\n";
        cout << "	4. Display Team stats\n	5. Display map comps\n";
        cin >> input;
        try
        {
            option = stoi(input);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue ;
        }
        if (option == 1)
        {

        }
        if (option == 2)
        {

        }
        if (option == 3)
        {
            if (teams.size() < 1)
            {
                std::cerr << HIRED << "No teams to delete, please create a team first\n";
                continue;
            }
            std::cout << HIWHITE << "Select a team:\n\n" << RESET;
            listTeams(teams);
            std::cout << HIWHITE << "Input team: ";
            std::cin >> input;
            std::cout << RESET;
            try
            {
                option = stoi(input);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                continue ;
            }
            if (option < 0 || static_cast<unsigned int>(option) > teams.size())
            {
                std::cout << HIRED << "Invalid input returning \n";
                continue ;
            }
            delete teams[option - 1];
            teams.erase(teams.begin() + (option - 1));
        }
        if (option == 4)
        {
            if (teams.size() < 1)
            {
                std::cerr << HIRED << "No teams to display, please create a team first\n";
                continue;
            }
            std::cout << HIWHITE << "Select a team:\n\n" << RESET;
            listTeams(teams);
            std::cout << HIWHITE << "Input team: ";
            std::cin >> input;
            std::cout << RESET;
            try
            {
                option = stoi(input);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << HIRED << "Invalid input returning \n";
                continue ;
            }
            if (option < 0 || static_cast<unsigned int>(option) > teams.size())
            {
                std::cout << HIRED << "Invalid input returning \n";
                continue ;
            }
            teams[option - 1]->printAllComps();
            cout << "\n\n";
        }
        if (option == 5)
        {
            std::cout << HIWHITE << "Select a team:\n\n" << RESET;
            listTeams(teams);
            std::cout << HIWHITE << "Input team: ";
            std::cin >> input;
            std::cout << RESET;
            try
            {
                option = stoi(input);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << HIRED << "Invalid input returning \n";
                continue ;
            }
            if (option < 0 || static_cast<unsigned int>(option) > teams.size())
            {
                std::cout << HIRED << "Invalid input returning \n";
                continue ;
            }
            teams[option - 1]->displayMapStats();
        }
    }
}
