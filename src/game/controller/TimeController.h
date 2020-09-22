#pragma once
#include <time/timercpp.h>
#include "../GameData.h"

class TimeController
{
public:
	TimeController();
	TimeController(GameData* data, std::function<void()> timeOut);
	void StartTimer();
	void StopTimer();

private:
	GameData* mData;
	std::function<void()> mTimeOutCallback;
	timer::Timer mTimer;
};