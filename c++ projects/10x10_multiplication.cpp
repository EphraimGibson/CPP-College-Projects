#include <iostream>

using namespace std;

int main()
{
    for(short multi = 1; multi < 11; multi++)
    {
        for(short increase = 1; increase < 11; increase++)
        {
            //cout.width(5);
            cout << increase * multi << "\t";
            if (increase == 10)
            cout << endl;
        }
    }
    return 0;
}