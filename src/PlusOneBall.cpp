#include "PlusOneBall.h"
#include <iostream>
void PlusOneBall::add_ball(std::vector<GameObject*>& balls) {

};
void PlusOneBall::update(std::vector<GameObject*>& balls) {
	updatePowerUp(balls);
	if (hasCollided == true) {
		add_ball(balls);
	}
};