#pragma once
#include <vector>
#include <iostream>
#include "Entity.h"

using namespace std;

class Block : public Entity
{
public:

	Block();
	~Block();

	void SetPos(float a_x, float a_y);
	void SetSize(float a_width, float a_heigth);
	void SetBlockID(char* a_spriteID);
	
	/*virtual void SetBlockPosition(float a_blockX, float a_blockY, int a_blockID, int a_itteration);
	virtual void DrawBlock(int a_blockID , int a_itteration);
	virtual void SetBlockTextureID(int a_blockID, unsigned int a_textureID);
	virtual void SetBlockCorners(int a_blockID, int a_itteration);
	virtual void SetBlockWidthHeigth(float a_width, float a_heigth, int a_itteration);*/

	static char* GROUND_BLOCK_SPRITEID;
	static const float GROUND_BLOCK_X;
	static const float GROUND_BLOCK_Y;
	static const float GROUND_BLOCK_WIDTH;
	static const float GROUND_BLOCK_HEIGTH;
};

