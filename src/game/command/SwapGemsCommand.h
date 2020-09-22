#pragma once
#include "Command.h"
#include "../view/Gem.h"

class SwapGemsCommand : public Command
{
public:
	SwapGemsCommand(Gem*& selected, Gem*& swiped);
	bool Execute() override;
	bool UnExecute() override;

private:
	Gem*& mSelectedGem;
	Gem*& mSwipedGem;
};
