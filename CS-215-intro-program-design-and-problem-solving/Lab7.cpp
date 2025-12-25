/*
Course:  CS215-002
Project: Lab7
Purpose: Calculates the execution score for the artistic gymnastics. The execution score, determined by a six-judge Panel, 
         begins at 10 and deductions are made for errors and faults in technique, execution and artistry/composition. 
         Each judge independently determines his/her score. The highest and lowest scores are dropped, 
         and the gymnast’s Execution Score is the average of the remaining four judges’ scores.
Author:  Elijah Russell
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function prototypes
void dropTWO(double& first_num, double& second_num, double& third_num, double& fourth_num, double& fifth_num, double& sixth_num);
double final_score(double final1, double final2, double final3, double final4);

int main()
{
    //intialize/declare variables and constants
    double first; //first score
    double second; //second score
    double third; //third score
    double fourth; //fourth score
    double fifth; // fifth score
    double sixth; //sixth score
    string placeholder; //empty used to test for invalid inputs
    const double min = 0.00; //minimum score
    const double max = 10.00; //maximum score

    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> first))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (first < min || first > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }
    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> second))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (second < min || second > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }
    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> third))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (third < min || third > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }
    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> fourth))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (fourth < min || fourth > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }
    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> fifth))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (fifth < min || fifth > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }
    while (true)
    {
        cout << "Please enter your score for the gymnast: " << endl;
        //collect input
        string input;
        getline(cin, input);
        stringstream ss(input);

        //check if input is of type int
        if (!(ss >> sixth))
        {
            //if input is not of type int then display invalid and display input requirements
            cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
        }

        //if input is of type int then run program
        else
        {
            //if input is not in correct year range then display invalid and display input requirements
            if (sixth < min || sixth > max)
            {
                cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
            }
            //otherwise run program
            else
            {
                //check for a second input
                if (ss >> placeholder)
                {
                    //if second input is present then display invalid and display input requirements
                    cout << "Invalid score! Expecting a score in the range [0.00, 10.00]" << endl;
                }
                //otherwise exit loop
                else
                {
                    break;
                }
            }
        }
    }

    //output judges scores in order
    {
        cout << "The scores from the judges are:" << endl;
        cout << fixed << setprecision(2) << first << "  " << second << "  " << third << "  " << fourth << "  " << fifth << "  " << sixth << endl;
    }
   
    //output judges scores after dropping two
    dropTWO(first, second, third, fourth, fifth, sixth); //call dropTWO function
    {
        cout << "The scores after dropping the highest and lowest scores:" << endl;
        cout << fixed << setprecision(2) << second << "  " << third << "  " << fourth << "  " << fifth << "  " << endl;
    }

    //output final judge score
    {
        cout << "Final Execution Score is: " << fixed << setprecision(2) << final_score(second, third, fourth, fifth); //call final_score function
    }
}

void dropTWO(double &first_num, double &second_num, double &third_num, double &fourth_num, double &fifth_num, double &sixth_num)
{
    //intialize/declare variables and constants
    double original[] = {first_num, second_num, third_num, fourth_num, fifth_num, sixth_num}; //array of judges scores
    double duplicate[] = {first_num, second_num, third_num, fourth_num, fifth_num, sixth_num}; //copy of array of judges scores to manipulate
    const int total_nums = 6; //total number of scores
    const int remaining = total_nums - 2; //number of scores after dropping two
    double dropped[remaining] = {0,0,0,0}; //array of dropped scores
    int n = 0; //variable to be used as counter in for/if loops
    bool lowest_dropped = false; //marks if lowest has already been dropped to account for if the lowest number occurs than once
    bool highest_dropped = false; //marks if highest has already been dropped to account for if the highest number occurs than once

    //sort the array in ascending order
    sort(duplicate, duplicate + total_nums);

    //drop highest and lowest scores and assign remianing scores to dropped scores array
    for (int i = 0; i < total_nums; i++)
    {
        //drop lowest score
        if (original[i] == duplicate[0] && !lowest_dropped)
        {
            lowest_dropped = true; //mark lowest as dropped
        } 

        //drop highest score
        else if (original[i] == duplicate[5] && !highest_dropped) 
        {
            highest_dropped = true; //mark highest as dropped
        }

        //assign scores not dropped to the dropped array in the order of the original array
        else
        {
            if (n < remaining) //ensures n doesnt exceed the possible indices for the dropped matrix
            {
                dropped[n] = original[i]; //assign score to the dropped matrix
                n++;
            }
        }
    }

    first_num  = 0; //lowest score
    second_num = dropped[0]; //first remaining score
    third_num  = dropped[1]; //second remaining score
    fourth_num = dropped[2]; //third remianing score
    fifth_num  = dropped[3]; //fourth remianing score
    sixth_num  = 0; //highest score
}

double final_score (double final1, double final2, double final3, double final4)
{
    //calculates the average of the 4 inputs
    double sum = final1 + final2 + final3 + final4;
    double num = 4;
    return sum / num;
}