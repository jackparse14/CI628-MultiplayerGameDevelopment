#include "GameObject.h"
#include "TextureLoader.h"

GameObject::GameObject(SDL_Renderer* render, std::string texturePath) {
	renderer = render;
	objectTexture = TextureLoader::load_texture(renderer, texturePath);
}

void GameObject::set_width(int w) {
	width = w;
}
void GameObject::set_height(int h) {
	height = h;
}
void GameObject::set_x_position(int x) {
	positionX = x;
}
void GameObject::set_y_position(int y) {
	positionY = y;
}

void GameObject::update() {	

}
void GameObject::render() {

}