#include <iostream>
#include <fstream>

using namespace std;

struct Member
{
    string name;
    string membership;
    int account;
};

// function prototype
void addMember();
void viewInfo();

int main()
{
    // declare user option varaiable
    int option;

    do
    {
        // menu
        cout << "\nMenu\n";
        cout << "\n1. Add Member\n";
        cout << "2. View Members\n";
        cout << "3. Exit\n";

        // user input
        cout << "\nEnter Option: ";
        cin >> option;

        switch(option)
        {
            case 1:
                addMember();
                break;
            case 2:
                viewInfo();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Option\n";
                break;
        }
    } while(option != 3);

    return 0;
}

void addMember()
{
    // create a stream writer object
    ofstream writeData;

    // open file
    writeData.open("member.bin", ios::binary | ios::app);

    // declare a member of Member struct
    Member member;

    // user input
    cout << "Enter member name: ";
    cin.ignore();
    getline(cin, member.name);

    cout << "Enter membership type: ";
    getline(cin, member.membership);

    cout << "Enter membership account: ";
    cin >> member.account;

    if(writeData.is_open())
    {
        // write data to a file
        writeData.write(reinterpret_cast<char*>(&member),(sizeof(Member)));

        // close file
        writeData.close();

        // success message
        cout << "Data successfully saved\n";
    }
    else
    {
        cout << "Failed to open the file\n";
    }
}

void viewInfo()
{
    // create a stream reader object
    ifstream readData;

    // open binary file
    readData.open("member.bin", ios::binary);

    if(readData.is_open())
    {
        // create member of Member type struct
        Member member;

        while(readData.read(reinterpret_cast<char*>(&member),sizeof(Member)))
        {
            cout << member.name << " " << member.account << " " << member.membership << endl;
        }

        // close file
        readData.close();
    }
    else
    {
        cout << "\nFailed to read file\n";
    }
}
