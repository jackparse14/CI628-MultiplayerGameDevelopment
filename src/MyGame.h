#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
} game_data;

class MyGame {
    public:
        std::vector<std::string> messages;
        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
        void load_media(SDL_Renderer* renderer);
        const int windowW = 800;
        const int windowH = 600;
    private:
        SDL_Rect player1 = { (windowW/4), 0, 20, 60 };
        SDL_Rect player2 = { ((windowW/4)*3)-20, 0, 20, 60 };
        SDL_Rect ball = {0,0,10,10};
        SDL_Texture* backgroundTexture;
        SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);
};

#endif