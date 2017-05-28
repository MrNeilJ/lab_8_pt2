/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.26.2017
 *
 * Description: This is the main function for the application
 * where we are able to search / sort through a set of numbers
 * that come from an external file(s).
**************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include "inputCheck.hpp"
#include "menuMaker.hpp"
#include "sorting.hpp"

int main() {
	// Create a welcome screen for the user to see
	std::cout << "****************************************" << std::endl;
	std::cout << "*        SEARCH / SORT PROGRAM         *" << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "Welcome to the Search / Sort Program! In here" << std::endl;
	std::cout << "you can search through multiple lists and see" << std::endl;
	std::cout << "if the number you are looking for exists. In" << std::endl;
	std::cout << "addition you can sort the list using the bubble" << std::endl;
	std::cout << "method and then search the list once more." << std::endl;


	//Create an array of all files that will be read
	std::string fileSets[4] = {"controlSet.txt", "set1.txt", "set2.txt", "set3.txt"};
	std::string updatedFileSets[4];

	/*********************************************
	 * SEARCH MENU
	 *********************************************/
	menuMaker searchMenu("What kind of search would you like to use?",
						 "Linear Search",
						 "Sort the files using Quick Sort",
						 "Binary Search (utilizing Quick Sort method)",
						 "Quit");

	int searchResponse;
	bool found;
	int numSearch;

	do {
		searchMenu.prompt();
		searchResponse = searchMenu.getResponse();

		// If the user selected to utilize Linear Search....
		if (searchResponse == 1) {
			// Ask the user for input on what value they want to look for
			std::cout << "\nWhat number would you like to search for?: ";
			// Save that value in a int variable
			numSearch = getInt();

			for (int i = 0; i < 4; i++){
				found = linearSearch(fileSets[i], numSearch);

				// Print out the results to the console
				std::cout << fileSets[i] << ": target value " << "\"" << numSearch << "\"";
				if (found) {
					std::cout << " found." << std::endl;
				}
				else {
					std::cout << " not found." << std::endl;
				}
			}
			std::cout << std::endl;
		}

		// If the user selected to just do the Sort function
		else if (searchResponse == 2 || searchResponse == 3) {
			char saveChoice;
			if (searchResponse == 2) {
				saveChoice = 'N';
			}
			else {
				saveChoice = 'Y';
			}

			std::vector<int> currVec;
			for (int i = 0; i < 4; i++) {
				// Move the current file information into a vector to sort in a moment
				fileToVect(fileSets[i], currVec);

				// Sort the information within the vector.
				quickSort(currVec, 0, (currVec.size()-1));

				if (toupper(saveChoice) == 'Y') {
					std::cout << "What would you like the saved file name to be?: " << std::endl;
					std::string saveName = getString();
					saveSort(currVec, saveName);
					updatedFileSets[i] = saveName;
					std::cout << "Successfully saved to " << updatedFileSets[i] << "." << std::endl;
				}
				else {
					// Print the results so the user can see
					std::cout << fileSets[i] << " list:" << std::endl;
					displayresults(currVec);

					std::cout << std::endl;
				}

				std::cout << std::endl;

				// Empty the vector so it can be used again
				currVec.clear();

			}
			if (searchResponse == 3) {
				// Ask the user for input on what value they want to look for
				std::cout << "\nWhat number would you like to search for?: ";
				// Save that value in a int variable
				numSearch = getInt();
				for (int i = 0; i < 4; i ++) {
					fileToVect(updatedFileSets[i], currVec);

					found = binarySearch(currVec, numSearch, 0, (currVec.size()-1));

					// Print out the results to the console
					std::cout << updatedFileSets[i] << ": target value " << "\"" << numSearch << "\"";
					if (found) {
						std::cout << " found." << std::endl;
					}
					else {
						std::cout << " not found." << std::endl;
					}

					currVec.clear();
				}
				std::cout << std::endl;
			}
		}

	} while (searchResponse != 4);

	return 0;
}