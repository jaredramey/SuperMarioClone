#include "Fly.h"

char* Fly::ENEMY_FLY_SPRITEID = "./images/platformerArt_v4/png/enemies/fly_normal.png";
const float Fly::ENEMY_FLY_X_START = 1000;
const float Fly::ENEMY_FLY_Y_START = 150;
const float Fly::ENEMY_FLY_WIDTH = 69;
const float Fly::ENEMY_FLY_HEIGTH = 31;

Fly::Fly()
{
	SetX(ENEMY_FLY_X_START);
	SetY(ENEMY_FLY_Y_START);
	SetWidth(ENEMY_FLY_WIDTH);
	SetHeigth(ENEMY_FLY_HEIGTH);
	SetSpriteID(ENEMY_FLY_SPRITEID);
	SetCorners();
}


Fly::~Fly()
{
}
