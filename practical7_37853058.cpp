/*
Name: Thuso
Surname: Ndou
Student No: 37853058
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// define a structure
struct AnimalInfo
{
    string speciesName;
    string habitatName;
    int populationCount;
};

// function to read data from file
int readFromFile(AnimalInfo* animalInfoArray, ifstream& readData)
{
    // counter for number of records
    int counter = 0;

    // open file
    readData.open("data.txt");

    if(readData.fail())
    {
        // error message if the file does not open
        cout << "Error! File can not be opened.\n";
    }
    else
    {
        while(!(readData.eof()))
        {
            // store the species name to an array
            getline(readData, animalInfoArray[counter].speciesName, ',');

            // store the species habitat name to an array
            getline(readData, animalInfoArray[counter].habitatName, ',');

            // store the population count into an array
            readData >> animalInfoArray[counter].populationCount;

            // increment count by 1
            counter++;
        }
    }

    // close file
    readData.close();

    // return count
    return counter;
}

// Function to display the species
void displaySpecies(AnimalInfo* speciesArray, int arrayElements, string habitatName)
{
    if(habitatName == "")
    {
        // display heading
        cout << left << setw(5) << "\nNo." << left << setw(20)  << "Species Name" << left << setw(25) << "Habitat Name" << "Population Count" << endl;
        cout << "-----------------------------------------------------------------\n";

        for(int i = 0; i < arrayElements; i++)
        {
            // display the details
            cout << left << setw(5) <<  i + 1 << left << setw(20)  << speciesArray[i].speciesName << left << setw(25) << speciesArray[i].habitatName << speciesArray[i].populationCount;
        }
    }
    else
    {
        // display heading
        cout << left << setw(5) << "\nNo." << left << setw(20)  << "Species Name" << left << setw(25) << "Habitat Name" << "Population Count" << endl;
        cout << "-----------------------------------------------------------------\n";

        for(int i = 0; i < arrayElements; i++)
        {
            // display the details
            cout << left << setw(5) <<  i + 1 << left << setw(20)  << speciesArray[i].speciesName << left << setw(25) << habitatName << speciesArray[i].populationCount;
        }
    }
}

// function to update the population
bool updatePop(AnimalInfo* speciesArray, int newPopulation)
{
    // declare a boolean variable
    bool success;
    int numberToUpdate;

    // user input for number of species to update
    cout << "Enter the number of the species you want to update: ";
    cin >> numberToUpdate;

    if(numberToUpdate > 0)
    {

        if(newPopulation > 0)
        {
            for(int i = 0; i < numberToUpdate; i++)
            {
                // update the population
                speciesArray[i].populationCount = newPopulation;
            }
            // set success to true
            success = true;
        }
        else
        {
            // set succes to false
            success = false;
        }
    }
    else
    {
        // set success to false
        success = false;
    }

    // return a boolen
    return success;
}

// Function to write data to a file
void writeToFile(AnimalInfo* speciesArray, int numberOfElements, ofstream& writeData)
{
    // if you want to append the data
    //writeData.open("data.txt", ios::app);

    // overwrite the data
    writeData.open("data.txt");

    if(writeData.fail())
    {
        // display error message if the file does not open
        cout << "Error! Failed to open the file\n";
    }
    else
    {
        for(int i = 0; i < numberOfElements; i++)
        {
            writeData << speciesArray[i].speciesName << ',' << speciesArray[i].habitatName << ',' << speciesArray[i].populationCount;
        }

        // display success message
        cout << "\nData EXPORT successful...\n";
    }
}

int main()
{
    // creating a read method
    ifstream readData;

    // create a write method
    ofstream writeData;

    // const maximum number an array can store
    const int maxsize = 100;

    // declare an array
    AnimalInfo speciesArray[maxsize];

    // point to the array
    AnimalInfo* pSpeciesArray;
    pSpeciesArray = speciesArray;

    // declaring the number of elements variable
    int arrayElements;

    // call the read data function and storing the return value
    arrayElements = readFromFile(pSpeciesArray,readData);

    // declare variables to use in the do-while loop
    int userOption;
    string habitatName;
    int newPopulation;
    bool success;

    do
    {
        // display menu
        cout << "\n1. Display Species\n";
        cout << "2. Update Population Count\n";
        cout << "3. Write Data To File\n";
        cout << "4. Exit\n";

        // user input
        cout << "Choose an option: ";
        cin >> userOption;

        switch(userOption)
        {
            case 1:
                // user input for habitat name
                cout << "Enter habitat name (leave empty to display all): ";
                cin.ignore();
                getline(cin, habitatName);

                // Call function to display species
                displaySpecies(pSpeciesArray, arrayElements, habitatName);
                break;
            case 2:
                // user input for new popluation
                cout << "Enter new population count: ";
                cin >> newPopulation;

                // call the update function
                success = updatePop(pSpeciesArray, newPopulation);

                // display message showing whether th eupdate was successfull or it failed to update
                if(success)
                {
                    cout << "Population count updated successfully.\n";
                }
                else
                {
                    cout << "Population count update failed.\n";
                }

                break;
            case 3:
                writeToFile(pSpeciesArray, arrayElements, writeData);
                break;
            case 4:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid Option! Please try again.\n";
                break;
        }

    } while(userOption != 4);

    return 0;
}
