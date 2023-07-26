/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that calculates the accumulated amount given a 5% interest
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    //heading
    cout << "Savings Account" << endl;

    //declaring variables
    const double rate {0.05};
    double principle_amount{};
    int years{};
    double accumulated_amount{};

    // user input for principle amount
    cout << "Enter principle amount: ";
    cin >> principle_amount;

    // user input for years
    cout << "Enter number of years: ";
    cin >> years;

    //heading
    cout << "\nAccount Balance: \n";

    for (int i = 1; i <= years; i++)
    {
        // calculations
        accumulated_amount = principle_amount * pow((1 + rate),i);
        cout << "Year " << i << "- R " << fixed << setprecision(2) << accumulated_amount << endl;
    }

    return 0;
}
