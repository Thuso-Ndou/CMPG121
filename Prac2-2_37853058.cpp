/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that analyses the examination results for a module and
classifies the module as high, low, or a medium risk module based on the pass rate.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

//declaring variables
int numOfStudents{};
int studentPassed{};
int exam_mark{};
double passRate{};

while (true)
{
    // user input for exam mark
    cout << "Enter examination mark(100) or -1 to stop: ";
    cin >> exam_mark;

    // stop the loop
    if (exam_mark == -1)
    {
    break;
    }

    // for values out of range
    if (exam_mark < 0 || exam_mark > 100)
    {
        cout << "Invalid mark. Please enter a mark between 0 and 100.\n";
    }

    //incrementation for number of students
    numOfStudents ++;

    if (exam_mark >= 50)
    {
        studentPassed++;
    }
}

// if no student mark was entered
if (numOfStudents == 0)
{
    cout << "No marks entered.";
}

// calculations for pass rate
passRate = (double)(studentPassed) / numOfStudents * 100;

cout << "\n";

// testing to determine the level of risks for students
if (passRate < 30) {
    //output display for total exam mark, students who passed and pass rate
    cout << studentPassed << " student(s) passed the module." << endl;
    cout << "The pass rate is " << fixed << setprecision(1) << passRate << "%" << endl;
    cout << "The module is high-risk\n";

}
else if (passRate <= 60){
    //output display for total exam mark, students who passed and pass rate
    cout << studentPassed << " student(s) achieved a mark of 50% or greater and passed the module." << endl;
    cout << "The pass rate is " << fixed << setprecision(1) << passRate << "%" << endl;
    cout << "The module is medium-risk\n";
} else{
    //output display for total exam mark, students who passed and pass rate
    cout << studentPassed << " student(s) achieved a mark of 50% or greater and passed the module." << endl;
    cout << "The pass rate is " << fixed << setprecision(1) << passRate << "%" << endl;
    cout << "The module is low-risk\n";
}
    return 0;
}

