#pragma once

class BoardState
{
public:
    enum State
    {
        NORMAL,
        OVER,
        MOVE,
        MOVE_BACK,
        DROP
    };
    
public:
	BoardState();

	void SetNormal() { mState = State::NORMAL; }
	void SetOver() { mState = State::OVER; }
	void SetMove() { mState = State::MOVE; }
	void SetMoveBack() { mState = State::MOVE_BACK; }
	void SetDrop() { mState = State::DROP; }

	bool IsNormal() const { return mState == State::NORMAL; }
	bool IsOver() const { return mState == State::OVER; }
	bool IsMove() const { return mState == State::MOVE; }
	bool IsMoveBack() const { return mState == State::MOVE_BACK; }
	bool IsDrop() const { return mState == State::DROP; }

private:
	State mState;
};
