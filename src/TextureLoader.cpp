#include "TextureLoader.h"
#include <SDL_image.h>

SDL_Texture* TextureLoader::load_texture(SDL_Renderer* renderer, std::string path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("SDL_Image Error: %s\n", IMG_GetError());
    }
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == nullptr) {
        printf("SDL_Texture Error: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}