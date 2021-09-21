#include "game.h"
#include "TextureManager.h"
#include "player.h"
using namespace std;

Player* player;

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystem initialized!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) cout << "Window created!..." << endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Render is created!..." << endl;
		}
		isRunning = true;
	}
	else isRunning = false;

	player = new Player("assets/player.png", renderer, 0, 0);
}

void Game::HandleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				player->ypos -= 5;
				break;
			case SDLK_DOWN:
				player->ypos += 5;
				break;
			case SDLK_LEFT:
				player->xpos -= 5;
				break;
			case SDLK_RIGHT:
				player->xpos += 5;
				break;
			default:
				break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update()
{
	player->Update();
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	cout << "Game cleaned!..." << endl;
}
