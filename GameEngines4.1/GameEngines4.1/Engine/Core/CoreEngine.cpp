#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::EngineInstance = nullptr;

CoreEngine::CoreEngine() : window(nullptr), IsRunning(nullptr), FPS(60), gameInterface(nullptr), CurrSceneNum(0), camera(nullptr){}
CoreEngine::~CoreEngine()
{
	OnDestroy();
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
	Debug::DebugInit();
	Debug::SetSev(MessType::TYPE_INFO);

	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) {
		Debug::FatalError("OnCreate Failed", "CoreEngine.cpp", __LINE__);
		return IsRunning = false;
	}

	ShaderHandler::GetInstance()->CreateProgram("colourShader", "Engine/Shaders/ColourVertexShader.glsl", "Engine/Shaders/ColourFragmentShader.glsl");

	ShaderHandler::GetInstance()->CreateProgram("basicShader", "Engine/Shaders/VertexShader.glsl", "Engine/Shaders/FragmentShader.glsl");

	if (gameInterface) {
		if (!gameInterface-> OnCreate()) {
			return IsRunning = false;
			Debug::FatalError("Game Interface does not have an OnCreate", "CoreEngine.cpp", __LINE__);
		}
	}

	timer.Start();

	Debug::Info("OnCreate completed", "CoreEngine.cpp", __LINE__);

	return IsRunning = true;
}
void CoreEngine::Run()
{
	while (IsRunning)
	{
		timer.Update();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(FPS));
	}
	if (!IsRunning) 
	{
		OnDestroy();
	}
}
bool CoreEngine::GetIsRunning() const
{
	return IsRunning;
}

CoreEngine * CoreEngine::GetInstance()
{
	if (EngineInstance.get() == nullptr)
	{
		EngineInstance.reset(new CoreEngine);
	}
	return EngineInstance.get();
}

void CoreEngine::OnDestroy()
{
	delete camera;
	camera = nullptr;

	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;

	SDL_Quit();
	exit(0);
}
void CoreEngine::Update(const float deltaTime_)
{
	if (gameInterface) {
		gameInterface->Update(deltaTime_);
	}
}
void CoreEngine::Render()
{
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// l      CALL GAME        l
	// V      RENDER HERE      V
	if (gameInterface) {
		gameInterface->Render();
	}
	SDL_GL_SwapWindow(window->GetWindow());
}

void CoreEngine::SetGameInterface(GameInterface* gameInterface_) {
	gameInterface = gameInterface_;
}

int CoreEngine::GetCurrSceneNum() {
	return CurrSceneNum;
}
void CoreEngine::SetCurrSceneNum(int CurrSceneNum_) {
	CurrSceneNum = CurrSceneNum_;
}

glm::vec2 CoreEngine::GetWindowSize() const {
	return glm::vec2(window->GetWidth(), window->GetHeight());
}

void CoreEngine::Exit() {
	IsRunning = false;
}
	
Camera* CoreEngine::GetCamera() const {
	return camera;
}

void CoreEngine::SetCamera(Camera* camera_) {
	camera = camera_;
}