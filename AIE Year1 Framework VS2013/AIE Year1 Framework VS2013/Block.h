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
	
	/*virtual void SetBlockPosition(float a_blockX, float a_blockY, int a_blockID, int a_itteration);
	virtual void DrawBlock(int a_blockID , int a_itteration);
	virtual void SetBlockTextureID(int a_blockID, unsigned int a_textureID);
	virtual void SetBlockCorners(int a_blockID, int a_itteration);
	virtual void SetBlockWidthHeigth(float a_width, float a_heigth, int a_itteration);*/
	

	static const char* BLOCK_SPRITEID;
	static const float BLOCK_X;
	static const float BLOCK_Y;
	static const float BLOCK_WIDTH;
	static const float BLOCK_HEIGTH;
};

