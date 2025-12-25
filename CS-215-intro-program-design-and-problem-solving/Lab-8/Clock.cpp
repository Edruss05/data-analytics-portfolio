/* File   : Clock.cpp
*  Course : CS215-002
*  Project: Lab 8
*  Purpose: Provide the implementation of the class named Clock
*		    Note that it represents a 24-hour clock (or you can call it military time)
*  Author : Elijah Russell
*/

#include "Clock.h"
#include <iostream>
#include <iomanip>

using namespace::std;

Clock::Clock()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Clock::Clock(int hh, int mm, int ss)
{
    hours = hh;
    minutes = mm;
    seconds = ss;
    adjustClock();
}

void Clock::setClock(int hh, int mm, int ss)
{
    if (hh < 0 || mm < 0 || ss < 0)
    {
        cout << "Invalid Time!" << endl;
        return;
    }
    hours = hh;
    minutes = mm;
    seconds = ss;
    adjustClock();
}

void Clock::incrementSeconds(int sec)
{
    seconds = seconds + sec;
    adjustClock();
}

void Clock::incrementMinutes(int min)
{
    minutes = minutes + min;
    adjustClock();
}

void Clock::incrementHours(int hh)
{
    hours = hours + hh;
    adjustClock();
}

void Clock::addTime(Clock C)
{
    seconds = seconds + C.seconds;
    minutes = minutes + C.minutes;
    hours = hours + C.hours;
    adjustClock();
}

void Clock::printTime() const
{
    cout.fill('0');
    cout << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
}

int Clock::compareTime(Clock C) const
{
    if (seconds + minutes * 100 + hours * 100 > C.seconds + C.minutes * 100 + C.hours * 100)
    {
        return 1;
    }
    else
        if (seconds + minutes * 100 + hours * 100 < C.seconds + C.minutes * 100 + C.hours * 100)
        {
            return -1;
        }
        else
            return 0;
}

void Clock::adjustClock()
{
    int adjust = 0;
    if (seconds >= 60)
    {
        adjust = seconds / 60;
        seconds = seconds % 60;
        minutes = minutes + adjust;
    }
    if (minutes >= 60)
    {
        adjust = minutes / 60;
        minutes = minutes % 60;
        hours = hours + adjust;
    }
    if (hours >= 24) { hours = hours % 24; }
}