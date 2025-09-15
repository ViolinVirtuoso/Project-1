//
// Created by samue on 9/13/2025.
//

#include "Maze.hpp"
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>

// loadFromFile
// pre: the name of a text file as a string, all 1's and 0's, all rows equally long,
// left and right sides having exactly one 0 each, and top and bottom sides only having 1's.
// post: the data is stored in a 2D array to represent a maze.
bool Maze::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    // failsafe in case the file doesn't exist
    if (!file.is_open())
        return false;

    std::string line;

    // while there is still data to look through
    while (std::getline(file, line)) {
        // process row by row
        std::vector<int> row;

        // iterate through the line of data
        for (char c : line) {
            // only process 0's and 1's (just in case there's something else)
            if (c == '0' || c == '1')
                row.push_back(c - '0');
        }
        // if there were any 0's or 1's, store the row in the 2D array
        if (!row.empty()) {
            maze.push_back(row);
        }
    }

    file.close();

    // locate and store the start and end nodes
    findStart();
    findEnd();

    return true;
}

// findStart
// pre: maze has data
// post: start gets a value
void Maze::findStart() {
    int i = 0;
    while (i < maze.size()) {
        if (maze[i][0] == 0) {
            start = std::make_pair(i, 0);
            break;
        }
        i++;
    }
}

// findEnd
// pre: maze has data
// post: end gets a value
void Maze::findEnd() {
    int i = 0;
    while (i < maze.size()) {
        if (maze[i][maze[0].size() - 1] == 0) {
            end = std::make_pair(i, maze[0].size() - 1);
            break;
        }
        i++;
    }
}

// getElement
// pre: maze has data and i and j are within the bounds of the array
// post: the specified value is retrieved
int Maze::getElement(int i, int j) const {
    return maze[i][j];
}

// setElement
// pre: i and j are within the bounds of the array
// post: the specified value is assigned to the specified location
void Maze::setElement(int i, int j, int key) {
    maze[i][j] = key;
}

// printMaze
// pre: maze has data
// post: maze's data is printed row by row
void Maze::printMaze() const {
    for (size_t i = 0; i < maze.size(); i++) {
        for (size_t j = 0;  j < maze[i].size(); j++) {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
    }
}

// solveMaze
// pre: maze has data
// post: the solution to the maze is stored in a stack
void Maze::solveMaze() {
    // temporary storage of the maze
    std::vector<std::vector<int>> temp = maze;

    // storage of the solution
    std::stack<std::pair<int, int>> stack;

    // push the starting node onto the stack and mark it as explored
    stack.push(start);
    temp[stack.top().first][stack.top().second] = 1;

    // find the solution
    while (!stack.empty()) {

        // if there is no way forward, backtrack
        if (temp[stack.top().first][stack.top().second + 1] == 1 && temp[stack.top().first + 1][stack.top().second] == 1 && temp[stack.top().first][stack.top().second - 1] == 1 && temp[stack.top().first - 1][stack.top().second] == 1) {
            stack.pop();
        }

        // otherwise, find the way forward, and push it onto the stack
        else {
            if (temp[stack.top().first][stack.top().second + 1] == 0)
                stack.push(std::make_pair(stack.top().first, stack.top().second + 1));
            else if (temp[stack.top().first + 1][stack.top().second] == 0)
                stack.push(std::make_pair(stack.top().first + 1, stack.top().second));
            else if (temp[stack.top().first][stack.top().second - 1] == 0)
                stack.push(std::make_pair(stack.top().first, stack.top().second - 1));
            else if (temp[stack.top().first - 1][stack.top().second] == 0)
                stack.push(std::make_pair(stack.top().first - 1, stack.top().second));

            // then, mark it as explored
            temp[stack.top().first][stack.top().second] = 1;

            // if we've reached the destination, break the loop
            if (stack.top() == end)
                break;
        }
    }

    // if the stack is empty, it's because there isn't a solution
    if (stack.empty())
        std::cout << "No solution :(" << std::endl;
    // otherwise, we have the solution, and we call printSolution to display it
    else
        printSolution(stack);
}

// printSolution
// pre: a stack of integer pairs must be provided
// post: the solution to the maze is printed, with spaces where the solution path is
void Maze::printSolution(std::stack<std::pair<int, int>> solutionPath) const {
    // define a temporary vector of characters to display
    std::vector<std::vector<char>> temp(maze.size(), std::vector<char>(maze[0].size()));

    // put all the elements from the integer maze into the character temporary maze
    for (size_t i = 0; i < maze.size(); i++) {
        for (size_t j = 0; j < maze[0].size(); j++) {
            temp[i][j] = getElement(i, j) + '0';
        }
    }

    // then, replace all the spaces involving the solution path with empty spaces
    while (!solutionPath.empty()) {
        std::pair<int, int> i = solutionPath.top();
        temp[i.first][i.second] = ' ';
        solutionPath.pop();
    }

    std::cout << "Solution:" << std::endl;

    // finally, print the solved maze
    for (size_t i = 0; i < temp.size(); i++) {
        for (size_t j = 0;  j < temp[i].size(); j++) {
            std::cout << temp[i][j];
        }
        std::cout << std::endl;
    }
}