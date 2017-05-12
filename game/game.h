typedef char* str;

typedef struct SDL_Init
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
  init;

init* SDL_Setup(char *name, int popupX, int popupY, int windowX, int windowY);

void renderColour(SDL_Renderer *ren, SDL_Rect *map, SDL_Rect *user, SDL_Rect *g, SDL_Rect *block, int blockNum);

SDL_Texture* renderText(SDL_Renderer *ren, str message, str f_type, int f_size, SDL_Color colour);

void renderMess(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, SDL_Rect *bit);

void cleanup(char *type, ...);
