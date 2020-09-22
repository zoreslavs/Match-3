#include <array>
#include <utility>
#include <ctime>
#include <cstdlib>

#include "CreateGemsCommand.h"
#include "../Helper.h"

CreateGemsCommand::CreateGemsCommand(King::Engine* engine, GEMS_ARRAY& gems, INDEX& offset)
	: mEngine(engine)
	, mOffset(offset)
	, mGems(gems)
{
}

bool CreateGemsCommand::Execute()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < Config::BOARD_HEIGHT; i++)
	{
		mGems[i] = std::array<Gem*, Config::BOARD_WIDTH>();
		for (int j = 0; j < Config::BOARD_WIDTH; j++)
		{
			INDEX textures = Helper::GetRandomGemTexture(mGems, i, j);
			TEXTURE texture = static_cast<TEXTURE>(textures.first);
			TEXTURE aTexture = static_cast<TEXTURE>(textures.second);
			Gem* gem = new Gem(mEngine->GetTextureWidth(texture), mEngine->GetTextureHeight(texture), texture, aTexture);
			gem->SetIndex(std::make_pair(i, j));

			float posX = j * Config::TILE_WIDTH + (Config::TILE_WIDTH - gem->GetWidth()) * 0.5f + mOffset.first;
			float posY = i * Config::TILE_HEIGHT + (Config::TILE_HEIGHT - gem->GetHeight()) * 0.5f + mOffset.second;
			gem->SetPosition(std::make_pair(posX, posY));
			gem->SetInitPosition(std::make_pair(posX, posY));
			gem->SetScore(Config::GEM_SCORE);

			mGems[i][j] = gem;
		}
	}

	return true;
}

bool CreateGemsCommand::UnExecute()
{
	return true;
}