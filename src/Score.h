#ifndef ___SCORE_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __SCORE_H__
#include <SDL_rect.h>
#include <string>;
class Score {
private:
    int width;
    int height;
    int x;
    int y;
    void create_rect();
public:
    Score(bool isRightScore){
        width = 50;
        height = 50;
        if (isRightScore) {
            x = 450;
        }
        else {
            x = 300;
        }
        y = 100;
        create_rect();
        color.r = (Uint8)300;
        color.g = (Uint8)100;
        color.b = (Uint8)100;
    };
    SDL_Rect rect;
    SDL_Color color;
    std::string score = "0";
};

#endif