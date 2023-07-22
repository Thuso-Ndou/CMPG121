/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that provide the ASCII value of a character
or provide the character for an ASCII value.
*/
#include <iostream>

using namespace std;

int main()
{
    // heading
    cout << "**ASCII and Character Conversion" << endl;

    // declaring variables
    char character{};
    int number{};

    // user input for character
    cout << "\nEnter character: ";
    cin >> character;

    // display output ASCII value
    cout << "The ASCII value is: " << (int)(character) << endl;

    cout << "====================";

    // user input for ASCII value
    cout << "\nEnter the ASCII value: ";
    cin >> number;

    // display output character
    cout << "The character is: " << (char)(number) << endl;

    return 0;
}
