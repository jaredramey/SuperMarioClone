#include "Player.h"
#include "AIE.h"

char* PLAYER_SPRITEID = "./images/platformerArt_v4/png/character/front.png";
float PLAYER_X = 100.f;
float PLAYER_Y = 300.f;
float PLAYER_WIDTH = 66.f;
float PLAYER_HEIGTH = 92.f;

Player::Player()
{
	SetX(PLAYER_X);
	SetY(PLAYER_Y);
	SetWidth(PLAYER_WIDTH);
	SetHeigth(PLAYER_HEIGTH);
	SetSpriteID(PLAYER_SPRITEID);
}


void Player::SetVelocity(float a_velocity)
{
	velocity = a_velocity;
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

void Player::Move(float a_speed, float a_timeStep, bool collision)
{

	if (IsKeyDown(moveLeft) /*&& hasJumped == false*/)
	{
		ChangeX((a_timeStep * a_speed), 2);
		if (GetX() < (leftMoveExtreeme + GetWidth()*.1f))
		{
			ChangeX((leftMoveExtreeme + GetWidth()*.1f), 3);
		}
	}

	//Moving Right
	if (IsKeyDown(moveRight) /*&& hasJumped == false*/)
	{
		ChangeX((a_timeStep * a_speed), 1);
		if (GetX() >(rightMoveExtreeme - GetWidth()) && velocity > 0)
		{
			ChangeX((rightMoveExtreeme - GetWidth()), 3);
		}
	}

	//Moving Up
	if (IsKeyDown(jump) && hasJumped == false && velocity >= 0.10f)
	{
				ChangeY(velocity, 1);
	}

	if (!IsKeyDown(jump))
	{
			
			if (collision == true)
			{
				hasJumped = false;
				velocity = 10.f;
			}
			//change gravity to a constant and move out of box when colliding
			if (hasJumped == false && collision == false)
			{
				ChangeY(0.1f, 2);
			}
	}

	if (velocity >= 0)
	{
		velocity -= 0.15f;
	}

	//Move the player sprite
	SetCorners();
	MoveSprite(GetSpriteID(), GetX(), GetY());
}

Player::~Player()
{
}
