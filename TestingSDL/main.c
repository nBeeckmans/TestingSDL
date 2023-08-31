#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#include "engine_constants.h"
#include "playable_character.h"
#include "controls.h"


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL; 
extern int is_running = FALSE; 

static struct Point* direction;

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

void initialize_direction(void)
{
	direction = malloc(sizeof(direction)); 
	direction->x = 0; 
	direction->y = 0; 
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

	initialize_direction(); 
	return TRUE; 

}

int quit(void)
{
	free(direction); 
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window); 
	SDL_Quit(); 
	return 0; 
}

void update_input(void)
{
	direction = give_direction();
	
}
void update_game_state(void) 
{
	if(direction) playable_character.mouvement(direction->x, direction->y); 
}
void render_game(void)
{
	playable_character.render(renderer); 
}

int main(int agrc, char** argv)
{
	is_running = start();
	playable_character.initialize();

	while(is_running) 
	{
		update_input(); 
		update_game_state(); 
		render_game(); 
		//is_running = FALSE;
	}
	return quit();
}