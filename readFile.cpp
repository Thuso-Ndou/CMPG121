#include <iostream>
#include <fstream>

using namespace std;

// define a struct
struct Species
{
    string species;
    string habitat;
    int population;
};

// function prototype
int readData(Species* sArray);

int main()
{
    // declaring variables
    int counter = 0;

    // declare a Species array
    Species speciesArray[50];


    // declaring a pointer to array
    Species* pSpeciesArray = nullptr;

    // assigning the first element address to a pointer
    pSpeciesArray = speciesArray;

    // function call
    counter = readData(pSpeciesArray);

    for(int i = 1; i <= counter; i++)
    {
        // display the data
        printf("%-2d %-25s %-25s %-15d\n", i, pSpeciesArray[i].species.c_str(), pSpeciesArray[i].habitat.c_str(), pSpeciesArray[i].population);
    }

    return 0;
}

// Function to read data from a file
int readData(Species* sArray)
{
    // declare variables
    int counter = 0;

    // read object
    ifstream infile;

    // open file
    infile.open("data.txt");

    // delare a string variable
    string readline;

    if(infile.fail())
    {
        cout << "Failed to open fail." << endl;

        // return for fail
        return 1;
    }
    else
    {
        // declaring position counter
        int pos;

        while(getline(infile,readline))
        {
            /** read the first part of the line **/
            // find the position of the first comma
            pos = readline.find(",");

            // store the data before the comma in an array of type struct
            sArray[counter].species = readline.substr(0, pos);

            // erase the first part of the line including the comma
            readline.erase(0, pos + 1);

            // find the position of the first comma
            pos = readline.find(",");

            // store the data before the comma in an array of type struct
            sArray[counter].habitat = readline.substr(0, pos);

            // erase the first part of the line
            readline.erase(0, pos + 1);

            /**Convert the string type to type int**/
            // store the remaining data to the array
            sArray[counter].population = stoi(readline);

            // increment counter by one
            counter ++;
        }

        // close file
        infile.close();

        // return count
        return counter;
    }
}
