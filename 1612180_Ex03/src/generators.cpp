#include <vector>
#include <algorithm>
#include "generators.h"

// Generate arrays of random integers
// Usage: <number_of_arrays> <size_of_array> <output_file>
// Example: 1000 1000 data.txt
int genRandomIntArray(int nArray, int arrSize, char* fileName)
{
	srand((unsigned int)time(NULL));

	ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		cout << "genIntArray: Error opening output file.";
		return 0;
	}

	// nArray - 1 arr
	for (int i = 0; i < nArray - 1; i++)
	{
		// arrSize - 1 number
		for (int j = 0; j < arrSize - 1; j++)
		{
			outFile << rand() << ' ';
		}
		// last number
		outFile << rand() << endl;
	}

	// last arr
	for (int j = 0; j < arrSize - 1; j++)
	{
		outFile << rand() << ' ';
	}
	outFile << rand();

	outFile.close();

	return 1;
}

int genOrderedIntArray(int nArray, int arrSize, char* fileName, bool increase)
{
	srand((unsigned int)time(NULL));

	ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		cout << "genIntArray: Error opening output file.";
		return 0;
	}

	// nArray - 1 arr
	for (int i = 0; i < nArray - 1; i++)
	{
		// rand vector<int>
		vector<int> arr = {};
		for (int j = 0; j < arrSize; j++) {
			arr.push_back(rand());
		}
		// tang dan
		if (increase) {
			sort(arr.begin(), arr.end());
		}
		// giam dan
		else {
			sort(arr.begin(), arr.end(), greater<int>());
		}

		// arrSize - 1 number
		for (int j = 0; j < arrSize - 1; j++)
		{
			outFile << arr[j] << ' ';
		}
		// last number
		outFile << arr[arrSize - 1] << endl;
	}

	// last arr
	// rand vector<int>
	vector<int> arr = {};
	for (int j = 0; j < arrSize; j++) {
		arr.push_back(rand());
	}
	// tang dan
	if (increase) {
		sort(arr.begin(), arr.end());
	}
	// giam dan
	else {
		sort(arr.begin(), arr.end(), greater<int>());
	}

	// arrSize - 1 number
	for (int j = 0; j < arrSize - 1; j++)
	{
		outFile << arr[j] << ' ';
	}
	// last number
	outFile << arr[arrSize - 1];

	outFile.close();

	return 1;
}