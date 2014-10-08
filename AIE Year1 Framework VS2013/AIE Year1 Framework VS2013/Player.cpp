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



//upper left
float Player::GetPlayerCorner1()
{
	return upperPlayerLeftCornerX;
}

float Player::GetPlayerCorner2()
{
	return upperPlayerLeftCornerY;
}
//upper right
float Player::GetPlayerCorner1_2()
{
	return upperPlayerRightCornerX;
}

float Player::GetPlayerCorner2_2()
{
	return upperPlayerRightCornerY;
}
//lower left
float Player::GetPlayerCorner1_3()
{
	return lowerPlayerLeftCornerX;
}

float Player::GetPlayerCorner2_3()
{
	return lowerPlayerLeftCornerY;
}
//lower right
float Player::GetPlayerCorner1_4()
{
	return lowerPlayerRightCornerX;
}

float Player::GetPlayerCorner2_4()
{
	return lowerPlayerRightCornerY;
}

void Player::SetPlayerCorners()
{
	//Upper Left (to the left and down)
	upperPlayerLeftCornerX = (x - (width * .5f));
	upperPlayerLeftCornerY = (y + (heigth * .5f));
	//Upper Right (to the right and up)
	upperPlayerRightCornerX = (x + (width * .5f));
	upperPlayerRightCornerY = (y + (heigth * .5f));
	//Lower Left (to the left and down)
	lowerPlayerLeftCornerX = (x - (width * .5f));
	lowerPlayerLeftCornerY = (y - (heigth * .5f));
	//Lower Right (to the right and down)
	lowerPlayerRightCornerX = (x + (width * .5f));
	lowerPlayerRightCornerY = (y - (heigth * .5f));
}

void Player::CheckCollision(float a_upLeftX, float a_upLeftY, float a_upRightX, float a_upRightY, float a_lowLeftX, float a_lowLeftY, float a_lowRightX, float a_lowRightY)
{
	/*for (int i = 0; i < 50; i++)
	{
		if ((lowerPlayerLeftCornerY <= blocks[i].upperLeftCornerY && lowerPlayerLeftCornerX >= blocks[i].upperLeftCornerX) && (lowerPlayerRightCornerY <= blocks[i].upperRightCornerY && lowerPlayerRightCornerX <= blocks[i].upperRightCornerX))
		{
			collision = true;
			goto checkDone;
		}

		if ((lowerPlayerLeftCornerY <= floatingBlocks[i].upperLeftCornerY && lowerPlayerRightCornerY <= floatingBlocks[i].upperRightCornerY) && (x >= blocks[i].upperLeftCornerX && x <= blocks[i].upperRightCornerX))
		{
			return collision = true;
		}*/

		/*else
		{
			collision = false;
		}*/
	for (int i = 0; i < myVect.size(); i++)
	{
	
	}

	for (int i = 0; i < 50; i++)
	{
		//(a_lowLeftY >= (blocks[i].upperLeftCornerY)) && (a_lowLeftX >= blocks[i].upperLeftCornerX) && (a_lowLeftX >= blocks[i].upperRightCornerX)
		//
		if ((a_lowLeftY <= blocks[i].upperLeftCornerY && a_lowRightY <= blocks[i].upperRightCornerY) /*&& (a_lowLeftX >= blocks[i].upperLeftCornerX && a_lowRightX <= blocks[i].upperRightCornerX)*/)
		{
			collision = true;
		}

		/*if ((a_lowLeftX < blocks[i].upperLeftCornerX) && (a_lowRightX > blocks[i].upperRightCornerX))
		{
			collision = false;
		}*/
	}

	if (collision != true)
	{
		collision = false;
	}

}

void Player::Move(float a_speed, float a_timeStep)
{
	//float a_upLeftX, float a_upLeftY, float a_upRightX, float upRightY, float a_lowLeftX, float a_lowLeftY, float a_lowRightX, float a_lowRightY
	CheckCollision(GetPlayerCorner1(), GetPlayerCorner2(), GetPlayerCorner1_2(), GetPlayerCorner2_2(), GetPlayerCorner1_3(), GetPlayerCorner2_3(), GetPlayerCorner1_4(), GetPlayerCorner2_4());

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
	}

	if (!IsKeyDown(jump))
	{
			
			if (collision == true)
			{
				y = (blocks[1].upperRightCornerY + (heigth));
				hasJumped = false;
				velocity = 10.f;
				collision = false;
			}

			else if (hasJumped == false)
			{
				y -= 0.1f;
			}
	}

	if (velocity >= 0)
	{
		velocity -= 0.15f;
	}

	//Move the player sprite
	MoveSprite(spriteID, x, y);
}

Player::~Player()
{
}
