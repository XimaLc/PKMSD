#include "Team.h"

Team::Team()
{
	team.push_back(Pokemon());
	team.push_back(Pokemon());
	team.push_back(Pokemon());
	team.push_back(Pokemon());
	team.push_back(Pokemon());
	team.push_back(Pokemon());
}

void Team::addMove(Move _move, int moveIndex, int teamIndex)
{
	team[teamIndex].setMove(_move, moveIndex);
}

void Team::save()
{

}