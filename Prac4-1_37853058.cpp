#include <iostream>
#include <iomanip>
/*
Name: Thuso
Surname: Ndou
Student Number: 37853058

*/
using namespace std;

// Other Functions
// function for finding the highest
int findHighestUsage(int toolHours[],int SIZE)
{
    // declaring and initializing highest value
    int highest = toolHours[0];

    for(int i = 0 ; i < SIZE ; i++)
    {
        // test for the highest value
        if (toolHours[i] > highest)
        {
            highest = toolHours[i];
        }
    }
    // return the highest value
    return highest;
}

// function for funding the lowest value
int findLowestUsage(int toolHours[],int SIZE)
{
    // declaring and initializing lowest value
    int lowest = toolHours[0];

    for(int i = 0 ; i < SIZE ; i++)
    {
        // test for the lowest value
        if (toolHours[i] > lowest)
        {
            lowest = toolHours[i];
        }
    }
    // return lowest value
    return lowest;
}

// function for average value
double averageUsage(int toolHours[],int SIZE)
{
    int total = 0;
    double average;

    // adding up all the values inside an array
    for(int i = 0 ; i < SIZE ; i++)
    {
       total = total + toolHours[i];
    }

    // calculating the average
    average = double(total) / SIZE;

    // return average
    return average;
}

// function for displaying
void displayTools(string toolNames[], int toolHours[], int SIZE)
{
    // display the headings in two columns
    cout << left << setw(25) << "Tool Names" << "Usage Hours\n";

    for (int i = 0 ; i < SIZE ; i++)
    {
      // Display the tool names and hours in columns
      cout << left << setw(25) << toolNames[i] << toolHours[i] << endl;
    }
}

// function for ranking tools
void rankTools(int toolHours[], int SIZE ,string toolNames[])
{
    for (int i = 0 ; i < SIZE -1 ; i++)
    {
      for (int j = 0 ; j < SIZE - i - 1 ; j++)
      {
          if(toolHours[j] < toolHours[j + 1])
          {
              swap(toolHours[j],toolHours[j + 1]);
              swap(toolNames[j],toolNames[j + 1]);
          }
      }
    }
    cout << "\n";
}

// Main Function
int main()
{
    // Initialized arrays with developer tool names and sample usage hours
    const int SIZE = 10;
    int toolHours[SIZE] = {25, 120, 40, 60, 35, 15, 90, 10, 5, 80};
    string toolNames[SIZE] = {"VSCode", "IntelliJ IDEA", "Docker", "Postman", "Git", "Slack", "Chrome DevTools", "PyCharm", "Notion", "Figma"};

    double avg = averageUsage(toolHours, SIZE);
    cout << "The average tool usage (excluding the highest and lowest) is: "<< fixed << setprecision(1) << avg << " hours.\n\n";

    cout << "Tools and their Usage:\n";
    displayTools(toolNames, toolHours, SIZE);

    // UNCOMMENT the following for the bonus section:

    cout << "\nRanked Tools based on Usage:\n";
    rankTools(toolHours, SIZE, toolNames);
    displayTools(toolNames, toolHours, SIZE);

    return 0;
}
