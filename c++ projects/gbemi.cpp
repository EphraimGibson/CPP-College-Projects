#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to display the menu options
void displayMenu() {
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

    // Code to store the user's name and initial scores in a file
    ofstream file("scores.txt", ios::app);
    file << name << " 0 0" << endl;
    file.close();

    cout << "User registered successfully!" << endl;
}

// Function to select a user from the registered names
void selectUser() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Code to check if the user exists in the file
    ifstream file("scores.txt");
    string line;
    bool userFound = false;
    while (getline(file, line)) {
        if (line.find(name) != string::npos) {
            userFound = true;
            break;
        }
    }
    file.close();

    if (userFound) {
        cout << "User selected successfully!" << endl;
    } else {
        cout << "User not found. Please register as a new user." << endl;
    }
}

// Function to display the registered names, scores, and win percentage
void displayScores() {
    ifstream file("scores.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to continue playing the game
void continuePlaying() {
    cout << "Continue playing..." << endl;
    // Code to implement the game logic
}

// Function to delete the user's progress
void deleteProgress() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Code to delete the user's progress from the file
    ifstream file("scores.txt");
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        if (line.find(name) == string::npos) {
            lines.push_back(line);
        }
    }
    file.close();

    ofstream outFile("scores.txt");
    for (const string& l : lines) {
        outFile << l << endl;
    }
    outFile.close();

    cout << "Progress deleted successfully!" << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
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
                cout << "Thank you for playing! Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
