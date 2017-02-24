
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/quadtree

SRC= main.c node.c output.c

# generic build details

CC=      cc
COPT=    -O
CFLAGS=  -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up object files

clean:
	rm -f $(OBJ)

# clean up compilation

cleaner:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c functions.h
node.o: node.c structs.h
output.o:  output.c structs.h
