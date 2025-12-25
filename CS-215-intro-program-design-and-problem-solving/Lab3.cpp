/*
Course:  CS215-002
Project: Lab3
Purpose: this program sorts numbers into ascending or descending order
Author:  Elijah Russell
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	cout << "Your wish is my command!\nI will sort three numbers under your wish : " << endl;
	string order;
	cout << "Enter A for ascending order, D for descending order (A or D): ";
	cin >> order;
	int firstnum;
	int secondnum;
	int thirdnum;
	
	if (order != "A" && order != "a" && order != "D" && order != "d")
		cout << "Invalid choice, quitting the program...";
	if (order == "A" || order == "a")
	{
		cout << "Please enter three integer numbers: ";
		cin >> firstnum >> secondnum >> thirdnum;
		cout << "Numbers are sorted in ascending order:" << endl;
		if (firstnum != secondnum && firstnum != thirdnum)
		{
			if (firstnum < secondnum && secondnum < thirdnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << secondnum;
				cout << " <= ";
				cout << thirdnum;
			}
				
			if (firstnum < thirdnum && thirdnum < secondnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << thirdnum;
				cout << " <= ";
				cout << secondnum;
			}
				
			if (secondnum < firstnum && firstnum < thirdnum)
			{
				cout << secondnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << thirdnum;
			}
				
			if (secondnum < thirdnum && thirdnum < firstnum)
			{
				cout << secondnum;
				cout << " <= ";
				cout << thirdnum;
				cout << " <= ";
				cout << firstnum;
			}
				
			if (thirdnum < firstnum && firstnum < secondnum)
			{
				cout << thirdnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << secondnum;
			}
				
			if (thirdnum < secondnum && secondnum < firstnum)
			{
				cout << thirdnum;
				cout << " <= ";
				cout << secondnum;
				cout << " <= ";
				cout << firstnum;
			}
				
				cout << "\nNumbers are in strictly ascending order!";
		}
		if (firstnum == secondnum)
		{
			if (firstnum < thirdnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << thirdnum;
			}
				
			if (firstnum > thirdnum)
			{
				cout << thirdnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << firstnum;
			}
				
			if (firstnum == thirdnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << firstnum;
			}
			cout << "\nNumbers are in leniently ascending order!";
		}
		if (firstnum == thirdnum)
		{
			if (firstnum < secondnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << secondnum;
			}				
			if (firstnum > secondnum)
			{
				cout << secondnum;
				cout << " <= ";
				cout << firstnum;
				cout << " <= ";
				cout << firstnum; 
			}
			cout << "\nNumbers are in leniently ascending order!";
		}
		if (secondnum == thirdnum)
		{
			if (firstnum < secondnum)
			{
				cout << firstnum;
				cout << " <= ";
				cout << secondnum;
				cout << " <= ";
				cout << secondnum;
			}
			if (firstnum > secondnum)
			{
				cout << secondnum;
				cout << " <= ";
				cout << secondnum;
				cout << " <= ";
				cout << firstnum;
			}	
			cout << "\nNumbers are in leniently ascending order!";
		}
	}
	if (order == "D" || order == "d")
	{
		cout << "Please enter three integer numbers: ";
		cin >> firstnum >> secondnum >> thirdnum;
		cout << "Numbers are sorted in descending order:" << endl;
		if (firstnum != secondnum && firstnum != thirdnum)
		{
			if (firstnum > secondnum && secondnum > thirdnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << secondnum;
				cout << " >= ";
				cout << thirdnum;
			}
				
			if (firstnum > thirdnum && thirdnum > secondnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << thirdnum;
				cout << " >= ";
				cout << secondnum;
			}
				
			if (secondnum > firstnum && firstnum > thirdnum)
			{
				cout << secondnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << thirdnum;
			}
				
			if (secondnum > thirdnum && thirdnum > firstnum)
			{
				cout << secondnum;
				cout << " >= ";
				cout << thirdnum;
				cout << " >= ";
				cout << firstnum;
			}
				
			if (thirdnum > firstnum && firstnum > secondnum)
			{
				cout << thirdnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << secondnum;
			}
				
			if (thirdnum > secondnum && secondnum > firstnum)
			{
				cout << thirdnum;
				cout << " >= ";
				cout << secondnum;
				cout << " >= ";
				cout << firstnum;
			}
				
			cout << "\nNumbers are in strictly descending order!";
		}
		if (firstnum == secondnum)
		{
			if (firstnum > thirdnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << thirdnum;
			}
				
			if (firstnum < thirdnum)
			{
				cout << thirdnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
			}
				
			if (firstnum == thirdnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
			}
			cout << "\nNumbers are in leniently descending order!";
		}
		if (firstnum == thirdnum)
		{
			if (firstnum > secondnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << secondnum;
			}
				
			if (firstnum < secondnum)
			{
				cout << secondnum;
				cout << " >= ";
				cout << firstnum;
				cout << " >= ";
				cout << firstnum;
			}
			cout << "\nNumbers are in leniently descending order!";
		}
		if (secondnum == thirdnum)
		{
			if (firstnum > secondnum)
			{
				cout << firstnum;
				cout << " >= ";
				cout << secondnum;
				cout << " >= ";
				cout << secondnum;
			}
				
			if (firstnum < secondnum)
			{
				cout << secondnum;
				cout << " >= ";
				cout << secondnum;
				cout << " >= ";
				cout << firstnum;
			}
			cout << "\nNumbers are in leniently descending order!";
		}
	}
	
}