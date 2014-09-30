#pragma once
#include "Block.h"
class GroundBlock :
	public Block
{
public:
	float upperLeftCorner;
	float lowerLeftCorner;
	float upperRightCorner;
	float lowerRightCorner;

	void SetCorners(float a_blockX, float a_blockY, float a_blockWidth, float a_blockHeigth);

	GroundBlock();
	~GroundBlock();
};

