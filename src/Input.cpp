#include <map>
#include <SDL2/SDL.h>
#include "Input.h"

Input::Input() {}
Input::~Input() {}

bool Input::IsKeyDown (SDL_Scancode key)
{
	return keys[key] == true;
}

bool Input::IsKeyUp (SDL_Scancode key)
{
	return keys[key] == false;
}

void Input::_SetKey (SDL_Scancode key, bool value)
{
	keys[key] = value;
}