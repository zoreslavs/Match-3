#pragma once
#include <king/Engine.h>

#include "Command.h"
#include "../Define.h"

class CreateGemsCommand : public Command
{
public:
	CreateGemsCommand(King::Engine* engine, GEMS_ARRAY& gems, INDEX& offset);
	bool Execute() override;
	bool UnExecute() override;

private:
	King::Engine* mEngine;
	INDEX& mOffset;
	GEMS_ARRAY& mGems;
};
