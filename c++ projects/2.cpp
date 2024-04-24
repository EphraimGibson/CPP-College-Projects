/*Given a three-digit number stored in a variable. Write a program to find the digits of
the number.*/

#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "input a 3 digit number: " ;
    cin >> num;

    if (num >= 100 && num <= 999)
    {
        int hundreds = num / 100;
        int tens = (num/10) % 10;
        int ones = num % 10;

        cout << "first digit = " << hundreds << endl;
        cout << "second digit = " << tens << endl;
        cout << "third digit = " << ones << endl;
    }
    else 
     cout << "number is not 3 digits" ;

     return 0;
}