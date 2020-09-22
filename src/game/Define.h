#pragma once
#include "view/Gem.h"
#include "view/Tile.h"
#include "Config.h"

#define GEMS_ARRAY std::array<std::array<Gem*, Config::BOARD_WIDTH>, Config::BOARD_HEIGHT>
#define TILES_ARRAY std::array<std::array<Tile*, Config::BOARD_WIDTH>, Config::BOARD_HEIGHT>