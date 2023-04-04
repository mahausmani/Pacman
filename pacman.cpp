#include "pacman.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// pigeon implementation will go here.


void Pacman::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){

    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
  
    }
bool Pacman::check_move_right(){
    if(counter==total_food){
        isRunning = false;
    }
    bool canMove = true;
    int x = moverRect.x+25;
    int y = moverRect.y;
    char c;
    for(int i = 0; i < grid_h; i++){
		for(int j = 0; j<grid_w; j++){
            c = *(grid+i*grid_w + j);  
            if(i==y/25 & j==x/25 & c=='x'){
                return canMove=false;
                break;
            }
            else if(i==y/25 & j==x/25 & c=='.'){
                canMove=true;
                *(grid+i*grid_w + j) = ' ';  //replaced
                counter++;
                break;
            }
            else if(i==y/25 & j==x/25 & c==' '){
                canMove=true;
                break;
            }
        }
    }
    return canMove;
}

bool Pacman::check_move_left(){
    if(counter==total_food){
        isRunning = false;
    }
    bool canMove = true;
    int x = moverRect.x-25;
    int y = moverRect.y;
    char c;
    for(int i = 0; i < grid_h; i++){
		for(int j = 0; j<grid_w; j++){
            c = *(grid+i*grid_w + j);  
            if(i==y/25 & j==x/25 & c=='x'){
                return canMove=false;
                break;
            }
            else if(i==y/25 & j==x/25 & c=='.'){
                canMove=true;
                *(grid+i*grid_w + j) = ' ';//replaced
                counter++;
                break;
            }
            else if(i==y/25 & j==x/25 & c==' '){
                canMove=true;
                break;
            }
        }
    }
    
    return canMove;
}
bool Pacman::check_move_down(){
    if(counter==total_food){
        isRunning = false;
    }
    if(lives==0){
        isRunning2 = false;
    }
    bool canMove = true;
    int x = moverRect.x;
    int y = moverRect.y+25;
    char c;
    for(int i = 0; i < grid_h; i++){
		for(int j = 0; j<grid_w; j++){
            c = *(grid+i*grid_w + j);  
            if(i==y/25 & j==x/25 & c=='x'){
                return canMove=false;
                break;
            }
            else if(i==y/25 & j==x/25 & c=='.'){
                canMove=true;
                *(grid+i*grid_w + j) = ' ';   //replaced
                counter++;
                break;
            }
            else if(i==y/25 & j==x/25 & c==' '){
                canMove=true;
                break;
            }
        }
    }
    
    return canMove;
} 
bool Pacman::check_move_up(){
    if(counter==total_food){
        isRunning = false;
    }
    bool canMove = true;
    int x = moverRect.x;
    int y = moverRect.y-25;
    char c;
    for(int i = 0; i < grid_h; i++){
		for(int j = 0; j<grid_w; j++){
            c = *(grid+i*grid_w + j);  
            if(i==y/25 & j==x/25 & c=='x'){
                return canMove=false;
                break;
            }
            else if(i==y/25 & j==x/25 & c=='.'){
                canMove=true;
                *(grid+i*grid_w + j) = ' ';//replaced
                counter++;
                break;
            }
            else if(i==y/25 & j==x/25 & c==' '){
                canMove=true;
                break;
            }
        }
    }
    
    return canMove;
} 

void Pacman::animate(){
   
    come_back=true;
    moverRect.x+=10;
}

SDL_Rect Pacman :: move_pac_right(){    //changes the image of pacman depending on its direction
    srcRect = {273,949,25,25};
    moverRect.x += 25;
    return moverRect;
}

SDL_Rect Pacman :: move_pac_left(){
    srcRect = {342,882,25,25};
    moverRect.x -= 25;
    return moverRect;
}

SDL_Rect Pacman :: move_pac_up(){
    srcRect = {346,949,25,25};
    moverRect.y -= 25;
    return moverRect;
    
    
}

SDL_Rect Pacman :: move_pac_down(){
    srcRect = {270,880,25,25};
    moverRect.y += 25;
    return moverRect;
}

SDL_Rect* Pacman:: getMover(){
    return &moverRect;
}

Pacman::Pacman(char* grid_, int gridw, int gridh){
    srcRect = {273,949,25,25};
    grid = grid_;
    grid_w = gridw;
    grid_h = gridh;
    moverRect = {50, 100, 25, 25};
    
}

