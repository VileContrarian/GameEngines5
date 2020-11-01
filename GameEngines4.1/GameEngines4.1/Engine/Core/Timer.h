#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer {
public:
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator = (const Timer&) = delete;
	Timer& operator = (Timer&&) = delete;

	Timer();

	void Start();
	void Update();
	float GetDeltaTime() const;
	unsigned int GetSleepTime(unsigned int FPS_) const;
	float GetTicks();

private:
	unsigned int PrevTicks, CurrTicks;
};

#endif TIMER_H