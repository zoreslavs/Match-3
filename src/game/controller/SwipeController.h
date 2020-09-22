#pragma once
#include <king/Engine.h>

#include "../Board.h"

class SwipeController
{
public:
	SwipeController(King::Engine* engine, Board* board);
	void Update();
	void Reset();

private:
	void OnMouseDown();
	void OnMouseUp();
	void DoSwipe(float angle);

private:
	King::Engine* mEngine;
	Board* mBoard;
	POSITION mMouseDownPos;
	POSITION mMouseUpPos;
	bool mIsMouseDown;
};
