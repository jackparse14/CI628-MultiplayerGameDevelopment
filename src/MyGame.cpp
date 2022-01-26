#include "MyGame.h"
#include "ctime"

/*void MyGame::init_audio() {
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
    sound = Mix_LoadWAV("drop.wav");
    if (sound == nullptr) {
        printf("Mix_LoadWAV: %s\n", Mix_GetError());
    }
    else {
        std::cout << "Sound effect loaded" << std::endl;
    }
}*/
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
        if (clientID == 0) {
            clientID = stoi(args.at(0));
        }
    }
    else if (cmd == "POWER_UP") {
        if (args.size() == 3) {
            game_data.powerUpX = stoi(args.at(0));
            game_data.powerUpY = stoi(args.at(1));
            game_data.powerUpNum = stoi(args.at(2));
            std::cout << game_data.powerUpNum << std::endl;
        }
    } else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::load_media(SDL_Renderer* renderer) {
    rend = renderer;
    textureLoader = new TextureLoader();
    backgroundTexture = textureLoader->load_texture(renderer, "../src/Assets/Images/PongBackground.bmp");
    if (backgroundTexture == nullptr) {
        printf("Failed to load BackgroundTexture \n");
    }
    player1 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", false);
    player2 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", true);
    powerUp = new PowerUp(rend, "");
    game_data.powerUpNum = 4;
    send("NO_POWERUP");
    srand((unsigned)time(0));
    //fontLoader = new FontLoader();
    //scoreFont = fontLoader->load_font("../src/Assets/Fonts/Gameplay.ttf",10);

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
    case SDLK_f:
        //play_sound();
        break;
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
        std::cout << "delete powerUp" << std::endl;
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
    
}

/*void MyGame::play_sound() {
    if (Mix_PlayChannel(-1, sound, 0) == -1) {
        printf("Error playing sound. Mix_PlayChannel: %s\n", Mix_GetError());
    }
}

void MyGame::destroy() {
    Mix_FreeChunk(sound);
    sound = nullptr;

    Mix_CloseAudio();
}*/