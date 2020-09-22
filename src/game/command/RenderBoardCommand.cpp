#include <array>
#include <utility>

#include "RenderBoardCommand.h"

RenderBoardCommand::RenderBoardCommand(King::Engine* engine,
	TILES_ARRAY& tiles,
	GEMS_ARRAY& gems)
	: mEngine(engine)
	, mTiles(tiles)
	, mGems(gems)
{
}

bool RenderBoardCommand::Execute()
{
	RenderTiles();
	RenderGems();

	return true;
}

bool RenderBoardCommand::UnExecute()
{
	return true;
}

void RenderBoardCommand::RenderTiles()
{
	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Tile* tile = mTiles[i][j];
			mEngine->Render(tile->GetTexture(), tile->GetPositionX(), tile->GetPositionY());
		}
	}
}

void RenderBoardCommand::RenderGems()
{
	for (size_t i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Gem* gem = mGems[i][j];

			TEXTURE texture = (gem->IsSelected()) ? gem->GetActiveTexture() : gem->GetTexture();
			mEngine->Render(texture, gem->GetPositionX(), gem->GetPositionY());
		}
	}
}
