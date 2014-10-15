#include "Slime.h"

char* Slime::ENEMY_SLIME_SPRITEID = "./images/platformerArt_v4/png/enemies/slime_normal.png";
const float Slime::ENEMY_SLIME_X_START = 600;
const float Slime::ENEMY_SLIME_Y_START = 150;
const float Slime::ENEMY_SLIME_WIDTH = 42;
const float Slime::ENEMY_SLIME_HEIGTH = 28;

Slime::Slime()
{
	SetX(ENEMY_SLIME_X_START);
	SetY(ENEMY_SLIME_Y_START);
	SetWidth(ENEMY_SLIME_WIDTH);
	SetHeigth(ENEMY_SLIME_HEIGTH);
	SetSpriteID(ENEMY_SLIME_SPRITEID);
	SetCorners();
}


Slime::~Slime()
{
}
