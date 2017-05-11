#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

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

void renderHard(SDL_Renderer *ren, SDL_Rect *map, SDL_Rect *user, SDL_Rect *g, SDL_Rect *car, SDL_Rect *car2, int carNum)
{
  SDL_RenderClear(ren);
  SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderFillRect(ren, map);
  SDL_SetRenderDrawColor(ren, 0xff, 0, 0, 0xff);
  SDL_RenderFillRect(ren, user);
  SDL_SetRenderDrawColor(ren, 0, 0, 0xff, 0xff);
  for (int i = 0; i < carNum; i++)
  {
    SDL_RenderFillRect(ren, car + i);
  }
  if (car2 != NULL)
  {
    for (int i = 0; i < carNum; i++)
    {
      SDL_RenderFillRect(ren, car2 + i);
    }
  }
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 0xff);
  SDL_RenderFillRect(ren, g);
  SDL_SetRenderDrawColor(ren, 0x99, 0, 0, 0xff);
  SDL_RenderPresent(ren);
}

SDL_Texture* renderText(SDL_Renderer *ren, string message, string f_type, int f_size, SDL_Color color)
{
  TTF_Font *ttf = TTF_OpenFont(f_type, f_size);
  if (ttf == NULL)
  {
    fprintf(stderr, "TTF_OpenFont: %s\n", SDL_GetError());
    return NULL;
  }
  SDL_Surface *temp = TTF_RenderText_Blended(ttf, message, color);
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

void renderTexture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, SDL_Rect *clip)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  if (clip != NULL)
  {
    dest.h = clip->h;
    dest.w = clip->w;
  }
  else
  {
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
  }
  SDL_RenderCopy(ren, tex, clip, &dest);
}

bool contains(SDL_Rect *bound, SDL_Rect *obj)
{
    int objTop		= obj->y;
    int objBottom	= obj->y + obj->h;
    int objLeft		= obj->x;
    int objRight	= obj->x + obj->w;

    int boundTop	= bound->y;
    int boundBottom	= bound->y + bound->h;
    int boundLeft	= bound->x;
    int boundRight	= bound->x + bound->w;

    if (objLeft < boundLeft || objTop < boundTop ||
        objRight > boundRight || objBottom > boundBottom)
    {
      return true;
  }
  return false;
}

bool crash(SDL_Rect *box1, SDL_Rect *box2)
{
  int b1Top    = box1->y;
  int b1Bottom = box1->y + box1->h;
  int b1Left   = box1->x;
  int b1Right  = box1->x + box1->w;

  int b2Top    = box2->y;
  int b2Bottom = box2->y + box2->h;
  int b2Left   = box2->x;
  int b2Right  = box2->x + box2->w;

  if (b1Left >= b2Right)
  {
    return false;
  }
  if (b1Right <= b2Left)
  {
    return false;
  }
  if (b1Top >= b2Bottom)
  {
    return false;
  }
  if (b1Bottom <= b2Top)
  {
    return false;
  }
return true;
}

bool Crash(SDL_Rect *player, SDL_Rect *car, int carNum)
{
  for (int i = 0; i < carNum; i++)
  {
    if (crash(car + i, player))
    {
      return true;
    }
  }
  return false;
}

void cleanup(char *type, ...)
{
  va_list objects;
  va_start(objects, type);

  while (*type != '\0')
  {
    if (*type == 't')
    {
      SDL_DestroyTexture(va_arg(objects, SDL_Texture *));
    }
    else if (*type == 'r')
    {
      SDL_DestroyRenderer(va_arg(objects, SDL_Renderer *));
    }
    else if (*type == 'w')
    {
      SDL_DestroyWindow(va_arg(objects, SDL_Window *));
    }
      type++;
  }
  va_end(objects);
}

SDL_Rect* addCars(int carNum)
{
  SDL_Rect *temp = (SDL_Rect*)malloc(carNum * sizeof(SDL_Rect));

  for (int i = 0; i < carNum; i++)
  {
      temp[i].x = 60 + i*20;
      temp[i].y = rand() % 440;
      temp[i].w = 20;
      temp[i].h = 20;
  }

  printf("Number of cars created = %d\n", carNum);
  return temp;
}

void roadCrossing(SDL_Rect *car, int carNum, int speed)
{
  for (int i = 0; i < carNum; i++)
  {
    if (i % 2 == 0)
    {
      car[i].y += (i + 1) % 3 * speed;

      if (car[i].y + car[i].h > 460)
      {
        car[i].y = 20;
      }
    }
    else
    {
      car[i].y -= (i + 1) % 3 * speed;

      if (car[i].y <= 20)
      {
        car[i].y = 460 - car[i].h;
      }
    }
  }
}
