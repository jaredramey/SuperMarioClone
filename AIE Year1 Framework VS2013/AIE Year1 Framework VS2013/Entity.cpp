#include "Entity.h"
#include "AIE.h"

Entity::Entity()
{
	//Jeff's collision method
	collisionDx = 0.0f;
}

bool Entity::isCollided(Entity* other)
{
	using namespace std;
	return pow(other->position.x - position.x, 2) + pow(other->position.y - position.y, 2) <= pow(collisionDx + other->collisionDx,2);
}

void Entity::SetCollisionDx(float dx)
{
	collisionDx = dx;
}

float Entity::GetCollisionDx()
{
	return collisionDx;
}

Point2D Entity::GetPosition()
{
	return position;
}

void Entity::SetPosition(float a_x, float a_y)
{
	position.x = a_x;
	position.y = a_y;
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
	upLeftCornerX = (x - (width*.5f));
	upLeftCornerY = (y + (heigth*.5f));

	upRightCornerX = (x + (width*.5f));
	upRightCornerY = (y + (heigth*.5f));

	lowLeftCornerX = (x - (width*.5f));
	lowLeftCornerY = (y - (heigth*.5f));

	lowRightCornerX = (x + (width*.5f));
	lowRightCornerY = (y - (heigth*.5f));
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
