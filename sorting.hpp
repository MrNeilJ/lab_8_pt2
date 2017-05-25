//
// Created by Neil on 5/23/2017.
//

#ifndef LAB_8_SORTING_HPP
#define LAB_8_SORTING_HPP

#include <iostream>
#include <fstream>
#include <vector>


bool linearSearch(std::string,int);
void fileToVect(std::string, std::vector<int>&);
void displayresults(std::vector<int>);
void quickSort(std::vector<int>&, int, int);
void saveSort(std::vector<int>&, std::string);

bool binarySearch(std::vector<int>, int, int, int);






#endif //LAB_8_SORTING_HPP