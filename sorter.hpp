/**
 * @file sorter.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A class to be used to perform different sorting algorithms and print them
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#pragma once
#include "run_time.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <vector>

class sorter
{
private:
    // stores the size of the users list
    uint64_t vector_size;
    // stores the list in a vector container, each container is specific to a sorting algorithm
    vector<int64_t> bubble_vector;
    vector<int64_t> selection_vector;
    vector<int64_t> quick_vector;
    vector<int64_t> insertion_vector;
    vector<int64_t> merge_vector;
    vector<int64_t> heap_vector;

public:
    /**
     * @brief constructor, that takes the user's list as a vector and stores it
     * in the private members of each vector that will be used for a specific sorting algorithm
     * @param user_list The vector to be sorted.
     * @return nothing, its a constructor
     **/
    sorter(vector<int64_t> user_list);

    /**
     * @brief sorts a vector using bubble sort algorithm.
     *
     * @param bubble_vector The user vector to be sorted as private member to be used for this algorithm.
     * @return does not return anything, alters the vector in the private members
     */
    void bubble_sort();

    /**
     * @brief sorts a vector using selection sort algorithm.
     *
     * @param selection_vector The user vector to be sorted as private member to be used for this algorithm.
     * @return does not return anything, alters the vector in the private members
     */
    void selection_sort();

    /**
     * @brief a function that finds the index of pivot point after moving all elements
     * smaller than the pivot to right of it and larger to the left of it.
     * the pivot point is initially the last element of the given vector
     * @param quick_sort The vector in the class private member
     * @param i_first the first index of the vector we want to sort
     * @param i_last the last index of the vector we want to sort
     * @return return the index of the pivot point
     */
    uint64_t partition(uint64_t i_first, uint64_t i_last);

    /**
     * @brief a function that automatically inputs the first and last index in the quick sort function
     * So, that the user does not have to manually do it
     * @param quick_vector The vector to be sorted using quick sort method
     * @return does not return anything, the private member vector is altered.
     */
    void quick_sort();

    /**
     * @brief a recursive function that sorts a vector using quick sort method
     *
     * @param quick_vector The vector to be sorted.
     * @param i_first the first index of the vector we want to sort
     * @param i_last the last index of the vector we want to sort
     * @return does not return anything, the private member vector is altered.
     */
    void quick_sort_implement(uint64_t i_first, uint64_t i_last);

    /**
     * @brief sorts a vector using insertion sort algorithm.
     *
     * @param insertion_vector The user vector to be sorted as private member to be used for this algorithm.
     * @return does not return anything, alters the vector in the private members
     */
    void insertion_sort();

    /**
     * @brief Function that calls the implementation of a merge sort algorithm
     * its used so the user does not have to pass the vector again in main
     * @param merge_vector The vector to be sorted.
     * @return does not return anything, alters the vector in the private members
     */
    void merge_sort();

    /**
     * @brief sorts a vector using merge sort algorithm.
     * its a recursive function that breaks down a vector by two in each iteration
     * then sorts and merges them/ builds them again
     * @param v The vector to be sorted.
     * @return does not return anything, alters the vector in the private members
     */
    void merge_sort_implement(vector<int64_t> &v);

    /**
     * @brief merges the right and left vector up into the user vector
     * @param merge_vector The user vector to be sorted.
     * @param left_half The left half of the vector.
     * @param right_half The right half of the vector.
     * @return does not return anything, alters the vector in the private members
     */
    void merge(vector<int64_t> &v, vector<int64_t> &left_half, vector<int64_t> &right_half);

    /**
     * @brief Function that calls the implementation of a heap sort algorithm
     * its used so the user does not have to pass the vector again in main
     * @param heap_vector The vector to be sorted.
     * @return does not return anything, alters the vector in the private members
     */
    void heap_sort();

    /**
     * @brief sorts a vector using heap sort algorithm (using max heap property).
     * key of particular node (child key) should be less than/ equal the parents key.
     * This function is a recursive function and it will swap values if there are not following max heap property.
     * leaf nodes are nodes with no children, so this should function should not be used to max heap-ify those leaf nodes
     * @param v The vector to be sorted.
     * @return does not return anything its a recursive function, the & is passed so that original vector is altered.
     */
    void heap_sort_implement(vector<int64_t> &v);

    /**
     * @brief functions that heap-ifi-es the nodes (maintains the max-heap property)
     * @param v The vector to be sorted.
     * @param i The index of the root node to heap-ify
     * @param n size of the list/vector to heap-ify
     * @return does not return anything its a recursive function, the & is passed so that original vector is altered.
     */
    void maxHeap_structure(vector<int64_t> &v, uint64_t n, uint64_t i);

    // prints user vector sorted using bubble sort algorithm
    void print_sorted_bubble();

    // prints user vector sorted using selection sort algorithm
    void print_sorted_selection();

    // prints user vector sorted using quick sort algorithm
    void print_sorted_quick();

    // prints user vector sorted using insertion sort
    void print_sorted_insertion();

    // prints user vector sorted using merge sort algorithm
    void print_sorted_merge();

    // prints user vector sorted using heap sort algorithm
    void print_sorted_heap();

    /**
     * @brief Prints the sorted list in a file
     * @param file_name The name of the output file
     * @return nothing
     */
    void print_sorted_toFile(string file_name);
};