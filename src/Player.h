#ifndef ___PLAYER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __PLAYER_H__

#include "GameObject.h"
#include <SDL_rect.h>

class Player : public GameObject {
public:
    void set_rect(int x, int y, int w, int h);
    void update_y_position(int y);
    SDL_Rect rect;
};

#endif