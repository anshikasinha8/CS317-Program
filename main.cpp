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
#include <sstream>
#include <chrono>

using namespace std;

// Function prototypes
void quickSort(string arr[], int left, int right);
int hoarePartition(string arr[], int left, int right);
void swap(string* a, string* b);

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
    cout << "Welcome to the sorting program!" << endl;
    cout << "Enter the name of the input file: ";
    cin >> input;
    cout << "Enter the name of the output file: ";
    cin >> output;

    // Open input file
    inputFile.open(input);

    // Check if file is open
    if (!inputFile.is_open()) {
        cout << "Error: Input file not found." << endl;
        return 0;
    }

    // Read file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        while (iss >> word) {
            words[count++] = word;
        }
          
    }
    // Close file
    inputFile.close();

    // Print number of words read
    cout << count << " words were found in the file: " << input << endl;
    // Prompt user for number of words per line
    cout << "How many words per line should be printed? ";
    cin >> M;

    // Open output file
    outputFile.open(output);
    // Check if file is open
    if (!outputFile.is_open()) {
        cout << "Error: Output file not found." << endl;
        return 0;
    }

    // Sort words using QuickSort
    auto start = chrono::high_resolution_clock::now();      // Start timer
    quickSort(words, 0, count - 1);                         // Sort words
    auto end = chrono::high_resolution_clock::now();        // Stop timer
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);   // Calculate time taken
    cout << "The initial quicksort took  " << duration1.count() << " microseconds" << endl;

    // Write sorted words to output file
    for (int i = 0; i < count; i++) {
        outputFile << words[i];
        if ((i + 1) % M == 0) {
            outputFile << endl;
        } else {
            outputFile << " ";
        }
    }
    cout << "Results printed to : " << output << endl;
    // Close file
    outputFile.close();

    // Take sorted array and run Quicksort on it again
    cout << "Resorting the already sorted list..." << endl;
    auto start2 = chrono::high_resolution_clock::now(); // Start timer
    quickSort(words, 0, count - 1);                     // Sort again
    auto end2 = chrono::high_resolution_clock::now();   // Stop timer
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2); // Calculate time taken
    cout << "Time taken to sort again: " << duration2.count() << " microseconds" << endl;

    // Compute the % time longer it takes to sort the ordered list
    double percent = ((double)duration2.count() - (double)duration1.count()) / (double)duration1.count() * 100;
    cout << "An increase of about " << round(percent) << "%" << endl; 

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
