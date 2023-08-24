/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program to track and manage user concerns about data privacy on various
online platforms. The program will use parallel arrays: one to store the name
of the platform, and a parallel array to store a numerical value representing
the level of user concern.
*/
#include <iostream>
#include <string>

using namespace std;

// Constants for the maximum number of platforms
const int MAX_PLATFORMS = 100;

// Function to display all platforms and their associated concern levels in column format
void displayPlatforms(string arrPlatformNames[], int arrConcernLevels[], int currentSize)
{
    cout << "No.   Platform           Concern Level\n";

    for (int i = 0; i < currentSize; ++i)
    {
        cout << i + 1 << ".    " << arrPlatformNames[i] << "               " << arrConcernLevels[i] << "\n";
    }
}

// Function to add a new platform and its associated concern level
void addPlatform(string arrPlatformNames[], int arrConcernLevels[], int &currentSize); // what does the & mean before a parameter name???

// Function to update the concern level for an existing platform
void updateConcernLevel(string arrPlatformNames[], int arrConcernLevels[], int currentSize);


int main()
{
    int choice;
    int currentSize = 4;  // Start with 4 initial records


    // ADD CODE HERE <Declare both arrays, namely arrPlatformNames and arrConcernLevels> ADD CODE HERE
    string arrPlatformNames[MAX_PLATFORMS];
    int arrConcernLevels[MAX_PLATFORMS];

    // ADD CODE HERE <Initialize both arrays with default values, at least 4 records> ADD CODE HERE
    arrPlatformNames[0] = "Facebook";
    arrConcernLevels[0] = 6;
    arrPlatformNames[1] = "Google";
    arrConcernLevels[1] = 7;
    arrPlatformNames[2] = "Apple";
    arrConcernLevels[2] = 9;
    arrPlatformNames[3] = "WhatsApp";
    arrConcernLevels[3] = 8;


    do
    {
        cout << "\nMenu:\n";
        cout << "1. View all platforms\n";
        cout << "2. Add a new platform\n";
        cout << "3. Update a platform's concern level\n";
        cout << "4. Exit\n";
        cout << "\nYour choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayPlatforms(arrPlatformNames, arrConcernLevels, currentSize);
                break;
            case 2:
                addPlatform(arrPlatformNames, arrConcernLevels, currentSize);
                break;
            case 3:
                updateConcernLevel(arrPlatformNames, arrConcernLevels, currentSize);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 4);

    return 0;
}


// Function to add a new platform and its associated concern level
void addPlatform(string arrPlatformNames[], int arrConcernLevels[], int &currentSize)
{
    if (currentSize < MAX_PLATFORMS)
        {
        string newPlatformName;
        int newConcernLevel;

        cout << "Enter platform name: ";
        cin.ignore();
        getline(cin, newPlatformName);

        cout << "Enter concern level (1-10): ";
        cin >> newConcernLevel;

        arrPlatformNames[currentSize] = newPlatformName;
        arrConcernLevels[currentSize] = newConcernLevel;

        currentSize++;

        cout << "Platform added successfully!\n";
    }
    else
    {
        cout << "Maximum number of platforms reached.\n";
    }
}


// Function to update the concern level for an existing platform
void updateConcernLevel(string arrPlatformNames[], int arrConcernLevels[], int currentSize)
{
    int platformNumber;

    cout << "Enter the number of the platform you want to update: ";
    cin >> platformNumber;

    if (platformNumber >= 1 && platformNumber <= currentSize)
    {
        int newConcernLevel;

        cout << "Enter the updated concern level (1-10): ";
        cin >> newConcernLevel;

        arrConcernLevels[platformNumber - 1] = newConcernLevel;

        cout << "Concern level updated successfully!\n";
    }
    else
    {
        cout << "Invalid platform number.\n";
    }
}
