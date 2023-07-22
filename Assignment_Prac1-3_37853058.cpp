/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that determines whether a user is eligible to vote, or not.
*/
#include <iostream>

using namespace std;

int main()
{
    // declaring variables
    int age{};
    char gender{};

    // user input for age
    cout << "Enter your age: ";
    cin >> age;

    // user input for gender
    cout << "Enter your gender (M/F): ";
    cin >> gender;

    // test conditions
    if (age >= 18){
        if (gender == 'M' || gender == 'F'){
            cout << "\nYou are eligible to vote" << endl;
        }
        else{
            cout << "\nInvalid gender" << endl;
        }
    }
    else{
        cout << "\nYou are not eligible to vote" << endl;
    };

    return 0;
}
