#pragma once
#include <king/Engine.h>

#include "Command.h"
#include "../Define.h"

class CreateTilesCommand : public Command
{
public:
	CreateTilesCommand(King::Engine* engine, TILES_ARRAY& tiles, INDEX& offset);
	bool Execute() override;
	bool UnExecute() override;

private:
	King::Engine* mEngine;
	INDEX& mOffset;
	TILES_ARRAY& mTiles;
};
