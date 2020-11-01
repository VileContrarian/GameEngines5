#pragma once
#ifndef GAME1_H
#define GAME1_H

#include "../Engine/Core/CoreEngine.h"
#include "Scenes/StartScene.h"
#include "Scenes/GameScene.h"

class Game1 : public GameInterface {
public:
	Game1();
	virtual ~Game1();

	virtual bool OnCreate();
	virtual void Update(const float DeltaTime_);
	virtual void Render();

private:
	Scene* CurrScene;
	int CurrSceneNum;
	void BuildScene();
};

#endif GAME1_H