#include "StateManager.h"
#include "DB.h"
int main()
{
	DB::loadTextures();
	stateManager->updateCurrentState();

	return 0;
}