#include <SDL.h>
#include "shapes.h" 

#include "engine_constants.h"
#include "main.h"

extern struct Point* direction = NULL;

void normalize()
{
	if (direction->x != 0 && direction->y != 0)
	{
		direction->x = 0.7f * direction->x;
		direction->y = 0.7f * direction->y;
	}
}

void update(SDL_Event event)  
{
	if (event.key.type == SDLK_w)
	{
		direction->y = -1; 
	}
	if (event.key.type == SDLK_s)
	{
		direction->y = 1;
	}
	if (event.key.type == SDLK_a)
	{
		direction->x = -1;
	}
	if (event.key.type == SDLK_d)
	{
		direction->x = 1;
	}
}

void give_direction(void)
{
	SDL_Event event; 
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.type != SDLK_ESCAPE) {
				update(event);
				normalize();
			}
			else {
				is_running = FALSE; 
			}
			
			direction->x = 0; 
			direction->y = 0; 
		}
	}
	
}