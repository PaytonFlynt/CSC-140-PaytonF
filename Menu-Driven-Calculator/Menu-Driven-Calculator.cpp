// Menu-Driven-Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//function definitions - accepting 2 numbers and returning results
//addition function
double add(double a, double b) { return a + b; }

//subtraction function
double subtract(double a, double b) { return a - b; }

//multiplication function
double multiply(double a, double b) { return a * b; }

//division function
double divide(double a, double b) {
	if (b == 0) {
		cout << "Error: Cannot divide by 0!\n";
		return 0;
		//no zero in denominator

	}
	return 0;
}

//modulo function
int modulo(int a, int b) {
	if (b == 0) {
		cout << "Error: Cannot complete modulo with 0!\n";
		return 0;
		//zero for modulo
	}
	return 0;
}

int main() {
	int choice; //store users menu choice
	double num1, num2; // user input numbers

	do {
		//Displaying the menu options
		cout << "\n===== Calculator Menu =====\n";
		cout << "1. Addition(+)\n";
		cout << "2. Subtraction(-)\n";
		cout << "3. Multiplication(*)\n";
		cout << "4. Division(/)\n";
		cout << "5. Modulo(%)\n";
		cout << "6. Exit Menu\n";
		cout << "Choose an option: ";
		cin >> choice;//read the users choice

		//operation selected 1-5 - ask user for 2 numbers to perform
		if (choice >= 1 && choice <= 5) {
			cout << "Enter first number: ";
			cin >> num1;
			cout << "Enter second number: ";
			cin >> num2;
		}
		//performing the chosen operation using a switch statement
		switch (choice) {
		case 1: //addition
			cout << "Results: " << add(num1, num2) << "\n";
			break;
		case 2: //subtraction
			cout << "Results: " << subtract(num1, num2) << "\n";
			break;
		case 3: //multiply
			cout << "Results: " << multiply(num1, num2) << "\n";
			break;
		case 4: //divide
			cout << "Results: " << divide(num1, num2) << "\n";
			break;
		case 5: //modulo
			cout << "Results: " << modulo(static_cast<int>(num1), static_cast<int>(num2)) << "\n";
			break;
		case 6:
			cout << "Exiting Program..........\n";
			break;
		default:
			cout << "Invalid option - please choose 1-6.";

		}
	} while (choice != 6); //repeat until exit is chosen and don't allow other number options
	return 0; //end the program
}