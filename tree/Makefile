
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/tree

SRC= tree_building.c main.c tree_traversal.c

# generic build details

CC=      cc
COPT=    -O
CFLAGS= 

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

tree_building.o:  tree_building.c tree_functions.h
main.o:  main.c tree_structures.h
tree_traversal.o: tree_traversal.c tree_functions.h
