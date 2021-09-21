#pragma once

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void HandleEvent();
	void Update();
	void Render();
	void Clean();

	bool running() { return isRunning; }
private:
	int count;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};



#endif

