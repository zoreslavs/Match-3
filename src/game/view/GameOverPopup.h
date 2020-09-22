#pragma once
#include <functional>

#include <king/Engine.h>
#include "../GameData.h"

class GameOverPopup
{
public:
	GameOverPopup::GameOverPopup(King::Engine* engine, GameData* data, std::function<void()> restart, std::function<void()> exit);
	void Update();

private:
	void RenderScreen();
	void CheckButtonClick();

private:
	King::Engine* mEngine;
	GameData* mData;
	std::function<void(void)> mRestartCallback;
	std::function<void(void)> mExitCallback;

	int mBtnWidth;
	int mBtnHeight;
	float mBtnLeftPosX;
	float mBtnRightPosX;
	float mBtnPosY;
	bool mIsMouseDown;
};
