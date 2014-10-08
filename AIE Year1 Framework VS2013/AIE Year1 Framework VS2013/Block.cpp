#include "Block.h"


const char* Block::BLOCK_SPRITEID = "/images/platformerArt_v4/png/alien_plant.png";
const float Block::BLOCK_X = 0;
const float Block::BLOCK_Y = 0;
const float Block::BLOCK_WIDTH = 0;
const float Block::BLOCK_HEIGTH = 0;

Block::Block() : Entity(BLOCK_X, BLOCK_Y, BLOCK_WIDTH, BLOCK_HEIGTH, BLOCK_SPRITEID)
{

}

Block::~Block()
{
}
