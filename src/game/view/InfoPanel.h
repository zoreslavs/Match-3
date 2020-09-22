#pragma once
#include <king/Engine.h>
#include "../GameData.h"

class InfoPanel
{
public:
	InfoPanel(King::Engine* engine, GameData* data);
	void Update();
	void UpdateMatchedScore();

private:
	King::Engine* mEngine;
	GameData* mData;
};
