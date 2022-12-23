/**
 * @file run_time.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A class to be used to calculate the elapsed time of running a piece of code
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#pragma once // Prevent reading the header file more than once
// Using the following library for precise time calculation
#include <chrono>

using namespace std;

class run_time
{
    // Private members
    // From lecture notes
private:
    // private member that stores start time
    chrono::time_point<chrono::steady_clock> begin_time = chrono::steady_clock::now();
    // private member that stores duration time of a piece of code
    chrono::duration<double> finished_time = chrono::duration<double>::zero();
    // Ends here

public:
    // Method that stores time when the piece of code began
    void begin()
    {
        begin_time = chrono::steady_clock::now();
    }
    // Method that stores duration of the piece of code since start
    void finished()
    {
        finished_time = chrono::steady_clock::now() - begin_time;
    }

    // Method the return duration time in milli seconds
    double seconds() const
    {
        return finished_time.count();
    }

    // Method the return duration time in milli seconds
    double milliseconds() const
    {
        return finished_time.count() * 1000;
    }
};