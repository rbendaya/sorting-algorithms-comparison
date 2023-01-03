#pragma once
/**
 * @file sorter.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief A file that contain a class that can perform different sorting algorithms and print the sorted list.
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */

#include "run_time.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief A class that can perform different sorting algorithms and print the sorted list.
 */
class sorter
{
    // ============
    // Private data
    // ============
private:
    /**
     * @brief Private member that stores the size of the users list.
     */
    uint64_t vector_size;
    /**
     * @brief A private member that stores the list in a vector container, each container is specific to a sorting algorithm.
     */
    vector<int64_t> bubble_vector;
    vector<int64_t> selection_vector;
    vector<int64_t> quick_vector;
    vector<int64_t> insertion_vector;
    vector<int64_t> merge_vector;
    vector<int64_t> heap_vector;

    // =======================
    // Public member functions
    // =======================
public:
    /**
     * @brief A constructor, that takes the user's list as a vector and stores it
     * in the private members of each vector that will be used for a specific sorting algorithm.
     * @param user_list The vector to be sorted.
     **/
    sorter(vector<int64_t> user_list);

    /**
     * @brief Sorts a vector using bubble sort algorithm.
     *
     * @param bubble_vector The user vector to be sorted as private member to be used for this algorithm.
     */
    void bubble_sort();

    /**
     * @brief Sorts a vector using selection sort algorithm.
     *
     * @param selection_vector The user vector to be sorted as private member to be used for this algorithm.
     */
    void selection_sort();

    /**
     * @brief A function that finds the index of pivot point after moving all elements
     * smaller than the pivot to right of it and larger to the left of it.
     * The pivot point is initially the last element of the given vector.
     * @param quick_sort The vector in the class private member
     * @param i_first the first index of the vector we want to sort
     * @param i_last the last index of the vector we want to sort
     * @return return the index of the pivot point
     */
    uint64_t partition(uint64_t i_first, uint64_t i_last);

    /**
     * @brief A function that automatically inputs the first and last index in the quick sort function
     * So, that the user does not have to manually do it.
     * @param quick_vector The vector to be sorted using quick sort method.
     */
    void quick_sort();

    /**
     * @brief A recursive function that sorts a vector using quick sort method.
     * @param quick_vector The vector to be sorted.
     * @param i_first The first index of the vector we want to sort.
     * @param i_last The last index of the vector we want to sort.
     */
    void quick_sort_implement(uint64_t i_first, uint64_t i_last);

    /**
     * @brief Sorts a vector using insertion sort algorithm.
     * @param insertion_vector The user vector to be sorted as private member to be used for this algorithm.
     */
    void insertion_sort();

    /**
     * @brief Function that calls the implementation of a merge sort algorithm.
     * It is used so the user does not have to pass the vector again in main.
     * @param merge_vector The vector to be sorted.
     */
    void merge_sort();

    /**
     * @brief Sorts a vector using merge sort algorithm.
     * It is a recursive function that breaks down a vector into two in each iteration.
     * It then sorts and merges/builds them again.
     * @param v The vector to be sorted.
     */
    void merge_sort_implement(vector<int64_t> &v);

    /**
     * @brief Merges the right and left vector all the way up into the user vector.
     * @param merge_vector The user vector to be sorted.
     * @param left_half The left half of the vector.
     * @param right_half The right half of the vector.
     */
    void merge(vector<int64_t> &v, vector<int64_t> &left_half, vector<int64_t> &right_half);

    /**
     * @brief Function that calls the implementation of a heap sort algorithm.
     * It is used so the user does not have to pass the vector again in main.
     * @param heap_vector The vector to be sorted.
     */
    void heap_sort();

    /**
     * @brief Sorts a vector using heap sort algorithm (using max heap property).
     * The property is satisfied when a particular node (child key) is less than/equal the parents key.
     * This function is a recursive function and it will swap values if they are not following max heap property.
     * leaf nodes are nodes with no children, so this function should not apply the max heap property on those leaf nodes.
     * @param v The vector to be sorted.
     */
    void heap_sort_implement(vector<int64_t> &v);

    /**
     * @brief Function that maintains the max-heap property of the nodes.
     * @param v The vector to be sorted.
     * @param i The index of the root node to heap-ify
     * @param n Size of the list/vector to sort using max heap property.
     */
    void maxHeap_structure(vector<int64_t> &v, uint64_t n, uint64_t i);

    /**
     * @brief Prints user vector sorted using bubble sort algorithm
     */
    void print_sorted_bubble();

    /**
     * @brief Prints user vector sorted using selection sort algorithm.
     */
    void print_sorted_selection();

    /**
     * @brief Prints user vector sorted using quick sort algorithm.
     */
    void print_sorted_quick();

    /**
     * @brief Prints user vector sorted using insertion sort.
     */
    void print_sorted_insertion();

    /**
     * @brief Prints user vector sorted using merge sort algorithm.
     */
    void print_sorted_merge();

    /**
     * @brief Prints user vector sorted using heap sort algorithm.
     */
    void print_sorted_heap();

    /**
     * @brief Prints the sorted list in a file
     * @param file_name The name of the output file
     */
    void print_sorted_toFile(string file_name);
};