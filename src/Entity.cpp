#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Entity.h"
// #include "Vector2D.h"
// #include "util/SDL_Simple.h"

using namespace std;

TTF_Font* font = TTF_OpenFont("assets/VT323-Regular.ttf", 24);

Entity::Entity (Vector2D pos)
{
	this->pos = pos;
}

Entity::~Entity () {}

void Entity::Update () {}
void Entity::Render (SDL_Renderer* renderer) {
	SDLS_SetRenderDrawColor(renderer, COLOR_WHITE);
	SDL_RenderDrawPoint(renderer, pos.x, pos.y);

	// const char* text = pos.x + "; " + pos.y;
	const char* text = "; ";
	// https://stackoverflow.com/a/22889483
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, SDL_Color {255, 255, 255, 255}); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = pos.x;  //controls the rect's x coordinate 
	Message_rect.y = pos.y; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 10; // controls the height of the rect

	// (0,0) is on the top left of the window/screen,
	// think a rect as the text's box,
	// that way it would be very simple to understand

	// Now since it's a texture, you have to put RenderCopy
	// in your game loop area, the area where the whole code executes

	// you put the renderer's name first, the Message,
	// the crop size (you can ignore this if you don't want
	// to dabble with cropping), and the rect which is the size
	// and coordinate of your texture
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}