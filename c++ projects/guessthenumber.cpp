#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int number = rand()%101;
    int guess;
    int min = 0;
    int max = 100;
    bool playermove = true;

    do 
        {
            if (playermove == true)
            {
                    cout << "Guess a number from[" << min << "-" << max << "]:";
                     cin >> guess;
            }
            else 
            {
                guess = min + rand() % (max-min+1);
                cout << "Computer guess from [" << min << "-" << max << "]:" << guess << endl << endl;
            }
            if(number > guess)
                {
                    cout << "The number to be guessed is larger" << endl << endl;
                    min = guess + 1;
                }
            else if (number < guess)
                {
                    cout << "The number to be guessed is smaller" << endl<< endl;
                    max = guess - 1;
                }
            else 
                cout << "You guessed the number!" << endl;  
             playermove = !playermove;
        }
    while(number != guess);
    return 0;
}