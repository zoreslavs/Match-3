#pragma once

#include <king/Engine.h>
#include <king/Updater.h>

#include "Board.h"
#include "GameData.h"
#include "view/InfoPanel.h"
#include "view/GameOverPopup.h"
#include "controller/TimeController.h"
#include "controller/SwipeController.h"
#include "controller/RenderController.h"

class Match3Game : public King::Updater
{
public:
	Match3Game();
	void Start();
	void Update();

private:
	void OnTimeOut();
	void ShowGameOverPopup();
	void OnRestart();
	void OnExit();

private:
	King::Engine mEngine;
	Board mBoard;
	GameData mData;
	InfoPanel mInfoPanel;
	GameOverPopup* mGameOverPopup;
	TimeController mTimeController;
	SwipeController mSwipeController;
	RenderController mRenderController;
};
