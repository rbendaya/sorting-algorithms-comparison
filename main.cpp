/**
 * @file main.cpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A program to compare multiple sorting algorithms given a user list
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#include "run_time.hpp"
#include "sorter.hpp"
#include "statistics.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    // The below code is here to avoid an error when we first run the code
    if (argv[1] == NULL)
    {
        // Introductory message to the user
        cout << "Welcome! Thank you for choosing my program " << endl;
        cout << "This program has only one command line input parameter, please input your file name: " << endl;
        exit(0);
    }

    // Incase user inputs more than one command line parameter
    if (argc > 2)
        cout << "Please input only one parameter " << endl;
    string user_file;
    user_file = argv[1];

    // Reading file
    ifstream input(user_file);
    // Let the user know if file didn't open
    if (!input.is_open())
    {
        cout << "File failed to open :(, make sure you the file name and extension is correct" << endl;
        cout << "This is a sample input: ./CSE701 MyFile.txt" << endl;
        ;
        return -1;
    }

    // Let the user know if the program ran successfully
    cout << "Program successfully ran!" << endl
         << endl;

    /**
     * @brief Variable to store the numbers from the file.
     **/
    int64_t list_element;
    /**
     * @brief Vector to store those elements/user's list.
     **/
    vector<int64_t> user_vector;

    // reading file
    while (input >> list_element)
    {
        user_vector.push_back(list_element); // appending elements in the vector
    }

    // Incase there is non number/double type let the user know
    if (input.eof())
        cout << "The list in your file was successfully inputted :D" << endl
             << endl;
    // Not reaching end of file indicates an invalid character in the file
    else if (input.fail())
        cout << "There is/are element/s in your file that are not numbers" << endl;

    // Close the file
    input.close();

    // Printing sorted list in a file
    sorter sort(user_vector);
    sort.print_sorted_toFile("sortedList.txt"); // printing

    // Printing comparison of different sorting algorithms in a report
    cout << "Processing the report, thank you for your patience..." << endl;
    statistics stat(user_vector);
    stat.comparison_report("comparisonReport.txt");
}