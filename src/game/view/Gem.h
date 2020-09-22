#pragma once
#include "Entity.h"

class Gem : public Entity
{
public:
	Gem(int width, int height, TEXTURE texture, TEXTURE aTexture);

	void SetIndex(INDEX index);
	INDEX GetIndex() const { return std::make_pair(mColIndex, mRowIndex); }

	void SetActiveTexture(TEXTURE texture) { mActiveTexture = texture; }
	TEXTURE GetActiveTexture() const { return mActiveTexture; }

	void SetInitPosition(POSITION pos) { mInitPosition = pos; }
	POSITION GetInitPosition() const { return mInitPosition; }

	void SetMovePosition(POSITION pos) { mMovePosition = pos; }
	POSITION GetMovePosition() const { return mMovePosition; }

	void SetScore(int score) { mScore = score; }
	int GetScore() const { return mScore; }

	void Select(bool value) { mIsSelected = value; }
	bool IsSelected() const { return mIsSelected; }

	void Swipe(bool value) { mIsSwiped = value; }
	bool IsSwiped() const { return mIsSwiped; }

	void Swap(bool value) { mIsSwapped = value; }
	bool IsSwapped() const { return mIsSwapped; }

	void Match(bool value) { mIsMatched = value; }
	bool IsMatched() const { return mIsMatched; }

	void Drop(bool value) { mIsDropped = value; }
	bool IsDropped() const { return mIsDropped; }

private:
	TEXTURE mActiveTexture;
	POSITION mMovePosition;
	POSITION mInitPosition;
	int mRowIndex;
	int mColIndex;
	int mScore;
	float mMovePosX;
	float mMovePosY;
	bool mIsSelected;
	bool mIsSwiped;
	bool mIsSwapped;
	bool mIsMatched;
	bool mIsDropped;
};
