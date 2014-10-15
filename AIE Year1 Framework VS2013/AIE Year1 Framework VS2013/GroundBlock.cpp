#include "GroundBlock.h"
#include "AIE.h"

char* GroundBlock::WOOD_BLOCK_SPRITEID = "./images/platformerArt_v4/png/block.png";
const float GroundBlock::WOOD_BLOCK_X = 100;
const float GroundBlock::WOOD_BLOCK_Y = 500;
const float GroundBlock::WOOD_BLOCK_WIDTH = 50;
const float GroundBlock::WOOD_BLOCK_HEIGTH = 50;

GroundBlock::GroundBlock()
{
	SetX(WOOD_BLOCK_X);
	SetY(WOOD_BLOCK_Y);
	SetWidth(WOOD_BLOCK_WIDTH);
	SetHeigth(WOOD_BLOCK_HEIGTH);
	SetSpriteID(WOOD_BLOCK_SPRITEID);
	SetCorners();
}

GroundBlock::~GroundBlock()
{
}
