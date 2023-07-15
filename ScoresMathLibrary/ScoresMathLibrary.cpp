/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Assignment Requirements:
    Pointer - Function.h contains the class that stores a pointer to a function.  Menu.cpp contains a vector of Function pointers.
Description - This program is an example program to demonstrate the use of the ScoresMathLibrary.
    It uses a simple menu to allow the user to select which function they would like to use.
    Menu.cpp contains the vector of Function objects that are available to the user.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Menu.h"

using namespace std;

bool running = true;

int main() {
    print_scores();
    cout << endl;

    while (running) {
        cout << "What would you like to do:" << endl;

        //program_names is a vector of strings containing the display names of the functions in the menu
        vector<string> program_names;
        for (const auto& program : functions) {
            program_names.push_back(program.display_name);
        }

        //get_option returns the index of the function selected by the user
        int option_index = get_option(program_names);

        //call the function selected by the user
        functions[option_index].function();
        cout << endl;
    }

    return 0;
}