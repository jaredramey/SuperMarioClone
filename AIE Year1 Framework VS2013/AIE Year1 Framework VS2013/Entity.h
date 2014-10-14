#pragma once

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
};

