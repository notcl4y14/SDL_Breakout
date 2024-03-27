#pragma once

#include <map>
#include <SDL2/SDL.h>

class Input {
public:
	std::map<SDL_Scancode, bool> keys;

	Input ();
	~Input ();
	
	bool IsKeyDown (SDL_Scancode key);
	bool IsKeyUp (SDL_Scancode key);
	void _SetKey (SDL_Scancode key, bool value);
};