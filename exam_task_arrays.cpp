#include <iostream>
#include <fstream>

using namespace std;

struct User 
{
    string name;
    int wins;
    int losses;
};

int main()
{

}

void menu()
{
    int selection;
    do {
        cout << "\nMain Menu:"<< endl << "1. Display Player Stats\n2. Register or Select User\n3. Play Game\n"
                "4. Delete User Progress\n0. Exit\nEnter your choice: ";
        cin >> selection;

        switch (selection) {
            case 1:
                displayPlayerStats();
                break;
            case 2:
                registerOrSelectUser();
                break;
            case 3:
                playGame();
                break;
            case 4:
                deleteUserProgress();
                break;
            case 0:
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }

    } while (selection != 0);
}

void registerOrSelectUser()
{
    string playerName;
    bool userExists = false;

    cout << "Enter your name: ";
    cin >> playerName;

    for (const Player& player : players) {
        if (player.name == playerName) {
            userExists = true;
            break;
        }
    }

    if (!userExists) {
        // New user registration
        User Newplayer;
        Newplayer.name = playerName;
        Newplayer.wins = 0;
        newPlayer.losses = 0;
        players.push_back(newPlayer);
    }
}