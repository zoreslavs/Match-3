#pragma once

#include <vector>
#include <utility>
#include "view/Gem.h"

class GameData
{
public:
	GameData();

	void AddTime(int value);
	void AddTickTime(float value);
	void AddScore(int value);
	void AddMatchedGem(Gem* gem);
	void RemoveMatchedGem(int index);
	void Reset();

	int GetTime() const { return mTime; }
	float GetTickTime() const { return mTickTime; }
	int GetScore() const { return mScore; }

	std::vector<std::pair<Gem*, float>> GetMatchedGems() const { return mMatchedGems; }

private:
	int mTime;
	int mScore;
	float mTickTime;
	std::vector<std::pair<Gem*, float>> mMatchedGems;
};
