#ifndef PLAYABLE_CHARACTER
#define PLAYABLE_CHARACTER
#include "character.h"

void mouvement_func(float x, float y);
void render_func(SDL_Renderer* renderer);
void initialize(void);

struct Character playable_character;

#endif 
