#include "player.h"

void Player::set_rect(int x, int y, int w, int h) {
    set_height(h);
    set_width(w);
    set_y_position(y);
    set_x_position(x);
    rect = { this->positionX,this->positionY,width,height };
}

void Player::update_y_position(int y) {
    set_y_position(y);
    rect.y = positionY;
}