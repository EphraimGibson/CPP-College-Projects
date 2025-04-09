/*Create program where user is asked to enter number and as a result gets multiplication table of that number.
 Use loop to generate result.*/


#include <iostream>

using namespace std;

int main ()
{
    int num;
    
    cout << "Enter a number: ";
    cin >>  num;
    if (num > 0)
    {
        for(short count = 1; count <= 10; count++)
            cout << num  << " * " << count << " = " << num * count << endl;
    }
    else cout << "Input number greater than 0 ";

    return 0; 
}