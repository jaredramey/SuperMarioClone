#include "Player.h"
#include "AIE.h"

Player::Player()
{
}

void  Player::SetSpriteID(unsigned int a_spriteID)
{
	spriteID = a_spriteID;
}

void Player::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

void Player::SetSize(float a_width, float a_heigth)
{
	width = a_width;
	heigth = a_heigth;
}

void Player::SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_jump)
{
	moveLeft = a_moveLeft;
	moveRight = a_moveRight;
	jump = a_jump;
}

void Player::SetMoveExtreeme(float a_leftExtreeme, float a_rightExtreeme, float a_bottomeExtreeme)
{
	leftMoveExtreeme = a_leftExtreeme;
	rightMoveExtreeme = a_rightExtreeme;
	bottomExtreeme = a_bottomeExtreeme;
}

unsigned int Player::GetSpriteID()
{
	return spriteID;
}

float Player::GetPositionX()
{
	return x;
}

float Player::GetPositionY()
{
	return y;
}

float Player::GetSizeWidth()
{
	return width;
}

float Player::GetSizeHeigth()
{
	return heigth;
}

float Player::GetleftExtreeme()
{
	return leftMoveExtreeme;
}

float Player::GetrightExtreeme()
{
	return rightMoveExtreeme;
}

float Player::GetbottomExtreeme()
{
	return bottomExtreeme;
}

void Player::Move(float a_speed, float a_timeStep)
{
	if (IsKeyDown(moveLeft))
	{
		x -= a_timeStep * a_speed;
		if (x < (leftMoveExtreeme + width*.1f))
		{
			x = (leftMoveExtreeme + width*.1f);
		}
	}

	//Moving Right
	if (IsKeyDown(moveRight))
	{
		x += a_timeStep * a_speed;
		if (x >(rightMoveExtreeme - width*.37f))
		{
			x = (rightMoveExtreeme - width*.37f);
		}
	}

	//Moving Up
	if (IsKeyDown(jump))
	{
		y += a_timeStep * a_speed;
		if (y > (bottomExtreeme + 100))
		{
			y -= a_timeStep * a_speed;
		}
	}
	//Move the player sprite
	MoveSprite(spriteID, x, y);
}


Player::~Player()
{
}
