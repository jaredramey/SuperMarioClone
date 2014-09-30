#pragma once
class Player
{
private:
	int health;

	float x;
	float y;
	float width;
	float heigth;
	float speed;

	unsigned int spriteID;
	unsigned int moveLeft;
	unsigned int moveRight;
	unsigned int jump;

public:
	Player();
	~Player();

	void SetSpriteID(unsigned int a_spriteID);
	void SetPosition(float a_x, float a_y);
	void SetSize(float a_width, float a_heigth);
	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_jump);

	unsigned int GetSpriteID();
	float GetPositionX();
	float GetPositionY();
	float GetSizeWidth();
	float GetSizeHeigth();

	void Move(unsigned int a_spriteID, float delta);
};

