/* File:    Lab8.cpp
 * Course:  CS215-002
 * Project: Lab 8
 * Purpose: Creates and manipulates two "Clock" objects.
 * Author:  Elijah Russell
 * Note: This program uses code written by the instructor, Jeremiah Davis.
 */

#include <iostream>
#include "Clock.h"

using namespace::std;

int main()
{
	//create Clock object C1
	Clock C1;
	//set C1 with h:m:s = 3:-5:16
	C1.setClock(3, -5, 16);
	//set C1 with h:m:s = 0:0:5
	C1.setClock(0, 0, 5);
	//create second Clock object C2 with h:m:s = 12:35:59
	Clock C2(12, 35, 59);

	//print C1
	cout << "Clock C1 -- ";
	C1.printTime();
	cout << endl;

	//print C2
	cout << "Clock C2 -- ";
	C2.printTime();
	cout << endl;

	//compare C1 with C2.
	if (C1.compareTime(C2) < 0)
	{
		cout << "C1 is earlier than C2" << endl;
	}
	else if (C1.compareTime(C2) > 0)
	{
		cout << "C1 is later than C2" << endl;
	}
	else
	{
		cout << "C1 is the same as C2" << endl;
	}

	//add C2 into C1
	C1.addTime(C2);

	//print C1
	cout << "Clock C1 -- ";
	C1.printTime();
	cout << endl;

	//print C2
	cout << "Clock C2 -- ";
	C2.printTime();
	cout << endl;

	//compare C1 with C2
	if (C1.compareTime(C2) < 0)
	{
		cout << "C1 is earlier than C2" << endl;
	}
	else if (C1.compareTime(C2) > 0)
	{
		cout << "C1 is later than C2" << endl;
	}
	else
	{
		cout << "C1 is the same as C2" << endl;
	}

	//increase clock C1 by 55 seconds
	C1.incrementSeconds(55);

	//print C1
	cout << "Clock C1 -- ";
	C1.printTime();
	cout << endl;

	//increase clock C1 by 119 minutes
	C1.incrementMinutes(119);

	//print C1
	cout << "Clock C1 -- ";
	C1.printTime();
	cout << endl;

	//increase clock C1 by 22 hours
	C1.incrementHours(22);

	//print C1
	cout << "Clock C1 -- ";
	C1.printTime();
	cout << endl;

	//print C2
	cout << "Clock C2 -- ";
	C2.printTime();
	cout << endl;

	//compare C2 with C1
	if (C1.compareTime(C2) < 0)
	{
		cout << "C1 is earlier than C2" << endl;
	}
	else if (C1.compareTime(C2) > 0)
	{
		cout << "C1 is later than C2" << endl;
	}
	else
	{
		cout << "C1 is the same as C2" << endl;
	}

	return 0;
}