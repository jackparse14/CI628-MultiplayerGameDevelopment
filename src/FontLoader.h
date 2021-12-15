#ifndef __FONT_LOADER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __FONT_LOADER_H__

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class FontLoader {
public:
	static TTF_Font* load_font(std::string path, int fontSize);
};

#endif