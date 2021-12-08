#include "PowerUp.h"
#include <iostream>
void PowerUp::start_timer() {
	startTime = SDL_GetTicks();
}

void PowerUp::update() {
	runningTime = SDL_GetTicks() - startTime;
	if (runningTime > spawnDelay) {
		spawnPowerUp();
		start_timer();
	}
}
void PowerUp::despawnPowerUp() {
	
}

void PowerUp::spawnPowerUp() {
	set_rect(randomNumberGen(0,800),randomNumberGen(0,600));
}

int PowerUp::randomNumberGen(int min,int max) {
	return (rand() % (max - min) + min);
}