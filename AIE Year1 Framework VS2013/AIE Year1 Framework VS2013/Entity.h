#pragma once
#include <math.h>

struct Point2D
{
	float x, y;
};

class Entity
{
private:
	float x;
	float y;
	float width;
	float heigth;
	float upLeftCornerX;
	float upLeftCornerY;
	float upRightCornerX;
	float upRightCornerY;
	float lowLeftCornerX;
	float lowLeftCornerY;
	float lowRightCornerX;
	float lowRightCornerY;

	unsigned int spriteID;

public:
	//stuff from Jeff's collision method
	void SetPosition(float a_x, float a_y);
	Point2D GetPosition();
	void SetCollisionDx(float dx);
	float GetCollisionDx();
	bool isCollided(Entity* other);

	void SetSpriteID(char* a_spriteID);
	void SetX(float a_x);
	void SetY(float a_y);
	void SetWidth(float a_width);
	void SetHeigth(float a_heigth);

	void ChangeX(float xChange, int changeType);
	void ChangeY(float yChange, int changeType);
	void SetCorners();

	float GetX();
	float GetY();
	float GetWidth();
	float GetHeigth();
	float GetUpLeftCornerX();
	float GetUpLeftCornerY();
	float GetUpRightCornerX();
	float GetUpRightCornerY();
	float GetLowLeftCornerX();
	float GetLowLeftCornerY();
	float GetLowRightCornerX();
	float GetLowRightCornerY();

	unsigned int GetSpriteID();

	Entity();
	virtual ~Entity();

protected:
	//Stuff for Jeff's collision method
	Point2D position;
	float collisionDx;
};

