#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream info;
    int i = 0,j = 0;
    int number;
    int numbers[i][j];
    int *I;
    int *J;


    info.open("2D_data.txt");
    if (info.fail()) cout << "no available file with that name";
    
    while (!info.eof())
    {
       info >> number;
       if (number == '\n')
       i = 2;
       if (number == ' ') 
       j = 3;


      // numbers[i][j] = number;
    }
    cout << i << j;
    

    return 0;
}