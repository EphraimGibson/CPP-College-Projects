include <iostream>
#include <fstream>

using namespace std;

// This function will be used to display the menu and to receive the user input
char displayMenuAndGetChoice()
{
    cout << "Choose: " << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "Enter your choice (1-3): ";

    char choice;
    cin >> choice;
    return choice;
}

// This function will be used to get the computer's choice randomly using rand() and switch/case
char getComputerChoice()
{
    int randomNum = rand() % 3 + 1;

    switch (randomNum)
    {
        case 1:
            return '1';
// The computer chooses rock
        case 2:
            return '2';
// The computer chooses paper
        case 3:
            return '3';
// The computer chooses scissors
    }

}

// This function is used to determine the winner of the game
char determineWinner(char userChoice, char computerChoice)
{
    if (userChoice == computerChoice)
        {
        return 'T';
// Tie
    } else if
    (
        (userChoice == '1' && computerChoice == '3') ||
        (userChoice == '2' && computerChoice == '1') ||
        (userChoice == '3' && computerChoice == '2')
    )
    {
        return 'W';
// The user has won
    } else
    {
        return 'L';
// The user has lost
    }
}

// This function is used to update the user's score based on the game results
void updateScore(char result, int &userScore, int &computerScore)
{
    if (result == 'W') {
        cout << "You win!\n";
        userScore++;
    } else if (result == 'L') {
        cout << "You lose!\n";
        computerScore++;
    } else {
        cout << "It's a tie!\n";
    }
}

// This void function is used to display scores and save them to the results file
void displayAndSaveScores(const string &userName, int userScore, int computerScore, const string &dateTime)
{
    cout << "Scores:\n";
    cout << userName << ": " << userScore << " wins\n";
    cout << "Computer: " << computerScore << " wins\n";

// This will save the scores to the results file
    ofstream outFile("scores.txt", ios::app);
    if (outFile.is_open())
        {
        outFile << userName << " " << userScore << " " << computerScore << " " << dateTime << endl;
        outFile.close();
    } else
    {
        cout << "Unable to save scores to file.\n";
    }
}

int main() {
    string userName;
    int userScore = 0;
    int computerScore = 0;

    cout << "Enter your name: ";
    getline(cin, userName);

    char playAgain;
    do {
        char userChoice = displayMenuAndGetChoice();
        char computerChoice = getComputerChoice();
        char result = determineWinner(userChoice, computerChoice);

// The user must manually enter the date and time upon winning the game, this will be saved alongside the playername and date/time
        string dateTime;
        if (result == 'W')
            {
            cout << "Enter date and time: ";
            cin.ignore();

// This should clear the memory buffer
            getline(cin, dateTime);
        }

        updateScore(result, userScore, computerScore);
        displayAndSaveScores(userName, userScore, computerScore, dateTime);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}