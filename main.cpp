#include "Team.hpp"

int main ()
{
	Team	zokorp("zokorp");

	zokorp.newTeam();
	zokorp.addHeroes(0);
	zokorp.addHeroes(0);
	zokorp.addHeroes(0);
	zokorp.addHeroes(0);
	zokorp.addHeroes(0);
	zokorp.addHeroes(0);
	std::cout << zokorp << "\n";
}