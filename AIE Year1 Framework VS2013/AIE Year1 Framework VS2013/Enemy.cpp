#include "Enemy.h"
#include "AIE.h"


Enemy::Enemy()
{
}

void Enemy::Move(float a_timeStep, bool collision, bool direction)
{
	bool left;
	bool right;

	if (direction == true)
	{
		left = true;
	}

	if (left == true)
	{
		ChangeX(.1f, 2);
	}

	if (collision == false)
	{
		ChangeY(0.3f, 2);
	}
}

Enemy::~Enemy()
{
}
