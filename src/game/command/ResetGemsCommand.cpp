#include <array>
#include <utility>
#include <ctime>
#include <cstdlib>

#include "ResetGemsCommand.h"
#include "../Helper.h"

ResetGemsCommand::ResetGemsCommand(GEMS_ARRAY& gems)
	: mGems(gems)
{
}

bool ResetGemsCommand::Execute()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Gem* gem = mGems[i][j];
			gem->SetPosition(gem->GetInitPosition());
			INDEX textures = Helper::GetRandomGemTexture(mGems, i, j);
			gem->SetTexture(static_cast<TEXTURE>(textures.first));
			gem->SetActiveTexture(static_cast<TEXTURE>(textures.second));
			gem->SetScore(Config::GEM_SCORE);

			gem->Select(false);
			gem->Swipe(false);
			gem->Swap(false);
			gem->Match(false);
			gem->Drop(false);
		}
	}

	return true;
}

bool ResetGemsCommand::UnExecute()
{
	return true;
}