#include <SDL.h>
#include <stdio.h>
#include "shapes.h" 

#include "engine_constants.h"
#include "main.h"

#if 1
#define WASD(c)
void print(char c);
#endif

static struct Point* direction;

void print(char c)
{
	fprintf(stderr, "%c", c);
}


void normalize()
{
	if (direction->x != 0 && direction->y != 0)
	{
		direction->x = 0.7f * direction->x;
		direction->y = 0.7f * direction->y;
	}
}

void inline update(union SDL_Event *event)  
{
	if (event->key.keysym.sym == SDLK_UP)
	{
		direction->y = -1; 
		WASD('W'); 
	}
	if (event->key.keysym.sym == SDLK_DOWN)
	{
		direction->y = 1;
		WASD('S');
	}
	if (event->key.keysym.sym == SDLK_LEFT)
	{
		direction->x = -1;
		WASD('A');
	}
	if (event->key.keysym.sym == SDLK_RIGHT)
	{
		direction->x = 1;
		WASD('D');
	}
}

struct Point* give_direction(void)
{
	free(direction); 
	union SDL_Event event;
	direction = malloc(sizeof(direction)); 
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym != SDLK_ESCAPE) {
				update(&event);
				normalize();
			}
			else {
				is_running = FALSE; 
				free(direction); 
				return NULL;
			}
			
		}
		direction->x = 0;
		direction->y = 0;
	}
	return direction;
}