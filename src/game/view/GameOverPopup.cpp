#include <string>

#include "GameOverPopup.h"
#include "../Helper.h"

GameOverPopup::GameOverPopup(King::Engine* engine, GameData* data, std::function<void()> restart, std::function<void()> exit)
	: mEngine(engine)
	, mData(data)
	, mRestartCallback(restart)
	, mExitCallback(exit)
	, mBtnWidth(0)
	, mBtnHeight(0)
	, mBtnLeftPosX(0)
	, mBtnRightPosX(0)
	, mBtnPosY(0)
	, mIsMouseDown(false)
{
}

void GameOverPopup::Update()
{
	RenderScreen();
	CheckButtonClick();
}

void GameOverPopup::RenderScreen()
{
	mEngine->Render(King::Engine::TEXTURE_BG_SHADOW, 0.f, 0.f);

	int bgWidth = mEngine->GetTextureWidth(King::Engine::TEXTURE_BG_POPUP);
	int bgHeight = mEngine->GetTextureHeight(King::Engine::TEXTURE_BG_POPUP);
	float bgPosX = (mEngine->GetWidth() - bgWidth) * 0.5f;
	float bgPosY = (mEngine->GetHeight() - bgHeight) * 0.5f;
	mEngine->Render(King::Engine::TEXTURE_BG_POPUP, bgPosX, bgPosY);

	mEngine->Write("GAME OVER", bgPosX + 110.f, bgPosY + 50.f);

	std::string scoreStr = "Your score : " + std::to_string(mData->GetScore());
	mEngine->Write(scoreStr.c_str(), bgPosX + 100.f, bgPosY + 130.f);

	float btnOffsetX = 20.f;
	mBtnWidth = mEngine->GetTextureWidth(King::Engine::TEXTURE_BUTTON);
	mBtnHeight = mEngine->GetTextureHeight(King::Engine::TEXTURE_BUTTON);
	mBtnLeftPosX = bgPosX + btnOffsetX;
	mBtnRightPosX = bgPosX + bgWidth - mBtnWidth - btnOffsetX;
	mBtnPosY = bgPosY + 220.f;
	mEngine->Render(King::Engine::TEXTURE_BUTTON, mBtnLeftPosX, mBtnPosY);
	mEngine->Render(King::Engine::TEXTURE_BUTTON, mBtnRightPosX, mBtnPosY);

	mEngine->Write("Restart", mBtnLeftPosX + 25.f, mBtnPosY + 7.f);
	mEngine->Write("Exit", mBtnRightPosX + 47.f, mBtnPosY + 7.f);
}

void GameOverPopup::CheckButtonClick()
{
	if (!mIsMouseDown && mEngine->GetMouseButtonDown())
	{
		mIsMouseDown = true;

		bool isRestart = Helper::IsPointInsideRectangle(
			mBtnLeftPosX, 
			mBtnPosY, 
			mBtnLeftPosX + mBtnWidth, 
			mBtnPosY + mBtnHeight, 
			mEngine->GetMouseX(), 
			mEngine->GetMouseY());

		if (isRestart)
		{
			mRestartCallback();
			return;
		}

		bool isExit = Helper::IsPointInsideRectangle(
			mBtnRightPosX, 
			mBtnPosY, 
			mBtnRightPosX + mBtnWidth, 
			mBtnPosY + mBtnHeight, 
			mEngine->GetMouseX(), 
			mEngine->GetMouseY());

		if (isExit)
		{
			mExitCallback();
			return;
		}

		mIsMouseDown = false;
	}
}