#ifndef ___PLAYER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __PLAYER_H__

#include "GameObject.h"

class Player : public GameObject {
public:
    void create_player(int x, int y);
    void update_y_position(int y);
private:
    int startingY = 0;
    int startingX = 0;
    int width = 20;
    int height = 60;
};

#endif