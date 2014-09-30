#include "AIE.h"
#include "Player.h"
#include <iostream>

const int screenWidth = 1500;
const int screenHeigth = 600;

Player player = Player();

int main( int argc, char* argv[] )
{	
    Initialise(screenWidth, screenHeigth, false, "Super Mario Clone");
    SetBackgroundColour(SColour(0, 189, 255, 255));

	//Set everything needed for player
	unsigned int myTextureHandle = CreateSprite("./images/platformerArt_v4/png/character/front.png", 66, 92, true);
	player.SetSpriteID(myTextureHandle);
	player.SetPosition(100.f, 100.f);
	player.SetSize(66, 92);
	player.SetMovementKeys(65, 68, 87);
	player.SetMoveExtreeme(300, 1200, 50);

    //Game Loop
    do
    {
		player.Move(1.0f, GetDeltaTime());
        DrawSprite(player.GetSpriteID());

        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
