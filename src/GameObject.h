#ifndef __GAME_OBJECT_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __GAME_OBJECT_H__

#include <string>
#include "SDL.h"

class GameObject {
public:
    //  Constructor
    GameObject(SDL_Renderer* renderer, std::string path);
    //  Destructor
    //~GameObject();
    void set_y_position(int y);
    void set_rect(int x,int y);
    void render();
    int width = NULL;
    int height = NULL;
    int get_x_position();
    int get_y_position();
protected:
    int xPosition = NULL;
    int yPosition = NULL;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    SDL_Rect rect;
    SDL_Renderer* renderer;
    SDL_Texture* objectTexture;
};

#endif