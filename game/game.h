typedef char* string;

typedef struct _sdl_init
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
  init;

SDL_Rect* addCars(int carNum);

void roadCrossing(SDL_Rect *car, int carNum, int speed);

bool Crash(SDL_Rect *player, SDL_Rect *car, int carNum);

void cleanup(char *type, ...);

init* SDL_Setup(char *name, int posX, int posY, int resX, int resY);

bool contains(SDL_Rect *bound, SDL_Rect *obj);

void renderHard(SDL_Renderer *ren, SDL_Rect *map, SDL_Rect *user, SDL_Rect *g, SDL_Rect *car, SDL_Rect *car2, int carNum);

bool crash(SDL_Rect *box1, SDL_Rect *box2);

SDL_Texture* renderText(SDL_Renderer *ren, string message, string f_type, int f_size, SDL_Color color);

void renderTexture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, SDL_Rect *clip);
