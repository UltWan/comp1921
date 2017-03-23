#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "gameData.h"
#include "gameFunctions.h"
#include "controlFunctions.h"

// initialise the game data

void init(void)
{
    SDL_Window *window = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
    
    atexit(SDL_Quit); // set for clean-up on exit

    SDL_CreateWindowAndRenderer(800, 480, 0, &window, &renderer);
    SDL_SetWindowTitle( window, "Circles eat squares");
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    square_surface = SDL_LoadBMP("images/square.bmp");
    sprite_surface = SDL_LoadBMP("images/sprite.bmp");
    background_surface = SDL_LoadBMP("images/background.bmp");

    square_texture = SDL_CreateTextureFromSurface(renderer, square_surface);
    sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);
    background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);

    square.x = 5;
    square.y = 5;

    sprite = square;
    oldsprite = sprite;

    dir = RIGHT;
    
    next_square();
    eaten = true;
    number = 0;

    return;
}

// read keyboard input

void input(void)
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    SDL_PumpEvents();

    if (state[SDL_SCANCODE_UP]) {
        dir = UP;
    } 
    else if (state[SDL_SCANCODE_DOWN]) {
        dir = DOWN;
    } 
    else if (state[SDL_SCANCODE_LEFT]) {
        dir = LEFT;
    } 
    else if (state[SDL_SCANCODE_RIGHT]) {
        dir = RIGHT;
    } 
    else if (state[SDL_SCANCODE_ESCAPE]) {
        exit(0);
    }
    return;
}

// update player position

bool update(void)
{
    oldsprite = sprite;

    switch (dir) {
        case UP:
            sprite.y = sprite.y - 1;
            break;
        case DOWN:
            sprite.y = sprite.y + 1;
            break;
        case LEFT:
            sprite.x = sprite.x - 1;
            break;
        case RIGHT:
            sprite.x = sprite.x + 1;
            break;
    }

    if (sprite.x < 0 || sprite.x > MAX_X || sprite.y < 0 || sprite.y > MAX_Y) {
        return false; // lose
    }

    if (sprite.x == square.x && sprite.y == square.y) {
        next_square();
        number++;
        eaten = true;  // eat square
    } else {
        eaten = false; // continue
    }

    return true;
}

// generate new square location

void next_square(void)
{
    square.x = (square.x * 6 + 1) % (MAX_X + 1);
    square.y = (square.y * 16 + 1) % (MAX_Y + 1);
}

// end of game

void gameover(void)
{
    printf("Score: %d\n", number);
    printf("Game Over\n");
    exit(0);
}

// render current game state

void render(void)
{
    if (eaten) 
        draw_object(square,square_texture); // draw new square if required
     
    draw_object(oldsprite,background_texture);   // redraw old location
    draw_object(sprite,sprite_texture);     // draw new location

    SDL_RenderPresent(renderer);

    return;
}

// draw game components

void draw_object( node object, SDL_Texture *texture ) 
{
    SDL_Rect rect;
    rect.h = TILE_SIZE;
    rect.w = TILE_SIZE;
    rect.x = object.x * TILE_SIZE;
    rect.y = object.y * TILE_SIZE;
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    return;
}

