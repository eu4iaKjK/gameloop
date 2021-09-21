#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("E&W Studio", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false);

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->HandleEvent();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);

	}
	
	game->Clean();

	return 0;
}