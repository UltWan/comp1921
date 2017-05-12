#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

// checks setup for errors

init* SDL_Setup(char *name, int popupX, int popupY, int windowX, int windowY)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
    return NULL;
  }

  SDL_Window *window = SDL_CreateWindow(name, popupX, popupY, windowX, windowY, SDL_WINDOW_SHOWN);

  if (window == NULL)
  {
    fprintf(stderr, "SDL_CreateWindow: %s\n", SDL_GetError());
    SDL_Quit();
    return NULL;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == NULL)
  {
    fprintf(stderr, "SDL_CreateRenderer: %s\n", SDL_GetError());
    cleanup("w", window);
    SDL_Quit();
    return NULL;
  }

  init *temp = (init*)malloc(sizeof(init));
  temp->window = window;
  temp->renderer = renderer;
  return temp;
}

// render colours for objects

void renderColour(SDL_Renderer *ren, SDL_Rect *map, SDL_Rect *user, SDL_Rect *g, SDL_Rect *block, int blockNum)
{
  SDL_RenderClear(ren);
  SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderFillRect(ren, map);
  SDL_SetRenderDrawColor(ren, 0xff, 0, 0, 0xff);
  SDL_RenderFillRect(ren, user);
  SDL_SetRenderDrawColor(ren, 0, 0, 0xff, 0xff);

  for (int i = 0; i < blockNum; i++)
  {
    SDL_RenderFillRect(ren, block + i);
  }

  SDL_SetRenderDrawColor(ren, 0, 0, 0, 0xff);
  SDL_RenderFillRect(ren, g);
  SDL_SetRenderDrawColor(ren, 0x99, 0, 0, 0xff);
  SDL_RenderPresent(ren);
}

// checks errors with TTF

SDL_Texture* renderText(SDL_Renderer *ren, str message, str f_type, int f_size, SDL_Color colour)
{
  TTF_Font *ttf = TTF_OpenFont(f_type, f_size);
  if (ttf == NULL)
  {
    fprintf(stderr, "TTF_OpenFont: %s\n", SDL_GetError());
    return NULL;
  }
  SDL_Surface *temp = TTF_RenderText_Blended(ttf, message, colour);
  if (temp == NULL)
  {
      fprintf(stderr, "TTF_RenderText_Blended: %s\n", SDL_GetError());
      TTF_CloseFont(ttf);
      return NULL;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, temp);
  if (texture == NULL)
  {
    fprintf(stderr, "SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
    TTF_CloseFont(ttf);
    SDL_FreeSurface(temp);
    return NULL;
  }
  TTF_CloseFont(ttf);
  SDL_FreeSurface(temp);
  return texture;
}

// render TTF

void renderMess(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, SDL_Rect *bit)
{
  SDL_Rect result;
  result.x = x;
  result.y = y;
  if (bit != 0)
  {
    result.h = bit->h;
    result.w = bit->w;
  }
  else
  {
    SDL_QueryTexture(tex, 0, 0, &result.w, &result.h);
  }
  SDL_RenderCopy(ren, tex, bit, &result);
}

// destroys renderer and window

void cleanup(char *type, ...)
{
  va_list objects;
  va_start(objects, type);

  while (*type != '\0')
  {
    if (*type == 'g')
    {
      SDL_DestroyRenderer(va_arg(objects, SDL_Renderer *));
    }
    else if (*type == 'g')
    {
      SDL_DestroyWindow(va_arg(objects, SDL_Window *));
    }
      type++;
  }
  va_end(objects);
}
