#pragma once
#include <utility>
#include <king/Engine.h>

#define INDEX std::pair<int, int>
#define POSITION std::pair<float, float>
#define TEXTURE King::Engine::Texture

class Entity
{
public:
	Entity(int width, int height, TEXTURE texture);

	void SetTexture(TEXTURE texture) { mTexture = texture; }
	TEXTURE GetTexture() const { return mTexture; }

	void SetPosition(POSITION pos);
	POSITION GetPosition() const { return std::make_pair(mPosX, mPosY); }
	float GetPositionX() const { return mPosX; }
	float GetPositionY() const { return mPosY; }

	void SetWidth(int width) { mWidth = width; }
	int GetWidth() const { return mWidth; }

	void SetHeight(int height) { mHeight = height;}
	int GetHeight() const { return mHeight; }

private:
	TEXTURE mTexture;
	float mPosX;
	float mPosY;
	int mWidth;
	int mHeight;
};
