#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "obstacles.h"

// checks if there are two variables

bool has(SDL_Rect *subj, SDL_Rect *obj)
{
    int subjTop	        = subj->y;
    int subjBottom	= subj->y + subj->h;
    int subjLeft	= subj->x;
    int subjRight	= subj->x + subj->w;

    int objTop		= obj->y;
    int objBottom	= obj->y + obj->h;
    int objLeft		= obj->x;
    int objRight	= obj->x + obj->w;

    if (objLeft < subjLeft || objTop < subjTop ||
        objRight > subjRight || objBottom > subjBottom)
    {
      return true;
  }
  return false;
}

// interaction between two boxes

bool box2box(SDL_Rect *boxA, SDL_Rect *boxB)
{
  int boxATop    = boxA->y;
  int boxABottom = boxA->y + boxA->h;
  int boxALeft   = boxA->x;
  int boxARight  = boxA->x + boxA->w;

  int boxBTop    = boxB->y;
  int boxBBottom = boxB->y + boxB->h;
  int boxBLeft   = boxB->x;
  int boxBRight  = boxB->x + boxB->w;

  if (boxALeft >= boxBRight)
  {
    return false;
  }
  if (boxARight <= boxBLeft)
  {
    return false;
  }
  if (boxATop >= boxBBottom)
  {
    return false;
  }
  if (boxABottom <= boxBTop)
  {
    return false;
  }
return true;
}

// collisions using box2box

bool crash(SDL_Rect *player, SDL_Rect *block, int blockNum)
{
  int i;
  for (i = 0; i < blockNum; i++)
  {
    if (box2box(block + i, player))
    {
      return true;
    }
  }
  return false;
}

// add blocks

SDL_Rect* addBlocks(int blockNum)
{
  SDL_Rect *temp = (SDL_Rect*)malloc(blockNum * sizeof(SDL_Rect));

  int i;
  for (i = 0; i < blockNum; i++)
  {
      temp[i].x = 60 + i*20;
      temp[i].y = rand() % 440;
      temp[i].w = 20;
      temp[i].h = 20;
  }

  printf("Number of cars created = %d\n", blockNum);
  return temp;
}

// vertical movement of blocks

void roadCrossing(SDL_Rect *block, int blockNum, int speed)
{
  int i;
  for (i = 0; i < blockNum; i++)
  {
    if (i % 2 == 0)
    {
      block[i].y += (i + 1) % 3 * speed;

      if (block[i].y + block[i].h > 460)
      {
        block[i].y = 20;
      }
    }
    else
    {
      block[i].y -= (i + 1) % 3 * speed;

      if (block[i].y <= 20)
      {
        block[i].y = 460 - block[i].h;
      }
    }
  }
}
