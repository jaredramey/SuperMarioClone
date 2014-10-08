#include "Player.h"
#include "AIE.h"

char* PLAYER_SPRITEID = "./images/platformerArt_v4/png/character/front.png";
float PLAYER_X = 100.f;
float PLAYER_Y = 300.f;
float PLAYER_WIDTH = 66.f;
float PLAYER_HEIGTH = 92.f;

Player::Player() : Entity(PLAYER_X, PLAYER_Y, PLAYER_WIDTH, PLAYER_HEIGTH, PLAYER_SPRITEID)
{
	
}


/*void  Player::SetSpriteID(unsigned int a_spriteID)
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
*/

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

void Player::Move(float a_speed, float a_timeStep)
{

	for (int i = 0; i < 50; i++)
	{
		//CheckCollision(player.GetX, player.GetY, blocks[i].blockX, blocks[i].blockY, player.GetWidth, player.GetHeigth, blocks[i].blockWidth, blocks[i].blockHeigth);
	}

	if (IsKeyDown(moveLeft) && hasJumped == false)
	{
		player.ChangeX((a_timeStep * a_speed), 2);
		if (player.GetX() < (leftMoveExtreeme + player.GetWidth()*.1f))
		{
			player.ChangeX((leftMoveExtreeme + player.GetWidth()*.1f), 3);
		}
	}

	//Moving Right
	if (IsKeyDown(moveRight) && hasJumped == false)
	{
		player.ChangeX((a_timeStep * a_speed), 1);
		if (player.GetX() >(rightMoveExtreeme - player.GetWidth()) && velocity > 0)
		{
			player.ChangeX((rightMoveExtreeme - player.GetWidth()), 3);
		}
	}

	//Moving Up
	if (IsKeyDown(jump) && hasJumped == false && velocity >= 0.10f)
	{
				player.ChangeY(velocity, 1);
	}

	if (!IsKeyDown(jump))
	{
			
			/*if (collision == true)
			{
				y = (blocks[0].blockHeigth + (width * 0.5f));
				hasJumped = false;
				velocity = 10.f;
				collision = false;
			}

			if (hasJumped == false && collision == false)
			{
				y -= 0.1f;
			}*/
	}

	if (velocity >= 0)
	{
		velocity -= 0.15f;
	}

	//Move the player sprite
	MoveSprite(this->GetSpriteID(), this->GetX(), this->GetY());
}

Player::~Player()
{
}
