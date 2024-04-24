
/*Write a program to increase the value of variable X bY a factor of 2 and the value of
variable Y bY a factor of 3.*/



#include <iostream>

using namespace std;

int main ()
{
    int X;
    int Y;

    cout << "input value for X: ";
    cin >> X;
    cout << "input value for Y: " ;
    cin >> Y;

    X *= 2;
    Y *= 3;
    cout << "X factor of 2 = " << X << endl;
    cout << "Y factor of 3 = " << Y << endl;

    return 0;
}