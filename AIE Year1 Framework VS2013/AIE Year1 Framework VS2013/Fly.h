#include "Enemy.h"
#pragma once


class Fly: public Enemy
{
public:
	Fly();
	~Fly();

	static char* ENEMY_FLY_SPRITEID;
	static const float ENEMY_FLY_X_START;
	static const float ENEMY_FLY_Y_START;
	static const float ENEMY_FLY_WIDTH;
	static const float ENEMY_FLY_HEIGTH;
};

