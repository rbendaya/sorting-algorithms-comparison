# CSE701 Final Project: Sorting Algorithms Comparison

# Table of Contents
1. [Overview](##Overview)
2. [This Program Features](##This Program Features)
3. [Classes](##Classes)
4. [Sample Command Line Input ](##Sample Command Line Input )
5. [Sample Output](##Sample Output)
6. [Additional Options to The Program Users](##Additional Options to The Program Users)
7. [Sorting Algorithm Code Explanation](##Sorting Algorithm Code Explanation)

## Overview 
This program sorts a list of integers from a file and compares the sorting algorithms mentioned below in terms of their time while providing time statistics.
* Bubble Sort
* Selection Sort
* Quick Sort
* Insertion Sort
* Merge Sort 
* Heap Sort
  
## This Program Features
* sort a list from a file given from a user and printing it in an output file 
* provide a report comparing the 6 different algorithm in terms of average, median, standard deviation, min and max of the processing time and printing it in an output file.
* sort based on the user choice of algorithm and printing it in the console 
* providing a specific statistics metric from the ones mentioned above 

## Classes
There are three classes developed in this program 

1. run-time class -> used to calculate the run time of a chunk of code 
2. sorter class -> used to sort a vector based on the choice of algorithm, print it in consol, and print sorted array in an output file.
3. statistics class -> runs sorting algorithms 100 times then provided a specific run time statistic for an algorithm and provide an algorithms comparison report.

## Sample Command Line Input 
```
./CSE701 sample_inputFile.txt
```
## Sample Output 

### File 1 - Sorted List
```
-2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2593 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2500 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -2020 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -264 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -256 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -254 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -230 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -29 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -26 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -20 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -15 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 21 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 25 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 34 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 52 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 54 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 55 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 56 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 89 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 123 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 200 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 213 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 221 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 225 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 236 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 250 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 356 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 545 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 561 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 623 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 845 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 2131 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5165 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 5415 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 13152 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 21215 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 51521 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 55526 
```

### File 2 - Comparison Report
``` 
Algorithm run time statistics (in MilliSeconds): 

Algorithm        Average   Std       Median    Max       Min       
--------------------------------------------------------------
Bubble Sort      99.0402   0.169738  98.8161   167.36    95.5733   
Selection Sort   100.789   0.264727  98.8246   172.337   97.7214   
Quick Sort       181.158   0.476976  182.668   206.901   4.7846    
Insertion Sort   0.824849  0.0720149 0.10675   71.825    0.104     
Merge Sort       6.39062   0.0200822 6.35355   9.4079    6.1353    
Heap Sort        2.60093   0.0078233 3.07175   3.9447    2.5189    

Kruskal Wallis Test: There is a significant difference between the algorithms run times

Best Performing Model: Insertion Sort 
```

## Additional Options to The Program Users 
The user can also use the classes in this program to perform the following operations in addition to what the main program can do.

### run-time class options
Users can use this class to calculate the run time of a chunk of code 

begin by calling the class and the constructor using your vector similar to the example below.

```cpp 
run_time sort_time:
```
add the below code before your chunk of code
```cpp 
sort_time.begin()
```
add the below code after your chunk of code
```cpp 
sort_time.finished()
```
Then you can use the following to get the resulting time in seconds or Mille seconds 
```cpp 
sort_time.seconds()
// or
sort_time.milliseconds()
```
### sorter class options

begin by calling the class and the constructor using your vector similar to the example below.
```cpp 
sorter sort(user_vector)
```
Then choose the algorithm you want to use to sort you vector following the following format algorithm_sort(), similar to the example below for using heap sort
```cpp 
sort.heap_sort();
```
In addition, if you want to print your list in the consol just add _print to the previous code, check the code below
```cpp 
sort.heap_sort_print();
```
User can also print the sorted list to a file using the code below
```cpp 
sort.print_sorted_toFile();
```
### statistics class option  
This class runs the model 100 times and allows user to obtain statistical information about the algorithm. The format is sorting algorithm_statistic() below are example of statistic that you can implement for the insertion sort algorithm.

begin by calling the class and the constructor using your vector similar to the example below.
```cpp 
statistics stat(user_vector)
```
Obtaining specific stats

```cpp 
stat.insertion_avgTime(); // Mean running time 
stat.insertion_stdTime(); // Standard deviation of the running time 
stat.insertion_max(); // Max run time
stat.insertion_min(); // Min run time 
stat.insertion_median(); // Median of running time 
```
Performing Kruskal-Wallis test to check if there is a significant difference between the run time of difference between the algorithms in terms of their running time using the code below.
```cpp 
stat.kruskalWallis_test(); 
```
## Sorting Algorithm Code Explanation

### Bubble Sort Algorithm
The main goal of this algorithm is to try to push the largest variable towards the left. This is done using a double loop.
The variable i in the first loop is the range of position to compare. 
```cpp
for (uint64_t i = 0; i < vector_size - 1; i++)
```
The variable j in the second loop is the current vector position. After every ith iteration, the number of elements to compare is 
reduced by one.
```cpp
for (uint64_t j = 0; j < vector_size - 1 - i; j++)
```
The comparison of the element j and the next element is done inside the two loops, if the jth element is greater then j+1th element then swap the two elements. 
```cpp
if (bubble_vector.at(j) > bubble_vector.at(j + 1)) 
    swap(bubble_vector.at(j), bubble_vector.at(j + 1));
```

### Selection Sort Algorithm
The idea of this algorithm is looking for the minimum element in a given range then swapping that element with the first element in that given range.

The first loop j, consists of the range of operation.
```cpp
for (uint64_t j = 0; j < vector_size - 1; j++)
```
Inside it we initialize the variable in the first index as the minimum.
```cpp
min_value = j; 
```
The second loop i, loops around the vector in that given range
```cpp
for (uint64_t i = j + 1; i < vector_size; i++)
```
If the value of the index at element i is less than the minum value in the min_value variable, the value in index i becomes the min.
```cpp
if (selection_vector.at(i) < selection_vector.at(min_value)) // storing the min value in the given range
    min_value = i;
```
After the second loop the first element is swapped by the minimum value.
```cpp
swap(selection_vector.at(j), selection_vector.at(min_value))
```
### Quick Sort Algorithm
Quick sort algorithms has three functions. 

The first is the partition function which is used to find the pivot point index. The point that splits the vector into two. In this code the pivot point is automatically assigned to the last element in the vector then the partition function moves all the elements smaller than the pivot point to the right of it, and the higher to the left of it. This is illustrated the code below.

```cpp
int64_t pivot;

    pivot = quick_vector.at(i_last); // choosing last element as the pivot
    uint64_t current = i_first;      // will be used to find correct position of the pivot element
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
```
The second function that automatically inputs the first and last index in the quick sort function its written So that the user does not have to manually do it when needing to perform the operation. The user only needs to input the vector to be sorted using quick sort algorithm.

The third function is a recursive function that implements the algorithm by recursivly partitioning the portion to the right and left until the first index is equal to the last in index the code inside this function can be seen below 
```cpp
if (i_first >= i_last)
        return;                              // return to the function, section of vector to sort has no elements
    uint64_t p = partition(i_first, i_last); // the pivot point
    // the pivot point is in its correct index
    // Now, deal with the portion to the left and the portion on the right of p
    quick_sort_implement(i_first, p - 1); // portion to the right
    quick_sort_implement(p + 1, i_last);  // portion to the left
    // recursively this will sort the entire vector
```
### Insertion Sort Algorithm 
A simple algorithm that builds the sorted list one element at a time using the comparison method. The code uses two loops. The first compares the current element with the previous one. If that element is greater than it is shifted to the right. The second loops the empty slot. The elements are shifted by copying.

The main loop to loop around the vector starts from 1 as the algorithms assumes it is in the correct position.
```cpp
for (uint64_t i = 1; i < vector_size; i++)
```
Inside it, the current element and the empty slot are initialized.

```cpp
int64_t current = insertion_vector.at(i);
uint64_t slot = i - 1 + 1;
```
In addition, to the while loop the slots, as long as the the value in that slot is greater than current element, the element to the right of the slot will be inserted in the slot.
```cpp
while (slot > 0 && insertion_vector.at(slot - 1) > current)
    {
        insertion_vector.at(slot + 1 - 1) = insertion_vector.at(slot - 1); // shift it to left by copying
        slot--;
     }
    insertion_vector.at(slot + 1 - 1) = current; // storing the current element in the empty slot
```
### Merge Sort Algorithm
The code for this algorithm also has three function. The first is a function "merge_sort" that calls the implementation of a merge sort algorithm.It is used so the user does not have to pass the vector again in main. The second is "merge_sort_implement" which is a recursive function that breaks down a vector into two in each iteration. It then sorts and merges/builds them again. The third is "merge". This function merges the right and left vector all the way up into the user sorted vector.

The code for the merge_sort_implement if straight forward. The vector is split into two and the right/left half are stored in two vectors in a recursive function in addition to the calling of the merge function to merge the right and left vectors.

In the merge function there is three iterators.
```cpp
uint64_t i = 0; // iterator for the left half
uint64_t j = 0; // iterator for the right half
uint64_t k = 0; // iterator for the merged vector
```
We begin looping around the left and right vector
```cpp
 while (i < left_length && j < right_length)
```
If the value of jth index at the right half is greater than value of the ith index of the left half vector we assign the value in the kth index of the user vector to the ith index of the left half and increment i, otherwise assign it to jth index of the right half vector and increment j. This will start building the final sorted list. After the first iteration increment k as well
```cpp
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

```
Then the leftover elements, that were not added in the previous step the main vector.
```cpp
// Adding the leftover elements
// If we ran out of elements in the left vector it will by pass this
while (i < left_length)
{
    v.at(k) = left_half.at(i);
    i++;
    k++;
}
// If we ran out of elements in the left vector it will by pass this
while (j < right_length)
{
    v.at(k) = right_half.at(j);
    j++;
    k++;
}

```
### Heap Sort Algorithm
The code for this algorithm also has three functions. The first is "heap_sort" that calls the implementation of a heap sort algorithm. It is used so the user does not have to pass the vector again in main. The second is "heap_sort_implement" which is used to sort a vector using heap sort algorithm (using max heap property).The property is satisfied when a particular node (child key) is less than/equal the parents key.This function is a recursive function and it will swap values if they are not following max heap property.leaf nodes are nodes with no children, so this function should not apply the max heap property on those leaf nodes. The third is "maxHeap_structure" which maintains the max-heap property of the nodes.

The explanation of the code of each function can be understood from the comments in the sorter.cpp file.

## References & Acknowledgement 
Channels/libraries in the links below were used for understanding the concept behind the algorithms.

[Michael Sambol Channel](https://www.youtube.com/@MichaelSambol/playlists)
[LalithaNatraj Channel](https://www.youtube.com/@LalithaNatraj/playlists)
Learning C++ 
[Barak Shoshany](https://baraksh.com/CSE701/#toc-topics)
