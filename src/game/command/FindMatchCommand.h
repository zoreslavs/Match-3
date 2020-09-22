#pragma once
#include <vector>

#include "Command.h"
#include "../Define.h"
#include "../view/Gem.h"

class FindMatchCommand : public Command
{
public:
	FindMatchCommand(GEMS_ARRAY& gems);
	bool Execute() override;
	bool UnExecute() override;

private:
	void FindHorizontal(INDEX index, int texture);
	void FindVertical(INDEX index, int texture);
	void MarkMatched(std::vector<Gem*>& temp);

private:
	bool mIsMatched;
	GEMS_ARRAY& mGems;
};