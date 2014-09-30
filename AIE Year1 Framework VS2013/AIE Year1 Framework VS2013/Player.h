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
	float leftMoveExtreeme;
	float rightMoveExtreeme;
	float bottomExtreeme;

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
	void SetMoveExtreeme(float a_leftExtreeme, float a_rightExtreeme, float a_bottomeExtreeme);

	unsigned int GetSpriteID();
	float GetPositionX();
	float GetPositionY();
	float GetSizeWidth();
	float GetSizeHeigth();
	float GetleftExtreeme();
	float GetrightExtreeme();
	float GetbottomExtreeme();

	void Move(float a_speed, float a_timeStep);
};

