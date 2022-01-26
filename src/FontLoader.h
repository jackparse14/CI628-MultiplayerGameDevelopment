#ifndef __FONT_LOADER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __FONT_LOADER_H__

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class FontLoader {
public:
	static SDL_Texture* load_font_texture(SDL_Renderer* renderer,std::string path, SDL_Color textColor, TTF_Font* font, int width, int height);
	static TTF_Font* load_font(std::string path, int fontSize);
	static SDL_Rect* create_rect(SDL_Rect* rect,int x,int y,int w,int h);
};

#endif