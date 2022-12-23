# CSE701 Project Draft 
Note: This is a quick summary of my program 

## Overview 
This program sorts a list of integers from a file and compares the sorting algorithms mentioned below in terms of their time while providing time statistics.
* Bubble Sort
* Selection Sort
* Quick Sort
* Insertion Sort
* Merge Sort 
* Heap Sort
  
## What can this program do 
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
![ss](https://user-images.githubusercontent.com/69400494/208174525-ce9e6a65-f91b-44b4-86f3-9bf6ae995b8f.png)

## Sample Output 

### File 1 - Sorted List
![sl](https://user-images.githubusercontent.com/69400494/208177344-7f135b93-83e7-4efb-9f93-4a0df9621fa8.png)

### File 2 - Comparison Report 
![cr](https://user-images.githubusercontent.com/69400494/209404529-73c60a4c-c46d-4c5a-b4dc-ffcdc98ecf4f.png)

## Additional Options to The Program Users 
The user is also use the classes in this program to perform the following operations in addition to what this program can do.

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

## References 
Channels/libraries in the links below were used for understanding the concept behind the algorithms.

[Michael Sambol Channel](https://www.youtube.com/@MichaelSambol/playlists)

[LalithaNatraj Channel](https://www.youtube.com/@LalithaNatraj/playlists)

Learning C++ 

[Barak Shoshany](https://baraksh.com/CSE701/#toc-topics)
