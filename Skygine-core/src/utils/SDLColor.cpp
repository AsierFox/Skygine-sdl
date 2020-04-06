#include "SDLUtils.h"

SDL_Color SDLUtils::getSDLColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Color col = { r,g,b,a };
    return col;
}
