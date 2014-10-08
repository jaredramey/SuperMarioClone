#include "Collision.h"


Collision::Collision()
{
}

bool Collision::CheckCollision(float x1, float x2, float y1, float y2, float width1, float heigth1, float width2, float heigth2)
{
	if (((x2 + width2) - (x1 + width1)) < 0 && ((y2 + heigth2) - (y1 + heigth1)) < 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}


Collision::~Collision()
{
}
