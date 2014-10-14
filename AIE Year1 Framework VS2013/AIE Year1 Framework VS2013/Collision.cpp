#include "Collision.h"


Collision::Collision()
{
}

bool Collision::CheckCollision(float x1, float x2, float y1, float y2, float width1, float heigth1, float width2, float heigth2)
{
	if (x1 > (x2+width2) &&  x1 < (x2-width2))
	{
		return false;
	}

	if (((x2 + width2) - (x1 + width1)) < 0 && ((y1 - (heigth1*.5f)) - (y2 + (heigth2*.5f))) < 0)
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
