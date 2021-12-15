#include "MyGame.h"
#include "TextureLoader.h"
#include "ctime"

void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
        }
    }
    else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::load_media(SDL_Renderer* renderer) {
    backgroundTexture = TextureLoader::load_texture(renderer, "../src/Assets/Images/PongBackground.bmp");
    if (backgroundTexture == nullptr) {
        printf("Failed to load BackgroundTexture \n");
    }
    player1 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", false);
    player2 = new Player(renderer, "../src/Assets/Images/PongBat.bmp", true);
    ball = new Ball(renderer, "../src/Assets/Images/Ball.bmp");
    game_data.balls.push_back(ball);
    ball = new Ball(renderer, "../src/Assets/Images/Ball.bmp");
    game_data.balls.push_back(ball);
    srand((unsigned)time(0));
    doubleBall = new DoubleBall(renderer, "../src/Assets/Images/DoubleBallPowerUp.png");
    plusOneBall = new PlusOneBall(renderer, "../src/Assets/Images/PlusOneBallPowerUp.png");
}


void MyGame::create_game_objects() {
    player1->set_rect((windowW / 4), 0);
    player2->set_rect(((windowW / 4) * 3) - 20, 0);
    game_data.balls[0]->set_rect(0,0);
    game_data.balls[1]->set_rect(0,0);
    doubleBall->start_timer();
    plusOneBall->start_timer();
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
    case SDLK_w:
        send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
        break;
    case SDLK_s:
        send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
        break;
    }
}

void MyGame::update() {
    player1->set_y_position(game_data.player1Y);
    player2->set_y_position(game_data.player2Y);
    game_data.balls[0]->set_y_position(game_data.ballY);
    game_data.balls[0]->set_x_position(game_data.ballX);
    game_data.balls[1]->set_y_position(game_data.ballY + 50);
    game_data.balls[1]->set_x_position(game_data.ballX + 50);
    
    std::vector<GameObject*> gameObjects;

    for (int it = 0; it < game_data.balls.size() ; ++it) {
        gameObjects.push_back(game_data.balls[it]);
    };
    doubleBall->updatePowerUp(gameObjects);
    plusOneBall->update(gameObjects);
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
    game_data.balls[0]->render();
    game_data.balls[1]->render();
    doubleBall->render();
    plusOneBall->render();
}