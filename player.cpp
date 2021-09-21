#include "player.h"
#include "TextureManager.h"

Player::Player(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
}

void Player::Update()
{	
	count++;
	if(count < 10) srcRect.x = 838;
	else if(count < 20) srcRect.x = 940;
	else if(count < 30) srcRect.x = 1040;
	else if(count < 40) srcRect.x = 735;
	else count = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void Player::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
