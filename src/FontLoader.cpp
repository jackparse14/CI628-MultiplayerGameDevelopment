#include "FontLoader.h"

TTF_Font* FontLoader::load_font(std::string path, int fontSize) {
	TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
	if (newFont == nullptr) {
		printf("TTF_Font Error: %s\n", TTF_GetError());
	}
	return newFont;
};