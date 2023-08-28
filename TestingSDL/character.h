#ifndef CHARACTER
#include "shapes.h"
#include <SDL.h>

typedef struct Character {
	//at initialization ! 
	int hp;
	float ms;
	float as;
	SDL_Surface* sprite; 

	//checked at everyframe
	float x;
	float y;

	struct Hitbox hitbox;
	
	// functions 
	void(*mouvement)(float, float);
	void(*render)(SDL_Renderer *);
	void(*initialize)(void); 

}Character;
#endif
