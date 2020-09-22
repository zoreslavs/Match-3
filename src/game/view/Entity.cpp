#include "Entity.h"

Entity::Entity(int width, int height, TEXTURE texture)
	: mWidth(width)
	, mHeight(height)
	, mTexture(texture)
{
}

void Entity::SetPosition(POSITION pos)
{
	mPosX = pos.first;
	mPosY = pos.second;
}
