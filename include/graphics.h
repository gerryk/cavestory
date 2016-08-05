#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <map>

/* Graphics class
 * Holds all information to do with graphics for the game
 */

struct SDL_Window;
struct SDL_Renderer;

class Graphics  {
public:
    Graphics();
    ~Graphics();
    /* SDL_Surface* loadImage
     * loads an image into the _spriteSheets map if it doesn't already exist.
     * Returns an image from the map whether it was just loaded or not.
     */
    SDL_Surface* loadImage(const std::string &filePath);

    /* void blitSurface
     * Draws a texture to a certain part of the screen
     */
    void blitSurface(SDL_Texture *source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    /* void flip
     * renders everything to the screen
     */
    void flip();

    /* void clear
     * clears the screen
     */
    void clear();

    /* SDL_Renderer getRenderer
     * Returns the renderer
     */
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheet;
};

#endif
