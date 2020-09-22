#include <array>
#include <utility>

#include "CreateTilesCommand.h"

CreateTilesCommand::CreateTilesCommand(King::Engine* engine, TILES_ARRAY& tiles, INDEX& offset)
	: mEngine(engine)
	, mTiles(tiles)
	, mOffset(offset)
{
}

bool CreateTilesCommand::Execute()
{
	for (int i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		mTiles[i] = std::array<Tile*, Config::BOARD_WIDTH>();
		for (int j = 0; j < Config::BOARD_WIDTH; j++)
		{
			Tile* tile = new Tile(Config::TILE_WIDTH, Config::TILE_HEIGHT, King::Engine::TEXTURE_TILE);
			
			int posX = j * Config::TILE_WIDTH + mOffset.first;
			int posY = i * Config::TILE_HEIGHT + mOffset.second;
			tile->SetPosition(std::make_pair(posX, posY));

			mTiles[i][j] = tile;
		}
	}
	return true;
}

bool CreateTilesCommand::UnExecute()
{
	return true;
}
