#include <utility>

#include "MoveGemsCommand.h"
#include "../Config.h"

MoveGemsCommand::MoveGemsCommand(Gem* selected, Gem* swiped, SwipeState& state)
	: mSelectedGem(selected)
	, mSwipedGem(swiped)
	, mState(state)
{
}

bool MoveGemsCommand::Execute()
{
	bool isMoving = false;
	bool isCondition = false;
	int moveSpeed = (mState.IsRight() || mState.IsDown()) ? Config::GEM_MOVE_SPEED : -Config::GEM_MOVE_SPEED;

	POSITION selectedPos = mSelectedGem->GetPosition();
	POSITION swipedPos = mSwipedGem->GetPosition();
	if (mState.IsRight() || mState.IsLeft())
	{
		isCondition = (mState.IsRight()) ? selectedPos.first < mSelectedGem->GetMovePosition().first :
											selectedPos.first > mSelectedGem->GetMovePosition().first;
		if (isCondition)
		{
			isMoving = true;
			mSelectedGem->SetPosition(std::make_pair(selectedPos.first + moveSpeed, selectedPos.second));
			mSwipedGem->SetPosition(std::make_pair(swipedPos.first - moveSpeed, swipedPos.second));
		}
		else
		{
			StopMoving();
		}
	}
	else if (mState.IsUp() || mState.IsDown())
	{
		isCondition = (mState.IsUp()) ? selectedPos.second < mSelectedGem->GetMovePosition().second :
										selectedPos.second > mSelectedGem->GetMovePosition().second;
		if (isCondition)
		{
			isMoving = true;
			mSelectedGem->SetPosition(std::make_pair(selectedPos.first, selectedPos.second - moveSpeed));
			mSwipedGem->SetPosition(std::make_pair(swipedPos.first, swipedPos.second + moveSpeed));
		}
		else
		{
			StopMoving();
		}
	}

	return isMoving;
}

bool MoveGemsCommand::UnExecute()
{
	return false;
}

void MoveGemsCommand::StopMoving()
{
	mSelectedGem->SetPosition(mSelectedGem->GetMovePosition());
	mSwipedGem->SetPosition(mSwipedGem->GetMovePosition());

	mSelectedGem->Swipe(false);
	mSwipedGem->Swipe(false);
}
