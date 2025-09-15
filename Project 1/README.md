Samuel Strong
005831181
https://github.com/ViolinVirtuoso/Project-1

Collaboration & Sources:
I used Claude AI to help build my starting main.cpp file, because for the life of me I could not remember how to properly feed data from a file into any receiver, let alone a 2D vector. Far later, I used Claude again to help me with printing the solved maze, as after successfully implementing the backtracking algorithm, I wasn't sure how to go about displaying the solution. Other than that, all the work is mine.

Implementation Details:
I have 3 files - main.cpp (the tester), Maze.hpp (the data structure header), and Maze.cpp (the data structure source).
main.cpp simply tests the functionality of the Maze class.
Maze.hpp defines a Maze class with the public functions loadFromFile, printMaze, and solveMaze (all self-explanatory).
Additionally, it contains private functions getElement, setElement, findStart and findEnd (for finding start and end nodes of the maze), and printSolution (a helper function for solveMaze).
Finally, it has a 2D vector called maze (the framework behind everything), and two pairs called start and end (the start and end nodes of said maze).
Maze.cpp implements all of the above functions.
You can find the pre and post conditions, as well as comments to help you along in your reading, in all three of these files.

Testing & Status:
Everything works. With the example input file you provided, here is the output:

"C:\Users\samue\CLionProjects\Project 1\cmake-build-debug\Project_1.exe"
Solution:
111111111111111
1     001   001
1 111 101 1 111
  001 101 1   1
11111 111 111 1
10000     1   1
10101011101 111
10101000101   1
1010111010111 1
1010001010101 1
1011101110101 1
1000100010001
111111111111111

Process finished with exit code 0

***PLEASE NOTE!!!***
The filename, within main.cpp, is a path that only works on my computer. You will have to change this to whatever the filepath is within Blue. I do not know the Blue file system. As long as you can change it to the correct path, it will work perfectly. Otherwise, the program will return 1.