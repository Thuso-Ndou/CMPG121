/*
Name: Thuso
Surname: Ndou
Student Number: 37853058
A C++ program that processes and displays
this cartoon viewership data
*/

#include <iostream>
#include <cstdlib>  // Required for random number generation
#include <iomanip>  // Required for output formatting

using namespace std;

const int MONTHS = 3;
const int WEEKS = 4;

// This function displays the cartoon viewership stats in a column format
void displayCartoonStats(int arrToonViewers[MONTHS][WEEKS])
{
    cout << "\nCartoon Viewership Stats\n";
    cout << setw(10) << " " << "Week 1" << setw(10) << "Week 2" << setw(10) << "Week 3" << setw(10) << "Week 4" << endl;

    for(int i = 0; i < MONTHS; i++)
    {
        cout << "Month " << i+1 << ":";
        for(int j = 0; j < WEEKS; j++)
        {
            // Display each entry in the array with proper spacing
            cout << setw(10) << arrToonViewers[i][j];
        }
        cout << endl;
    }
}

// This function calculates and displays the number of viewers for a specific month
int calcToonFansOfMonth(int arrToonViewers[MONTHS][WEEKS], int month)
{
    int totalViews = 0;
    if (month >= 1 && month <= MONTHS)
    {
        cout << "\nViewership Stats for Month " << month << ":\n";
        for (int j = 0; j < WEEKS; j++)
        {
            cout << "Week " << j + 1 << ": " << arrToonViewers[month - 1][j] << endl;
            totalViews += arrToonViewers[month - 1][j];
        }
    }
    else
    {
        cout << "Invalid month number. Please enter a valid month (1-" << MONTHS << ")." << endl;
    }
    return totalViews;
}

int main()
{
    // declare month selected
    int selectedMonth;

    int arrToonViewers[MONTHS][WEEKS];

    // Populate array with random values
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = 0; j < WEEKS; j++)
        {
            // randomize from 100 to 10000
            arrToonViewers[i][j] = rand() % 9901 + 100; // Range: 100 to 10000
        }
    }

    // displays the cartoon viewership stats
    displayCartoonStats(arrToonViewers);

    // prompt the user for the month
    cout << "\nEnter a month number (1-" << MONTHS << "): ";
    cin >> selectedMonth;

    // calculate the total viewship
    int totalViewership = calcToonFansOfMonth(arrToonViewers, selectedMonth);

    if (totalViewership > 0)
    {
        cout << "\nTotal viewership for Month " << selectedMonth << ": " << totalViewership << endl;
    }

    return 0;
}
