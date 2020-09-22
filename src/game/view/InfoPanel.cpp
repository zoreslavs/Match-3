#include <string>
#include <vector>
#include <utility>

#include "InfoPanel.h"
#include "../Helper.h"

InfoPanel::InfoPanel(King::Engine* engine, GameData* data)
	: mEngine(engine)
	, mData(data)
{
}

void InfoPanel::Update()
{
	std::string timeStr = "Time: " + Helper::GetTimeString(mData->GetTime());
	std::string scoreStr = "Score : " + std::to_string(mData->GetScore());

	mEngine->Write(timeStr.c_str(), 50.f, 200.f);
	mEngine->Write(scoreStr.c_str(), 50.f, 280.f);

	UpdateMatchedScore();
}

void InfoPanel::UpdateMatchedScore()
{
	auto matchedGems = mData->GetMatchedGems();
	for (int i = 0; i < matchedGems.size(); i++)
	{
		std::pair<Gem*, float> matchedGem = matchedGems[i];
		if (matchedGem.second != mData->GetTickTime())
		{
			mData->RemoveMatchedGem(i);
			break;
		}
		else
		{
			std::string scoreStr = std::to_string(matchedGem.first->GetScore());
			float posX = matchedGem.first->GetMovePosition().first;
			float posY = matchedGem.first->GetMovePosition().second;
			mEngine->Write(scoreStr.c_str(), posX, posY);
		}
	}
}