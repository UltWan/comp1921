typedef char* str;

typedef struct _sdl_init
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
  init;

init* SDL_Setup(char *name, int posX, int posY, int resX, int resY);

void renderColour(SDL_Renderer *ren, SDL_Rect *map, SDL_Rect *user, SDL_Rect *g, SDL_Rect *block, int blockNum);

SDL_Texture* renderText(SDL_Renderer *ren, str message, str f_type, int f_size, SDL_Color colour);

void renderTexture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, SDL_Rect *clip);

void cleanup(char *type, ...);
