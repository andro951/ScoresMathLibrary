/*
Author - Isaac Richards
Date - 12JUL23
Assignment - Object Oriented Math Library Program
Description - Functions for obtaining the total, average, min, max, deviance, variance and standard deviation of all float values in a vector.
*/

#include <iostream>
#include <vector>
#include <cmath>

float total(const std::vector<float>& scores) {
    float t = 0;
    for (int i = 0; i < scores.size(); i++) {
        t += scores[i];
    }

    return t;
}

float average(const std::vector<float>& scores) {
    //Prevent divide by zero error by returning if size is < 1
    if (scores.size() < 1)
        return 0;

    return total(scores) / scores.size();
}

float min(const std::vector<float>& scores) {
    //Prevent attempting to access the first value in the vector if the size of the vector is < 1
    if (scores.size() < 1)
        return 0;

    float lowest = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        float score = scores[i];
        if (score < lowest)
            lowest = score;
    }

    return lowest;
}

float max(const std::vector<float>& scores) {
    //Prevent attempting to access the first value in the vector if the size of the vector is < 1
    if (scores.size() < 1)
        return 0;

    float highest = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        float score = scores[i];
        if (score > highest)
            highest = score;
    }

    return highest;
}

float deviance(const float value, const float average) {
    float difference = average - value;
    return difference * difference;
}

float variance(const std::vector<float>& scores) {
    //Prevent divide by zero error by returning if size is < 1
    if (scores.size() < 1)
        return 0;

    float totalDeviation = 0;
    float avg = average(scores);
    for (int i = 0; i < scores.size(); i++) {
        totalDeviation += deviance(scores[i], avg);
    }

    return totalDeviation / scores.size();
}

float standard_deviation(const std::vector<float>& scores) {
    //Prevent divide by zero error by returning if size is < 1
    if (scores.size() < 1)
        return 0;

    return std::sqrt(variance(scores));
}

void print_score_stats(const std::vector<float>& scores) {
    std::cout << "total: " << total(scores) << ", average: " << average(scores) << ", min: " << min(scores) << ", max: " << max(scores) <<
        ", variance: " << variance(scores) << ", standard deviation: " << standard_deviation(scores) << std::endl;
}