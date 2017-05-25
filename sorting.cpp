//
// Created by Neil on 5/23/2017.
//

#include "sorting.hpp"

bool linearSearch(std::string fileName,int userSearch) {
	std::ifstream inFile;
	inFile.open(fileName);

	if(inFile.fail()) {
		std::cout << "Could not open file, an error has occurred." << std::endl;
		exit(1);
	}
	else {
		int fileInt;
		while (inFile >> fileInt) {
			if (fileInt == userSearch) {
				inFile.close();
				return true;
			}
		}
		inFile.close();
		return false;
	}
}

void fileToVect(std::string fileName, std::vector<int>& vecName) {
	std::ifstream inFile;
	inFile.open(fileName);
	int currNum;

	while (inFile >> currNum){
		vecName.push_back(currNum);
	}
	// Close current file as we are done with it currently
	inFile.close();
}

void displayresults(std::vector<int> vecName) {
	for(int i = 0; i < vecName.size(); i++) {
		std::cout << vecName[i] << " ";
	}
}

void quickSort(std::vector<int>& arr, int left, int right) {
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort(arr, left, j);
	}
	if (i < right) {
		quickSort(arr, i ,right);
	}
}

void saveSort(std::vector<int>& arr, std::string fileName){
	// Open the file that we want to save to
	std::ofstream outFile;
	outFile.open(fileName);

	// Check to see if the file opened successfully
	if (outFile.fail()){
		std::cout << "Could not open file, an error has occurred." << std::endl;
		return;
	}
	// Otherwise, continue with writing the vector contents to a file
	else {
		for (int i = 0; i < arr.size(); i++) {
			outFile << arr.at(i) << " ";
		}
	}
}

bool binarySearch(std::vector<int> arr, int value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (arr[middle] == value) {
			return true;
		}
		else if (arr[middle] > value) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return false;
}