#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "obstacles.h"

bool contains(SDL_Rect *subj, SDL_Rect *obj)
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

// player to box interaction

bool box2box(SDL_Rect *box1, SDL_Rect *box2)
{
  int box1Top    = box1->y;
  int box1Bottom = box1->y + box1->h;
  int box1Left   = box1->x;
  int box1Right  = box1->x + box1->w;

  int box2Top    = box2->y;
  int box2Bottom = box2->y + box2->h;
  int box2Left   = box2->x;
  int box2Right  = box2->x + box2->w;

  if (box1Left >= box2Right)
  {
    return false;
  }
  if (box1Right <= box2Left)
  {
    return false;
  }
  if (box1Top >= box2Bottom)
  {
    return false;
  }
  if (box1Bottom <= box2Top)
  {
    return false;
  }
return true;
}

// collision c

bool crash(SDL_Rect *player, SDL_Rect *block, int blockNum)
{
  for (int i = 0; i < blockNum; i++)
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

  for (int i = 0; i < blockNum; i++)
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
  for (int i = 0; i < blockNum; i++)
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
