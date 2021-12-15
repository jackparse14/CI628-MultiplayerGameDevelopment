#ifndef ___BALL_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __BALL_H__

#include "GameObject.h"

class Ball : public GameObject {
public:
	Ball(SDL_Renderer* renderer, std::string path) : GameObject(renderer, path) {
		width = 10;
		height = 10;
	};
	void set_x_position(int x);
	
};

#endif