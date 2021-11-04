#ifndef __TEXTURE_LOADER_H__	// To make sure you don't declare the function more than once by including the header multiple times.
#define __TEXTURE_LOADER_H__

#include "SDL.h"
#include <string>

class TextureLoader {
	public:
		static SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);
};

#endif