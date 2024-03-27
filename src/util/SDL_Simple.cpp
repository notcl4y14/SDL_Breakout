#include "SDL2/SDL.h"
#include "SDL_Simple.h"

struct SDLS_Color;
// struct SDLS_Color
// {
// 	int R;
// 	int G;
// 	int B;
// 	int A;
// };

// SDLS_Color const COLOR_BLACK = { 0, 0, 0, 255 };
// SDLS_Color const COLOR_WHITE = { 255, 255, 255, 255 };
// SDLS_Color const COLOR_RED = { 255, 0, 0, 255 };
// SDLS_Color const COLOR_BLUE = { 0, 255, 0, 255 };
// SDLS_Color const COLOR_GREEN = { 0, 0, 255, 255 };
// SDLS_Color const COLOR_PURPLE = { 255 / 2, 0, 255 / 2, 255 };

int SDLS_SetRenderDrawColor(SDL_Renderer* renderer, SDLS_Color color)
{
	return SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
}