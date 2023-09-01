#include <SDL.h>
#include <stdio.h>
#include "shapes.h" 

#include "engine_constants.h"
#include "main.h"

static struct Point direction;

void normalize()
{
	if (direction.x != 0 && direction.y != 0)
	{
		direction.x = 0.7f * direction.x;
		direction.y = 0.7f * direction.y;
	}
}

void inline update(union SDL_Event event)  
{
	if (event.key.keysym.sym == SDLK_w)
	{
		direction.y = -1; 
		return; 
	}
	if (event.key.keysym.sym == SDLK_s)
	{
		direction.y = 1;
		return; 
	}
	if (event.key.keysym.sym == SDLK_a)
	{
		direction.x = -1;
		return;
	}
	if (event.key.keysym.sym == SDLK_d)
	{
		direction.x = 1;
		return;
	}
	direction.x = 0; 
	direction.y = 0; 
	return; 
}

struct Point* give_direction(void)
{
	union SDL_Event event;
	direction.x = 0; 
	direction.y = 0; 
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym != SDLK_ESCAPE) {
				update(event);
				normalize();
			}
			else {
				is_running = FALSE;
				return NULL;
			}
		}
	}
	return &direction;
}