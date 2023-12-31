/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Menu for the Math Library Program.  This menu is a Python to C++ port of the menu from my assignments from CMIT-135-40B.
    The menu lists available options for functions to perform on a list of numbers.  The user can select an option by entering the number for
    the desired function.  Each entry from the user is checked for validity.  The user will continue to be prompted until a valid entry is made.
*/

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Function.h"

using namespace std;

extern vector<Function> functions;
extern bool running;

#pragma region ScoresFunctions

/// <summary>
/// Print the list of scores.
/// </summary>
void print_scores();

/// <summary>
/// Allows the user to add scores to the vector of scores.
/// </summary>
void enter_scores();

/// <summary>
/// Clear the scores vector.
/// </summary>
void clear_scores();

/// <summary>
/// Prints the scores then calls print_score_stats() from ScoresMathLibrary.
/// </summary>
void score_stats();

#pragma endregion

#pragma region GeneralMenuFunctions

/// <summary>
/// Lists each of the options in option_list and prompts the user to select one.
/// </summary>
/// <param name="option_list"></param>
/// <returns>The index of the selected option from option_list</returns>
int get_option(const vector<string>& option_list);

/// <summary>
/// Continue to prompt the user for float inputs until a blank line is entered.
/// </summary>
/// <param name="prompt"></param>
/// <param name="floats"></param>
void get_float_inputs_until_blank(const string& prompt, vector<float>& floats);

/// <summary>
/// Gets a line from the user then converts it to a vector of integers.
/// </summary>
/// <param name="prompt"></param>
/// <param name="integers"></param>
/// <returns>The string entered by the user.</returns>
string get_integer_inputs(const string& prompt, vector<int>& integers);

/// <summary>
/// Gets an integer from the user.  Includes input validation for integers and having more than one integer on a line.
/// </summary>
/// <param name="prompt"></param>
/// <returns></returns>
int get_integer_input(const string& prompt);

/// <summary>
/// Gets a line from the user then converts it to a vector of floats.
/// </summary>
/// <param name="prompt"></param>
/// <param name="floats"></param>
/// <returns>The string entered by the user.</returns>
string get_float_inputs(const string& prompt, vector<float>& floats);

/// <summary>
/// Gets a float from the user.  Includes input validation for floats and having more than one float on a line.
/// </summary>
/// <param name="prompt"></param>
/// <returns></returns>
float get_float_input(const string& prompt);

/// <summary>
/// Checks if str can be converted to an integer.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool is_integer(const string& str);

/// <summary>
/// Check if str can be converted to a float.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool is_float(const std::string& str);

/// <summary>
/// Calls get_integer_input() then checks if the integer is in the range [range_min, range_max].
/// Continues to prompt the user until a valid integer is entered.
/// </summary>
/// <param name="prompt"></param>
/// <param name="range_min"></param>
/// <param name="range_max"></param>
/// <returns></returns>
int get_integer_input_in_range(const string& prompt, int range_min, int range_max);

/// <summary>
/// Calls get_float_input() then checks if the float is in the range [range_min, range_max].
/// Continues to prompt the user until a valid float is entered.
/// </summary>
/// <param name="prompt"></param>
/// <param name="range_min"></param>
/// <param name="range_max"></param>
/// <returns></returns>
float get_float_input_in_range(const string& prompt, float range_min, float range_max);

/// <summary>
/// Joins the strings in list_strings with separator between each string.
/// </summary>
/// <param name="list_strings"></param>
/// <param name="separator"></param>
/// <returns></returns>
string join(const vector<string>& list_strings, const string& separator = "\n");

/// <summary>
/// Sets running to false.
///</summary>
void stop_running();

#pragma endregion