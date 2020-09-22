#include "Match3Game.h"

Match3Game::Match3Game()
	: mEngine("./assets")
	, mBoard(&mEngine, &mData)
	, mInfoPanel(&mEngine, &mData)
	, mGameOverPopup(nullptr)
	, mSwipeController(&mEngine, &mBoard)
	, mRenderController(&mEngine, &mBoard, &mInfoPanel)
{
	mTimeController = TimeController(&mData, std::bind(&Match3Game::OnTimeOut, this));
}

void Match3Game::Start()
{
	mTimeController.StartTimer();
	mEngine.Start(*this);
}

void Match3Game::Update()
{
	mRenderController.Update();

	if (mGameOverPopup)
		mGameOverPopup->Update();
	else 
		mSwipeController.Update();
}

void Match3Game::OnTimeOut()
{
	mBoard.GameOver();
	ShowGameOverPopup();
}

void  Match3Game::ShowGameOverPopup()
{
	std::function<void()> restart = std::bind(&Match3Game::OnRestart, this);
	std::function<void()> exit = std::bind(&Match3Game::OnExit, this);
	mGameOverPopup = new GameOverPopup(&mEngine, &mData, restart, exit);
}

void Match3Game::OnRestart()
{
	mData.Reset();
	mBoard.Reset();
	mSwipeController.Reset();

	delete mGameOverPopup;
	mGameOverPopup = nullptr;

	mTimeController.StartTimer();
}

void Match3Game::OnExit()
{
	mEngine.Quit();
}