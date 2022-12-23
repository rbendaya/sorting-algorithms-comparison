/**
 * @file sorter.hpp
 * @author Rayan Ben Daya (bendayar@mcmaster.ca)
 * @brief cpp file of the class used to perform different sorting algorithms and print them
 * @version 1.0
 * @date 2022-12-19
 * @copyright Copyright (c) 2022 Rayan Ben Daya
 */
#include "run_time.hpp"
#include "sorter.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

sorter::sorter(vector<int64_t> user_list)
{
    vector_size = user_list.size();

    for (uint64_t i = 0; i < vector_size; i++)
    {
        bubble_vector.push_back(user_list.at(i));
        selection_vector.push_back(user_list.at(i));
        quick_vector.push_back(user_list.at(i));
        insertion_vector.push_back(user_list.at(i));
        merge_vector.push_back(user_list.at(i));
        heap_vector.push_back(user_list.at(i));
    }
}

void sorter::bubble_sort()
{
    // this loops tries to push the largest integers to the left
    // i is the range of positions to compare
    // j is the vector position
    for (uint64_t i = 0; i < vector_size - 1; i++)
    {
        for (uint64_t j = 0; j < vector_size - 1 - i; j++) // after every iteration of i reduce the indicies to compare by i
        {
            if (bubble_vector.at(j) > bubble_vector.at(j + 1)) // if the number on the left is greater than on the right swap
                swap(bubble_vector.at(j), bubble_vector.at(j + 1));
        }
    }
}

void sorter::selection_sort()
{
    uint64_t min_value;                            // will store minimum value of the elements in each iteration
    for (uint64_t j = 0; j < vector_size - 1; j++) // the range of operation
    {
        min_value = j;                                 // initialing the first element of the range to the min
        for (uint64_t i = j + 1; i < vector_size; i++) // looping around the vector in the given range
        {
            if (selection_vector.at(i) < selection_vector.at(min_value)) // storing the min value in the given range
                min_value = i;
        }
        swap(selection_vector.at(j), selection_vector.at(min_value)); // swapping the first element by the min value
    }
}

uint64_t sorter::partition(uint64_t i_first, uint64_t i_last)
{
    int64_t pivot = quick_vector.at(i_last); // choosing last element as the pivot
    uint64_t current = i_first;              // will be used to find correct position of the pivot element
    // looping around the vector up to last index (befor pivot index)
    for (uint64_t i = i_first; i < i_last; i++)
    {
        // the algorithm below tries to push element > pivot to the left
        // and elements < pivot to the right
        if (quick_vector.at(i) <= pivot)
        {
            swap(quick_vector.at(i), quick_vector.at(current));
            current += 1;
        }
    }
    // insert the pivot in the middle of the two portions/ its correct position
    swap(quick_vector.at(current), quick_vector.at(i_last));
    // return the pivot position
    return current;
}

void sorter::quick_sort()
{
    uint64_t first_index = 0;
    uint64_t last_index = size(quick_vector) - 1;
    quick_sort_implement(first_index, last_index);
}

void sorter::quick_sort_implement(uint64_t i_first, uint64_t i_last)
{
    if (i_first >= i_last)
        return;                              // return to the function, section of vector to sort has no elements
    uint64_t p = partition(i_first, i_last); // the pivot point
    // the pivot point is in its correct index
    // Now, deal with the portion to the left and the portion on the right of p
    quick_sort_implement(i_first, p - 1); // portion to the right
    quick_sort_implement(p + 1, i_last);  // portion to the left
    // recursively this will sort the entire vector
}

void sorter::insertion_sort()
{
    // this loops tries to push the largest integers to the left
    // i is the range of positions to compare
    // j is the vector position
    for (uint64_t i = 1; i < vector_size; i++) // start from 1 as the algorithms assumes it is in the correct position
    {
        int64_t current = insertion_vector.at(i); // current element
        // another loop to look at all previous items
        // if an item is greater we shift them to the right
        uint64_t slot = i - 1 + 1; // loop the slot (empty cell), adding + 1 to use uint then deducting it whenever we use i
        while (slot > 0 && insertion_vector.at(slot - 1) > current)
        {
            insertion_vector.at(slot + 1 - 1) = insertion_vector.at(slot - 1); // shift it to left by copying
            slot--;
        }
        insertion_vector.at(slot + 1 - 1) = current; // storing the current element in the empty slot
    }
}

void sorter::merge_sort()
{
    // call the function that implements the merge sort algorithm
    merge_sort_implement(merge_vector);
}

void sorter::merge_sort_implement(vector<int64_t> &v)
{
    uint64_t v_length = v.size(); // length of user vector

    if (v_length < 2) // means the vector has one element, stop as its sorted and return to function
        return;
    // divide the vector into two vectors
    uint64_t i_mid = v_length / 2; // middle index
    // create two new vectors right & left
    vector<int64_t> left_half;
    vector<int64_t> right_half;

    // populate left vector elements from the input vector
    for (uint64_t i = 0; i < i_mid; i++)
    {
        // left_half.at(i) = v.at(i);
        left_half.push_back(v.at(i));
    }
    // populate right vector elements from the input vector
    for (uint64_t i = i_mid; i < v_length; i++)
    {
        // right_half.at(i) = v.at(i);
        right_half.push_back(v.at(i));
    }

    // now merge sort each of those two vector (recursive concept of this algorithm)
    merge_sort_implement(left_half);
    merge_sort_implement(right_half);

    // merge the two sorted vector into the larger vector
    merge(v, left_half, right_half);
}

void sorter::merge(vector<int64_t> &v, vector<int64_t> &left_half, vector<int64_t> &right_half)
{
    uint64_t left_length = left_half.size();   // length of left half vector
    uint64_t right_length = right_half.size(); // length of right half vector

    uint64_t i = 0; // iterator for the left half
    uint64_t j = 0; // iterator for the right half
    uint64_t k = 0; // iterator for the merged vector

    // The below code checks and iterated through the indicies of the
    // two vectors sorts them and build the new larger vector
    // loop until we run out of elements in the right or left vector
    while (i < left_length && j < right_length)
    {
        if (left_half.at(i) <= right_half.at(j))
        {
            v.at(k) = left_half.at(i);
            i++;
        }
        else
        {
            v.at(k) = right_half.at(j);
            j++;
        }
        // increment the larger array
        k++;
    }

    // adding the leftover elements
    // if we ran out of elements in the left vector it will by pass this
    while (i < left_length)
    {
        v.at(k) = left_half.at(i);
        i++;
        k++;
    }
    // if we ran out of elements in the left vector it will by pass this
    while (j < right_length)
    {
        v.at(k) = right_half.at(j);
        j++;
        k++;
    }
}

void sorter::heap_sort()
{
    // call the function that implements the merge sort algorithm
    heap_sort_implement(heap_vector);
}

void sorter::heap_sort_implement(vector<int64_t> &v)
{
    uint64_t n = v.size(); // size of the vector
    // for loop below sorts a vector to make it follow max heap property data structure
    for (uint64_t i = (n / 2) - 1 + 1; i > 0; --i) // (n/2)- 1 is used to ignore leaf nodes, + 1 is added in the loop then deducted so uint can be used
        maxHeap_structure(v, n, i - 1);            // recursive

    // for loop below to sort the vector correctly by extracting elements from the heap obtained before one by one
    // i.e. build max heap
    for (uint64_t i = n - 1 + 1; i > 0; --i) // + 1 is added in the loop then deducted so uint can be used
    {
        // swap root position (0) of the vector with last element (lowest value)
        swap(v.at(0), v.at(i - 1));
        // then again make the list follow a max heap structure but excluding the last element after each iteration
        maxHeap_structure(v, i - 1, 0);
    }
}

void sorter::maxHeap_structure(vector<int64_t> &v, uint64_t n, uint64_t i)
{
    uint64_t largest = i;             // assigning largest variable as root node (assumption) index
    uint64_t left_child = 2 * i + 1;  // left child of the subtree index
    uint64_t right_child = 2 * i + 2; // right child of the subtree index
    // if the left child > than root ie max heap property violated
    // also left child index can not be >= size of the vector, equal because we are not considering last leaf node
    if ((left_child < n) && (v.at(left_child) > v.at(largest)))
    {
        largest = left_child;
    }
    // if the right child > than root ie max heap property violated
    // also right child index can not be >= size of the vector, equal because we are not considering last leaf node
    if ((right_child < n) && (v.at(right_child) > v.at(largest)))
    {
        largest = right_child;
    }

    // if the root node changed swap
    if (largest != i)
    {
        swap(v.at(i), v.at(largest));
        // recursive , making subtree follow max heap property, subtree that might be effected by change in the root node
        maxHeap_structure(v, n, largest);
    }
}

void sorter::print_sorted_bubble()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << bubble_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_selection()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << bubble_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_quick()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << quick_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_insertion()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << insertion_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_merge()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << merge_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_heap()
{
    for (uint64_t i = 0; i < vector_size; i++)
    {
        cout << heap_vector.at(i) << " ";
    }
    cout << endl;
}

void sorter::print_sorted_toFile(string file_name)
{
    // printing results in a file
    ofstream output(file_name);
    if (!output.is_open())
    {
        cout << "Error in opening the output file :(";
        exit(0);
    }

    // sorting
    bubble_sort();

    // printing
    for (uint64_t i = 0; i < vector_size; i++)
    {
        output << bubble_vector.at(i) << " ";
    }

    cout << "Sorted list successfully printed in the file: " << file_name << endl;

    // Close file
    output.close();
}