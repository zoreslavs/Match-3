#include <array>
#include <utility>

#include "SelectGemCommand.h"
#include "../Helper.h"

SelectGemCommand::SelectGemCommand(Gem*& selected)
	: mSelectedGem(selected)
{
}

SelectGemCommand::SelectGemCommand(Gem*& selected, GEMS_ARRAY& gems, POSITION& mousePos)
	: mSelectedGem(selected)
	, mMousePos(mousePos)
	, mGems(gems)
{
}

bool SelectGemCommand::Execute()
{
	UnExecute();

	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Gem* gem = mGems[i][j];
			if (Helper::IsPointInsideRectangle(gem->GetPosition().first, 
											   gem->GetPosition().second,
											   gem->GetPosition().first + gem->GetWidth(),
											   gem->GetPosition().second + gem->GetHeight(), 
											   mMousePos.first, 
											   mMousePos.second))
			{
				gem->Select(true);
				mSelectedGem = gem;
				return true;
			}
		}
	}
	return false;
}

bool SelectGemCommand::UnExecute()
{
	if (mSelectedGem)
	{
		mSelectedGem->Select(false);
		return true;
	}
	return false;
}