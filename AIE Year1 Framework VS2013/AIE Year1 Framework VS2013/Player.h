#include "AIE.h"
#include "Collision.h"
#include "Entity.h"
#include <vector>
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

	Entity player;

	bool hasJumped=false;
	float airTime = 150;
	float jumpRecharge;

	/*void SetSpriteID(unsigned int a_spriteID);
	void SetPosition(float a_x, float a_y);
	void SetSize(float a_width, float a_heigth);
	void SetPlayerCorners();*/

	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_jump);
	void SetMoveExtreeme(float a_leftExtreeme, float a_rightExtreeme, float a_bottomeExtreeme);
	void SetVelocity(float a_velocity);
	

	/*unsigned int GetSpriteID();
	float GetPositionX();
	float GetPositionY();
	float GetSizeWidth();
	float GetSizeHeigth();
	float GetleftExtreeme();
	float GetrightExtreeme();
	float GetbottomExtreeme();*/

	//upper left
	/*float GetPlayerCorner1();
	float GetPlayerCorner2();
	//upper right
	float GetPlayerCorner1_2();
	float GetPlayerCorner2_2();
	//lower left
	float GetPlayerCorner1_3();
	float GetPlayerCorner2_3();
	//lower right
	float GetPlayerCorner1_4();
	float GetPlayerCorner2_4();*/

	void Move(float a_speed, float a_timeStep);

	/*static char* PLAYER_SPRITEID;
	static float PLAYER_X;
	static float PLAYER_Y;
	static float PLAYER_WIDTH;
	static float PLAYER_HEIGTH;*/
};

