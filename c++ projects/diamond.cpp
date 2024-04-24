#include <iostream>

using namespace std;

int main ()
{
    short num;
    short flag = 1;

// TOP OF DIAMOND
    cout << " input an odd number: ", cin >> num;
    if (num % 2 != 0)
    {
        for(short lines = 1; lines <= num; lines++)
    {
        for(short stars = 1; stars <= 2 * lines-1; stars++)
        {
            if (flag == 1)
                cout.width(num - lines+1);
                
                cout << "*" ;
                flag = 0;
        }
        flag = 1;
        cout << endl;   
    }
        //BOTTOM OF DIAMOND
         for(short lines = num-1; lines > 0; lines--)
    {
        for(short stars = 1; stars <= 2 * lines-1; stars++)
        {
            if (flag == 1)
                cout.width(num - lines+1);

                cout << "*" ;
                flag = 0;
        }
        flag = 1;
        cout << endl;   
    }
    }
    else
    cout << "Unable to form a diamond with this number.\nPlease input odd number. ";

    return 0;
}