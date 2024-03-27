#pragma once

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include "util/SDL_Simple.h"

class Entity
{
public:
	Vector2D pos;

	Entity (Vector2D pos);
	~Entity ();

	void Update ();
	void Render (SDL_Renderer* renderer);
};