#ifndef CHARACTER
#include "shapes.h"
#include <SDL.h>

typedef struct Character {
	//at initialization ! 
	int hp;
	float ms;
	float as;
	struct SDL_Rect rect; 

	struct Hitbox hitbox;
	
	// functions 
	void(*mouvement)(float, float);
	void(*render)(SDL_Renderer *);
	void(*initialize)(void); 

}Character;
#endif
