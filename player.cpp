#include "player.h"



player::player()
{
}


player::~player()
{
	delete image1;

}

player::player(SDL_Surface * img)
{
	image1 = img;
	box.x = 0;
	box.y = 0;
	box.w = 50;
	box.h = 100;
	xvel = 0;
	yvel = 0;
	for (int i = 0; i < 4; i++)
	{
		clips[i].x = i * 50;
		clips[i].y = 0;
		clips[i].w = clips[i].h = 50;
	}
	ground = 0;
}

SDL_Rect * player::getRect()
{
	return &box;
}

void player::setXvel(int vel)
{
	xvel = vel;
}

int player::getXvel()
{
	return xvel;
}

void player::move(const std::vector<std::vector<int>>& test)
{
	int start = (base::coord.x - (base::coord.x % base::TILE_SIZE)) / base::TILE_SIZE;
	int end = (base::coord.x + base::coord.w + (base::TILE_SIZE - (base::coord.x + base::coord.w) % base::TILE_SIZE)) / 50;
	if (start < 0)
		start = 0;
	if (end > test[0].size())
		end = test[0].size();

	bool nc = 0;
	for (int i = 0; i < test.size(); i++){
		for (int j = 0; j < end; j++) { 
			if (test[i][j] == 0)
				continue;
			//SDL_Rect destrect = { j * 50 - base::coord.x, i * 50,50,50 };
			destrect = { j * 50 - base::coord.x, i * 50,50,50 };
			if (collisionbase(&box, &destrect)) {
				nc = 1;
				if (destrect.y >= box.y + box.h-11 ) {//-11

					ground = 1;
					yvel = 1;//0
				}
				else if (destrect.y + destrect.h <= box.y+11 )//+11
				{
					box.x++;
					yvel = 5;//5
				}				//>=				//-5								+6									20
				if (box.x + box.w >= destrect.x  && box.y-5 + box.h >= destrect.y  && box.x+6 + box.w <= destrect.x+20){//-5+6+20 
					xvel = 0;//0
					box.x--;
				}
				else if (box.x <= destrect.x + destrect.w&& box.y + box.h >= destrect.y ) {//6
					xvel = 0;
					box.x++;
				}


			}
		}
	}
	
	if (!nc) {
		yvel = 35;//5   35
		
		
	}

	box.x += xvel;
	box.y += yvel;
}

void player::show(SDL_Surface * screen)
{
	SDL_BlitSurface(image1, &clips[0], screen, &box);
}
