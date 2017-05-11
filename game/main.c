#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

int main(int argc, char *argv[])
{
  int popup_x = 250, popup_y = 250, window_x = 700, window_y = 500;

  init *game = SDL_Setup("Cross the Road", popup_x, popup_y, window_x, window_y);

  if (TTF_Init() != 0)
  {
    fprintf(stderr, "TTF_Init: %s\n", SDL_GetError());
    cleanup("g", game->renderer, game->window);
    free(game);
    SDL_Quit();
    return 1;
  }

  SDL_Rect map;
  map.x = 5;
  map.y = 0;
  map.w = window_x - 2 * map.x;
  map.h = window_y - 2 * map.y;

  SDL_Rect user;
  user.w = 20;
  user.h = 20;
  user.x = map.x;
  user.y = window_y / 2 - user.h / 2;

  SDL_Rect end;
  end.w = user.w;
  end.h = user.h;
  end.x = window_x - map.x;
  end.y = window_y / 2 - end.h / 2;

  SDL_Rect winning;
  winning.h = map.h - 20;
  winning.w = map.w - 20;
  winning.x = map.x + 10;
  winning.y = map.y + 10;

  int carNum = 30;
  SDL_Rect *traffic = addCars(carNum);

  bool escape = false, win = false;
  SDL_Event event;

  while (!escape)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        escape = true;
        printf("Game closed\n");
        break;
      }
      if (event.type == SDL_KEYDOWN)
      {
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
          escape = true;
          printf("Escape pressed: Game closed\n");
             break;
          case SDLK_UP:
              user.y -= user.h;
             break;
          case SDLK_DOWN:
              user.y += user.h;
             break;
          case SDLK_LEFT:
              user.x -= user.w;
             break;
          case SDLK_RIGHT:
               user.x += user.w;
             break;
          default:
             break;
        }
      }
    }

    if (win)
    {
      SDL_SetRenderDrawColor(game->renderer, 0xff, 0xff, 0xff, 0xff);
      SDL_RenderFillRect(game->renderer, &winning);

      str f_type = "fonts/Gobold Blocky Italic.otf";
      SDL_Color color = {25, 25, 25, 25};
      SDL_Texture *message = renderText(game->renderer, "Victory!", f_type, 100, color);
      if (message == NULL)
      {
        cleanup("g", game->renderer, game->window);
        free(traffic);
        free(game);
        TTF_Quit();
        SDL_Quit();
             
        fprintf(stderr, "renderText: %s\n", SDL_GetError());
        return 1;
      }
      int message_h, message_w;
      SDL_QueryTexture(message, NULL, NULL, &message_w, &message_h);

      int x = window_x / 2 - message_w / 2;
      int y = window_y / 2 - message_h / 2;

      renderTexture(game->renderer, message, x, y, NULL);

      SDL_RenderPresent(game->renderer);
      }

      else
      {
        int counter = 0;
        roadCrossing(traffic, carNum, 1);

        if (contains(&map, &user) || crash(&user, traffic, carNum))
        {
          printf("Crashed\n");
          counter++;

          if (box2box(&end, &user))
          {
            win = true;
            printf("Victory!");
            //printf("%d\n", counter);
          }
          user.x = map.x;
          user.y = window_y / 2 - user.h / 2;
        }
        renderHard(game->renderer, &map, &user, &end, traffic, NULL, carNum);
        SDL_Delay(2);
      }
    }
    cleanup("g", game->renderer, game->window);
    free(traffic);
    free(game);
    SDL_Quit();

    return 0;
}
