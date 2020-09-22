#pragma once

class SwipeState
{
public:
	enum State
	{
		NONE,
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

public:
	SwipeState();

	void SetNone() { mState = State::NONE; }
	void SetRight() { mState = State::RIGHT; }
	void SetLeft() { mState = State::LEFT; }
	void SetUp() { mState = State::UP; }
	void SetDown() { mState = State::DOWN; }

	bool IsNone() const { return mState == State::NONE; }
	bool IsRight() const { return mState == State::RIGHT; }
	bool IsLeft() const { return mState == State::LEFT; }
	bool IsUp() const { return mState == State::UP; }
	bool IsDown() const { return mState == State::DOWN; }

	void SetState(State state) { mState = state; }
	State GetState() const { return mState; }

private:
	State mState;
};
