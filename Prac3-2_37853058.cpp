/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that calculates and displays the hospital charges for a
patient’s stay. The charges should be computed based on whether the
patient was admitted as an in-patient or an out-patient.
*/
#include<iostream>
#include<iomanip>
using namespace std;

// Function to calculate charges for in-patients
double totalCharge(int days, double rate, double medCharges, double serviceCharges)
{
    double totalCharges;

    // calculations for total charges
    totalCharges = (rate * days) + medCharges + serviceCharges;

    return totalCharges;
}

// Function to calculate charges for out-patients
double totalCharge(double medCharges, double serviceCharges)
{
    double totalCharges;

    // calculations for total charges
    totalCharges = medCharges + serviceCharges;

    return totalCharges;
}

int main() {
    char patientType;
    double totalCharges;

    // Ask the user for patient type
    cout << "Enter patient type: (I) for in-patient, (O) for out-patient" << endl;
    cin >> patientType;
    patientType = toupper(patientType);

    if(patientType == 'I')
    {
        // Declare the required variables HERE
        int numberOfDays;
        double dailyRate;
        double medicationCharge;
        double serviceCharge;

        // Get in-patient data (uncomment cin statements and complete)
        cout << "Enter the number of days spent in the hospital:" << endl;
        cin >> numberOfDays;
        cout << "Enter the daily rate:" << endl;
        cin >> dailyRate;
        cout << "Enter the hospital medication charges:" << endl;
        cin >> medicationCharge;
        cout << "Enter the charges for hospital services:" << endl;
        cin >> serviceCharge;

        // Call the overloaded function to calculate total charges for in-patients
        totalCharges = totalCharge(numberOfDays, dailyRate, medicationCharge, serviceCharge);

    }
    else if(patientType == 'O')
    {
        // Declare required variables HERE
        double medicationCharge;
        double serviceCharge;

        // Get out-patient data (uncomment cin statements and complete)
        cout << "Enter the hospital medication charges:" << endl;
        cin >> medicationCharge;
        cout << "Enter the charges for hospital services:" << endl;
        cin >> serviceCharge;

        // Call the overloaded function to calculate total charges for out-patients
        totalCharges = totalCharge(medicationCharge,serviceCharge);
    }
    else
    {
        cout << "Invalid patient type entered. Please try again." << endl;
        return 1;
    }

    // Display the total charges
    cout << "\nTotal charges = R " << fixed << setprecision(2) << totalCharges << endl;

    return 0;
}
