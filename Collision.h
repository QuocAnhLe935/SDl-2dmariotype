#ifndef COLLISION_H
#define COLLISION_H
#include "Vector.h"
#include "Ball.h"
#include "VMath.h"
#include <SDL.h>
class Collision: public Body, public GameObject

{
public:
	static bool Collisions(Ball *ball,  Ball *ball2);
	static void ResponseCollision(Ball *ball, Ball *ball2);

};

#endif