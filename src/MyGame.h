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
class GameObject {
    public:
        void set_width(int w) {
            width = w;
        };
        void set_height(int h) {
            height = h;
        };
        void set_x_position(int x) {
            positionX = x;
        }
        void set_y_position(int y) {
            positionY = y;
        }
    protected:
        int positionY;
        int positionX;
        int width;
        int height;
};
class Player: public GameObject {
    public:
        void set_rect(int x,int y,int w, int h) {
             set_height(h);
             set_width(w);
             set_y_position(y);
             set_x_position(x);
             rect = {this->positionX,this->positionY,width,height};
        }
        void update_y_position(int y) {
            set_y_position(y);
            rect.y = positionY;
        };
        SDL_Rect rect;
};
class Ball : public GameObject {
    public:
        
};

class MyGame {
    public:
        std::vector<std::string> messages;
        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
        void load_media(SDL_Renderer* renderer);
        void create_game_objects();
        const int windowW = 800;
        const int windowH = 600;
        // FPS variables
        
    private:
        Player player1;
        Player player2;
        //SDL_Rect player1 = { (windowW / 4), 0, 20, 60 };
        //SDL_Rect player2 = { ((windowW / 4) * 3) - 20, 0, 20, 60 };
        SDL_Rect ball = { 0,0,10,10 };
        SDL_Texture* backgroundTexture;
        SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);
};

#endif