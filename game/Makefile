# code details

EXE_DIR = .
EXE = $(EXE_DIR)/game

SRC= main.c game.c obstacles.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image -lSDL2_ttf

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c game.h obstacles.h
game.o:  game.c game.h
obstacles.o: obstacles.c obstacles.h

