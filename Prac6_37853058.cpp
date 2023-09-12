/*
Name: Thuso
Surname: Ndou
Student no: 37853058
*/
#include <iostream>

using namespace std;

// constant value for danger default
const int dangerDefault = 5;

// Define a structure for alien species
struct AlienSpecies
{
    string name;
    string planetOrigin;
    int dangerLevelToHumans;
    bool officalContacted;
};

// Function prototype
void recordNewSpecies(AlienSpecies *alienSpeciesArr, int &counter);
void displaySpeciesAboveDangerLevel(AlienSpecies *alienSpeciesArr, int counter, int dangerLevel);
AlienSpecies* findMostDangerousYetUncontacted(AlienSpecies *alienSpeciesArr, int counter);

int main()
{
    // declaring an array using structure
    AlienSpecies alienSpeciesArr[100];

    // initializating the count to zero
    int alienCount = 0;

    // declaring user option
    int userOption{};

    // flag value
    bool option = false;

    while (! option)
    {
        // print the main
        printf("\nGalactic Explorer Interface:\n");
        printf("1. Record a new alien species.\n");
        printf("2. Display species above a certain danger level.\n");
        printf("3. Identify the most dangerous uncontacted species.\n");
        printf("4. Terminate session.\n");
        printf("Enter selection: ");

        // user input
        cout << "Enter selection: " ;
        cin >> userOption;

        if (userOption == 1)
        {
            recordNewSpecies(alienSpeciesArr, alienCount);
        }
        else if(userOption == 2)
        {
            int dangerLevel;
            cout << "Enter danger level threshold (or press enter for default level 5): ";
            cin >> dangerLevel;
            displaySpeciesAboveDangerLevel(alienSpeciesArr, alienCount, dangerLevel);
        }
        else if(userOption == 3)
        {
            AlienSpecies* dangerousSpecies = findMostDangerousYetUncontacted(alienSpeciesArr, alienCount);
            if (dangerousSpecies != nullptr)
                {
                    cout << "The most dangerous uncontacted species is: " << endl;
                    cout << "Name: " << dangerousSpecies->name << endl;
                    cout << "Planet of Origin: " << dangerousSpecies->planetOrigin << endl;
                    cout << "Danger Level: " << dangerousSpecies->dangerLevelToHumans <<endl;
                }
        }
        else if(userOption == 4)
        {
            option = true;
        }
        else
        {
            cout << "Invalid Input. Please enter a valid input: \n";
        }

    }

    return 0;
}

// A function for adding new species
void recordNewSpecies(AlienSpecies *alienSpeciesArr, int &counter)
{
    // when the array element reaches 100
    if (counter >= 100)
    {
       cout << "Maximum species limit reached. Cannot add more species." << std::endl;
        return;
    }

    // declare a new array
    AlienSpecies newSpecies;

    // input for species name
    cout << "Species Name: ";
    cin >> newSpecies.name;

    // input for planet origin
    cout << "Planet of origin: ";
    cin.ignore();
    getline(cin, newSpecies.planetOrigin);

    // input for danger level
    cout << "Danger Level (1-10): ";
    cin >> newSpecies.dangerLevelToHumans;

    // input for contact of species
    cout << "Officially Contacted? (1 for Yes, 0 for No) :";
    cin >> newSpecies.officalContacted;

    // store a new species in an array
    alienSpeciesArr[counter] = newSpecies;
    counter++;

    // display a success message
    cout << "Species recorded successfully!\n";
}

// A function for showing all species with danger level above a specified threshold
void displaySpeciesAboveDangerLevel(AlienSpecies *alienSpeciesArr, int counter, int dangerLevel)
{
    cout << "Species with danger level above " << dangerDefault << ":" << endl;
    cout << "Name \tPlanet   \tDanger Level" << endl;

    for (int i = 0; i < counter; i++)
    {
        if (alienSpeciesArr[i].dangerLevelToHumans > dangerDefault)
        {
            cout << alienSpeciesArr[i].name << "\t" << alienSpeciesArr[i].planetOrigin<< "  \t" << alienSpeciesArr[i].dangerLevelToHumans << endl;
        }
    }
}

// A function for finding the most dangerous uncontacted alien species
AlienSpecies* findMostDangerousYetUncontacted(AlienSpecies *alienSpeciesArr, int counter)
{
    // assigning dangerous to an empty array
    AlienSpecies* dangerousSpecies = nullptr;

    for (int i = 0; i < counter; i++)
        {
        if (!alienSpeciesArr[i].officalContacted)
        {
            if (dangerousSpecies || alienSpeciesArr[i].dangerLevelToHumans > dangerousSpecies->dangerLevelToHumans)
            {
                dangerousSpecies = &alienSpeciesArr[i];
            }
        }

        return dangerousSpecies;
        }
}

