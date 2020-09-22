#pragma once

#include <set>
#include <array>
#include <utility>
#include <king/Engine.h>

#include "Define.h"
#include "GameData.h"
#include "view/Tile.h"
#include "view/Gem.h"
#include "state/BoardState.h"
#include "state/SwipeState.h"
#include "command/RenderBoardCommand.h"
#include "command/DropGemsCommand.h"

class Board
{
public:
	Board(King::Engine* engine, GameData* data);
	void Update();
	void SelectGem(POSITION mousePos);
	void DeselectGem();
	void DoSwipe(SwipeState::State state);
	void GameOver();
	void Reset();

	GEMS_ARRAY GetGems()& { return mGems; }

private:
	void InitBoard();
	bool FindMatches();
	void RemoveMatches();
	void CheckMovingGems();
	void MoveGems();
	void DropGems();

private:
	King::Engine* mEngine;
	GameData* mData;
	INDEX mOffset;
	std::set<Gem*> mMovingGems;
	Gem* mSelectedGem;
	Gem* mSwipedGem;
	BoardState mBoardState;
	SwipeState mSwipeState;
	RenderBoardCommand* mRenderBoardCmd;
	DropGemsCommand* mDropGemsCmd;

	TILES_ARRAY mTiles;
	GEMS_ARRAY mGems;
};