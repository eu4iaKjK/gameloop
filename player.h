#pragma once

#include "game.h"

class Player {
public:
	Player(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~Player();

	void Update();
	void Render();

	int xpos;
	int ypos;
private:
	int count;

	SDL_Texture* objTexture;
	SDL_Rect srcRect = { 735, 106, 67, 132 }, destRect;
	SDL_Renderer* renderer;
	SDL_Event e;
};
