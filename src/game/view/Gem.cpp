#include "Gem.h"

Gem::Gem(int width, int height, TEXTURE texture, TEXTURE aTexture)
	: Entity(width, height, texture)
	, mActiveTexture(aTexture)
	, mIsSelected(false)
	, mIsSwiped(false)
	, mIsSwapped(false)
	, mIsMatched(false)
	, mIsDropped(false)
{

}

void Gem::SetIndex(INDEX index)
{
	mColIndex = index.first;
	mRowIndex = index.second;
}