/* File:    SuperString.cpp
* Course:   CS215 - 002
* Project:  Project 2
* Purpose:  the implementation of member functions for the SuperString class.
* Author:   Elijah Russell
*/
#include <iostream>
#include <string>
#include <stack>
#include "SuperString.h"

// constructor: initialize str with ini_str passing as a parameter
SuperString::SuperString(std::string ini_str) {
    str = ini_str;  // Initialize the private data member 'str' with the given string
}

// return the current value of the private data member: str
std::string SuperString::getString() const {
    return str;  // Return the current value of 'str'
}

// set the value of str to be the passed in parameter input_str
void SuperString::setString(std::string input_str) {
    str = input_str;  // Set the value of 'str' to the new string
}

// return a reverse string using a loop
// Note that the private data member named str has not been changed
std::string SuperString::rev_loop() const {
    std::string reversed = "";
    // Traverse the string in reverse and append each character to 'reversed'
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;  // Return the reversed string
}

// return a reverse string using recursion
// Note that the private data member named str has not been changed
std::string SuperString::rev_recursion() const {
    if (str.length() <= 1) {
        return str;  // Base case: single character or empty string is already reversed
    }
    else {
        // Recursively reverse the substring, then append the first character to the end
        return str[str.length() - 1] + SuperString(str.substr(0, str.length() - 1)).rev_recursion();
    }
}

// return a reverse string using a stack
// Note that the private data member named str has not been changed
std::string SuperString::rev_stack() const {
    std::stack<char> charStack;
    // Push each character of 'str' onto the stack
    for (char c : str) {
        charStack.push(c);
    }

    std::string reversed = "";
    // Pop characters off the stack to form the reversed string
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }
    return reversed;  // Return the reversed string
}

// return true if str is a palindrome, otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// Calling member function to implement
// Note that the private data member named str has not been changed
bool SuperString::isPalindrome() const {
    if (str.length() <= 1) {
        return true;  // A single character or empty string is a palindrome
    }
    else {
        // Check if first and last characters are the same, and check if the middle is also a palindrome
        bool firstPair = (str[0] == str[str.length() - 1]);
        SuperString shorter(str.substr(1, str.length() - 2));
        return firstPair && shorter.isPalindrome_recursion();  // Recursive check for palindrome
    }
}

// return true if str is a palindrome using recursion, otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// Using recursion to implement
// Note that the private data member named str has not been changed
bool SuperString::isPalindrome_recursion() const {
    if (str.length() <= 1) {
        return true;  // Base case: single character or empty string is a palindrome
    }
    else {
        bool firstPair = (str[0] == str[str.length() - 1]);
        SuperString shorter(str.substr(1, str.length() - 2));
        return firstPair && shorter.isPalindrome_recursion();  // Recursive check
    }
}

// displays str, followed by a new line marker, to the standard output
void SuperString::print() const {
    std::cout << str << std::endl;  // Print the string followed by a newline
}
