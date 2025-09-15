#include "Maze.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main() {

    // the filename
    std::string mazeFileName = "C:/Users/samue/CLionProjects/Project 1/maze0-1_input.txt";

    // define maze object
    Maze maze;
    maze.loadFromFile(mazeFileName);

    // solve and print
    maze.solveMaze();



    return 0;
}