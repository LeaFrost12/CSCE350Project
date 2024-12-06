#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "File_Handler.h"

using namespace std;

/**
 * Project
 * Quick Sort algorithm
 * CSCE 350 F24
 * Lea Frost
 */

//implement hoare partition
int partition(vector<float>& arr, int left, int right) {
    //initialize high and low pointers
    int i = left-1;
    int j = right+1;
    //set pivot to leftmost value
    float p = arr[left];

    while (true) {
        //decrement high pointer
        do {
            j--; 
        } while (arr[j] > p);

        //increment low pointer
        do {
            i++;
        } while (arr[i] < p);

        //if pointers cross, then swap
        if (i < j) {
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        //return partition index
        else 
            return j;
    }
}


// Find index of pivot point using median of three method
int findPivotIndex(vector<float>& arr, int left, int right) {
    //calculate middle index
    int middle = left + (right - left + 1) / 2;

    //get the three values
    float a = arr[left];
    float b = arr[middle];
    float c = arr[right];

    //Return median index
    if ((a >= b && a <= c) || (a <= b && a >= c)) 
        return left;
    if ((b >= a && b <= c) || (b <= a && b >= c)) 
        return middle;
    return right;

}

void quickSort(vector<float>& arr, int left, int right){

    // Quicksort
    if (left < right) {

        // Swap pivot with leftmost value
        int pivotIndex = findPivotIndex(arr, left, right);

        float temp = arr[left];
        arr[left] = arr[pivotIndex];
        arr[pivotIndex] = temp;

        //partition
        int p = partition(arr, left, right);
        //recursion
        quickSort(arr, left, p);
        quickSort(arr, p+1, right);

    }
    
}


int main(int argc, char* argv[]) {

    //if given files, run quick sort
    if (argc == 3) {
        //read input file
        vector<float> arr = readFile(argv[1], ' ');

        int size = arr.size();

        // start clock
        auto start = chrono::high_resolution_clock::now();

        // quick sort
        quickSort(arr, 0, size-1);

        // stop clock
        auto stop = chrono::high_resolution_clock::now();

        // calculate time
        auto time = chrono::duration_cast<chrono::microseconds>(stop - start);

        // create time data string
        string timeData = to_string(size) + "\t" + to_string(time.count()) + "\n";

        //print time
        printToFile("output/Frost_Lea_executionTime.txt", timeData, true);

        //print sorted list to output file
        printVectorToFile(argv[2], arr);
    }
    else {
        //if no files given, compute average time
        computeAverageTimes();
    }

}