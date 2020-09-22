#pragma once
#include <set>

#include "Command.h"
#include "../Define.h"

class DropGemsCommand : public Command
{
public:
	DropGemsCommand(std::set<Gem*>& movingGems, GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	std::set<Gem*>& mMovingGems;
	GEMS_ARRAY& mGems;
};