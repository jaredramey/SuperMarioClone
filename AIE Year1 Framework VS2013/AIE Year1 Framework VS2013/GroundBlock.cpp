#include "GroundBlock.h"
#include "AIE.h"


GroundBlock::GroundBlock()
{
}

void Block::SetBlockTextureID(int a_blockID ,unsigned int a_textureID)
{
	if (a_blockID == 1)
	{
		for (int i = 0; i < 50; i++)
		{
			blocks[i].textureID = a_textureID;
		}
	}

	if (a_blockID == 2)
	{
		for (int i = 0; i < 50; i++)
		{
			floatingBlocks[i].textureID = a_textureID;
		}
	}
}

void Block::SetBlockPosition(float a_x, float a_y, int a_blockID, int a_itteration)
{
	if (a_blockID == 1)
	{
		blocks[0].blockX = a_x;
		blocks[0].blockY = a_y;

		for (int i = 1; i < a_itteration; i++)
		{
			blocks[i].blockX = (blocks[i - 1].blockX + 68);
			blocks[i].blockY = a_y;
		}
	}

	if (a_blockID == 2)
	{
		floatingBlocks[0].blockX = a_x;
		floatingBlocks[0].blockY = a_y;

		for (int i = 1; i < 50; i++)
		{
			floatingBlocks[i].blockX = (floatingBlocks[i - 1].blockX + 68);
			floatingBlocks[i].blockY = a_y;
		}
	}

}

void Block::DrawBlock(int a_blockID ,int a_itteration)
{
	if (a_blockID == 1)
	{
		for (int i = 0; i < a_itteration; i++)
		{
			MoveSprite(blocks[i].textureID, blocks[i].blockX, blocks[i].blockY);
			DrawSprite(blocks[i].textureID);
		}
	}

	if (a_blockID == 2)
	{
		for (int i = 0; i < a_itteration; i++)
		{
			MoveSprite(floatingBlocks[i].textureID, floatingBlocks[i].blockX, floatingBlocks[i].blockY);
			DrawSprite(floatingBlocks[i].textureID);
		}
	}
}

void Block::SetBlockWidthHeigth(float a_width, float a_heigth)
{
	
}

void Block::SetBlockCorners(int a_blockID, int a_itteration)
{
	if (a_blockID == 1)
	{
		for (int i = 0; i < 50; i++)
		{
			blocks[i].upperLeftCornerX = (blocks[i].blockX - (blocks[i].blockWidth * .5f));
			blocks[i].upperLeftCornerY = (blocks[i].blockY + (blocks[i].blockHeigth));
			blocks[i].upperRightCornerX = (blocks[i].blockX + (blocks[i].blockWidth * .5f));
			blocks[i].upperRightCornerY = (blocks[i].blockY + (blocks[i].blockHeigth  * .5f));
			blocks[i].lowerLeftCornerX = (blocks[i].blockX - (blocks[i].blockWidth * .5f));
			blocks[i].lowerLeftCornerY = (blocks[i].blockY - (blocks[i].blockHeigth * .5f));
			blocks[i].lowerRightCornerX = (blocks[i].blockX + (blocks[i].blockWidth * .5f));
			blocks[i].lowerRightCornerY = (blocks[i].blockY - (blocks[i].blockHeigth * .5f));
		}
	}

	if (a_blockID == 2)
	{
		for (int i = 0; i < 50; i++)
		{
			floatingBlocks[i].upperLeftCornerX = (floatingBlocks[i].blockX - (floatingBlocks[i].blockWidth / 2));
			floatingBlocks[i].upperLeftCornerY = (floatingBlocks[i].blockY + (floatingBlocks[i].blockHeigth / 2));
			floatingBlocks[i].upperRightCornerX = (floatingBlocks[i].blockX + (floatingBlocks[i].blockWidth / 2));
			floatingBlocks[i].upperRightCornerY = (floatingBlocks[i].blockY + (floatingBlocks[i].blockHeigth / 2));
			floatingBlocks[i].lowerLeftCornerX = (floatingBlocks[i].blockX - (floatingBlocks[i].blockWidth / 2));
			floatingBlocks[i].lowerLeftCornerY = (floatingBlocks[i].blockY - (floatingBlocks[i].blockHeigth / 2));
			floatingBlocks[i].lowerRightCornerX = (floatingBlocks[i].blockX + (floatingBlocks[i].blockWidth / 2));
			floatingBlocks[i].lowerRightCornerY = (floatingBlocks[i].blockY - (floatingBlocks[i].blockHeigth / 2));
		}
	}
}

GroundBlock::~GroundBlock()
{
}
