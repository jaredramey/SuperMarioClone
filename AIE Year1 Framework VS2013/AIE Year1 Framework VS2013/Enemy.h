#include "Entity.h"
#pragma once



class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	float velocity;

	void Move(float a_timeStep, bool collision, bool direction);
};

