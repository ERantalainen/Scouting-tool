#include "Team.hpp"

void	listTeams(vector<Team *> teams)
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		cout <<  HIGREEN << i + 1 << ": " << (*teams[i]).getName() << RESET << "\n";
	}
}

int main ()
{
	vector<Team *>	teams;
	cout << HIGREEN << "WELCOME TO THE SCOUTING MANAGER\n\n\n" << RESET;
	while (1)
	{
		string	input;
		int		option;

		cout << BWHITE << "Choose an OPTION:\n";
		cout <<	"	1. Create new team\n" << "	2. Edit team\n" << "	3. Delete team\n";
		cout << "	4. Display Team stats\n";
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
			std::cout << RESET << BCYAN << "Choose team name\n" << RESET;
			std::cin >> input;
			teams.push_back(new Team(input));
			teams[teams.size() - 1]->newTeam();
			while (1)
			{
				std::cout << HIWHITE << "Add more comps? Y/n:" << RESET;
				std::cin >> input;
				std::transform(input.begin(), input.end(), input.begin(), ::toupper);
				if (input == "Y")
					teams[teams.size() - 1]->newTeam();
				else
				{
					std::cout << (*teams[option - 1]);
					break ;
				}
			}
		}
		if (option == 2)
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
				continue ;
			}
			std::cout << HIWHITE << "Select comp to edit: \n" << RESET;
			std::cout << *teams[option - 1];
			std::cout << HIWHITE << "Select comp:";
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
			teams[option - 1]->addHeroes(option - 1);
			while (1)
			{
				std::cout << HIWHITE << "Continue editing? Y/n:" << RESET;
				std::cin >> input;
				std::transform(input.begin(), input.end(), input.begin(), ::toupper);
				if (input == "Y")
					teams[option - 1]->addHeroes(option - 1);
				else
				{
					std::cout << (*teams[option - 1]);
					break ;
				}
			}
		}
		if (option == 4)
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
				continue ;
			}
			if (option < 0 || static_cast<unsigned int>(option) > teams.size())
				continue ;
			teams[option - 1]->printAllComps();
			cout << "\n\n";
		}
	}
}