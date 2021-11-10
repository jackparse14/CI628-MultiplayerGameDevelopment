#include "player.h"

void Player::create_player(int x, int y) {
    set_x_position(x);
    set_y_position(y);
    set_rect(width,height);
}

void Player::update_y_position(int y) {
    set_y_position(y);
    rect.y = positionY;
}