/* File:    SuperString.h
 * Course:  CS215-002
 * Project: Lab 12
 * Purpose: the declaration for the SuperString class.
 *
 */

#ifndef SUPERSTRING_H
#define SUPERSTRING_H

#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>

class SuperString
{
public:
	// constructor: initialize str with ini_str passing as a parameter
	SuperString(std::string ini_str);

	// return the current value of the private data member: str
	std::string getString() const;

	// set the value of str to be the passed in parameter input_str
	void setString(std::string input_str);

	// return a reverse string
	// using a loop to implement
	// Note that the private data member named str, has not been changed
	std::string rev_loop() const;

	// return a reverse string
	// using recursion to implement
	// Note that the private data member named str, has not been changed
	std::string rev_recursion() const;

	// return a reverse string
	// using a stack to implement
	// Note that the private data member named str, has not been changed
	std::string rev_stack() const;

	// return true if str is a palindrome
	// otherwise return false
	// A palindrome is defined as a sequence of characters which
	// reads the same backward as forward
	// Calling member function to implement
	// Note that the private data member named str, has not been changed
	bool isPalindrome() const;

	// return true if str is a palindrome
	// otherwise return false
	// A palindrome is defined as a sequence of characters which
	// reads the same backward as forward
	// Using recursion to implement
	// Note that the private data member named str, has not been changed
	bool isPalindrome_recursion() const;

	// displays str, followed by a new line marker,
	// to the standard output
	void print() const;
private:
	std::string str;
};
#endif  /* SUPERSTRING_H */