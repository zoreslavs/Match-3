#include "GameData.h"
#include "Config.h"

GameData::GameData()
	: mTime(Config::TOTAL_TIME)
	, mTickTime(0)
	, mScore(0)
{
}

void GameData::AddTime(int value)
{
	mTime += value;
}

void GameData::AddTickTime(float value)
{
	mTickTime += value;
}

void GameData::AddScore(int value)
{
	mScore += value;
}

void GameData::AddMatchedGem(Gem* gem)
{
	mMatchedGems.push_back(std::make_pair(gem, mTickTime));
}

void GameData::RemoveMatchedGem(int index)
{
	if (!mMatchedGems.empty())
		mMatchedGems.erase(mMatchedGems.begin() + index);
}

void GameData::Reset()
{
	mTime = Config::TOTAL_TIME;
	mTickTime = 0;
	mScore = 0;
	mMatchedGems = {};
}