/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Menu for the Math Library Program.  This menu is a Python to C++ port of the menu from my assignments from CMIT-135-40B.
    The menu lists available options for functions to perform on a list of numbers.  The user can select an option by entering the number for 
    the desired function.  Each entry from the user is checked for validity.  The user will continue to be prompted until a valid entry is made.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include "Menu.h"
#include "ScoresMathFunctions.h"

using namespace std;

#pragma region ScoresFunctions

//Stores the scores entered by the user.
vector<float> scores = {
    0.0f, 18.0f, 97.3f, 84.2f, 100.1f, 99.9f
};

void print_scores() {
    cout << "Scores: ";
    bool first = true;
    for (int i = 0; i < scores.size(); i++) {
        if (first) {
            first = false;
        }
        else {
            cout << ", ";
        }

        cout << scores[i];
    }

    cout << endl;
}

void enter_scores() {
    cout << "Please enter a list of scores. To finish entering scores, enter a blank line.\n"
        "You may enter scores on the same line separated by commas/spaces or by entering them on multiple lines.\n";

    string prompt = "Please enter the next value(s). Enter a blank line to finish.";
    get_float_inputs_until_blank(prompt, scores);
    print_scores();
}

void clear_scores() {
    scores.clear();
    cout << "Scores cleared." << endl;
    print_scores();
}

void score_stats() {
    print_scores();
    print_score_stats(scores);
}

#pragma endregion

#pragma region GeneralMenuFunctions

int get_option(const vector<string>& option_list) {
    // List of all options with number labels
    vector<string> options;
    for (int i = 0; i < option_list.size(); i++) {
        options.push_back(to_string(i + 1) + ". " + option_list[i]);
    }

    string prompt = join(options) + "\n";
    return get_integer_input_in_range(prompt, 1, option_list.size()) - 1;
}

void get_float_inputs_until_blank(const string& prompt, vector<float>& floats) {
    int count = scores.size();
    get_float_inputs(prompt, scores);
    if (count == scores.size())
        return;

    return get_float_inputs_until_blank(prompt, floats);
}

string get_integer_inputs(const string& prompt, vector<int>& integers) {
    cout << prompt << endl;
    string answer;
    getline(cin, answer);
    vector<string> answer_list;
    stringstream ss(answer);
    string temp;
    while (getline(ss, temp, ' ')) {
        answer_list.push_back(temp);
    }

    for (const auto& str : answer_list) {
        string stripped_str = str;
        stripped_str.erase(remove(stripped_str.begin(), stripped_str.end(), ','), stripped_str.end());
        if (is_integer(stripped_str))
            integers.push_back(stoi(stripped_str));
    }

    return answer;
}

int get_integer_input(const string& prompt) {
    vector<int> integers;
    string answer = get_integer_inputs(prompt, integers);

    if (integers.size() == 1) {
        return integers[0];
    }
    else if (integers.size() > 1) {
        cout << "Received multiple numbers." << endl;
    }
    else {
        cout << answer << " is not a whole number." << endl;
    }

    return get_integer_input(prompt);
}

string get_float_inputs(const string& prompt, vector<float>& floats) {
    cout << prompt << endl;
    string answer;
    getline(cin, answer);
    vector<string> answer_list;
    stringstream ss(answer);
    string temp;
    while (getline(ss, temp, ' ')) {
        answer_list.push_back(temp);
    }

    for (const auto& str : answer_list) {
        string stripped_str = str;
        stripped_str.erase(remove(stripped_str.begin(), stripped_str.end(), ','), stripped_str.end());
        if (is_float(stripped_str))
            floats.push_back(stof(stripped_str));
    }

    return answer;
}

float get_float_input(const string& prompt) {
    vector<float> floats;
    string answer = get_float_inputs(prompt, floats);

    if (floats.size() == 1) {
        return floats[0];
    }
    else if (floats.size() > 1) {
        cout << "Received multiple numbers." << endl;
    }
    else {
        cout << answer << " is not a number." << endl;
    }

    return get_integer_input(prompt);
}

bool is_integer(const string& str) {
    if (str.empty())
        return false;

    bool found_minus = (str[0] == '-');
    for (int i = (found_minus ? 1 : 0); i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

bool is_float(const std::string& str) {
    if (str.empty())
        return false;

    bool is_negative = (str[0] == '-');
    bool has_decimal = false;
    for (size_t i = is_negative ? 1 : 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (has_decimal)
                return false;// Multiple decimal points

            has_decimal = true;
        }
        else if (!std::isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

int get_integer_input_in_range(const string& prompt, int range_min, int range_max) {
    int value = -1;
    bool getting_input = true;
    while (getting_input) {
        value = get_integer_input(prompt);
        if (value < range_min || value > range_max) {
            cout << value << " is out of range." << endl;
        }
        else {
            getting_input = false;
        }
    }

    return value;
}

float get_float_input_in_range(const string& prompt, float range_min, float range_max) {
    float value = -1.0f;
    bool getting_input = true;
    while (getting_input) {
        value = get_float_input(prompt);
        if (value < range_min || value > range_max) {
            cout << value << " is out of range." << endl;
        }
        else {
            getting_input = false;
        }
    }

    return value;
}

string join(const vector<string>& list_strings, const string& separator) {
    string result = "";
    bool first = true;
    for (const auto& s : list_strings) {
        if (first) {
            first = false;
        }
        else {
            result += separator;
        }

        result += s;
    }

    return result;
}

void stop_running() {
    cout << "Goodbye" << endl;
    running = false;
}

#pragma endregion

vector<Function> functions = {
    Function("Enter Scores", enter_scores),
    Function("Print Scores", print_scores),
    Function("Clear Scores", clear_scores),
    Function("Score Stats", score_stats),
    Function("Quit program", stop_running)
};