#include "Entity.h"
#include "AIE.h"

Entity::Entity()
{

}

void Entity::SetX(float a_x)
{
	x = a_x;
}

void Entity::SetY(float a_y)
{
	y = a_y;
}

void Entity::SetWidth(float a_width)
{
	width = a_width;
}

void Entity::SetHeigth(float a_heigth)
{
	heigth = a_heigth;
}

void Entity::SetSpriteID(char* a_spriteID)
{
	spriteID = CreateSprite(a_spriteID, width, heigth, true);
}


//1 = add, 2 = subtract, 3 = stay in place
void Entity::ChangeX(float xChange, int changeType)
{
	if (changeType == 1)
	{
		this->x += xChange;
	}

	else if (changeType == 2)
	{
		this->x -= xChange;
	}

	else
	{
		this->x = xChange;
	}
}

//1 = add, 2 = subtract, 3 = stay in place
void Entity::ChangeY(float yChange, int changeType)
{
	if (changeType == 1)
	{
		this->y += yChange;
	}

	else if (changeType == 2)
	{
		this->y -= yChange;
	}

	else
	{
		this->y = yChange;
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
	return this->x;
}

float Entity::GetY()
{
	return this->y;
}

float Entity::GetWidth()
{
	return this->width;
}

float Entity::GetHeigth()
{
	return this->heigth;
}

float Entity::GetUpLeftCornerX()
{
	return this->upLeftCornerX;
}

float Entity::GetUpLeftCornerY()
{
	return this->upLeftCornerY;
}

float Entity::GetUpRightCornerX()
{
	return this->upRightCornerX;
}

float Entity::GetUpRightCornerY()
{
	return this->upRightCornerY;
}

float Entity::GetLowLeftCornerX()
{
	return this->lowLeftCornerX;
}

float Entity::GetLowLeftCornerY()
{
	return this->lowLeftCornerY;
}

float Entity::GetLowRightCornerX()
{
	return this->lowRightCornerX;
}

float Entity::GetLowRightCornerY()
{
	return this->lowRightCornerY;
}

unsigned int Entity::GetSpriteID()
{
	return this->spriteID;
}

Entity::~Entity()
{
}
