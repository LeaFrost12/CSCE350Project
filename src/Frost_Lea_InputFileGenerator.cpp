#include "File_Handler.h"
#include <iostream>
#include <string>

/**
 * For generating 25 input files of each size
 */

int NUM_FILES = 25;

int main() {

    //Generate size 10 files
    for (int i = 0; i<NUM_FILES; i++) {
        string file_name = "input/input_10_" + to_string(i+1) + ".txt";
        createRandomFile(file_name, 10);
    }

    //Generate size 100 files
    for (int i = 0; i<NUM_FILES; i++) {
        string file_name = "input/input_100_" + to_string(i+1) + ".txt";
        createRandomFile(file_name, 100);
    }

    //Generate size 1000 files
    for (int i = 0; i<NUM_FILES; i++) {
        string file_name = "input/input_1000_" + to_string(i+1) + ".txt";
        createRandomFile(file_name, 1000);
    }
    
}