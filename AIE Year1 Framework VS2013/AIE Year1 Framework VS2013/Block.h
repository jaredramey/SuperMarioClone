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
		float upperLeftCornerX;
		float lowerLeftCornerX;
		float upperRightCornerX;
		float lowerRightCornerX;
		float upperLeftCornerY;
		float lowerLeftCornerY;
		float upperRightCornerY;
		float lowerRightCornerY;

		bool hasBeenHit = false;

		unsigned int textureID;
	};

	Object blocks[50];
	std::vector<Object> myVect;
	Object floatingBlocks[50];

	Block();
	~Block();
	
	virtual void SetBlockPosition(float a_blockX, float a_blockY, int a_blockID, int a_itteration);
	virtual void DrawBlock(int a_blockID , int a_itteration);
	virtual void SetBlockTextureID(int a_blockID, unsigned int a_textureID);
	virtual void SetBlockCorners(int a_blockID, int a_itteration);
	virtual void SetBlockWidthHeigth(float a_width, float a_heigth, int a_itteration);
	virtual float GetCorner1();
	virtual float GetCorner2();
	virtual float GetCorner1_2();
	virtual float GetCorner2_2();
	virtual float GetCorner1_3();
	virtual float GetCorner2_3();
	virtual float GetCorner1_4();
	virtual float GetCorner2_4();
	float GetBlockCorner(int a_cornerID, int a_itterition);
	
};

