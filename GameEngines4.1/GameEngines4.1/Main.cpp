#include "Engine\Core\CoreEngine.h"
#include "Game/Game1.h"

int main(int argc, char* argv[]) {
	CoreEngine::GetInstance()->SetGameInterface(new Game1);

	if (!CoreEngine::GetInstance()->OnCreate("Game Engines 4", 800, 600)) {
		return 0;
	}

	CoreEngine::GetInstance()->Run();

	return 0;
}