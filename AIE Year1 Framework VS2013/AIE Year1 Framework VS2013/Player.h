#include "AIE.h"
#include "Block.h"
#include "Window.h"
#pragma once


class Player : public Block, public Window
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

	//upper left
	float GetPlayerCorner1();
	float GetPlayerCorner2();
	//upper right
	float GetPlayerCorner1_2();
	float GetPlayerCorner2_2();
	//lower left
	float GetPlayerCorner1_3();
	float GetPlayerCorner2_3();
	//lower right
	float GetPlayerCorner1_4();
	float GetPlayerCorner2_4();

	void CheckCollision(float a_upLeftX, float a_upLeftY, float a_upRightX, float upRightY, float a_lowLeftX, float a_lowLeftY, float a_lowRightX, float lowRightY);

	void Move(float a_speed, float a_timeStep);
};

