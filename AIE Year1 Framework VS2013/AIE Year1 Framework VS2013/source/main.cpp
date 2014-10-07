#include "AIE.h"
#include "Player.h"
#include "Block.h"
#include "GroundBlock.h"
#include <iostream>

const int screenWidth = 1500;
const int screenHeigth = 600;

Player player = Player();
GroundBlock ground = GroundBlock();

Block * gBlock = &ground;
Block * bBlock = &ground;


int main( int argc, char* argv[] )
{	


    Initialise(screenWidth, screenHeigth, false, "Super Mario Clone");
    SetBackgroundColour(SColour(197, 255, 255, 255));

	//Set everything needed for player
	//unsigned int myTextureHandle = CreateSprite("./images/platformerArt_v4/png/character/front.png", 66, 92, true);
	player.SetSpriteID(CreateSprite("./images/platformerArt_v4/png/character/front.png", 66, 92, true));
	player.SetPosition(100.f, 300.f);
	player.SetSize(66.f, 92.f);
	player.SetMovementKeys(65, 68, 87);
	player.SetMoveExtreeme(50, 1500, 100);
	player.SetVelocity(1.f);
	

	//set everything for the ground block
	gBlock->SetBlockTextureID(CreateSprite("./images/platformerArt_v4/png/ground.png", 70, 70, true), 1);
	gBlock->SetBlockPosition(35, 25, 1, 20);
	gBlock->SetBlockWidthHeigth(70.f, 70.f, 20);
	

	//set everything for the "brick" block
	bBlock->SetBlockTextureID(CreateSprite("./images/platformerArt_v4/png/block.png", 70, 70, true), 2);
	bBlock->SetBlockPosition(350, 275, 2, 4);
	bBlock->SetBlockCorners(2, 4);

	//for debugging where corners are
	unsigned int Debug = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug2 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug3 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);
	unsigned int Debug4 = CreateSprite("./images/platformerArt_v4/png/alien_plant.png", 10, 10, true);

    //Game Loop
    do
    {
		ClearScreen();
		player.SetPlayerCorners();
		gBlock->SetBlockCorners(1, 20);

		//debugging corners
		MoveSprite(Debug, gBlock->GetCorner1(), gBlock->GetCorner2());
		DrawSprite(Debug);
		MoveSprite(Debug2, gBlock->GetCorner1_2(), gBlock->GetCorner2_2());
		DrawSprite(Debug2);
		/*MoveSprite(Debug3, gBlock->GetCorner1_3(), gBlock->GetCorner2_3());
		DrawSprite(Debug3);
		MoveSprite(Debug4, gBlock->GetCorner1_4(), gBlock->GetCorner2_4());
		DrawSprite(Debug4);*/

		player.Move(300.0f, GetDeltaTime());
        DrawSprite(player.GetSpriteID());

		gBlock->DrawBlock(1, 20);
		bBlock->DrawBlock(2, 4);
       

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
