#include "TimeController.h"

TimeController::TimeController()
{
}

TimeController::TimeController(GameData* data, std::function<void()> timeOut)
	: mData(data)
	, mTimeOutCallback(timeOut)
{
}

void TimeController::StartTimer()
{
	mTimer.setInterval([&]()
	{
		mData->AddTickTime(0.5f);
		if (mData->GetTickTime() == 1.f)
		{
			if (mData->GetTime() > 0)
			{
				mData->AddTime(-1);
				mData->AddTickTime(-1);
			}
			else
			{
				StopTimer();
				mTimeOutCallback();
			}
		}
	}, 500);
}

void TimeController::StopTimer()
{
	mTimer.clear = true;
}