#pragma once
#include <SDL2/SDL.h>

// ignore this class

class Object
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    void draw();
};