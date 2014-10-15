#include "Collision.h"


Collision::Collision()
{
}

bool Collision::CheckCollision(float x1, float x2, float y1, float y2, float x3, float x4, float y3, float y4)
{
	//x1 = playerLeftCornerX, x2 = otherEntityLeftCornerX, x3 = playerRightCornerX, x4 = otherEntityRightCornerX
	//y1 = playerLeftCornerY, y2 = otherEntityLeftCornerY, y3 = playerRightCorneryY, y4 = otherEntityRightCornerY
	//old no collision check: x1 > (x2+width2) &&  x1 < (x2-width2)
	//new no collision check: ((x1 > x2 && x3 > x4) && (y1 > y2 && y3 < y4))
	if ((x1 < x2 && x3 > x4) && (y1 > y2 && y3 > y4))
	{
		return false;
	}

	//x1 = playerLeftCornerX, x2 = otherEntityLeftCornerX, x3 = playerRightCornerX, x4 = otherEntityRightCornerX
	//y1 = playerLeftCornerY, y2 = otherEntityLeftCornerY, y3 = playerRightCorneryY, y4 = otherEntityRightCornerY
	//old collision: ((x2 + width2) - (x1 + width1)) < 0 && ((y1 - (heigth1*.5f)) - (y2 + (heigth2*.5f))) < 0
	//new collision: ((x1 <= x2 && x3 <= x4) && (y1 <= y2 && y3 >= y4)) 
	if (/*(x1 >= x2) &&*/ (x3 >= x4) && (y1 <= y2 && y3 <= y4))
	{
		return true;
	}
}


Collision::~Collision()
{
}
