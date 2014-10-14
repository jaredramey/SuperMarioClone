#include "Block.h"
#include "AIE.h"


char* Block::GROUND_BLOCK_SPRITEID = "./images/platformerArt_v4/png/block.png";
const float Block::GROUND_BLOCK_X = 50;
const float Block::GROUND_BLOCK_Y = 50;
const float Block::GROUND_BLOCK_WIDTH = 100;
const float Block::GROUND_BLOCK_HEIGTH = 100;

Block::Block()
{
	
		SetX(GROUND_BLOCK_X);
		SetY(GROUND_BLOCK_Y);
		SetWidth(GROUND_BLOCK_WIDTH);
		SetHeigth(GROUND_BLOCK_HEIGTH);
		SetSpriteID(GROUND_BLOCK_SPRITEID);
		SetCorners();

}

void Block::SetPos(float a_x, float a_y)
{
	SetX(a_x);
	SetY(a_y);
}

void Block::SetSize(float a_width, float a_heigth)
{
	SetWidth(a_width);
	SetHeigth(a_heigth);
}

void Block::SetBlockID(char* a_spriteID)
{
	SetSpriteID(a_spriteID);
}

Block::~Block()
{
}
