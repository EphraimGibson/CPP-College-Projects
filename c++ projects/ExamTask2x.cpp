#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

void displayMenu();
void registerUser(string *name);
void selectUser(string &name);
void displayScores();
void continuePlaying(string &name,int *wins, int *losses);
void deleteProgress();

int main()
{
;
   string name;
    int selection;

    int win, losses;

    int *WIN = &win;
    int *LOSSES = &losses;

    do 
    {

        // display menu
        displayMenu();
        cin >> selection;

        switch (selection) {
            case 1:
                registerUser(&name);
                break;
            case 2:
                selectUser(name);
                break;
            case 3:
                displayScores();
                break;
            case 4:
                continuePlaying(name, WIN,LOSSES);
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
void registerUser(string *name)
 {
   string username;
    cout << "Enter your name: ";
    cin >> username;
    *name = username;

    // Write the user's name and initial scores at the end of the file
    ofstream file("UsersScores.txt", ios::app);
    file << username << " 0 0" << endl;
    file.close();

    cout << "User registered successfully" << endl;
    cout << "Hello" << username << "\n\n" << "select 4 to continue playing" << endl;
}

void selectUser(string &name) 
{
    // Check if the user exists in the file
    displayScores();
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

//displays the score

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

void continuePlaying(string &name, int *wins, int *losses) // function to continue playing
{
    string moves[] = {"Rock", "Paper", "Scissors"};
    int wi ; 
    int loss;

    wi = *wins;
    loss = *losses;
    
    cout << "Enter your move (Rock, Paper, or Scissors): ";
    string MoveUser;
    cin >> MoveUser;

    // Generate a random move for the PC
    srand(time(NULL));
    string MoveComputer = moves[rand() % 3]; 

    cout << "Computer's move: " << MoveComputer << endl;

    // Check for winner
    if (MoveUser == MoveComputer)
        cout << "It's a tie!\n";
    else if ((MoveUser == "Rock" && MoveComputer == "Scissors") ||
               (MoveUser == "Paper" && MoveComputer == "Rock") ||
               (MoveUser == "Scissors" && MoveComputer == "Paper")) 
               {
            cout << "You win!\n";

            if (name == MoveUser) {
                wi++;
            
        }
    } else {
        cout << "Computer wins!\n";
            if (name == MoveUser) {
                loss++; //checks for losses
        }
    }
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


