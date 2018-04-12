// BCS 230 Assignment 10
// Ian Liotta
// Read values from a file and store them in a dynamic array. Find the sum and average of the values using pointers.

#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
int countLines(string fileName);
void readFile(double *arr, int size, string fileName);
double findSum(double *arr, int size);
double findAverage(double *arr, int size);
void printArray(double *arr, int size);

int main() {
	// count how many lines of data are in dataFile.txt and create an array large enough to hold them
	int dataSize = countLines("dataFile.txt");
	double *arr = new double[dataSize];

	// read dataFile.txt into array. Print the data, sum, and averages
	readFile(arr, dataSize, "dataFile.txt");
	printArray(arr, dataSize);
	cout << findSum(arr, dataSize) << endl;
	cout << findAverage(arr, dataSize) << endl;
	return 0;
}

// countLines returns the number of lines in the file specified by parameter fileName
int countLines(string fileName) {
	ifstream inFile(fileName);
	double input = 0;
	int dataSize = 0;

	while (inFile >> input) 
		dataSize++;
	inFile.close();
	return dataSize;
}

// readFile reads each line from the file specified by parameter fileName and 
// writes it to a location in array pointed to by paramter arr.
void readFile(double *arr, int size, string fileName) {
	ifstream inFile(fileName);
	int i = 0;

	while (inFile >> *(arr + i)) 
		i++;
	inFile.close();
}

// findSum returns the sum of all doubles stored in array pointed to by arr
double findSum(double *arr, int size) {
	double sum = 0.0;

	for (int i = 0; i < size; i++) 
		sum += *(arr + i);
	return sum;
}

// findAverage returns the average of the data stored in array pointed to by arr
double findAverage(double *arr, int size) {
	return findSum(arr, size) / size;
}

// printArray iterates through array pointed to by arr and prints each stored value.
void printArray(double *arr, int size) {
	for (int i = 0; i < size; i++) 
		cout << *(arr + i) << endl;
}