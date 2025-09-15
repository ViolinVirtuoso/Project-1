//
// Created by samue on 9/13/2025.
//

#ifndef PROJECT_1_MAZE_HPP
#define PROJECT_1_MAZE_HPP

#include <utility>
#include <vector>
#include <string>
#include <stack>

class Maze {
public:
    // publicly accessible functions
    bool loadFromFile(const std::string& filename);
    void printMaze() const;
    void solveMaze();

private:
    // the maze, along with the start and end nodes
    std::vector<std::vector<int>> maze;
    std::pair<int, int> start;
    std::pair<int, int> end;

    // get and set element
    int getElement(int, int) const;
    void setElement(int, int, int);
    // find start and end
    void findStart();
    void findEnd();
    // function for solveMaze
    void printSolution(std::stack<std::pair<int, int>> solutionPath) const;

};


#endif //PROJECT_1_MAZE_HPP