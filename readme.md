# Writing SVG Files

This program creates a scalable vector graphics (svg) file with shapes based on input read from standard input. Each line of input defines a shape to be added to the line(s) indicated in template.svg. The first character on each line determines whether theshape is a circle (‘C’) or a rectangle (‘R’). The position and size of the shape is described by integers in the rest of the input line.A rectangle is specified by the position of its lower left corner, its width and its height.

A rectangle is specified by the position of its lower left corner, its width and its height.
Example: Rectangle with corners at (10,20), (40,20), (40,60), (10,60)
R 10 20 30 40

A circle is specified by the position of its center and its radius
Example: Circle centered at position (30,40) with radius 20
C 30 40 20

# Packing Circles and Rectangles

This program, given a rectangular domain and a list of circles and rectangles, can check if the packing configurationis valid, in the sense that all shapes fit within the domain and there are no overlaps between shapes. The program should create a visualrepresentation of the domain and shapes as a scalable vector graphics (svg) file. 

The program should write on standard output the svg representation of all the shapes, and includein addition the following diagnostic message:
1. "ok" if the configuration is valid, i.e. all shapes fit in the domain and there are no overlaps between shapes. 
2. "overlap" if the shapes fit in the domain but some of the shapes overlap
3. "does not fit" if any of the shapes does not fit in the domain.
4. If some shapes overlap and some shapes do not fit, the program should only print "does not fit"