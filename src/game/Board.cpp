#include <iostream>

#include "Board.h"
#include "Helper.h"

#include "command/CreateTilesCommand.h"
#include "command/CreateGemsCommand.h"
#include "command/SelectGemCommand.h"
#include "command/SwipeGemsCommand.h"
#include "command/MoveGemsCommand.h"
#include "command/FindMatchCommand.h"
#include "command/SwapGemsCommand.h"
#include "command/RemoveMatchCommand.h"
#include "command/ResetGemsCommand.h"

Board::Board(King::Engine* engine, GameData* data)
	: mEngine(engine)
	, mData(data)
	, mMovingGems({})
	, mSelectedGem(nullptr)
	, mSwipedGem(nullptr)
	, mRenderBoardCmd(nullptr)
	, mDropGemsCmd(nullptr)
{
	InitBoard();
}

void Board::InitBoard()
{
	int offsetX = int((mEngine->GetWidth() - Config::TILE_WIDTH * Config::BOARD_WIDTH) * 0.75);
	int offsetY = int((mEngine->GetHeight() - Config::TILE_HEIGHT * Config::BOARD_HEIGHT) * 0.5);
	mOffset = std::make_pair(offsetX, offsetY);

	CreateTilesCommand createTiles(mEngine, mTiles, mOffset);
	createTiles.Execute();

	CreateGemsCommand createGems(mEngine, mGems, mOffset);
	createGems.Execute();

	mRenderBoardCmd = new RenderBoardCommand(mEngine, mTiles, mGems);
	mDropGemsCmd = new DropGemsCommand(mMovingGems, mGems);

	mBoardState.SetNormal();
	mSwipeState.SetNone();
}

void Board::Update()
{
	mRenderBoardCmd->Execute();

	if (!mBoardState.IsOver())
		CheckMovingGems();
}

void Board::CheckMovingGems()
{
	if (mBoardState.IsMove() || mBoardState.IsMoveBack())
	{
		MoveGems();
	}
	else if (mBoardState.IsDrop())
	{
		DropGems();
	}
}

void Board::SelectGem(POSITION mousePos)
{
	if (!mBoardState.IsNormal())
		return;

	SelectGemCommand command(mSelectedGem, mGems, mousePos);
	command.Execute();
}

void Board::DeselectGem()
{
	SelectGemCommand command(mSelectedGem);
	command.UnExecute();
}

void Board::DoSwipe(SwipeState::State state)
{
	if (!mBoardState.IsNormal() || state == SwipeState::State::NONE || !mSelectedGem)
		return;

	mSwipeState.SetState(state);
	SwipeGemsCommand command(mSelectedGem, mSwipedGem, mSwipeState, mGems);
	bool isSuccess = command.Execute();
	if (isSuccess)
		mBoardState.SetMove();
	DeselectGem();
}

bool Board::FindMatches()
{
	FindMatchCommand command(mGems);
	bool isSuccess = command.Execute();

	if (isSuccess)
		RemoveMatches();

	return isSuccess;
}

void Board::RemoveMatches()
{
	RemoveMatchCommand command(mData, mMovingGems, mGems);
	bool isSuccess = command.Execute();

	if (isSuccess)
		mBoardState.SetDrop();
}

void Board::MoveGems()
{
	MoveGemsCommand command((mBoardState.IsMove()) ? mSelectedGem : mSwipedGem, 
							(mBoardState.IsMove()) ? mSwipedGem : mSelectedGem, 
							mSwipeState);

	if (command.Execute())
		return;

	if (mBoardState.IsMove())
	{
		Gem temp = *mSelectedGem;
		mSelectedGem->SetPosition(mSwipedGem->GetPosition());
		mSwipedGem->SetPosition(temp.GetPosition());

		SwapGemsCommand command(mSelectedGem, mSwipedGem);
		command.Execute();

		if (!FindMatches())
		{
			command.UnExecute();
			SwipeGemsCommand command(mSelectedGem, mSwipedGem, mSwipeState, mGems);
			command.UnExecute();

			mBoardState.SetMoveBack();
		}
	}
	else if (mBoardState.IsMoveBack())
	{
		mBoardState.SetNormal();
	}
}

void Board::DropGems()
{
	bool isSuccess = mDropGemsCmd->Execute();
	if (!isSuccess)
	{
		mBoardState.SetNormal();
		mMovingGems.clear();

		FindMatches();
	}
}

void Board::GameOver()
{
	mBoardState.SetOver();
	mSwipeState.SetNone();
}

void Board::Reset()
{
	mBoardState.SetNormal();

	ResetGemsCommand command(mGems);
	command.Execute();
}