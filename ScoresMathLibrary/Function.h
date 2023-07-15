/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Function stores a pointer to a function and a display name for the function.  Function is meant to be used in a vector of 
    Function objects for a menu.
*/

#pragma once
#include <string>

using namespace std;

class Function {
public:
    string display_name;
    void (*function)();

    Function(const string& name, void (*func)()) : display_name(name), function(func) {}
};