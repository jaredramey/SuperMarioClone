#pragma once
class Window
{
private:
	float x;
	float y;
	float speed;

	bool move;

public:

	void SetWindowPos(float a_x, float a_y);
	void SetSpeed();

	Window();
	~Window();
};

