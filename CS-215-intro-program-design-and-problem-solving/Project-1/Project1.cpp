/*
Course:  CS215-002
Project: Lab5
Purpose: Repeatedly asks the user to input a year for the Super Bowl,
         and displays the corresponding Super Bowl with Roman Numeral, 
         until the user enters either “Q” or “q” to quit your program.
Author:  Elijah Russell
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Function prototypes
string roman_digit(int digit, string one, string five, string ten);
string roman_numeral(int n);

//main code
int main()
{
    //declare constants
    const int START_SUPERBOWL = 1967;
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    const int END_SUPERBOWL = MAX_ROMAN + START_SUPERBOWL - MIN_ROMAN;
    int year;
    string test;
    string quit;

    //print starting information
    {
        cout << "***************************************************************" << endl; 
        cout << "*       The Super Bowl is the annual final playoff game       *" << endl; 
        cout << "*         of the NFL to determine the league champion.        *" << endl; 
        cout << "*     The first Super Bowl took place on January 15, 1967.    *" << endl; 
        cout << "*    Super Bowl I (Los Angeles Memorial Coliseum) --> 1967    *" << endl; 
        cout << "*                                                             *" << endl; 
        cout << "*        Super Bowl LIX was played on February 9, 2025        *" << endl; 
        cout << "*             at Caesars Superdome in New Orleans.            *" << endl; 
        cout << "*       Philadelphia Eagles 40 -- Kansas City Chiefs 22       *" << endl; 
        cout << "*                                                             *" << endl;
        cout << "* This Roman Numerals Convertor is written by Elijah Russell. *" << endl; 
        cout << "*     If you had a time machine, which year of Super Bowl     *" << endl; 
        cout << "*           would you want to attend (1967 - 5965)?           *" << endl; 
        cout << "***************************************************************" << endl;
    }
    
    //prompt for input
    {
        cout << "Please enter the year you want to attend (click Q or q to quit):  ";
    }
   
    while (true)
    {
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> year))
        {
            //if input is not of type int then check for quit or invalid input
           
                //if quit input detected then exit the loop and end program
                if (input == "Q" || input == "q")
                {
                    break;
                }

                //if invalid input decteced then display invalid and display input requirements
                else
                {
                    cout << "Invalid year! Expecting an integer in [" << START_SUPERBOWL << ", " << END_SUPERBOWL << "]" << endl << endl;
                }

            //prompt for input
            {
                cout << "Please enter the year you want to attend (click Q or q to quit):  ";
            }
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (year < (START_SUPERBOWL) || year >(MAX_ROMAN + START_SUPERBOWL - MIN_ROMAN))
            {
                cout << "Invalid year! Expecting an integer in [" << START_SUPERBOWL << ", " << END_SUPERBOWL << "]" << endl << endl;
            }

            //if input is in correct year range then run program
            else
            {
                //double check for a second input
                if (ss >> test)
                {
                    cout << "Invalid year! Expecting an integer in [" << START_SUPERBOWL << ", " << END_SUPERBOWL << "]" << endl << endl;
                }
                    
                else
                {
                    cout << year << " is Super Bowl " << roman_numeral(year) << endl << endl; //use roman_numeral function to display associated roman numeral
                }
                
            }

            //prompt for input
            {
                cout << "Please enter the year you want to attend (click Q or q to quit):  ";
            }
        }
    }

    /*print quit message*/ 
    {
        cout << endl << "Thank you, have a great day!" << endl;
        return 0;
    }
}

// Converts a single digit to a Roman numeral
string roman_digit(int digit, string one, string five, string ten)
{
    string roman;
    switch (digit)
    {
    case 1: roman = one; break;
    case 2: roman = one + one; break;
    case 3: roman = one + one + one; break;
    case 4: roman = one + five; break;
    case 5: roman = five; break;
    case 6: roman = five + one; break;
    case 7: roman = five + one + one; break;
    case 8: roman = five + one + one + one; break;
    case 9: roman = one + ten; break;
    default: break;
    }
    return roman;
}

// Converts an integer to a Roman numeral
string roman_numeral(int n)
{
    //declare constants
    const int START_SUPERBOWL = 1967;
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    const int END_SUPERBOWL = MAX_ROMAN + START_SUPERBOWL - MIN_ROMAN;

    //convert integer
    /*
    Purpose: convert the integer n to its corresponding Roman Numeral n
    must be between 1 and 3999 it returns string form of the Roman Numeral
    @param n int: representing the number to convert into Roman Numeral
    @return string: representing the corresponding Roman Numeral for n
    */
    return roman_digit((n - START_SUPERBOWL + MIN_ROMAN) / 1000, "M", "", "") + //first digit
        roman_digit(((n - START_SUPERBOWL + MIN_ROMAN) % 1000) / 100, "C", "D", "M") + //second digit
        roman_digit(((n - START_SUPERBOWL + MIN_ROMAN) % 100) / 10, "X", "L", "C") + //third digit
        roman_digit((n - START_SUPERBOWL + MIN_ROMAN) % 10, "I", "V", "X"); //last digit
}
