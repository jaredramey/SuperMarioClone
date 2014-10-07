#include "Block.h"


Block::Block()
{
}

/*void Block::SetBlockTextureID(unsigned int a_textureID)
{
	
}*/

/*void Block::SetBlockPosition(float a_blockX, float a_blockY)
{
	
}

void Block::DrawBlock(unsigned int a_textureID)
{
	
}*/
float Block::GetBlockCorner(int a_cornerID, int a_itterition)
{
	switch (a_cornerID)
	{
	case 1:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].upperLeftCornerX;
		}
		break;

	case 2:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].upperLeftCornerY;
		}
		break;

	case 3:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].upperRightCornerX;
		}
		break;

	case 4:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].upperRightCornerY;
		}
		break;

	case 5:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].lowerLeftCornerX;
		}
		break;

	case 6:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].lowerLeftCornerY;
		}
		break;

	case 7:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].lowerRightCornerX;
		}
		break;

	case 8:
		for (int i = a_itterition; i < (a_itterition + 1); i++)
		{
			return blocks[i].lowerRightCornerY;
		}
		break;
	}

}

Block::~Block()
{
}
