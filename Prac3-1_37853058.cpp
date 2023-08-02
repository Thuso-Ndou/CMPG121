/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that calculates the average number of days a company’s
employees are absent. The program will have multiple functions,
each with a specific role in achieving the program’s objective.
*/
#include <iostream>
#include <iomanip>

using namespace std;

// function prototype
int numberOfEmployees();
int numberOfEmployees(int numberOfEmployees);
double averageDays(int employees, int days);

int main()
{
    // declaration of variables
    int numOfEmployees;
    int numOfDaysAbsent;
    double average; // convert to a double

    // ask for number of employees
    numOfEmployees = numberOfEmployees();

    cout << "\n";

    // ask for number of days absent
    numOfDaysAbsent = numberOfEmployees(numOfEmployees);

    // average with located two arguments
    average = averageDays(numOfEmployees, numOfDaysAbsent);

    // display
    cout << "\nThe number of employees is " << numOfEmployees;
    cout << "\nThe total number of days is " << numOfDaysAbsent;
    cout << "\nThe average number of days absent is " << fixed  << setprecision(2) << average <<endl;

    return 0;
}

// A function for user input for number of employees
int numberOfEmployees()
{
    int numberOfEmployees;

    cout << "Enter number of employees: ";
    cin >> numberOfEmployees;

    // input validation for number of employees
    while(numberOfEmployees < 1)
    {
        cout << "Error: Enter positive number of employees: ";
        cin >> numberOfEmployees;
    }

    return numberOfEmployees;
}

// A function for user input for number of days absent
// and this function takes in number of employees as an arguments
int numberOfEmployees(int numberOfEmployees)
{
    int totalDays= 0;
    int daysAbsent;

    // A loop for days absent for each user
    for(int i = 1; i <= numberOfEmployees; i++)
    {
        cout << "Enter number of days absent for employee " << i <<" : ";
        cin >> daysAbsent;

        // loop for negative number of days
        while(daysAbsent < 0)
        {
            cout << "Error: Enter postive number of days absent for employee " << i <<" : ";
            cin >> daysAbsent;
        }

        // increment by days absent for each user
        totalDays += daysAbsent;
    }

    return totalDays;
}

// A function to average number of days absent
double averageDays(int employees, int days)
{
    double average;

    // calculations for average
    average = static_cast<double>(days) / employees;

    return average;
}
