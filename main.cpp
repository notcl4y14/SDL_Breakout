#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"
#include "src/Vector2D.h"
#include "src/Input.h"
#include "src/Layout.h"
#include "src/Entity.h"
#include "src/util/SDL_Simple.h"

using namespace std;

Input input;
SDL_Window *Game_Window;
SDL_Renderer *Game_Renderer;
Layout Game_Layout;

// ====================================================

void GameLoop ();
void Update ();
void Render (SDL_Renderer* Game_Renderer);

int InitSDL ();
int CheckEvents ();

// ====================================================

int main(int argc, char **argv)
{
	if (InitSDL() == 1) return 1;
	input = Input();
	Game_Layout = Layout();

	Game_Layout.Add(Entity({20, 20}));

	bool quit = false;
	while (!quit)
	{
		if (CheckEvents() == 1) quit = true;
		GameLoop();
	}

	return 0;
}

// ====================================================

void GameLoop ()
{
	Update();
	Render(Game_Renderer);
}

void Update ()
{
	Game_Layout.Update();
}

void Render (SDL_Renderer* Game_Renderer)
{
    // Clear canvas
    SDLS_SetRenderDrawColor(Game_Renderer, COLOR_BLACK);
    SDL_RenderClear(Game_Renderer);

    // SDLS_SetRenderDrawColor(Game_Renderer, COLOR_PURPLE);
	SDLS_SetRenderDrawColor(Game_Renderer, COLOR_WHITE);
	Game_Layout.Render(Game_Renderer);

    // Apply changes
    SDL_RenderPresent(Game_Renderer);
}

// ====================================================

int InitSDL ()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

		return 1;
	}

	Game_Window = SDL_CreateWindow(
		"SDL Breakout :D",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);

	if (Game_Window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();

		return 1;
	}

	Game_Renderer = SDL_CreateRenderer(
		Game_Window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	
	if (Game_Renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;

		SDL_DestroyWindow(Game_Window);
		SDL_Quit();

		return 1;
	}
}

int CheckEvents ()
{
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		// Quit
		if (event.type == SDL_QUIT) {
			return 1;
		}

		// KeyDown
		else if (event.type == SDL_KEYDOWN) {
			SDL_Scancode code = event.key.keysym.scancode;

			input._SetKey(code, true);
		}
		
		// KeyUp
		else if (event.type == SDL_KEYUP) {
			SDL_Scancode code = event.key.keysym.scancode;

			input._SetKey(code, false);
		}

	}

	return 0;
}