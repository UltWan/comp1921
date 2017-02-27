// COMP 1711 Assignment 6
// Ryan Wan, Thursday 8th December 2016

Quadtree Readme File

Notes: 

-This program is designed to count the number of times different words occur.

-This is done by either piping in a text file or running the program and entering text manually.

-Work is split between the "WordMain.c", "WordList.c" and "WordNode.c" files; they can be opened and viewed in any text editor.

-The other files that are needed to run the program are the "WordList.h" and "WordNode.h" files, however the makefile will automatically handle these files in the compilation process as long as they are in the same folder.

Instructions:

-In order to run the file it must first be complied, which is done with the makefile. To do this on Linux, go to the directory containing the "makefile", "WordMain.c", "WordList.c", "WordNode.c", "WordList.h" and "WordList.h" files, then enter the following command into the terminal:
	./make
The compilation is successful if it reports that the makefile is up to date or it has been complied, and therefore updated.

-Then execute the file with the following command:
	./wordcount
-After all the text has been entered, press enter, then Ctrl+D to simulate end of file for the program to run.

-Or pipe the file with the following command:
	./wordcount < xxxx
(xxxx being the name of the text file that is to be read in)
(NOTE Return, then Ctrl+D is not required if a file is being piped in)
