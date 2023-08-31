#include <stdio.h>

#ifdef __linux__ 
    #include <SDL2/SDL.h>
	#include <SDL2/SDL_surface.h>
#elif _WIN32
    #include <SDL.h>
	#include <SDL_surface.h>
#else
#endif
 
#include "engine_constants.h"
#include "shapes.h"
#include "character.h"

void mouvement_func(float x, float y);
void render_func(SDL_Renderer* renderer);
void initialize(void);

extern struct Character playable_character = {
	.hp = 10,
	.ms = 1,
	.as = 0,

	.rect = {.w = 10, .h = 10, .x = 10, .y = 10 },

	.hitbox = {.center =
				{.x = MIDDLE_WITDTH, .y = MIDDLE_HEIGHT},
				.height = 4,
				.width = 4},

	.mouvement = mouvement_func,
	.render = render_func,
	.initialize = initialize
};

void mouvement_func(float x, float y)
{
	playable_character.rect.x = playable_character.rect.x +(int) x * playable_character.ms;
	playable_character.rect.y = playable_character.rect.y +(int) y * playable_character.ms;

	playable_character.hitbox.center.x += (int)x * playable_character.ms;
	playable_character.hitbox.center.y += (int)y * playable_character.ms;
}

void render_func(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer); 
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
	SDL_RenderDrawRect(renderer, &playable_character.rect);
	SDL_RenderFillRect(renderer, &playable_character.rect);
	SDL_RenderPresent(renderer);
}

void initialize(void) 
{
	//playable_character.sprite = SDL_LoadBMP_RW(SDL_RWFromFile("sprite.bmp", "rb"), 1);
	//if (!playable_character.sprite)
	//{
	//	fprintf(stderr, "cant load sprite !" );
	//}
}
