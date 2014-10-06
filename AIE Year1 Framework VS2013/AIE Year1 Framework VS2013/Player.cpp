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

void Player::SetPlayerCorners()
{
	upperPlayerLeftCornerX = (x - (width * .5f));
	upperPlayerLeftCornerY = (y + (heigth * .5f));
	upperPlayerRightCornerX = (x + (width * .5f));
	upperPlayerRightCornerY = (y + (heigth * .5f));
	lowerPlayerLeftCornerX = (x - (width * .5f));
	lowerPlayerLeftCornerY = (y - (heigth * .5f));
	lowerPlayerRightCornerX = (x + (width * .5f));
	lowerPlayerRightCornerY = (y - (heigth * .5f));
}

void Player::CheckCollision()
{
	for (int i = 0; i < 50; i++)
	{
		if ((lowerPlayerLeftCornerY <= (blocks[i].upperLeftCornerY + heigth) /* && lowerPlayerRightCornerY <= blocks[i].upperRightCornerY) && (x <= blocks[i].upperLeftCornerX && x >= blocks[i].upperRightCornerX)*/))
		{
			collision = true;
			goto checkDone;
		}

		/*if ((lowerPlayerLeftCornerY <= floatingBlocks[i].upperLeftCornerY && lowerPlayerRightCornerY <= floatingBlocks[i].upperRightCornerY) && (x >= blocks[i].upperLeftCornerX && x <= blocks[i].upperRightCornerX))
		{
			return collision = true;
		}*/

		/*else
		{
			collision = false;
		}*/
	}
checkDone:;
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
		if (x >(rightMoveExtreeme - width) && velocity > 0)
		{
			x = (rightMoveExtreeme - width);
		}
	}

	//Moving Up
	if (IsKeyDown(jump) && hasJumped == false && velocity >= 0.10f)
	{
				y += velocity;
				if (velocity >= 0)
				velocity -= 0.15f;
			
			//if (y >= (heigth*3) || !(IsKeyDown(jump)))
				if (!IsKeyDown(jump))
				hasJumped = true;
	}

	if (!IsKeyDown(jump) && y >= 0)
	{
			y-=0.9f;
			CheckCollision();
			if (collision == true)
			{
				y = 100;
				for (int i = 0; i < 50; i++)
				{
					y = (blocks[i].upperRightCornerY + (heigth));
					break;
				}
				hasJumped = false;
				velocity = 10.f;
				collision = false;
			}
		
	}
	//Move the player sprite
	MoveSprite(spriteID, x, y);
}


Player::~Player()
{
}
