/* --------------------------------------------------------------------------
 * File: main.cpp
 * Description: CS 317 Program 1 
 * Fuction: This program reads a file and sorts the words using QuickSort with 
 *          Hoare's partition algorithm.
 * 
 * OS: MacOS Sequoia (15.3.1)
 * Compiler: g++ (Apple clang version 15.0.0)
 * Development environment: VS Code
 * 
 * Input: Input & output file name (.txt), no. of words per line
 * Output: Sorted words in the file, time taken for each sort
 * 
 * Author: Anshika Sinha
 * Date: March 27, 2025
 * --------------------------------------------------------------------------*/

// Include libraries
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

// Function prototypes
void quickSort(string arr[], int left, int right);
int hoarePartition(string arr[], int left, int right);
void swap(string* a, string* b);
void printArray(string arr[], int size); 

// Main function
int main() {
    // Declare variables
    string input, output, line, word;
    int M, count = 0;
    ifstream inputFile;
    ofstream outputFile;
    const int MAX = 100000;
    string words[MAX];

    // Prompt user for filenames
    cout << "Enter the name of the input file: ";
    cin >> input;
    cout << "Enter the name of the output file: ";
    cin >> output;
    cout << "Enter the number of words to write per line: ";
    cin >> M;

    // Open input file
    inputFile.open(input);

    // Check if file is open
    if (!inputFile.is_open()) {
        cout << "Error: Input file not found." << endl;
        return 0;
    }

    // Read file
    while (getline(inputFile, line)) {
        words[count++] += word;  
    }
    // Close file
    inputFile.close();

    // Open output file
    outputFile.open(output);
    // Check if file is open
    if (!outputFile.is_open()) {
        cout << "Error: Output file not found." << endl;
        return 0;
    }

    // Write sorted words to output file
    for (int i = 0; i < count; i++) {
        outputFile << words[i];
        if ((i + 1) % M == 0) {
            outputFile << endl;
        } else {
            outputFile << " ";
        }
    }
    // Close file
    outputFile.close();

    return 0;
}

// QuickSort function
void quickSort(string arr[], int left, int right) {
    if (left < right) {
        int p = hoarePartition(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);
    }
}

// Hoare's partition algorithm
int hoarePartition(string arr[], int left, int right) {
    string pivot = arr[left];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}

// Swap two strings
void swap(string* a, string* b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}