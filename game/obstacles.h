bool contains(SDL_Rect *subj, SDL_Rect *obj);

bool box2box(SDL_Rect *box1, SDL_Rect *box2);

bool crash(SDL_Rect *player, SDL_Rect *block, int blockNum);

SDL_Rect* addBlocks(int blockNum);

void roadCrossing(SDL_Rect *block, int blockNum, int speed);
