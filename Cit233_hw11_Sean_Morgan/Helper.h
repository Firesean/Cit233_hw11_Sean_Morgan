#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>

/*
Useful functions created seperate from the main project for reuseable code for eventually expansion through other projects later down the road
Functions consisted inside Helper.h

isEmptyString(string str)
boolean is returned whether str is empty

fileExists(string fileName)
boolean is return if file exists

createFile(string fileName)
Creates exact file name, even if no extension to file is included

count(string str, char chr=' ')
returns the count of character passed through within the string, and by default the character counted is a space

split(string str, char chr=' ')
Returns a vector of strings being the string passed and seperating the string by the character provided
*/

using namespace std;

bool isEmptyString(string str) {
	return str == ""; // Returns if str is an empty string
}

bool fileExists(string fileName) {
	ifstream f(fileName); // "if" stream for file stream
	return f.good(); // If the file exists it returns true otherwise false
}

void createFile(string fileName) {
	ofstream f(fileName); // "Open File" stream for creating files or just reads a file 
	f.close(); // Closes file since openning.
}

int count(string str, char chr = ' ') { // Default parameter for chr is a space
	int counted = 0; // initialize to count and return
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == chr) { // Compares character to current place in string
			counted++; // Increments if character matches index of string
		}
	}
	return counted;
}

vector<string> split(string str, char chr = ' ') {
	vector<string> result; // Sets vector of strings
	int counted = count(str, chr); // Function within helper header file returns int based on characters in string
	int curPos = 0; // Place marker for character
	int prePos = 0; // Used to obtain length of substring
	for (int i = 0; i < counted + 1; i++) {
		curPos = str.find(chr, curPos) + 1; // Finds next character position
		result.push_back(str.substr(prePos, curPos - prePos - 1));
		// Next section of the string based on character input is placed in the back of result
		prePos = curPos; // Sets previous position to determine size of substring
	}
	return result;
}

void UPPERCASE(string& str) {
	for (auto& c : str) c = toupper(c);
}

bool isParsableNumber(string input) {
	string nums = "1234567890.";
	string test = input;
	int attempt;
	try {
		if (count(test, '.') > 1) { return false; }
		for (int i = 0; i < test.length(); i++) {
			if (nums.find(test[i]) == string::npos) { return false; }
			attempt = atoi(&test[i]); // String to integer
		}
		return true;
	}
	catch (...) { // Catches any error thrown
		return false;
	}
}


int indexOf(string* list, string value, int length) {
	for (int i = 0; i < length; i++) {
		if (list[i] == value) {
			return i;
		}
	}
	return -1;
}

void swap(int& fValue, int& sValue)
{
	int temp = fValue;
	fValue = sValue;
	sValue = temp;
}

void swap(string& fValue, string& sValue){
	string temp = fValue;
	fValue = sValue;
	sValue = temp;
}

void show(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void show(string* arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void reverse(string& str) {
	std::string s = " ";
	for (int i = 0; i < str.length(); i++) {
		s = str[str.length() - 1];
		// 1, 2 , 3, 4
		// s = 4 as i = 0
		// 4 , 1, 2, 3
		// s = 3 as i = 1
		// 4, 3, 1, 2
		// 4, 3, 2, 1
		str.pop_back();
		str.insert(i, s);
	}
}
