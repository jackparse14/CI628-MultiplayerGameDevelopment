#ifndef ___SCORE_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __SCORE_H__
#include "GameObject.h"

class Score : public GameObject {
private:
    void choose_score_type();
public:
    Score(SDL_Renderer* renderer, std::string path, bool isRightPlayer) : GameObject(renderer, path) {
        width = 20;
        height = 60;
        if (isRightPlayer) {
            flip_player();
        }
    };
};

#endif