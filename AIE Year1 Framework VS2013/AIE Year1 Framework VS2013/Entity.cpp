#include "Entity.h"
#include "AIE.h"


Entity::Entity()
{
	
}

Entity::Entity(float a_x, float a_y, float a_width, float a_heigth, const char* a_spriteID)
{
	x = a_x;
	y = a_y;
	width = a_width;
	heigth = a_heigth;
	//unsigned int temp = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", a_width, a_heigth, true);
	spriteID = CreateSprite(a_spriteID, a_width, a_heigth, true);

	SetCorners();
}

//1 = add, 2 = subtract, 3 = stay in place
void Entity::ChangeX(float xChange, int changeType)
{
	if (changeType == 1)
	{
		x += xChange;
	}

	else if (changeType == 2)
	{
		x -= xChange;
	}

	else
	{
		x = xChange;
	}
}

//1 = add, 2 = subtract, 3 = stay in place
void Entity::ChangeY(float yChange, int changeType)
{
	if (changeType == 1)
	{
		y += yChange;
	}

	else if (changeType == 2)
	{
		y -= yChange;
	}

	else
	{
		y = yChange;
	}
}

void Entity::SetCorners()
{
	upLeftCornerX = (x + (heigth*.5f));
	upLeftCornerY = (y - (width*.5f));
	upRightCornerX = (x + (heigth*.5f));
	upRightCornerY = (y + (width*.5f));
	lowLeftCornerX = (x - (heigth*.5f));
	lowLeftCornerY = (y - (width*.5f));
	lowRightCornerX = (x - (heigth*.5f));
	lowRightCornerY = (y + (width*.5f));
}

float Entity::GetX()
{
	return x;
}

float Entity::GetY()
{
	return y;
}

float Entity::GetWidth()
{
	return width;
}

float Entity::GetHeigth()
{
	return heigth;
}

float Entity::GetUpLeftCornerX()
{
	return upLeftCornerX;
}

float Entity::GetUpLeftCornerY()
{
	return upLeftCornerY;
}

float Entity::GetUpRightCornerX()
{
	return upRightCornerX;
}

float Entity::GetUpRightCornerY()
{
	return upRightCornerY;
}

float Entity::GetLowLeftCornerX()
{
	return lowLeftCornerX;
}

float Entity::GetLowLeftCornerY()
{
	return lowLeftCornerY;
}

float Entity::GetLowRightCornerX()
{
	return lowRightCornerX;
}

float Entity::GetLowRightCornerY()
{
	return lowRightCornerY;
}

unsigned int Entity::GetSpriteID()
{
	return spriteID;
}

Entity::~Entity()
{
}
