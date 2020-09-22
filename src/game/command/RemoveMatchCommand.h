#pragma once
#include <set>

#include "Command.h"
#include "../Define.h"
#include "../GameData.h"
#include "../view/Gem.h"

class RemoveMatchCommand : public Command
{
public:
	RemoveMatchCommand(GameData* data, std::set<Gem*>& movingGems, GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	void CheckColMatchedGems(Gem* matchedGem);
	void ShiftColGemTextures(INDEX index, int counter);
	void AddNewColGemTextures(INDEX index, int counter);
	void MoveColGemTextures(INDEX index, int counter);

private:
	GameData* mData;
	std::set<Gem*>& mMovingGems;
	GEMS_ARRAY& mGems;
};