#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream data;
    ofstream result;

    data.open("rand.txt");
    result.open("resultfile.txt");
    if(data.fail()) cout << "File not found!" << endl;
    else
    {
        int number,evens;
        
        while(!data.eof())
        {
            data >> number;

            if (number % 2 == 0)
            result << number << endl;
        }
    }
    data.close(); result.close();
    return 0;
}