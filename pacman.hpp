#include<SDL.h>
#include <string>
#include <vector>
#include <fstream>
#pragma once

class Pacman{
bool come_back=false;
SDL_Rect srcRectf;
char flag = 'm';
SDL_Surface* foodImage;
// SDL_Renderer *gRenderer;
// SDL_Texture *assets;
char* grid;
int grid_w;
int grid_h;
int counter = 0;
int total_food = 392;

public:
    bool isRunning = true;
    bool isRunning2 = true;
    int lives = 3;
    SDL_Rect srcRect, moverRect;
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void animate();
    SDL_Rect move_pac_right();
    SDL_Rect move_pac_left();
    SDL_Rect move_pac_up();
    SDL_Rect move_pac_down();
    bool check_move_right();
    bool check_move_left();
    bool check_move_down();
    bool check_move_up();
    SDL_Rect* getMover();
    Pacman(char* grid_, int gridw, int gridh); // may add other overloaded constructors here... 
};
