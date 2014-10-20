#include "AIE.h"
#include "Player.h"
#include "Block.h"
#include "GroundBlock.h"
#include "Collision.h"
#include "GlobalInfo.h"
#include "Slime.h"
#include <iostream>


//Block * gBlock = &ground;
//Block * bBlock = &ground;


int main( int argc, char* argv[] )
{	

	Initialise(GlobalInfo::screenWidth, GlobalInfo::screenHeigth, false, "Super Mario Clone");
    SetBackgroundColour(SColour(197, 255, 255, 255));

	bool collisionDetection = false;
	bool enemyCollisionDetection = false;
	bool enemyDead = false;
	bool playerDead = false;
	int tempNum;

	Player player = Player();
	Block testBlock = Block();
	Enemy enemy = Enemy();
	Slime slime = Slime();
	Collision collision = Collision();
	std::vector<Block*> groundBlock;
	for (int i = 0; i < 20; i++)
	{
		groundBlock.push_back(new Block());
	}
	std::vector<Block*> WoodPlanks;
	
	std::vector<Slime*> slimes;
	for (int i = 0; i < 2; i++)
	{
		slimes.push_back(new Slime());
	}


	//ground = GroundBlock();

	player.SetMovementKeys(65, 68, 87);
	player.SetMoveExtreeme((0+(player.GetWidth()*.5f)), 1500, 100);
	player.SetVelocity(.5f);
	
	//set everything for the ground block
	//groundBlock = std::vector<Block*>();
	int tempX = testBlock.GetX();
	int tempY = testBlock.GetY();
	int tempWidth = testBlock.GetWidth();
	int tempHeigth = testBlock.GetHeigth();
	for (int i = 0; i < 20; i++)
	{
		if (i == 0)
		{
			(*groundBlock[i]).SetPos(tempX, tempY);
			(*groundBlock[i]).SetPosition(tempX, tempY);
			(*groundBlock[i]).SetSize(tempWidth, tempHeigth);
			MoveSprite((*groundBlock[i]).GetSpriteID(), (*groundBlock[i]).GetX(), (*groundBlock[i]).GetY());
		}
		else if (i > 0)
		{
			(*groundBlock[i]).SetPos(tempX, tempY);
			(*groundBlock[i]).SetSize(tempWidth, tempHeigth);
			MoveSprite((*groundBlock[i]).GetSpriteID(), (*groundBlock[i]).GetX(), (*groundBlock[i]).GetY());
		}

		tempX += 98;
	}

	int tempSlimeX = slime.GetX();
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			(*slimes[i]).SetPosition((*slimes[i]).GetX(), slime.GetY());
			MoveSprite((*slimes[i]).GetSpriteID(), (*slimes[i]).GetX(), (*slimes[i]).GetY());
		}
		else if (i > 0)
		{
			(*slimes[i]).SetPosition(tempSlimeX, slime.GetY());
			MoveSprite((*slimes[i]).GetSpriteID(), (*slimes[i]).GetX(), (*slimes[i]).GetY());
		}

		tempSlimeX += 21;
	}

	tempX = testBlock.GetX();
	tempSlimeX = slime.GetX();
	//set everything for the "brick" block

	//for debugging where corners are
	unsigned int Debug = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug2 = CreateSprite("./images/platformerArt_v4/png/coin_bronze.png", 10, 10, true);
	unsigned int Debug3 = CreateSprite("./images/platformerArt_v4/png/coin_gold.png", 10, 10, true);
	unsigned int Debug4 = CreateSprite("./images/platformerArt_v4/png/coin_silver.png", 10, 10, true);
	unsigned int Debug5 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug6 = CreateSprite("./images/platformerArt_v4/png/coin_bronze.png", 10, 10, true);
	unsigned int Debug7 = CreateSprite("./images/platformerArt_v4/png/coin_gold.png", 10, 10, true);
	unsigned int Debug8 = CreateSprite("./images/platformerArt_v4/png/coin_silver.png", 10, 10, true);

    //Game Loop
    do
    {
		for (int i = 0; i < 20; i++)
		{
			
			DrawSprite((*groundBlock[i]).GetSpriteID());
		}

		for (int i = 0; i < 2; i++)
		{
			(*slimes[i]).SetCorners();

			if (collision.CheckCollision((*slimes[i]).GetLowLeftCornerX(), (*groundBlock[i]).GetUpLeftCornerX(), (*slimes[i]).GetLowLeftCornerY(), (*groundBlock[i]).GetUpLeftCornerY(), (*slimes[i]).GetLowRightCornerX(), (*groundBlock[i]).GetUpRightCornerX(), (*slimes[i]).GetLowRightCornerY(), (*groundBlock[i]).GetUpRightCornerY()) == true)
			{
				enemyCollisionDetection = true;
			}
			else
			{
				enemyCollisionDetection = false;
			}
			(*slimes[i]).Move(player.GetX(), enemyCollisionDetection, true);
			MoveSprite((*slimes[i]).GetSpriteID(), (*slimes[i]).GetX(), (*slimes[i]).GetY());
			DrawSprite((*slimes[i]).GetSpriteID());
		}
		ClearScreen();
		MoveSprite(Debug, player.GetLowLeftCornerX(), player.GetLowLeftCornerY());
		DrawSprite(Debug);
		MoveSprite(Debug2, player.GetLowRightCornerX(), player.GetLowRightCornerY());
		DrawSprite(Debug2);
		MoveSprite(Debug3, player.GetUpLeftCornerX(), player.GetUpLeftCornerY());
		DrawSprite(Debug3);
		MoveSprite(Debug4, player.GetUpRightCornerX(), player.GetUpRightCornerY());
		DrawSprite(Debug4);

		MoveSprite(Debug5, (*groundBlock[0]).GetLowLeftCornerX(), (*groundBlock[0]).GetLowLeftCornerY());
		DrawSprite(Debug5);
		MoveSprite(Debug6, (*groundBlock[0]).GetLowRightCornerX(), (*groundBlock[0]).GetLowRightCornerY());
		DrawSprite(Debug6);
		MoveSprite(Debug7, (*groundBlock[0]).GetUpLeftCornerX(), (*groundBlock[0]).GetUpLeftCornerY());
		DrawSprite(Debug7);
		MoveSprite(Debug8, (*groundBlock[0]).GetUpRightCornerX(), (*groundBlock[0]).GetUpRightCornerY());
		DrawSprite(Debug8);

		for (int i = 0; i < 20; i++)
		{
			if (collision.CheckCollision(player.GetLowLeftCornerX(), (*groundBlock[i]).GetUpLeftCornerX(), player.GetLowLeftCornerY(), (*groundBlock[i]).GetUpLeftCornerY(), player.GetLowRightCornerX(), (*groundBlock[i]).GetUpRightCornerX(), player.GetLowRightCornerY(), (*groundBlock[i]).GetUpRightCornerY()) == true)
			{
				collisionDetection = true;
				break;
			}
		}
		//DrawSprite(testBlock.GetSpriteID());
		//Check Collision, move player
		player.Move(300.0f, GetDeltaTime(), collisionDetection);
        DrawSprite(player.GetSpriteID());
		if (collisionDetection == true)
		{
			collisionDetection = false;
		}

		if (player.GetX() > 100 && IsKeyDown(player.GetMovementKeyRight()))
		{
			for (int i = 0; i < 20; i++)
			{
				tempNum = ((*groundBlock[i]).GetX() - player.GetX());
				(*groundBlock[i]).ChangeX(1.f, 2);
				(*groundBlock[i]).SetCorners();
				MoveSprite((*groundBlock[i]).GetSpriteID(), ((*groundBlock[i]).GetX() /*- player.GetX()*/), ((*groundBlock[i]).GetY()));
			}
		 }

			if (IsKeyDown(player.GetMovementKeyLeft()) && (player.GetX() > (*groundBlock[1]).GetX()))
			{
				for (int i = 0; i < 20; i++)
				{
					tempNum = ((*groundBlock[i]).GetX() - player.GetX());
					(*groundBlock[i]).ChangeX((1.f), 1);
					(*groundBlock[i]).SetCorners();
					MoveSprite((*groundBlock[i]).GetSpriteID(), ((*groundBlock[i]).GetX() /*- player.GetX()*/), ((*groundBlock[i]).GetY()));
				}
			}


    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
