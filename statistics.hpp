#pragma once
/**
 * @file sorter.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A class used to obtain time statistics of sorting algorithm and compares them by running algorithms multiple times
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#include "run_time.hpp"
#include "sorter.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip> // helps in printing neatly

using namespace std;

class statistics
{
    // ============
    // Private data
    // ============
private:
    /**
     * @brief Private member that stores the number of algorithm running repetitions.
     */
    const uint16_t run_frequency = 100;
    /**
     * @brief Private member that stores the number of algorithm to compare.
     */
    const uint8_t num_algorithms = 6;
    /**
     * @brief Private member vector to store bubble sort algorithm run time for each iteration.
     */
    vector<double> bubble_times;
    /**
     * @brief Private member vector to store selection sort algorithm run time for each iteration.
     */
    vector<double> selection_times;
    /**
     * @brief Private member vector to store quick sort algorithm run time for each iteration.
     */
    vector<double> quick_times;
    /**
     * @brief Private member vector to store insertion sort algorithm run time for each iteration.
     */
    vector<double> insertion_times;
    /**
     * @brief Private member vector to store merge sort algorithm run time for each iteration.
     */
    vector<double> merge_times;
    /**
     * @brief Private member vector to store heap sort algorithm run time for each iteration.
     */
    vector<double> heap_times;

    // =======================
    // Public member functions
    // =======================
public:
    /**
     * @brief Constructor, that runs the algorithms multiple times
     * then stores the time taken for each time an algorithm runs in the algorithm's private member vector.
     **/
    statistics(vector<int64_t> user_vector)
    {
        sorter sort(user_vector);
        run_time sort_time;
        for (uint32_t i = 0; i < run_frequency; i++)
        {
            // bubble sort
            sort_time.begin();                                // start time
            sort.bubble_sort();                               // run algorithm on user's list
            sort_time.finished();                             // stop time
            bubble_times.push_back(sort_time.milliseconds()); // append time for iteration i

            // selection sort
            sort_time.begin();                                   // start time
            sort.selection_sort();                               // run algorithm on user's list
            sort_time.finished();                                // stop time
            selection_times.push_back(sort_time.milliseconds()); // append time for iteration i

            // quick sort
            sort_time.begin();                               // start time
            sort.quick_sort();                               // run algorithm on user's list
            sort_time.finished();                            // stop time
            quick_times.push_back(sort_time.milliseconds()); // append time for iteration i

            // insertion sort
            sort_time.begin();                                   // start time
            sort.insertion_sort();                               // run algorithm on user's list
            sort_time.finished();                                // stop time
            insertion_times.push_back(sort_time.milliseconds()); // append time for iteration i

            // merge sort
            sort_time.begin();                               // start time
            sort.merge_sort();                               // run algorithm on user's list
            sort_time.finished();                            // stop time
            merge_times.push_back(sort_time.milliseconds()); // append time for iteration i

            // heap sort
            sort_time.begin();                              // start time
            sort.heap_sort();                               // run algorithm on user's list
            sort_time.finished();                           // stop time
            heap_times.push_back(sort_time.milliseconds()); // append time for iteration i
        }
    }

    /**
     * @brief Finds the sum of elements in a vector.
     * @param v the vector.
     * @return the sum.
     */
    double vector_sum(vector<double> v)
    {
        double sum = 0;
        for (uint32_t i = 0; i < v.size(); i++)
        {
            sum += v.at(i);
        }
        return sum;
    }

    //============================================================================
    // Below are codes that obtain statistics for the different sorting algorithms
    //============================================================================

    /**
     * @brief Finds the average running time of bubble sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return average run time.
     */
    double bubble_avgTime()
    {
        return (vector_sum(bubble_times) / run_frequency);
    }

    /**
     * @brief Finds the average running time of selection sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return Average run time.
     */
    double selection_avgTime()
    {
        return (vector_sum(selection_times) / run_frequency);
    }

    /**
     * @brief Finds the average running time of quick sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return Average run time.
     */
    double quick_avgTime()
    {
        return (vector_sum(quick_times) / run_frequency);
    }

    /**
     * @brief Finds the average running time of insertion sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return Average run time.
     */
    double insertion_avgTime()
    {
        return (vector_sum(insertion_times) / run_frequency);
    }

    /**
     * @brief Finds the average running time of merge sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return Average run time.
     */
    double merge_avgTime()
    {
        return (vector_sum(merge_times) / run_frequency);
    }

    /**
     * @brief Finds the average running time of heap sort algorithm
     * takes the vectors containing the times of each iteration from the private member.
     * @return Average time.
     */
    double heap_avgTime()
    {
        return (vector_sum(heap_times) / run_frequency);
    }

    /**
     * @brief Finds the std of elements in a vector.
     * @param v The vector.
     * @return The standard deviation.
     */
    double vector_std(vector<double> v)
    {
        if (v.size() == 0)
        {
            return 0;
        }

        double avg = vector_sum(v) / run_frequency; // Mean
        double ss_sum = 0;                          // Sum of squared difference variable

        // Calculating standard deviation
        for (uint16_t i = 0; i < v.size(); i++)
        {
            ss_sum = +(v.at(i) - avg) * (v.at(i) - avg);
        }

        return sqrt(ss_sum / double(v.size()));
    }

    /**
     * @brief Finds the standard deviation of running time of bubble sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member
     * @return Standard deviation of algorithm run time.
     */
    double bubble_stdTime()
    {
        return (vector_std(bubble_times));
    }

    /**
     * @brief Finds the standard deviation of running time of selection sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Standard deviation of algorithm run time.
     */
    double selection_stdTime()
    {
        return (vector_std(selection_times));
    }

    /**
     * @brief Finds the standard deviation of running time of quick sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Standard deviation of algorithm run time.
     */
    double quick_stdTime()
    {
        return (vector_std(quick_times));
    }

    /**
     * @brief Finds the standard deviation of running time of insertion sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Standard deviation of algorithm run time.
     */
    double insertion_stdTime()
    {
        return (vector_std(insertion_times));
    }

    /**
     * @brief Finds the standard deviation of running time of merge sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Standard deviation of algorithm run time.
     */
    double merge_stdTime()
    {
        return (vector_std(merge_times));
    }

    /**
     * @brief Finds the standard deviation of running time of heap sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Standard deviation of algorithm run time.
     */
    double heap_stdTime()
    {
        return (vector_std(heap_times));
    }

    /**
     * @brief Function that gets max element in a given vector.
     * @param v The vector.
     * @return Max element.
     */

    double max(vector<double> v)
    {
        /**
         * @brief Variable to store max time.
         */
        double max_time = v.at(0);
        for (uint16_t i = 0; i < run_frequency; i++)
        {
            if (v.at(i) > max_time)
            {
                max_time = v.at(i);
                ;
            }
        }

        return max_time;
    }

    /**
     * @brief Finds the maximum of running time of bubble sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double bubble_max()
    {
        return (max(bubble_times));
    }

    /**
     * @brief Finds the maximum of running time of selection sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double selection_max()
    {
        return (max(selection_times));
    }

    /**
     * @brief Finds the maximum of running time of quick sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double quick_max()
    {
        return (max(quick_times));
    }

    /**
     * @brief Finds the maximum of running time of insertion sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double insertion_max()
    {
        return (max(insertion_times));
    }

    /**
     * @brief Finds the maximum of running time of merge sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double merge_max()
    {
        return (max(merge_times));
    }

    /**
     * @brief Finds the maximum of running time of heap sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Maximum of algorithm run time.
     */
    double heap_max()
    {
        return (max(heap_times));
    }

    /**
     * @brief Function that gets minimum element in a given vector.
     * @param v The vector.
     * @return Minimum element.
     */
    double min(vector<double> v)
    {
        /**
         * @brief Variable to store max time.
         */
        double min_time = v.at(0);
        for (uint16_t i = 0; i < v.size(); i++)
        {
            if (v.at(i) < min_time)
            {
                min_time = v.at(i);
            }
        }

        return min_time;
    }

    /**
     * @brief Finds the minimum of running time of bubble sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double bubble_min()
    {
        return (min(bubble_times));
    }

    /**
     * @brief Finds the minimum of running time of selection sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double selection_min()
    {
        return (min(selection_times));
    }

    /**
     * @brief Finds the minimum of running time of quick sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double quick_min()
    {
        return (min(quick_times));
    }

    /**
     * @brief Finds the minimum of running time of insertion sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double insertion_min()
    {
        return (min(insertion_times));
    }

    /**
     * @brief Finds the minimum of running time of merge sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double merge_min()
    {
        return (min(merge_times));
    }

    /**
     * @brief Finds the minimum of running time of heap sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Minimum of algorithm run time.
     */
    double heap_min()
    {
        return (min(heap_times));
    }

    /**
     * @brief Function that gets median element in a given vector.
     * @param v The vector.
     * @return Median.
     */
    double median(vector<double> v)
    {
        /**
         * @brief Variable to store the median time.
         */
        double median_time = 0;
        vector<double> temp = v;

        // sorting the temp vector using bubble sort
        for (uint16_t i = 0; i < run_frequency - 1; i++)
        {
            for (uint16_t j = 0; j < run_frequency - 1 - i; j++)
            {
                if (temp.at(j) > temp.at(j + 1))
                    swap(temp.at(j), temp.at(j + 1));
            }
        }

        // calculating median
        if (run_frequency % 2 == 0) // if even
        {
            median_time = (v.at(run_frequency / 2 - 1) + v.at(run_frequency / 2)) / 2;
        }
        else // if odd
        {
            median_time = v.at(run_frequency / 2);
        }

        return median_time;
    }

    /**
     * @brief Finds the median of running time of bubble sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double bubble_median()
    {
        return (median(bubble_times));
    }

    /**
     * @brief Finds the median of running time of selection sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double selection_median()
    {
        return (median(selection_times));
    }

    /**
     * @brief Finds the median of running time of quick sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double quick_median()
    {
        return (median(quick_times));
    }

    /**
     * @brief Finds the median of running time of insertion sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double insertion_median()
    {
        return (median(insertion_times));
    }

    /**
     * @brief Finds the median of running time of merge sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double merge_median()
    {
        return (median(merge_times));
    }

    /**
     * @brief Finds the median of running time of heap sort algorithm.
     * Takes the vectors containing the times of each iteration from the private member.
     * @return Median of algorithm run time.
     */
    double heap_median()
    {
        return (median(heap_times));
    }

    string kruskalWallis_test()
    {
        /**
         * @brief Variable the stores the decision rule to reject or accept hypothesis.
         * Decision rule at alpha = 0.55 and df = 5 (num_algorithms - 1) is 5.99.
         * Meaning if chi^2 is greater than 5.999 reject null hypothesis.
         */
        const double decision_rule = 5.99;

        // Below are sum of the vectors containing the run time of each algorithm
        double sum_bubble = vector_sum(bubble_times);
        double sum_selection = vector_sum(selection_times);
        double sum_quick = vector_sum(quick_times);
        double sum_insertion = vector_sum(insertion_times);
        double sum_merge = vector_sum(merge_times);
        double sum_heap = vector_sum(heap_times);

        /**
         * @brief Variable to the Chi^2 value.
         */
        double test_statistic = (12 / (num_algorithms * 100 * (num_algorithms * 100 + 1))) * (sum_bubble / num_algorithms + sum_selection / num_algorithms + sum_quick / num_algorithms + sum_insertion / num_algorithms + sum_merge / num_algorithms + sum_heap / num_algorithms) + 3 * (num_algorithms * 100 + 1);
        if (test_statistic <= decision_rule)
        {
            return ("Kruskal Wallis Test: There is no significant difference between the algorithms run times");
        }
        else
        {
            return ("Kruskal Wallis Test: There is a significant difference between the algorithms run times");
        }
    }

    /**
     * @brief Prints a comparison report in a file that compares different algorithm in terms of
     * of their time stats.
     * @param output_file The file to print the report in.
     */
    void comparison_report(string file_name)
    {
        // setw(x) -> to set the width of the output variable width in the output field
        // left -> left align the characters

        cout << endl;
        // ========================
        // printing results in a file
        // ========================
        ofstream output(file_name);
        if (!output.is_open())
        {
            cout << "Error in opening the output file :(";
            exit(0);
        }

        // printing the comparison table
        output << "Algorithm run time statistics (in MilliSeconds): " << endl;
        output << endl;
        // column title
        output << left << setw(17) << "Algorithm" << left << setw(10) << "Average"
               << left << setw(10) << "Std" << left << setw(10) << "Median"
               << left << setw(10) << "Max" << left << setw(10) << "Min" << endl;

        output << "--------------------------------------------------------------" << endl;

        // row 1 - Bubble Sort
        output << left << setw(17) << "Bubble Sort" << left << setw(10) << bubble_avgTime()
               << left << setw(10) << bubble_stdTime() << left << setw(10) << bubble_median()
               << left << setw(10) << bubble_max() << left << setw(10) << bubble_min() << endl;

        // row 1 - Selection Sort
        output << left << setw(17) << "Selection Sort" << left << setw(10) << selection_avgTime()
               << left << setw(10) << selection_stdTime() << left << setw(10) << selection_median()
               << left << setw(10) << selection_max() << left << setw(10) << selection_min() << endl;

        // row 1 - Quick Sort
        output << left << setw(17) << "Quick Sort" << left << setw(10) << quick_avgTime()
               << left << setw(10) << quick_stdTime() << left << setw(10) << quick_median()
               << left << setw(10) << quick_max() << left << setw(10) << quick_min() << endl;

        // row 1 - Insertion Sort
        output << left << setw(17) << "Insertion Sort" << left << setw(10) << insertion_avgTime()
               << left << setw(10) << insertion_stdTime() << left << setw(10) << insertion_median()
               << left << setw(10) << insertion_max() << left << setw(10) << insertion_min() << endl;

        // row 1 - Merge Sort
        output << left << setw(17) << "Merge Sort" << left << setw(10) << merge_avgTime()
               << left << setw(10) << merge_stdTime() << left << setw(10) << merge_median()
               << left << setw(10) << merge_max() << left << setw(10) << merge_min() << endl;

        // row 1 - Heap Sort
        output << left << setw(17) << "Heap Sort" << left << setw(10) << heap_avgTime()
               << left << setw(10) << heap_stdTime() << left << setw(10) << heap_median()
               << left << setw(10) << heap_max() << left << setw(10) << heap_min() << endl;

        output << endl;

        /**
         * @brief Variable to store the result of the significance difference test, True/False.
         */
        string difference_test = kruskalWallis_test();
        output << difference_test << endl;
        output << endl;

        // Checking best algorithm
        // appending means in a list
        vector<double> avg_list;
        avg_list.push_back(bubble_avgTime());
        avg_list.push_back(selection_avgTime());
        avg_list.push_back(quick_avgTime());
        avg_list.push_back(insertion_avgTime());
        avg_list.push_back(merge_avgTime());
        avg_list.push_back(heap_avgTime());

        // looking for the best model
        /**
         * @brief Variable to store the best running time.
         */
        double best_time;
        best_time = min(avg_list);
        if (avg_list.at(0) == best_time)
            output << "Best Performing Model: Bubble Sort ";
        if (avg_list.at(1) == best_time)
            output << "Best Performing Model: Selection Sort ";
        if (avg_list.at(2) == best_time)
            output << "Best Performing Model: Quick Sort ";
        if (avg_list.at(3) == best_time)
            output << "Best Performing Model: Insertion Sort ";
        if (avg_list.at(4) == best_time)
            output << "Best Performing Model: Merge Sort ";
        if (avg_list.at(5) == best_time)
            output << "Best Performing Model: Heap Sort ";

        cout << "Comparison report successfully printed in the file: " << file_name << endl;
        cout << endl;

        // Close file
        output.close();
    }
};