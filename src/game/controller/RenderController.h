#pragma once
#include <king/Engine.h>

#include "../Board.h"
#include "../view/InfoPanel.h"

class RenderController
{
public:
	RenderController(King::Engine* engine, Board* board, InfoPanel* info);
	void Update();

private:
	King::Engine* mEngine;
	Board* mBoard;
	InfoPanel* mInfoPanel;
};