/*
Course:  CS215-002
Project: Lab2
Purpose: this program converts CAD to USD and prints in standard american coin units
Author:  Elijah Russell
*/

#include <iomanip>
#include <iostream>

using namespace std;
int main()
{
    // Collect amounts due and received
    double cad = 0.00;
    double usd = 0.00;
    cout << "Convert CAD to USD service." << endl;
    cout << "Please enter the amount of Canadian Dollars you want to exchange: C$ ";
    cin >> cad;
    cout << endl;
    // Set up exchange rate for math
    const double EXCHANGE_RATE = 0.69;
    usd = cad * EXCHANGE_RATE;
    // Set up rounding error constant for math
    const double ROUNDING_ERROR = 0.05;
    cout << "The exchange for C$ " << fixed << setprecision(2) << cad << " --> $ " << fixed << setprecision(2) << usd << " :" << endl;
    // do math to find quarters
    int dollar_value = 1;
    int dollars = usd / dollar_value + ROUNDING_ERROR;
    usd = usd - dollars * dollar_value;
    if (dollars < 10) {
        cout << "Dollars:            " << dollars << endl;
    }
    if (dollars > 9 && dollars < 1000) {
        cout << "Dollars:           " << dollars << endl;
    }
    if (dollars > 999) {
        cout << "Dollars:          " << dollars << endl;
    }
    else {
        cout << "";
    }
    // do math to find quarters
    const double quarter_value = .25;
    int quarters = usd / quarter_value + ROUNDING_ERROR;
    // cout << usd << endl;
    usd = usd - quarters * quarter_value;
    // cout << usd << endl;
        cout << "Quarters:           " << quarters << endl;
    // Do math to find dimes
    const double dime_value = .10;
    int dimes = usd / dime_value + ROUNDING_ERROR;
    usd = usd - dimes * dime_value;
    // cout << usd << endl;
        cout << "Dimes:              " << dimes << endl;
    // Do math to find nickels
    const double nickel = .05;
    int nickels = usd / nickel + ROUNDING_ERROR;
    usd = usd - nickels * nickel;
    // cout << usd << endl;
        cout << "Nickels:            " << nickels << endl;
    // Do math to find pennies
    const double penny = .01;
    int pennies = usd / penny + ROUNDING_ERROR;
        cout << "Pennies:            " << pennies << endl;
        // cout << usd;
   
}