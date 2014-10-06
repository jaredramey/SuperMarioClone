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


int main( int argc, char* argv[] )
{	


    Initialise(screenWidth, screenHeigth, false, "Super Mario Clone");
    SetBackgroundColour(SColour(197, 255, 255, 255));

	//Set everything needed for player
	//unsigned int myTextureHandle = CreateSprite("./images/platformerArt_v4/png/character/front.png", 66, 92, true);
	player.SetSpriteID(CreateSprite("./images/platformerArt_v4/png/character/front.png", 66, 92, true));
	player.SetPosition(100.f, 200.f);
	player.SetSize(66.f, 92.f);
	player.SetMovementKeys(65, 68, 87);
	player.SetMoveExtreeme(50, 1500, 150);

	//set everything for the ground block
	gBlock->SetBlockTextureID(CreateSprite("./images/platformerArt_v4/png/ground.png", 70, 70, true));
	gBlock->SetBlockPosition(35, 25);

    //Game Loop
    do
    {
		ClearScreen();
		player.Move(300.0f, GetDeltaTime());
        DrawSprite(player.GetSpriteID());

		gBlock->DrawBlock();

       

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
