#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();
void registerUser();
void selectUser();
void displayScores();
void continuePlaying();
void deleteProgress();

int main()
{
    int selection;

    do 
    {

        displayMenu();
        cin >> selection;

        switch (selection) {
            case 1:
                registerUser();
                break;
            case 2:
                selectUser();
                break;
            case 3:
                displayScores();
                break;
            case 4:
                continuePlaying();
                break;
            case 5:
                deleteProgress();
                break;
            case 6:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (selection != 6);

    return 0;
}


// Function to display the menu options
void displayMenu() 
{
    cout << "Welcome to Rock Paper Scissors Game!" << endl;
    cout << "1. Register as a new user" << endl;
    cout << "2. Select your name from registered users" << endl;
    cout << "3. Display registered names, scores, and win percentage" << endl;
    cout << "4. Continue playing" << endl;
    cout << "5. Delete your progress" << endl;
    cout << "6. Exit the game" << endl;
    cout << "Enter your choice: ";
}

// Function to register a new user
void registerUser() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Write the user's name and initial scores at the end of the file
    ofstream file("UsersScores.txt", ios::app);
    file << name << " 0 0" << endl;
    file.close();

    cout << "User registered successfully" << endl;
}

void selectUser() 
{
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Check if the user exists in the file
    string line;
    bool userFound = false;

    ifstream file("UsersScores.txt");
    if(file.fail()) cout << "File not found!" << endl;
    else
    {
        while (getline(file, line)) 
        {
            if (line.find(name) != string::npos) 
            {
                userFound = true;
                break;
            }
        }
        file.close();
    }
    if (userFound)
        cout << "User selected successfully!" << endl;
    else
        cout << "User not found. Please register as a new user." << endl;
}

void displayScores() 
{
    string line;
    ifstream file("UsersScores.txt");
    if(file.fail()) cout << "File not found!" << endl;
    else
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    file.close();
}

void continuePlaying() // function to continue playing
{
    cout << "Continue playing..." << endl;
}

// Function to delete the user's progress
void deleteProgress() 
{
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Code to delete the user's progress from the file
    ifstream file("UsersScores.txt");
    ofstream outputFile("temp.txt");
    string line;

    if(file.fail()) cout << "File not found!" << endl;
    else
    {
      while (getline(file, line)) 
      {
        if (line.find(name) == string::npos) 
            outputFile << line << endl;
      }
        file.close();
        outputFile.close();

        remove("UsersScores.txt");
        rename("temp.txt", "UsersScores.txt");

   
        cout << "Progress deleted successfully!" << endl;
    }
}


