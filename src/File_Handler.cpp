#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <random>

using namespace std;

/**
 * Class for file input and output, computing average time
 * Lea Frost
 */

// Random float generation
random_device rd; 
default_random_engine gen(rd());
uniform_real_distribution<double> distribution(-100.0,100.0);

string timeFileName = "output/Frost_Lea_executionTime.txt";
string averageTimeFileName = "output/Frost_Lea_averageExecutionTime.txt";

int NUM = 10;

/*
splits a string into an array of floats, delimited by spaces
*/
vector<float> split(string str, char delim)
{
    vector<float> result;
    stringstream data(str);
    string line;
    while(getline(data,line,delim))
    {
        result.push_back(stof(line));
    }
    return result;
}

// Reads file of floats delimited by spaces
vector<float> readFile(string file_name, char delim)
{
    string line;
    vector<float> splitline;

    ifstream infile(file_name);

    // Get lines
    while (getline(infile, line)) {
        vector<float> next_line = split(line, delim);
        splitline.insert(splitline.end(), next_line.begin(), next_line.end());
    }

    infile.close();
    return splitline;

}

// Generates random float from -100.0 to 100.0
float randomFloat() {
    return distribution(gen);
}

// Prints a string to a file
void printToFile(string file_name, string str, bool append) {
    
    if (append) {
        ofstream outFile(file_name, ios::app);
        outFile << str;
    }
    else {
        ofstream outFile(file_name);
        outFile << str;
    }
}

/**
 * Creates file with random floats delimited by spaces
 * @param file_name Name of the file to be created
 * @param n Number of random numbers
 */ 
void createRandomFile(string file_name, int n) {

    string str = "";

    for (int i = 0; i<n; i++) {
        str += to_string(randomFloat()) + ' ';
    }

    printToFile(file_name, str, false);
    
}

// Print a vector of floats to a file
void printVectorToFile(string file_name, vector<float> arr) {
    ofstream outFile(file_name);
    for (float num : arr) {
        outFile << to_string(num) << ' ';
    }
}

void computeAverageTimes() {

    string line;
    vector<float> timeData;

    ifstream timeFile(timeFileName);

    // Get time data
    while (getline(timeFile, line)) {
        vector<float> next_line = split(line, '\t');
        timeData.push_back(next_line[1]);
    }

    int totalTime10 = 0;
    int totalTime100 = 0;
    int totalTime1000 = 0;

    cout << timeData.size();


    // Sum total times
    for (int i = 0; i<static_cast<int>(timeData.size()); i++) {
        if (i<25) {
            totalTime10 += timeData[i];
        }
        else if (i<50) {
            totalTime100 += timeData[i];
        }
        else {
            totalTime1000 += timeData[i];
        }
    }

    string averageTimes = 
        "10\t" + to_string(totalTime10/25) +  "\n"
        "100\t" + to_string(totalTime100/25) + "\n"
        "1000\t" + to_string(totalTime1000/25);
    
    printToFile(averageTimeFileName, averageTimes, false);
}
