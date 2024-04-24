/*The value of the variable PN is a 5-digit natural number, swap the second and last
digits of this number*/

#include <iostream>

using namespace std;

int main()
{
    int PN;

    cout << "enter a five digit number: " ;
    cin >> PN ;

    if (PN >= 10000 && PN <= 99999)
    {
        int num1 = PN / 10000;
        int num2 = (PN / 1000) % 10;
        int num3 = (PN / 100) % 10;
        int num4 = (PN / 10) % 10;
        int num5 = PN % 10;

        int swap = num1 * 10000 + num5 * 1000 + num3 * 100 + num4 * 10 + num2;
        cout << "swapped 2nd and 5th number = " << swap ;
    }
    else 
        cout << "Your number is not 5 digits! Kindly re-run program :-(" ;

        return 0;
}