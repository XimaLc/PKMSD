#include "Team.h"
#include "DB.h"

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
	DB::saveTeam(*this);
}

void Team::load()
{
	int pId1, pId2, pId3, pId4, pId5, pId6, mId1, mId2, mId3, mId4, mId5, mId6, mId7, mId8, mId9, mId10, mId11, mId12, mId13, mId14, mId15, mId16, mId17, mId18, mId19, mId20, mId21, mId22, mId23, mId24;

	std::ifstream file("team.dat");
	if (file.is_open())
	{
		file >> pId1 >> mId1 >> mId2 >> mId3 >> mId4 >> pId2 >> mId5 >> mId6 >> mId7 >> mId8 >> pId3 >> mId9 >> mId10 >> mId11 >> mId12 >> pId4 >> mId13 >> mId14 >> mId15 >> mId16 >> pId5 >> mId17 >> mId18 >> mId19 >> mId20 >> pId6 >> mId21 >> mId22 >> mId23 >> mId24;
		file.close();
	}

	team[0] = DB::getPokemonById(pId1);
	team[0].setMove(DB::getMoveById(mId1), 0);
	team[0].setMove(DB::getMoveById(mId2), 1);
	team[0].setMove(DB::getMoveById(mId3), 2);
	team[0].setMove(DB::getMoveById(mId4), 3);

	team[1] = DB::getPokemonById(pId2);
	team[1].setMove(DB::getMoveById(mId5), 0);
	team[1].setMove(DB::getMoveById(mId6), 1);
	team[1].setMove(DB::getMoveById(mId7), 2);
	team[1].setMove(DB::getMoveById(mId8), 3);

	team[2] = DB::getPokemonById(pId3);
	team[2].setMove(DB::getMoveById(mId9), 0);
	team[2].setMove(DB::getMoveById(mId10), 1);
	team[2].setMove(DB::getMoveById(mId11), 2);
	team[2].setMove(DB::getMoveById(mId12), 3);

	team[3] = DB::getPokemonById(pId4);
	team[3].setMove(DB::getMoveById(mId12), 0);
	team[3].setMove(DB::getMoveById(mId14), 1);
	team[3].setMove(DB::getMoveById(mId15), 2);
	team[3].setMove(DB::getMoveById(mId16), 3);

	team[4] = DB::getPokemonById(pId5);
	team[4].setMove(DB::getMoveById(mId17), 0);
	team[4].setMove(DB::getMoveById(mId18), 1);
	team[4].setMove(DB::getMoveById(mId19), 2);
	team[4].setMove(DB::getMoveById(mId20), 3);

	team[5] = DB::getPokemonById(pId6);
	team[5].setMove(DB::getMoveById(mId21), 0);
	team[5].setMove(DB::getMoveById(mId22), 1);
	team[5].setMove(DB::getMoveById(mId23), 2);
	team[5].setMove(DB::getMoveById(mId24), 3);
}