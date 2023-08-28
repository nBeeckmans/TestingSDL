#include <stdio.h>
#include <SDL.h>

#include "engine_constants.h"
#include "playable_character.h"


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL; 
int is_running = FALSE; 

int inline initialize_renderer()
{
	renderer = SDL_CreateRenderer(
		window,
		-1,
		0);

	if (!renderer)
	{
		fprintf(stderr, "renderer cant be initialize");
		return FALSE;
	}

	return TRUE; 
}

int inline initialize_window() 
{
	window = SDL_CreateWindow(
		"test_1",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		0);

	if (!window)
	{
		fprintf(stderr, "window cant be initialize");
		return FALSE;
	}
	return TRUE;
}

int start(void)
{
	 
	SDL_Init(SDL_INIT_EVERYTHING);
	int is_valid = initialize_window(); 

	if (!is_valid)
	{
		return FALSE; 
	}

	is_valid = initialize_renderer();

	if (!is_valid)
	{
		return FALSE; 
	}

	return TRUE; 
}

int quit(void)
{
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window); 
	SDL_Quit(); 
	return 0; 
}

int main(void)
{
	is_running = start();
	playable_character.initialize();

	while(is_running) 
	{
		
		for (int i = 0; i < 1000000; i++)
		{

		}
		is_running = FALSE; 
	}
	return quit();
}