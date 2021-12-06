#ifndef ___PLAYER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __PLAYER_H__

#include "GameObject.h"

class Player : public GameObject {
private:
    void flip_player();
public:
    Player(SDL_Renderer* renderer, std::string path, bool isRightPlayer) : GameObject(renderer, path) {
        width = 20;
        height = 60;
        if (isRightPlayer) {
            flip_player();
        }
    };
};

#endif