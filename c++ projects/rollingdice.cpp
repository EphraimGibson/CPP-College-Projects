/*Two brothers disagree on who should clean the room.

They roll the dice.
If the number 1, 3 or 5 is rolled, the younger one takes the room,
if 2, 4 or 6, the older one takes the room.

Write a program that, when the number is entered, displays the message 'The room will be handled by the younger brother' or 'The room will be handled by the older brother'.

Do not forget that sometimes user of program can enter illegal value, for ex. 9.*/

#include <iostream>

using namespace std; 

int main ()
{
    int dice;

    cout << "Please roll the dice and enter the number below : " << endl;
    cin >> dice;

    if (!(dice > 0 && dice < 7))
        cout << "your number is not on a dice! Please re-run program and enter a number from 0 to 6 " << endl << "Thank you :-)" ; 
    else if (dice % 2 != 0)
        cout << "The room will be handled by the younger brother " ;
    else
        cout << "The room will be handled by the older brother" ;
    
    return 0;
}