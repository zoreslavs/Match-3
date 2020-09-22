#pragma once
#include "Command.h"
#include "../Define.h"
#include "../view/Gem.h"

class SelectGemCommand : public Command
{
public:
	SelectGemCommand(Gem*& selected);
	SelectGemCommand(Gem*& selected, GEMS_ARRAY& gems, POSITION& mousePos);
	bool Execute() override;
	bool UnExecute() override;

private:
	Gem*& mSelectedGem;
	POSITION mMousePos;
	GEMS_ARRAY mGems;
};