#include <SDL2/SDL.h>
#include <vector>
// #include "Entity.h"
#include "Layout.h"

Layout::Layout () {}
Layout::~Layout () {}

void Layout::Add (Entity obj)
{
	objects.push_back(obj);
}

void Layout::Update ()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects.at(i).Update();
	}
}
void Layout::Render (SDL_Renderer* renderer)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects.at(i).Render(renderer);
	}
}