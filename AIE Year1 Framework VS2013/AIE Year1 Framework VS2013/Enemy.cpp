#include "Enemy.h"


Enemy::Enemy()
{
}

void Enemy::Move(float a_timeStep, float a_speed, bool direction)
{
	bool left;
	bool right;

	if (direction == true)
	{
		left = true;
	}

	if (left == true)
	{
		ChangeX(.75f, 2);
	}
}

Enemy::~Enemy()
{
}
