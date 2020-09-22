#pragma once
#include <string>

#include "Define.h"
#include "view/Gem.h"

class Helper
{
public:
	static float GetDistance(float x1, float y1, float x2, float y2);
	static float GetAngle(float x1, float y1, float x2, float y2);
	static bool IsPointInsideRectangle(float x1, float y1, float x2, float y2, float x, float y);
	static INDEX GetRandomGemTexture(GEMS_ARRAY& gems, int i, int j);
	static std::string Helper::GetTimeString(int seconds);
};
