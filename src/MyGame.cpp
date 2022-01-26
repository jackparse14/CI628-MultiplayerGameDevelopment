#include "MyGame.h"
#include "ctime"

void MyGame::init_audio() {
    // open 44.1KHz, 
    // signed 16bit
    // system byte order, 
    // stereo audio,
    // using 1024 byte chunks
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        return;
    }

    // all good to go
    hitwall_sound = Mix_LoadWAV("../src/Assets/Audio/hitwall.wav");
    if (hitwall_sound == nullptr) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    else {
        std::cout << "Sound effect loaded" << std::endl;
    }
    hitpowerup_sound = Mix_LoadWAV("../src/Assets/Audio/hitpowerup.wav");   
    if (hitpowerup_sound == nullptr) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    else {
        std::cout << "Sound effect loaded" << std::endl;
    }
    hitplayer_sound = Mix_LoadWAV("../src/Assets/Audio/hitplayer.wav");
    if (hitplayer_sound == nullptr) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    else {
        std::cout << "Sound effect loaded" << std::endl;
    }
    newpowerup_sound = Mix_LoadWAV("../src/Assets/Audio/newpowerup.wav");
    if (newpowerup_sound == nullptr) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    else {
        std::cout << "Sound effect loaded" << std::endl;
    }
    Mix_Volume(-1, 2);
}
void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        game_data.numBalls = stoi(args.at(0));
        if (args.size() == (3+(game_data.numBalls*2))) {
            game_data.player1Y = stoi(args.at(1));
            game_data.player2Y = stoi(args.at(2));
            int it2 = 0;
            for (int it = 0; it < game_data.numBalls; it++) {
                if (it != 0) {
                    it2 += 2;
                }
                game_data.ballsPosX[it] = stoi(args.at(it2 + 3));
                game_data.ballsPosY[it] = stoi(args.at(it2 + 4));
            }
        }
    }
    else if (cmd == "PLAYERNUM") {
        numPlayers = stoi(args.at(0));
        if (numPlayers == 1) {
            clientID = 1;
        }
        else if (numPlayers == 2) {
            if (clientID == 0) {
                clientID = 2;
            }
        }
        else {
            std::cout << "TWO PLAYERS ALREADY IN GAME" << std::endl;
        }
    }
    else if (cmd == "POWER_UP") {
        if (args.size() == 3) {
            game_data.powerUpX = stoi(args.at(0));
            game_data.powerUpY = stoi(args.at(1));
            game_data.powerUpNum = stoi(args.at(2));
            if (game_data.powerUpNum == 4) {
                play_sound(hitpowerup_sound);
            }
            else {
                play_sound(newpowerup_sound);
            }
        }
    }
    else if (cmd == "SCORES") {
        if (args.size() == 2) {
            player1Score->score = args.at(0);
            player2Score->score = args.at(1);
            play_sound(hitwall_sound);
        }
    }
    else if (cmd == "HIT_WALL_UP" || cmd == "HIT_WALL_DOWN") {
        play_sound(hitwall_sound);
    }
    else if (cmd == "BALL_HIT_BAT1" || cmd == "BALL_HIT_BAT2") {
        play_sound(hitplayer_sound);
    }
    else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}
void MyGame::update_scores() {
    player1ScoreTexture = fontLoader->load_font_texture(rend, player1Score->score, player1Score->color, scoreFont, 10, 10);
    player2ScoreTexture = fontLoader->load_font_texture(rend, player2Score->score, player1Score->color, scoreFont, 10, 10);

}
void MyGame::load_media(SDL_Renderer* renderer) {
    rend = renderer;
    textureLoader = new TextureLoader();
    backgroundTexture = textureLoader->load_texture(renderer, "../src/Assets/Images/PongBackground.bmp");
    if (backgroundTexture == nullptr) {
        printf("Failed to load BackgroundTexture \n");
    }
    fontLoader = new FontLoader();
    player1Score = new Score(false);
    player2Score = new Score(true);
    scoreFont = fontLoader->load_font("../src/Assets/Fonts/Gameplay.ttf", 100);
    player1ScoreTexture = fontLoader->load_font_texture(renderer,"0", player1Score->color,scoreFont,10,10);
    player2ScoreTexture = fontLoader->load_font_texture(renderer, "0", player2Score->color, scoreFont, 10, 10);
    
    player1 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", false);
    player2 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", true);
    powerUp = new PowerUp(rend, "");
    game_data.powerUpNum = 4;
    send("NO_POWERUP");
    srand((unsigned)time(0));

}
void MyGame::spawn_ball(SDL_Renderer* renderer) {
    ball = new Ball(renderer, "../src/Assets/Images/Ball.bmp");
    game_data.balls.push_back(ball);
    auto it = std::find(game_data.balls.begin(), game_data.balls.end(), ball);
    int index = 0;
    if (it != game_data.balls.end())
    {
        index = it - game_data.balls.begin();
    }
    else {
        std::cout << "-1" << std::endl;
    }
    game_data.balls[index]->set_rect(0, 0);
}
void MyGame::despawn_ball() {
    game_data.balls.pop_back();
}


void MyGame::create_game_objects() {
    player1->set_rect((windowW / 4), 0);
    player2->set_rect(((windowW / 4) * 3) - 20, 0);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
    case SDLK_w:
        if (clientID == 1) {
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        }
        else if (clientID == 2) {
            send(event.type == SDL_KEYDOWN ? "I_DOWN" : "I_UP");
            break;
        }
        else {
            break;
        }
    case SDLK_s:
        if (clientID == 1) {
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
        }
        else if (clientID == 2) {
            send(event.type == SDL_KEYDOWN ? "K_DOWN" : "K_UP");
        break;
        }
        else {
            break;
        }
    }
}
void MyGame::choose_power_up() {
    if (game_data.powerUpNum == 0) {
        spawn_power_up("../src/Assets/Images/MinusOneBallPowerUp.png");
    }
    else if (game_data.powerUpNum == 1) {
        spawn_power_up("../src/Assets/Images/PlusOneBallPowerUp.png");
    }
    else if (game_data.powerUpNum == 2) {
        spawn_power_up("../src/Assets/Images/HalfBallPowerUp.png");
    }
    else if (game_data.powerUpNum == 3) {
        spawn_power_up("../src/Assets/Images/DoubleBallPowerUp.png");
    }
    else {
        powerUp->set_width_height(0, 0);
        powerUp->set_rect(0, 0);
    }
}
void MyGame::spawn_power_up(std::string path) {
    powerUp = new PowerUp(rend, path);
    powerUp->set_rect(game_data.powerUpX, game_data.powerUpY);
}
void MyGame::update() {
    player1->set_y_position(game_data.player1Y);
    player2->set_y_position(game_data.player2Y);
    if (game_data.numBalls > game_data.balls.size()){
        spawn_ball(rend);
    } else if (game_data.numBalls < game_data.balls.size()){
        despawn_ball();
    }
    for (int it = 0; it < game_data.balls.size() ; ++it) {
        game_data.balls[it]->set_y_position(game_data.ballsPosY[it]);
        game_data.balls[it]->set_x_position(game_data.ballsPosX[it]);
        
    };
       choose_power_up();
       update_scores();
}

void MyGame::render(SDL_Renderer* renderer) {
    // Render Background
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);
    // Render Players
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
    player1->render();
    player2->render();
    //SDL_RenderFillRect(renderer, &player1.rect);
    //SDL_RenderFillRect(renderer, &player2.rect);
    // Render Ball
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int it = 0; it < game_data.balls.size(); it++) {
        game_data.balls[it]->render();
    }
        powerUp->render();
        SDL_RenderCopy(renderer,player1ScoreTexture, nullptr,&player1Score->rect);
        SDL_RenderCopy(renderer, player2ScoreTexture, nullptr, &player2Score->rect);
}

void MyGame::play_sound(Mix_Chunk* sound) {
    if (Mix_PlayChannel(-1, sound, 0) == -1) {
        printf("Error playing sound. Mix_PlayChannel: %s\n", Mix_GetError());
    }
}

void MyGame::destroy() {
    Mix_FreeChunk(hitplayer_sound);
    hitplayer_sound = nullptr;
    Mix_FreeChunk(hitpowerup_sound);
    hitpowerup_sound = nullptr;
    Mix_FreeChunk(newpowerup_sound);
    newpowerup_sound = nullptr;
    Mix_FreeChunk(hitwall_sound);
    hitwall_sound = nullptr;
    Mix_CloseAudio();
}