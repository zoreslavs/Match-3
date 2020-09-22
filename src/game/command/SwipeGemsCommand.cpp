#include <array>
#include <utility>

#include "SwipeGemsCommand.h"

SwipeGemsCommand::SwipeGemsCommand(Gem*& selected, Gem*& swiped, SwipeState& state, GEMS_ARRAY& gems)
	: mSelectedGem(selected)
	, mSwipedGem(swiped)
	, mState(state)
	, mGems(gems)
{
}

bool SwipeGemsCommand::Execute()
{
	bool isSuccess = true;
	INDEX index = mSelectedGem->GetIndex();

	if (mState.IsRight() && index.second < Config::BOARD_WIDTH - 1)
	{
		SwipeGems(mGems[index.first][index.second + 1]);
	}
	else if (mState.IsLeft() && index.second > 0)
	{
		SwipeGems(mGems[index.first][index.second - 1]);
	}
	else if (mState.IsUp() && index.first < Config::BOARD_HEIGHT - 1)
	{
		SwipeGems(mGems[index.first + 1][index.second]);
	}
	else if (mState.IsDown() && index.first > 0)
	{
		SwipeGems(mGems[index.first - 1][index.second]);
	}
	else
	{
		isSuccess = false;
	}
	return isSuccess;
}

bool SwipeGemsCommand::UnExecute()
{
	Gem temp = *mSelectedGem;
	mSelectedGem->SetPosition(mSwipedGem->GetPosition());
	mSwipedGem->SetPosition(temp.GetPosition());
	SwipeGems(mSwipedGem);

	return true;
}

void SwipeGemsCommand::SwipeGems(Gem* next)
{
	Gem temp = *mSelectedGem;
	mSwipedGem = next;
	mSelectedGem->SetMovePosition(mSwipedGem->GetPosition());
	mSwipedGem->SetMovePosition(temp.GetPosition());

	mSelectedGem->Swipe(true);
	mSwipedGem->Swipe(true);
}