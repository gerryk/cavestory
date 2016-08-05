#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"

/* Graphics class
 * Holds all information to do with graohics for the game
 */

Graphics::Graphics()    {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics()   {
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)   {
    if (this->_spriteSheet.count(filePath) == 0)    {
        this->_spriteSheet[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheet[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()   {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()  {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}



