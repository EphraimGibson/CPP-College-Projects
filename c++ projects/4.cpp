/*The values of the variables L1 and L2 are three-digit natural numbers, find the
multiplication of the middle digits.*/

#include <iostream>

using namespace std;

int main ()
{
    int L1;
    int L2;


    cout << "put the first 3 digit number: " ; 
    cin >> L1;

    cout << "put second 3 digit number:" ;
    cin >> L2;

    if ((L1 >= 100 && L1 <= 999) && (L2 >= 100 && L2 <= 999)) 
    {
        int L1_midle = (L1 / 10) % 10;
        int L2_midle = (L2 / 10) % 10; 
        int result = L1_midle * L2_midle;

        cout << "multiplication of the middle number = " << result;
    }
       else 
     cout << "number is not 3 digits, kindly run program again :-(" ;
     return 0;
    
}