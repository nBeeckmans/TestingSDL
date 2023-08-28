#ifndef SHAPES
#define SHAPES 

typedef struct Point {
	float x;
	float y;
}Point;

typedef struct Hitbox {
	Point center; 
	int width;
	int height;
} hitbox;

#endif // !SHAPES