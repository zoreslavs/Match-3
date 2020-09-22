#include <cmath>
#include <array>
#include <utility>
#include <king/Engine.h>

#include "Helper.h"

float Helper::GetDistance(float x1, float y1, float x2, float y2)
{
	return float(std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0));
}

float Helper::GetAngle(float x1, float y1, float x2, float y2)
{
	return float(atan2(y2 - y1, x2 - x1) * 180 / (std::atan(1) * 4));
}

bool Helper::IsPointInsideRectangle(float x1, float y1, float x2, float y2, float x, float y)
{
	if (x > x1 && x < x2 && y > y1 && y < y2)
		return true;

	return false;
}

INDEX Helper::GetRandomGemTexture(GEMS_ARRAY& gems, int i, int j)
{
	int texture;
	int activeTexture;
	do
	{
		int randTexture = (rand() % Config::NUM_COLORS);
		texture = int(randTexture + King::Engine::TEXTURE_GEM_FIRST);
		activeTexture = int(randTexture + King::Engine::TEXTURE_GEM_LAST);
	} 
	while ((i >= 2 && gems[i - 1][j]->GetTexture() == texture && gems[i - 2][j]->GetTexture() == texture) ||
			 (j >= 2 && gems[i][j - 1]->GetTexture() == texture && gems[i][j - 2]->GetTexture() == texture));

	return std::make_pair(texture, activeTexture);
}

std::string Helper::GetTimeString(int seconds)
{
	bool neg = seconds < 0;
	if (neg)
		seconds = -seconds;
	int m = seconds / 60;
	seconds -= m * 60;
	std::string result;
	if (neg)
		result.push_back('00');
	if (m < 10)
		result.push_back('0');
	result += std::to_string(m / 1);
	result += ':';
	if (seconds < 10)
		result.push_back('0');
	result += std::to_string(seconds / 1);

	return result;
}