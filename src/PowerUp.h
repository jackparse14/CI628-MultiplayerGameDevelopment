#ifndef __POWER_UP_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __POWER_UP_H__

#include "GameObject.h"

class PowerUp : public GameObject {
public:
private:
	Uint32 startTime;
	Uint32 runningTime;
	void start_timer();
	void update();
};

#endif