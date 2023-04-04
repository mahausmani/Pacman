#pragma once
#include<SDL.h>

//ignore this class

class Object{
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
public:
    void draw();
};