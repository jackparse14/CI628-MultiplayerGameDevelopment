#ifndef __POWER_UP_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __POWER_UP_H__

#include "GameObject.h"

class PowerUp : public GameObject {
public:
	PowerUp(SDL_Renderer* renderer, std::string path) : GameObject(renderer, path) {
		width = 15;
		height = 15;
	};
	void spawnPowerUp();
	void update();
private:
	Uint32 startTime;
	Uint32 runningTime;
	Uint32 spawnDelay = 1000;
	void start_timer();
	int randomNumberGen(int min,int max);
	bool isVisible = false;
	void despawnPowerUp();
};

#endif