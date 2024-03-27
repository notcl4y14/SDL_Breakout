#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Entity.h"

class Layout
{
public:
	std::vector<Entity> objects;

	Layout ();
	~Layout ();

	void Add (Entity obj);
	
	void Update ();
	void Render (SDL_Renderer* renderer);
};