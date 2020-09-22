#pragma once
#include <king/Engine.h>

#include "Command.h"
#include "../Define.h"

class RenderBoardCommand : public Command
{
public:
	RenderBoardCommand(King::Engine* engine, TILES_ARRAY& tiles, GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	void RenderTiles();
	void RenderGems();

private:
	King::Engine* mEngine;
	TILES_ARRAY& mTiles;
	GEMS_ARRAY& mGems;
};
