#pragma once
#include "Block.h"
#include "Window.h"

class GroundBlock :
	public Block//, public Window
{
public:
	

	GroundBlock();
	~GroundBlock();

	static char* WOOD_BLOCK_SPRITEID;
	static const float WOOD_BLOCK_X;
	static const float WOOD_BLOCK_Y;
	static const float WOOD_BLOCK_WIDTH;
	static const float WOOD_BLOCK_HEIGTH;
};

