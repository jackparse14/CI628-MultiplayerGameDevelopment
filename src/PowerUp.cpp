#include "PowerUp.h"

void PowerUp::start_timer() {
	startTime = SDL_GetTicks();
}

void PowerUp::update() {
	runningTime = SDL_GetTicks() - startTime;
}