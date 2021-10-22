#include "SDL.h"
#include <string>

class TextureLoader {
	public:
		static SDL_Texture* load_texture(SDL_Renderer* renderer, std::string path);
};