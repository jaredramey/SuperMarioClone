#include "AIE.h"
#include "Player.h"
#include "Block.h"
#include "GroundBlock.h"
#include "Collision.h"
#include "GlobalInfo.h"
#include <iostream>


//Block * gBlock = &ground;
//Block * bBlock = &ground;


int main( int argc, char* argv[] )
{	

	Initialise(GlobalInfo::screenWidth, GlobalInfo::screenHeigth, false, "Super Mario Clone");
    SetBackgroundColour(SColour(197, 255, 255, 255));

	bool collisionDetection;

	Player player = Player();
	Block testBlock = Block();
	Collision collision = Collision();
	std::vector<Block*> groundBlock;
	for (int i = 0; i < 4; i++)
	{
		groundBlock.push_back(new Block());
	}
	std::vector<Block*> WoodPlanks;
	//ground = GroundBlock();

	player.SetMovementKeys(65, 68, 87);
	player.SetMoveExtreeme(50, 1500, 100);
	player.SetVelocity(1.f);
	
	//set everything for the ground block
	//groundBlock = std::vector<Block*>();
	int tempX = testBlock.GetX();
	int tempY = testBlock.GetY();
	int tempWidth = testBlock.GetWidth();
	int tempHeigth = testBlock.GetHeigth();
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			(*groundBlock[i]).SetPos(tempX, tempY);
			(*groundBlock[i]).SetSize(tempWidth, tempHeigth);
		}
		else if (i > 0)
		{
			(*groundBlock[i]).SetPos(tempX, tempY);
			(*groundBlock[i]).SetSize(tempWidth, tempHeigth);
		}

		tempX += 98;
	}
	//set everything for the "brick" block

	//for debugging where corners are
	unsigned int Debug = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug2 = CreateSprite("./images/platformerArt_v4/png/coin_bronze.png", 10, 10, true);
	unsigned int Debug3 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug4 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug5 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug6 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug7 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug8 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);

    //Game Loop
    do
    {
		ClearScreen();
		for (int i = 0; i < 4; i++)
		{
			MoveSprite((*groundBlock[i]).GetSpriteID(), (*groundBlock[i]).GetX(), (*groundBlock[i]).GetY());
			DrawSprite((*groundBlock[i]).GetSpriteID());
		}

		for (int i = 0; i < 4; i++)
		{
			if (collision.CheckCollision(player.GetX(), (*groundBlock[i]).GetX(), player.GetY(), (*groundBlock[i]).GetY(), player.GetWidth(), player.GetHeigth(), (*groundBlock[i]).GetWidth(), (*groundBlock[i]).GetHeigth()) == true)
			{
				collisionDetection = true;
				break;
			}
			else
			{
				collisionDetection = false;
			}
		}
		//DrawSprite(testBlock.GetSpriteID());
		//Check Collision, move player
		player.Move(300.0f, GetDeltaTime(), collisionDetection);
        DrawSprite(player.GetSpriteID());

		
       

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
