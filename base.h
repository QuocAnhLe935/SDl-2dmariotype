#ifndef BASE_H
#define BASE_H
#include <SDL.h>
//#include "player.h"
class base {

	
public:
		static SDL_Rect coord;
		static const int TILE_SIZE = 50;
		bool collisionbase(SDL_Rect* rec1, SDL_Rect* rec2);
};

#endif // !BASE
