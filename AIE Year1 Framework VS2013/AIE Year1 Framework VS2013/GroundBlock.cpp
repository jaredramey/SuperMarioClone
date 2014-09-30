#include "GroundBlock.h"
#include "AIE.h"


GroundBlock::GroundBlock()
{
}

void Block::SetBlockTextureID(unsigned int a_textureID)
{
	for (int i = 0; i < 50; i++)
	{
		blocks[i].textureID = a_textureID;
	}
}

void Block::SetBlockPosition(float a_x, float a_y)
{
	blocks[0].blockX = a_x;
	blocks[0].blockY = a_y;

	for (int i = 1; i < 50; i++)
	{
		blocks[i].blockX = (blocks[i - 1].blockX + 68);
		blocks[i].blockY = a_y;
	}
	
}

void Block::DrawBlock()
{
	for (int i = 0; i < 50; i++)
	{
		MoveSprite(blocks[i].textureID, blocks[i].blockX, blocks[i].blockY);
		DrawSprite(blocks[i].textureID);
	}
}

GroundBlock::~GroundBlock()
{
}
