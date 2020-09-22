#include <array>
#include <utility>
#include <king/Engine.h>

#include "RemoveMatchCommand.h"
#include "../Helper.h"

RemoveMatchCommand::RemoveMatchCommand(GameData* data, std::set<Gem*>& movingGems, GEMS_ARRAY& gems)
	: mData(data)
	, mMovingGems(movingGems)
	, mGems(gems)
{
}

bool RemoveMatchCommand::Execute()
{
	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Gem* gem = mGems[i][j];
			if (gem->IsMatched())
			{
				CheckColMatchedGems(gem);
			}
		}
	}

	return !mMovingGems.empty();
}

bool RemoveMatchCommand::UnExecute()
{
	return false;
}

void RemoveMatchCommand::CheckColMatchedGems(Gem* matchedGem)
{
	int counter = 0;
	int lastMatched = -1;
	INDEX index = matchedGem->GetIndex();
	for (int i = index.first; i < Config::BOARD_HEIGHT; i++)
	{
		if (mGems[i][index.second]->IsMatched())
		{
			if (lastMatched < 0 || i - lastMatched == 1)
			{
				lastMatched = i;
				counter++;
			}
			else
			{
				mGems[i][index.second]->Match(false);
			}
		}
	}

	ShiftColGemTextures(index, counter);
	AddNewColGemTextures(index, counter);
	MoveColGemTextures(index, counter);
}

void RemoveMatchCommand::ShiftColGemTextures(INDEX index, int counter)
{
	for (int i = index.first + counter - 1; i >= counter; i--)
	{
		Gem* gem = mGems[i][index.second];
		gem->SetTexture(mGems[i - counter][index.second]->GetTexture());
		gem->SetActiveTexture(mGems[i - counter][index.second]->GetActiveTexture());
	}
}

void RemoveMatchCommand::AddNewColGemTextures(INDEX index, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		Gem* gem = mGems[i][index.second];
		INDEX textures = Helper::GetRandomGemTexture(mGems, i, index.second);
		gem->SetTexture(static_cast<TEXTURE>(textures.first));
		gem->SetActiveTexture(static_cast<TEXTURE>(textures.second));
	}
}

void RemoveMatchCommand::MoveColGemTextures(INDEX index, int counter)
{
	for (int i = 0; i < index.first + counter; i++)
	{
		Gem* gem = mGems[i][index.second];
		gem->SetMovePosition(gem->GetPosition());
		gem->SetPosition(std::make_pair(gem->GetPosition().first, gem->GetPosition().second - counter * Config::TILE_HEIGHT));

		if (gem->IsMatched())
		{
			gem->Match(false);
			mData->AddScore(gem->GetScore());
			mData->AddMatchedGem(gem);
		}
		gem->Drop(true);
		mMovingGems.insert(gem);
	}

	if (mMovingGems.empty())
		return;

	for (size_t i = 1; i < Config::BOARD_HEIGHT - 1; i++)
	{
		for (size_t j = 1; j < Config::BOARD_WIDTH - 1; j++)
		{
			Gem* gem = mGems[i][j];
			gem->Swap(true);
		}
	}
}