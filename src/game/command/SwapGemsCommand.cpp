#include "SwapGemsCommand.h"

SwapGemsCommand::SwapGemsCommand(Gem*& selected, Gem*& swiped)
	: mSelectedGem(selected)
	, mSwipedGem(swiped)
{
}

bool SwapGemsCommand::Execute()
{
	Gem temp = *mSelectedGem;
	mSelectedGem->SetTexture(mSwipedGem->GetTexture());
	mSelectedGem->SetActiveTexture(mSwipedGem->GetActiveTexture());
	mSwipedGem->SetTexture(temp.GetTexture());
	mSwipedGem->SetActiveTexture(temp.GetActiveTexture());

	mSelectedGem->Swap(true);
	mSwipedGem->Swap(true);

	return true;
}

bool SwapGemsCommand::UnExecute()
{
	return Execute();
}