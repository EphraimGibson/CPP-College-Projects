/*The value of the variable THREE is a 3-digit natural number, find the value of the
variable REVERSE, which is equal to the number obtained by writing the digits of the
variable THREE backwards. For example: if THREE =123, then REVERSE=321.*/

#include <iostream>

using namespace std;

int main ()
{
    int THREE;
    int REVERSE;

    cout << "enter a 3 digits number : " ;
    cin >> THREE;

    if (THREE >= 100 && THREE <= 999)
    {
        int c = THREE % 10;
        int b = (THREE/10) % 10;
        int a = THREE / 100;

        REVERSE = c * 100 + b * 10 + a;
    
        cout << "Reverse of your number is : " << REVERSE << endl;
    }
     else 
     cout << "number is not 3 digits! please run program again :-(" ;

    return 0;
}