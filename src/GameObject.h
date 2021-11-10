#ifndef __GAME_OBJECT_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __GAME_OBJECT_H__

#include <string>

class GameObject {
public:
    GameObject(SDL_Renderer* renderer, std::string path);
    void set_width(int w);
    void set_height(int h);
    void set_x_position(int x);
    void set_y_position(int y);
    void update();
    void render();
protected:
    int positionY;
    int positionX;
    int width;
    int height;
    SDL_Rect rect;
    SDL_Renderer* renderer;
    SDL_Texture* objectTexture;
};

#endif