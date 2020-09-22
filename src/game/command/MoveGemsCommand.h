#pragma once

#include "Command.h"
#include "../view/Gem.h"
#include "../state/SwipeState.h"

class MoveGemsCommand : public Command
{
public:
	MoveGemsCommand(Gem* selected, Gem* swiped, SwipeState& state);
	bool Execute() override;
	bool UnExecute() override;

private:
	void StopMoving();

private:
	Gem* mSelectedGem;
	Gem* mSwipedGem;
	SwipeState& mState;
};