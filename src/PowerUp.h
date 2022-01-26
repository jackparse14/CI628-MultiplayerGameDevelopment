#ifndef __POWER_UP_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __POWER_UP_H__

#include "GameObject.h"
#include <vector>

class PowerUp : public GameObject {
public:
	PowerUp(SDL_Renderer* renderer, std::string path) : GameObject(renderer, path) {
		width = 45;
		height = 45;
	};
	void set_width_height(int w, int h);
	/*
	void spawnPowerUp();
	void updatePowerUp(std::vector<GameObject*> balls);
	void start_timer();
	bool hasCollided = false;*/
private:
	/*Uint32 startTime;
	Uint32 runningTime;
	Uint32 spawnDelay = 1000;
	
	int randomNumberGen(int min,int max);
	bool hasSpawned = false;
	
	void despawnPowerUp();
	void collision_detection(std::vector<GameObject*> balls);*/
	
};

#endif