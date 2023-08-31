#ifndef CHARACTER
#include "shapes.h"

#ifdef __linux__ 
    #include <SDL2/SDL.h>
#elif _WIN32
    #include <SDL.h>
#else
#endif

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
