/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.26.2017
 *
 * Description: This is the sorting file for the various features
 * inside of the main function.  In hear we are hosting the ability
 * to perform a linear / quick sort / binary search functionality.
**************************************************************/
#include "sorting.hpp"

/**************************************************************
 *                  linearSearch()
 * Method that allows the user to search a file and see if
 * it conatins the number that you are looking for.
**************************************************************/
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

/**************************************************************
 *                  fileToVect()
 *  This method allows us to easily transform a file to a
 *  reference to a vector elsewhere.
**************************************************************/
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

/**************************************************************
 *                  displayResults()
 *  This method allows us to easily display the items that
 *  are currently stored within a specific vector
**************************************************************/
void displayresults(std::vector<int> vecName) {
	for(int i = 0; i < vecName.size(); i++) {
		std::cout << vecName[i] << " ";
	}
}

/**************************************************************
 *                  quickSort()
 * Metod that allows the user to organize an array using the
 * quickSort sorting method, much more efficient than bubble sort
 *
 * Referenced website below for building of the algorithm:
 * http://www.algolist.net/Algorithms/Sorting/Quicksort
**************************************************************/
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

/**************************************************************
 *                  saveSort()
 * This method allows us to save that items inside of a specific
 * vector and trsnfer those to a specific file that the user
 * specifies.
**************************************************************/
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

/**************************************************************
 *                  binarySearch()
 *  This search allows us to quickly search by splitting an already
 *  sorted menu in half and only searching half at a time, making
 *  the overall runtime significantly shorter.
 *
 * Referenced website below for building of the algorithm:
 * http://www.algolist.net/Algorithms/Binary_search
**************************************************************/
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