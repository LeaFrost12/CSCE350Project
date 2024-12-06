#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>

using namespace std;

vector<float> readFile(string filename, char delim);
void printToFile(string file_name, string str, bool append);
void createRandomFile(string file_name, int n);
void printVectorToFile(string file_name, vector<float> arr);
void computeAverageTimes();

#endif