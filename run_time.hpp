#pragma once

/**
 * @file run_time.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A class to be used to calculate the elapsed time of running a piece of code
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#include <chrono> // Using the following library for precise time calculation

using namespace std;

/**
 * @brief An easy to use class, that allows the user to calculates running time of some code.
 */
class run_time
{
    // ============
    // Private data
    // ============
    // From lecture notes
private:
    /**
     * @brief A private member that stores the start time of the piece of code.
     */
    chrono::time_point<chrono::steady_clock> begin_time = chrono::steady_clock::now();

    /**
     * @brief A private member that stores duration time of a piece of code.
     */
    chrono::duration<double> finished_time = chrono::duration<double>::zero();
    // Ends here

    // =======================
    // Public member functions
    // =======================
public:
    /**
     * @brief Method that stores time when the piece of code began.
     */
    void begin()
    {
        begin_time = chrono::steady_clock::now();
    }
    /**
     * @brief Method that stores duration of the piece of code since start.
     */
    void finished()
    {
        finished_time = chrono::steady_clock::now() - begin_time;
    }
    /**
     * @brief Method that counts duration time in milli seconds.
     * @return Duration time in milli seconds.
     */
    double seconds() const
    {
        return finished_time.count();
    }

    /**
     * @brief Method that counts duration time in seconds.
     * @return Duration time in seconds.
     */
    double milliseconds() const
    {
        return finished_time.count() * 1000;
    }
};