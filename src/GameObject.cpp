#include "GameObject.h"
#include "TextureLoader.h"

GameObject::GameObject(SDL_Renderer* render, std::string texturePath) {
	renderer = render;
	objectTexture = TextureLoader::load_texture(renderer, texturePath);
	if (objectTexture == nullptr) {
		printf("Failed to load objectTexture \n");
	}
}
void GameObject::set_y_position(int y) {
	yPosition = y;
	rect.y = yPosition;
}
void GameObject::set_rect(int x, int y) {
	xPosition = x;
	yPosition = y;
	rect = {x,y,width,height};
}
void GameObject::render() {
	SDL_RenderCopyEx(renderer, objectTexture, NULL, &rect,NULL,NULL, flipType);
}  
int GameObject::get_x_position() {
	return xPosition;
}
int GameObject::get_y_position() {
	return yPosition;
}