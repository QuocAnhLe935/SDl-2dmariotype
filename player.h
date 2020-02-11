#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <SDL.h>

#include "base.h"

class player : public base
{
	SDL_Rect destrect;
	SDL_Rect box;
	SDL_Surface* image1;
	int xvel, yvel;
	SDL_Rect clips[4];
	bool ground;
public:
	player();
	~player();
	player(SDL_Surface* img);
	SDL_Rect* getRect();
	void setXvel(int vel);
	int getXvel();
	void move(const std::vector < std::vector<int> > &test);
	void show(SDL_Surface* screen);
};

#endif // !PLAYER_H