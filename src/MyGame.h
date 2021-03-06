#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "SDL.h"
#include "Ball.h"
#include "PowerUp.h"
#include "FontLoader.h"
#include "TextureLoader.h"
#include "SDL_mixer.h"
#include "Score.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int powerUpX = 0;
    int powerUpY = 0;
    int powerUpNum = 0;
    int numBalls = 0;
    double ballsPosX[10];
    double ballsPosY[10];
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
    void spawn_ball(SDL_Renderer* renderer);
    void despawn_ball();
    void choose_power_up();
    void update_scores();
    void spawn_power_up(std::string path);
    void create_game_objects();
    const int windowW = 800;
    const int windowH = 600;
    void init_audio();
    void destroy();
    // FPS variables

private:
    SDL_Renderer* rend;
    std::vector<GameObject*> gameObjects;
    Player* player1;
    Player* player2;
    Score* player1Score;
    Score* player2Score;
    int clientID = 0;
    int numPlayers = 0;
    Mix_Chunk* hitwall_sound;
    Mix_Chunk* hitpowerup_sound;
    Mix_Chunk* newpowerup_sound;
    Mix_Chunk* hitplayer_sound;
    Ball* ball;
    //Power Ups
    PowerUp* powerUp;

    TextureLoader* textureLoader;
    SDL_Texture* backgroundTexture;

    FontLoader* fontLoader;
    TTF_Font* scoreFont;
    SDL_Texture* player1ScoreTexture;
    SDL_Texture* player2ScoreTexture;
    
    void play_sound(Mix_Chunk* sound);
    
};

#endif