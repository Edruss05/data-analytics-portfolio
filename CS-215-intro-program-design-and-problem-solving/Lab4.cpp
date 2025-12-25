/*
 Course:  CS215-002
 Project: Lab4
 Purpose: this program checks the validity of an 8-digit credit card number
 Author:  Elijah Russell
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main() {

    // Sets up initial prompt and gets the entire line for user input
    cout << "Please enter the 8-digit credit card number (enter -1 to quit): " << endl;
    int input;
    cin >> input;

    // Tests if user input is -1, ending program
    if (input == -1) 
    {
        cout << "Thank you for using Credit Card Number Validation!" << endl;
    }
    else
    {
        // Initializes digits
        int eighth = input % 10;
        int seventh = ((input % 100) - eighth)/10;
        int sixth = ((input % 1000) - seventh - eighth)/100;
        int fifth = ((input % 10000) - sixth - seventh - eighth)/1000;
        int fourth = ((input % 100000) - fifth - sixth - seventh - eighth)/10000;
        int third = ((input % 1000000) - fourth - fifth - sixth - seventh - eighth)/100000;
        int second = ((input % 10000000) - third - fourth - fifth - sixth - seventh - eighth)/1000000;
        int first = ((input % 100000000) - second - third - fourth - fifth - sixth - seventh - eighth)/10000000;
        // cout << first << second << third << fourth << fifth << sixth << seventh << eighth << endl;

        // Sums the first set of numbers
        int firstSum = second + fourth + sixth + eighth;

        // Doubles the unused numbers
        int double1 = first * 2;
        int double3 = third * 2;
        int double5 = fifth * 2;
        int double7 = seventh * 2;

        // Calculates the digits of the doubled numbers
        int firstDigit1 = double1 / 10;
        int lastDigit1 = double1 % 10;
        int firstDigit3 = double3 / 10;
        int lastDigit3 = double3 % 10;
        int firstDigit5 = double5 / 10;
        int lastDigit5 = double5 % 10;
        int firstDigit7 = double7 / 10;
        int lastDigit7 = double7 % 10;

        // Sums the first and last digit of the second set of numbers
        int secondSum = firstDigit1 + lastDigit1 + firstDigit3 + lastDigit3 +
            firstDigit5 + lastDigit5 + firstDigit7 + lastDigit7;

        // Combines the two sums
        int total = firstSum + secondSum;

        // Checks if the number is valid
        if (total % 10 == 0)
        {
            cout << "Number is valid." << endl;
        }

        // Calculates the check digit by evaluating all 9 possibilities
        else {
            cout << "Number is invalid." << endl;
            int off = 10 - (total % 10);
            // cout << eighth << " " << off << endl;
            int check;
            if (eighth + off < 10)
            {
                check = eighth + off;
            }
            else if (eighth + off == 10)
            {
                check = 0;
            }
            else
            {
                check = (eighth + off) % 10;
            }
            cout << "Check digit should have been " << check << endl;
        }
    }

    return 0;
}