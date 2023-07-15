/*
Author - Isaac Richards
Date - 15JUL23
Assignment - Object Oriented Math Library Program
Description - Functions for obtaining the total, average, min, max, deviance, variance and standard deviation of all float values in a vector.
*/

#pragma once

/// <summary>
/// Finds the total of all values in the vector.
/// </summary>
/// <param name="scores"></param>
/// <returns></returns>
float total(const std::vector<float>& scores);

/// <summary>
/// Finds the average value in the vector.
/// </summary>
/// <param name="scores"></param>
/// <returns></returns>
float average(const std::vector<float>& scores);

/// <summary>
/// Finds the lowest value in the vector.
/// </summary>
/// <param name="scores"></param>
/// <returns></returns>
float min(const std::vector<float>& scores);

//Finds the highest value in the vector.
float max(const std::vector<float>& scores);

/// <summary>
/// Finds the deviance (squared difference) between the value and average.
/// </summary>
/// <param name="value"></param>
/// <param name="average"></param>
/// <returns></returns>
float deviance(const float value, const float average);

/// <summary>
/// Finds the variance (average of all deviances) of the values in the vector.
/// </summary>
/// <param name="scores"></param>
/// <returns></returns>
float variance(const std::vector<float>& scores);

/// <summary>
/// Finds the standard deviation (square root of the variance) of the values in the vector.
/// </summary>
/// <param name="scores"></param>
/// <returns></returns>
float standard_deviation(const std::vector<float>& scores);

/// <summary>
/// Prints all available statistics for the values in the vector.
/// </summary>
/// <param name="scores"></param>
void print_score_stats(const std::vector<float>& scores);