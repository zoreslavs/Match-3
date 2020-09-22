#pragma once
struct Config
{
	static const size_t BOARD_WIDTH = 8;
	static const size_t BOARD_HEIGHT = 8;
	static const size_t TILE_WIDTH = 50;
	static const size_t TILE_HEIGHT = 50;
	static const size_t NUM_COLORS = 5;
	static const size_t NUM_ELEMENTS = BOARD_WIDTH * BOARD_HEIGHT;
	static const size_t MIN_SWIPE_DISTANCE = 25;
	static const size_t TOTAL_TIME = 60;

	static const int GEM_MOVE_SPEED = 5;
	static const int GEM_DROP_SPEED = 5;
	static const int GEM_SCORE = 10;
};