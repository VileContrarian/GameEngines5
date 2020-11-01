#include "Game1.h"

Game1::Game1() : GameInterface(),CurrScene(nullptr), CurrSceneNum(0){

}
Game1::~Game1(){
	delete CurrScene;
	CurrScene = nullptr;
}

bool Game1::OnCreate() {
	if (CoreEngine::GetInstance()->GetCurrSceneNum() == 0) {
		CurrScene = new StartScene();
		if (!CurrScene->OnCreate()) {
			Debug::FatalError("Current Scene does not have an OnCreate", "Game1.cpp", __LINE__);
			return false;
		}
		return true;
	}
	Debug::FatalError("Engine SceneNum is not 0", "Game1.cpp", __LINE__);
	return false;
}
void Game1::Update(const float DeltaTime_) {
	if (CurrSceneNum != CoreEngine::GetInstance()->GetCurrSceneNum()) {
		BuildScene();
	}
	CurrScene->Update(DeltaTime_);
}
void Game1::Render() {
	CurrScene->Render();
}

void Game1::BuildScene() {
	delete CurrScene;
	CurrScene = nullptr;

	switch (CoreEngine::GetInstance()->GetCurrSceneNum()) {
	case 1:
		CurrScene = new GameScene();
		break;
	default:
		CurrScene = new StartScene();
		break;
	}

	if (!CurrScene->OnCreate()) {
		CoreEngine::GetInstance()->Exit();
		Debug::FatalError("Current Scene does not have an OnCreate", "Game1.cpp", __LINE__);
	}
	CurrSceneNum = CoreEngine::GetInstance()->GetCurrSceneNum();
}