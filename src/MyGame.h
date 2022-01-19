#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "SDL.h"
#include "Ball.h"
#include "DoubleBall.h"
#include "PlusOneBall.h"
#include "FontLoader.h"
#include "TextureLoader.h"
#include "SDL_mixer.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
    int ball2X = 0;
    int ball2Y = 0;
    int numBalls = 1;
    double ballsPos[1][2];
    std::vector<Ball*> balls;
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
    void create_game_objects();
    const int windowW = 800;
    const int windowH = 600;
    
    // FPS variables

private:
    Player* player1;
    Player* player2;
    
    Mix_Chunk* sound;
    Ball* ball;
    //Power Ups
    DoubleBall* doubleBall;
    PlusOneBall* plusOneBall;

    TextureLoader* textureLoader;
    SDL_Texture* backgroundTexture;

    FontLoader* fontLoader;
    TTF_Font* scoreFont;

    void init_audio();
    void play_sound();
    void destroy();
};

#endif