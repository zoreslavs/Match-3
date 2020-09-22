#pragma once
#include "Command.h"
#include "../Define.h"
#include "../view/Gem.h"
#include "../state/SwipeState.h"

class SwipeGemsCommand : public Command
{
public:
	SwipeGemsCommand(Gem*& selected, Gem*& swiped, SwipeState& state, GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	void SwipeGems(Gem* next);

private:
	Gem*& mSelectedGem;
	Gem*& mSwipedGem;
	SwipeState& mState;
	GEMS_ARRAY& mGems;
};