
#include <iostream>

using namespace std;

int main()
{
    int num = 1, next = 1, count = 1,result;

    while (count <= 100 )
    {
        if (num == 1)

            cout << count << "   " ;
        else
        {
            result = num * next; 
            cout << result << "   " ;
        }
        if (next == 10)
        {
            cout << endl;
            num++;
            next = 0;
        }
        count++;
        next++;
    }
    return 0;
}