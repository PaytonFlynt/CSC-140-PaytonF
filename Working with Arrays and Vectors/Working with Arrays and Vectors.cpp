// Working with Arrays and Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
  //starting with arrays
	int arr[5] = { 10, 20, 30, 40, 50 }; //declare

	//print
	cout << "Original array: ";
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	//vectors
	vector<int> vec = { 100, 200, 300 }; //declare

	//print
	cout << "Original Vector: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
		cout << endl;
	}
	vec.pop_back(); //remove last element
	cout << "After pop_back: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "Vector size: " << vec.size() << endl;
	vec.insert(vec.begin() + 1, 250);  // Insert 250 at the second position
	cout << "After insert(250) at position 1: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	vec.erase(vec.begin() + 2); //remove last element at its position
		cout << "After erase at position 2: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	//final
	cout << "Final Vector: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";

	}
	cout << endl;
	return 0;
}
