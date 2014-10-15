#include "Entity.h"
#pragma once



class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	void Move(float a_timeStep, float a_speed, bool direction);
};

