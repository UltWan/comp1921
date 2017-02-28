// COMP 1921 Code Review
// Ryan Wan, Monday 28th February 2017

Quadtree Readme File

Notes: 

-This program is designed to create a quadtree and display the results in gnuplot.

-This is done by running the program.

-Work is split between the "main.c", "node.c", "output.c" and "valueTree.c" files; they can be opened and viewed in any text editor.

-The other files that are needed to run the program are the "functions.h" and "structs.h" files, however the makefile will automatically handle these files in the compilation process as long as they are in the same folder.

Instructions:

-In order to run the file it must first be complied, which is done with the makefile. To do this on Linux, go to the directory containing the "makefile", "main.c", "node.c", "output.c", "valueTree.c", "functions.h" and "structs.h" files, then enter the following command into the terminal:
	./make

The compilation is successful if it reports that the makefile is up to date or it has been complied, and therefore updated.

-Then execute the file with the following command:
	./quadtree

If the program runs successfully it will produce a quad.out file needed for Gnuplot

-Load Gnuplot by typing gnuplot into the terminal where quad.gnu is located.

-Display the quadtree through Gnuplot by typing:
	load 'quad.gnu'

A plotted graph should appear on Gnuplot.
