/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

A C++ program that will store details about different movies in an array of structures
and allow users to sort and display them based on different criteria.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

// Using the standard namespace to avoid prefixing with "std::"
using namespace std;

//Add struct declaration here
struct Movie {
    string title;
    int year;
    float rating;
    string genre;
};


// Function prototypes
void inputMovies(Movie arrMovies[], int n);
void displayMovies(Movie arrMovies[], int n);

bool sortByTitle(Movie a, Movie b);
bool sortByRating(Movie a, Movie b);

int main()
{
    int n;
    // Prompt the user for the number of movies they want to input
    cout << "How many movies do you want to input? ";
    cin >> n;

    // ADD CODE HERE <Declare an array of Movie structs to store the movie details called arrMovies> ADD CODE HERE

     Movie arrMovies[n];


    //============================================================================================================

    // Call the inputMovies function to get movie details from the user
    inputMovies(arrMovies, n);

    int choice;

    do
    {
        // Display the sorting options menu to the user
        cout << "\nChoose a sorting option:\n";
        cout << "1. Sort by title\n";
        cout << "2. Sort by IMDb rating\n";
        cout << "3. Exit\n";
        cout << "\nYour choice: ";
        cin >> choice;

        // Use a switch-case to handle the user's choice
        switch (choice)
        {
            case 1:
                // Sort the movies array by title
                sort(arrMovies, arrMovies + n, sortByTitle);
                break;
            case 2:
                // Sort the movies array by IMDb rating
                sort(arrMovies, arrMovies + n, sortByRating);
                break;
            case 3:
                // Exit the program
                cout << "Exiting...\n";
                return 0;
            default:
                // Handle invalid choices
                cout << "Invalid choice. Try again.\n";
                continue;
        }

        // Display the sorted list of movies
        displayMovies(arrMovies, n);
    }
    while (choice != 5);

    return 0;
}
// ADD CODE BELOW
// Function to get movie details from the user
void inputMovies(Movie arrMovies[], int n) {
    cin.ignore(); // Clear the newline character from the previous input
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for movie " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, arrMovies[i].title);
        cout << "Year: ";
        cin >> arrMovies[i].year;
        cout << "Rating: ";
        cin >> arrMovies[i].rating;
        cin.ignore(); // Clear the newline character from the previous input
        cout << "Genre: ";
        getline(cin, arrMovies[i].genre);
    }
}

// Function to display the list of movies
void displayMovies(Movie arrMovies[], int n) {
    // heading
    cout << "\nMovies:\n";

    for (int i = 0; i < n; ++i) {
        // display movie title
        cout << left << setw(20) << arrMovies[i].title << " | ";
        // display the year
        cout << left << setw(5) << arrMovies[i].year << " | ";
        //display movie rating
        cout << left <<  setw(6) << fixed << setprecision(1) << arrMovies[i].rating << " | ";
        // display movie genre
        cout << arrMovies[i].genre << "\n";
    }
}

// Comparison function to sort movies by title
bool sortByTitle(Movie a, Movie b) {
    return a.title < b.title;
}

// Comparison function to sort movies by IMDb rating in descending order
bool sortByRating(Movie a, Movie b) {
    return a.rating > b.rating;
}


