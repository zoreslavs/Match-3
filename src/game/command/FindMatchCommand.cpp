#include <array>
#include <utility>

#include "FindMatchCommand.h"

FindMatchCommand::FindMatchCommand(GEMS_ARRAY& gems)
	: mGems(gems)
	, mIsMatched(false)
{
}

bool FindMatchCommand::Execute()
{
	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Gem* gem = mGems[i][j];
			if (gem->IsSwapped())
			{
				FindHorizontal(gem->GetIndex(), gem->GetTexture());
				FindVertical(gem->GetIndex(), gem->GetTexture());

				gem->Swap(false);
			}
		}
	}
	return mIsMatched;
}

void FindMatchCommand::FindHorizontal(INDEX index, int texture)
{
	std::vector<Gem*> temp = {};
	int lastIndex = -1;
	for (size_t i = 0; i < Config::BOARD_WIDTH; i++)
	{
		Gem* gem = mGems[index.first][i];
		if (texture == gem->GetTexture() &&
			(lastIndex < 0 || gem->GetIndex().second - lastIndex == 1))
		{
			lastIndex = gem->GetIndex().second;
			temp.push_back(gem);
		}
		else if (temp.size() < 3)
		{
			lastIndex = -1;
			temp.clear();
		}
		else
		{
			break;
		}
	}
	MarkMatched(temp);
}

void FindMatchCommand::FindVertical(INDEX index, int texture)
{
	std::vector<Gem*> temp = {};
	int lastIndex = -1;
	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		Gem* gem = mGems[i][index.second];
		if (texture == gem->GetTexture() &&
			(lastIndex < 0 || gem->GetIndex().first - lastIndex == 1))
		{
			lastIndex = gem->GetIndex().first;
			temp.push_back(gem);
		}
		else if (temp.size() < 3)
		{
			lastIndex = -1;
			temp.clear();
		}
		else
		{
			break;
		}
	}
	MarkMatched(temp);
}

void FindMatchCommand::MarkMatched(std::vector<Gem*>& temp)
{
	if (temp.size() >= 3)
	{
		for (Gem* gem : temp)
		{
			gem->Match(true);
		}
		mIsMatched = true;
	}
}

bool FindMatchCommand::UnExecute()
{
	return false;
}