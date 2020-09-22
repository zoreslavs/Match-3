#include "DropGemsCommand.h"

DropGemsCommand::DropGemsCommand(std::set<Gem*>& movingGems, GEMS_ARRAY& gems)
	: mMovingGems(movingGems)
	, mGems(gems)
{
}

bool DropGemsCommand::Execute()
{
	bool isMoving = false;
	for (Gem* gem : mMovingGems)
	{
		if (gem->IsDropped())
		{
			isMoving = true;
			gem->SetPosition(std::make_pair(gem->GetPositionX(), gem->GetPositionY() + Config::GEM_DROP_SPEED));
			if (gem->GetPosition().second >= gem->GetMovePosition().second)
			{
				gem->SetPosition(gem->GetMovePosition());
				gem->Drop(false);
				gem->Swap(true);
			}
		}
	}

	return isMoving;
}

bool DropGemsCommand::UnExecute()
{
	return false;
}