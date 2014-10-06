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
	if (IsKeyDown(moveLeft) && hasJumped == false)
	{
		x -= a_timeStep * a_speed;
		if (x < (leftMoveExtreeme + width*.1f))
		{
			x = (leftMoveExtreeme + width*.1f);
		}
	}

	//Moving Right
	if (IsKeyDown(moveRight) && hasJumped == false)
	{
		x += a_timeStep * a_speed;
		if (x >(rightMoveExtreeme - width))
		{
			x = (rightMoveExtreeme - width);
		}
	}

	//Moving Up
	if (IsKeyDown(jump) && hasJumped == false)
	{
		if (hasJumped == false && y <= bottomExtreeme)
		{
			for (y; y < (bottomExtreeme + (heigth * 3));)
			{
				y += 0.01f;
			}
			if (y >= (heigth*3) || !(IsKeyDown(jump)))
			{
				hasJumped = true;
			}
		}
	}

	if (!(IsKeyDown(jump)) && y >= bottomExtreeme)
	{
			y-=0.25f;
			if (y <= bottomExtreeme)
			{
				hasJumped = false;
			}
		
	}
	//Move the player sprite
	MoveSprite(spriteID, x, y);
}


Player::~Player()
{
}
