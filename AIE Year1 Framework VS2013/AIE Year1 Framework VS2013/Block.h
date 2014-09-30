#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Block
{
public:

	struct Object
	{
		float blockX;
		float blockY;
		float blockWidth;
		float blockHeigth;

		bool hasBeenHit = false;

		unsigned int textureID;
	};

	Object blocks[50];

	Block();
	~Block();


	virtual void SetBlockPosition(float a_blockX, float a_blockY);
	virtual void DrawBlock();
	virtual void SetBlockTextureID(unsigned int a_textureID);
	
};

