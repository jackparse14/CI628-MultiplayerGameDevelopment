#ifndef __PLUS_ONE_BALL__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __PLUS_ONE_BALL__

#include "PowerUp.h"

class PlusOneBall : public PowerUp {
	using PowerUp::PowerUp;
public:
	void add_ball(std::vector<GameObject*>& balls);
	void update(std::vector<GameObject*>& balls);
};

#endif