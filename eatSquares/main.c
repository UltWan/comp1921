#include <stdbool.h>
#include <SDL2/SDL.h>

#include "controlFunctions.h"


int main( void )
{
    int delay = 160;

    init();   // setup the game data
    render(); // render initial state

    while( true ) {      // game loop

        input();           // keyboard input

        if( !update() )    // update and check
            gameover();    // if finished

        render();          // render new state

        SDL_Delay( delay );
    }
    return 0;
}

