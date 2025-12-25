/*
Course:  CS215-002
Project: Lab5
Purpose: First, it converts a sequence of numbers to its corresponding Roman Numerals
         Second, it repeatedly asks the user to input a triangle size until the user enters "Q" or "q" to quit
         the program then displays a triangles using stars (asterisk symbol) and the total rows of stars is equal
         to the user input size, say n. (The triangle contains one star at the first line, three little stars at
         the second line, and so on till 2*n-1 stars at the nth line, and it is symmetric.) It displays the 
         original triangle then roates the triangle 90-degree clockwise.

Author: Elijah Russell
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

// Function prototypes
string roman_digit(int digit, string one, string five, string ten);
string roman_numeral(int n);
void printTri(int n);
void printTriR90(int n);

int main()
{
    const int START = 0;
    const int END = 12;
    const int BASE = 2;
    const int WIDTH = 10;

    cout << "\tWelcome to CS215 Roman Numeral Converter!" << endl;
    cout << "\tDecimal\t\tRoman Numerals" << endl;

    // Display power sequence and its Roman Numerals
    for (int i = START; i <= END; i++)
    {
        int value = pow(BASE, i);
        cout << setw(WIDTH) << value << "\t\t" << roman_numeral(value) << endl;
    }

    const int MINSIZE = 1;
    const int MAXSIZE = 50;
    int triangle_size = 0;

    cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
    cout << "Type Q (or q) to quit the program: ";
    cin >> triangle_size;

    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            string usrOption;
            cin >> usrOption;

            if (usrOption == "Q" || usrOption == "q")
                break;
            else
                cout << "Invalid size! Expecting an integer in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
        }
        else
        {
            if (triangle_size >= MINSIZE && triangle_size <= MAXSIZE)
            {
                cout << "The triangle with size " << triangle_size << " (ROMAN NUMBER: " << roman_numeral(triangle_size) << " ) is:" << endl;
                printTri(triangle_size);
                cout << "The rotation for 90 degrees clockwise: " << endl;
                printTriR90(triangle_size);
            }
            else
                cout << "The size is not in the correct range! Expecting the size in [" << MINSIZE << ", " << MAXSIZE << "]" << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the size of your triangle (an integer in [" << MINSIZE << ", " << MAXSIZE << "])" << endl;
        cout << "Type Q (or q) to quit the program: ";
        cin >> triangle_size;
    }

    cout << "Thank you, have a great day!" << endl;
    return 0;
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
    if (n < 1 || n > 3999) return "Error: NOT in the correct range!";
    return roman_digit(n / 1000, "M", "", "") +
        roman_digit((n % 1000) / 100, "C", "D", "M") +
        roman_digit((n % 100) / 10, "X", "L", "C") +
        roman_digit(n % 10, "I", "V", "X");
}

// Prints first triangle size n
void printTri(int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < n - i; j++) 
        {
            cout << " ";                                        
            // Spaces for triangle
        }

        for (int k = 0; k < 2 * i - 1; k++) 
        {
            cout << "*";                                        
            // Stars for triangle
        }
        cout << endl;
    }
}

// Rotates triangle for size n
void printTriR90(int n) {
    for (int i = 1; i <= n; i++) 
    {                              
        // Upper half of triangle
        for (int j = 1; j <= i; j++) 
        {
            cout << "*";                                        
            // Stars for triangle
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--) 
    {                          
        // Lower half of triangle
        for (int j = 1; j <= i; j++) 
        {
            cout << "*";                                        
            // Stars for triangle
        }
        cout << endl;
    }
}
