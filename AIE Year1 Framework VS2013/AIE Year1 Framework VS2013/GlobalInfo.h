#pragma once

class GlobalInfo
{
public:
	static const int screenWidth = 1300;
	static const int screenHeigth = 600;
	int screenWidthMove = 1300;
	int amountOfLives;
	float score;

	GlobalInfo();
	~GlobalInfo();
};

