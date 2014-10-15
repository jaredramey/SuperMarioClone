#include "AIE.h"
#include "Collision.h"
#include "Entity.h"
#include "Block.h"

#pragma once

class Player : public Entity, public Collision
{
private:
	int health;

	float speed;
	float velocity;
	float leftMoveExtreeme;
	float rightMoveExtreeme;
	float bottomExtreeme;

	unsigned int moveLeft;
	unsigned int moveRight;
	unsigned int jump;

public:
	Player();
	~Player();

	

	bool hasJumped=false;
	float airTime = 150;
	float jumpRecharge;

	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_jump);
	void SetMoveExtreeme(float a_leftExtreeme, float a_rightExtreeme, float a_bottomeExtreeme);
	void SetVelocity(float a_velocity);
	float GetMovementKeyRight();
	float GetMovementKeyLeft();
	float GetMovementKeyJump();

	void Move(float a_speed, float a_timeStep, bool collision);

	/*static char* PLAYER_SPRITEID;
	static float PLAYER_X;
	static float PLAYER_Y;
	static float PLAYER_WIDTH;
	static float PLAYER_HEIGTH;*/
};

