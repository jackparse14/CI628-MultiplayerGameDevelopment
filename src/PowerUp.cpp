#include "PowerUp.h"
#include <iostream>

/*void PowerUp::start_timer() {
	startTime = SDL_GetTicks();
}

void PowerUp::updatePowerUp(std::vector<GameObject*> balls) {
	/*runningTime = SDL_GetTicks() - startTime;
	if (runningTime > spawnDelay && hasSpawned == false) {
		set_width_height(45,45);
		spawnPowerUp();
		hasSpawned = true;
		hasCollided = false;
	}
	collision_detection(balls);
}
void PowerUp::despawnPowerUp() {
	hasSpawned = false;
	set_width_height(0,0);
	set_rect(0,0);
	render();
	start_timer();
}

void PowerUp::collision_detection(std::vector<GameObject*> balls) {
	for (int it = 0; it < balls.size(); ++it) {
		if (rect.x < balls[it]->get_x_position() + balls[it]->width &&
			rect.x + width > balls[it]->get_x_position() &&
			rect.y < balls[it]->get_y_position() + balls[it]->height &&
			height + rect.y > balls[it]->get_y_position()) {
			hasCollided = true;
			despawnPowerUp();
		}
	}
}

void PowerUp::spawnPowerUp() {
	set_rect(randomNumberGen(0,800 - height),randomNumberGen(0,600 - width));
}

int PowerUp::randomNumberGen(int min,int max) {
	return (rand() % (max - min) + min);
}*/
void PowerUp::set_width_height(int w,int h) {
	width = w;
	height = h;
}