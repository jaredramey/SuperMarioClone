#include "Enemy.h"
#pragma once
class Slime: public Enemy
{
public:
	Slime();
	~Slime();

	static char* ENEMY_SLIME_SPRITEID;
	static const float ENEMY_SLIME_X_START;
	static const float ENEMY_SLIME_Y_START;
	static const float ENEMY_SLIME_WIDTH;
	static const float ENEMY_SLIME_HEIGTH;
};

