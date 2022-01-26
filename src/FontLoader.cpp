#include "FontLoader.h"

TTF_Font* FontLoader::load_font(std::string path, int fontSize) {
	TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
	if (newFont == nullptr) {
		printf("TTF_Font Error: %s\n", TTF_GetError());
	}
	return newFont;
};
SDL_Texture* FontLoader::load_font_texture(SDL_Renderer* renderer,std::string textureText, SDL_Color textColor, TTF_Font* font, int width,int height)
{
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        SDL_Texture* texture;
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (texture == NULL)
        {
            printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        }
        //Get rid of old surface
        SDL_FreeSurface(textSurface);
        return texture;
    }
}
SDL_Rect* FontLoader::create_rect(SDL_Rect* rect,int x,int y, int w, int h) {
    rect->x = x;
    rect->w = w;
    rect->y = y;
    rect->h = h;
    return rect;
}

