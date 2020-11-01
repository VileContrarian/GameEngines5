#ifndef COREENGINE_H
#define COREENGINE_H

#include <memory>
#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"
#include "Scene.h"
#include "..\Rendering\3D\GameObject.h"
#include "..\Graphics\ShaderHandler.h"
#include "..\Graphics\TextureHandlerr.h"
#include "..\Camera\Camera.h"

class CoreEngine 
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator = (const CoreEngine&) = delete;
	CoreEngine& operator = (CoreEngine&&) = delete;

	bool OnCreate(std::string name_, int width_, int height_);
	void Run();
	bool GetIsRunning() const;

	static CoreEngine* GetInstance();

	void SetGameInterface(GameInterface* gameInterface_);

	int GetCurrSceneNum();
	void SetCurrSceneNum(int CurrSceneNum_);

	glm::vec2 GetWindowSize() const;

	Camera* GetCamera() const;
	void SetCamera(Camera* camera_);

	void Exit();

private:
	CoreEngine();
	~CoreEngine();
	
	static std::unique_ptr<CoreEngine> EngineInstance;
	friend std::default_delete<CoreEngine>;

	void OnDestroy();
	void Update(const float deltaTime_);
	void Render();
	Window* window;
	bool IsRunning;

	Timer timer;
	unsigned int FPS;

	GameInterface* gameInterface;

	int CurrSceneNum;

	Camera* camera;
};

#endif // !COREENGINE_H