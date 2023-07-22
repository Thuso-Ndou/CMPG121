/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that calculates the area, volume, and diagonal of a square
pyramid that has a base and perpendicular height given by the user.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // declaring and initializing variables
    double area{};
    double volume{};
    double diagonal{};
    double base{};
    double height{};

    // heading
    cout << "Pyramid Calculator" << endl;

    // user input for base and height
    cout << "\nEnter the base (cm): ";
    cin >> base;
    cout << "Enter the height (cm): ";
    cin >> height;

    // calculations for area
    area = (base * base) + (2 * base) * (sqrt(base * base / 2 + height * height));

    // calculations for volume
    volume = (base * base * height) / 3;

    // calculations for diagonal
    diagonal = sqrt(5 * base * base / 4 + height * height);

    // display output
    cout << "\nArea of the pyramid is " << fixed << setprecision(4) << area << " square cm" << endl;
    cout << "Space diagonal of the pyramid is " << fixed << setprecision(3) << diagonal << " cm" << endl;
    cout << "Volume of the pyramid is " << fixed << setprecision(2) << volume << " cubic cm" << endl;

    // heading
    cout << "\n**Pyramid Dimension:**" << endl;

    // pyramid dimension output
    cout << "Base: " << fixed << setprecision(1) << base << " cm\n" << "Height: " << fixed << setprecision(1) << height << " cm" << endl;

    return 0;
}
