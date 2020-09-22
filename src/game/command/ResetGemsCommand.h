#pragma once
#include "Command.h"
#include "../Define.h"

class ResetGemsCommand : public Command
{
public:
	ResetGemsCommand(GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	GEMS_ARRAY& mGems;
};