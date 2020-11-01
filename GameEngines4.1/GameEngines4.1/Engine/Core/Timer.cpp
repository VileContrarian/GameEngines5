#include "Timer.h"

Timer::Timer() : PrevTicks(0), CurrTicks(0){
}
void Timer::Start() {
	PrevTicks = SDL_GetTicks();
	CurrTicks = SDL_GetTicks();
}
void Timer::Update() {
	PrevTicks = CurrTicks;
	CurrTicks = SDL_GetTicks();
}
float Timer::GetDeltaTime() const {
	return static_cast<float>(CurrTicks - PrevTicks) / 1000.0f;
}
unsigned int Timer::GetSleepTime(unsigned int FPS_) const {
	unsigned int MilliAFrame = 1000 / FPS_;
	if (MilliAFrame == 0) {
		return 0;
	}
	
	unsigned int SleepTime = MilliAFrame - SDL_GetTicks();
	if (SleepTime > MilliAFrame) {
		return MilliAFrame;
	}
	else {
		return SleepTime;
	}
}
float Timer::GetTicks() {
	return static_cast<float>(CurrTicks) / 1000.0f;
}