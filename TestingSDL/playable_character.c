#include <SDL.h>
#include <SDL_surface.h>
 
#include "engine_constants.h"
#include "shapes.h"
#include "character.h"

void mouvement_func(float x, float y);
void render_func(SDL_Renderer* renderer);
void initialize(void);

struct Hitbox PC_hitbox = {
	.height = 4,
	.width = 4
};

extern struct Character playable_character = {
	.hp = 10,
	.ms = 100,
	.as = 0,

	.x = MIDDLE_WITDTH,
	.y = MIDDLE_HEIGHT,

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
	playable_character.x += (int)x * playable_character.ms;
	playable_character.y += (int)y * playable_character.ms;

	playable_character.hitbox.center.x += (int)x * playable_character.ms;
	playable_character.hitbox.center.y += (int)y * playable_character.ms;
}

void render_func(SDL_Renderer* renderer)
{
	
}

void initialize(void) 
{
	playable_character.sprite = SDL_LoadBMP_RW(SDL_RWFromFile("", "rb"), 1);

}
