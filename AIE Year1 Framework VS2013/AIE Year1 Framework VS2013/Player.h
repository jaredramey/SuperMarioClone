#pragma once
#include "AIE.h"
#include "Block.h"

class Player : public Block
{
private:
	int health;

	float x;
	float y;
	float width;
	float heigth;
	float speed;
	float velocity;
	float leftMoveExtreeme;
	float rightMoveExtreeme;
	float bottomExtreeme;
	float upperPlayerLeftCornerX;
	float lowerPlayerLeftCornerX;
	float upperPlayerRightCornerX;
	float lowerPlayerRightCornerX;
	float upperPlayerLeftCornerY;
	float lowerPlayerLeftCornerY;
	float upperPlayerRightCornerY;
	float lowerPlayerRightCornerY;

	unsigned int spriteID;
	unsigned int moveLeft;
	unsigned int moveRight;
	unsigned int jump;

	unsigned int walkSprites[10];

	bool collision;

public:
	Player();
	~Player();

	bool hasJumped=false;
	float airTime = 150;
	float jumpRecharge;

	void SetSpriteID(unsigned int a_spriteID);
	void SetPosition(float a_x, float a_y);
	void SetSize(float a_width, float a_heigth);
	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_jump);
	void SetMoveExtreeme(float a_leftExtreeme, float a_rightExtreeme, float a_bottomeExtreeme);
	void SetVelocity(float a_velocity);
	void SetPlayerCorners();
	

	unsigned int GetSpriteID();
	float GetPositionX();
	float GetPositionY();
	float GetSizeWidth();
	float GetSizeHeigth();
	float GetleftExtreeme();
	float GetrightExtreeme();
	float GetbottomExtreeme();

	void CheckCollision();

	void Move(float a_speed, float a_timeStep);
};

