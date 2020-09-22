#include "SwipeController.h"

#include "../state/SwipeState.h"
#include "../Helper.h"

SwipeController::SwipeController(King::Engine* engine, Board* board)
	: mEngine(engine)
	, mBoard(board)
{
}

void SwipeController::Update()
{
	if (mEngine->GetMouseButtonDown())
		OnMouseDown();
	else
		OnMouseUp();
}

void SwipeController::Reset()
{
	mIsMouseDown = false;
}

void SwipeController::OnMouseDown()
{
	if (mIsMouseDown)
		return;

	mIsMouseDown = true;
	mMouseDownPos = std::make_pair(mEngine->GetMouseX(), mEngine->GetMouseY());

	mBoard->SelectGem(mMouseDownPos);
}

void SwipeController::OnMouseUp()
{
	if (!mIsMouseDown)
		return;

	mIsMouseDown = false;
	mMouseUpPos = std::make_pair(mEngine->GetMouseX(), mEngine->GetMouseY());

	float distance = Helper::GetDistance(mMouseDownPos.first, mMouseDownPos.second, mMouseUpPos.first, mMouseUpPos.second);
	if (distance > Config::MIN_SWIPE_DISTANCE)
	{
		DoSwipe(Helper::GetAngle(mMouseDownPos.first, mMouseDownPos.second, mMouseUpPos.first, mMouseUpPos.second));
	}
	else
	{
		mBoard->DeselectGem();
	}
}

void SwipeController::DoSwipe(float angle)
{
	SwipeState::State state = SwipeState::State::NONE;
	if (angle > -45 && angle <= 45)
		state = SwipeState::State::RIGHT;
	else if (angle > 45 && angle <= 135)
		state = SwipeState::State::UP;
	else if (angle > 135 || angle <= -135)
		state = SwipeState::State::LEFT;
	else if (angle < -45 && angle >= -135)
		state = SwipeState::State::DOWN;

	mBoard->DoSwipe(state);
}