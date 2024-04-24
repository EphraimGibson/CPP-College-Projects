/*The clock shows h hours and m minutes. Write a program to calculate how many
minutes and how many seconds have passed since midnight.
Analysis of the task:
The input data for a program are the variables h and m, the output data are the variables
min and sec. What is their data type?
How do I find the values min, sec? Algorithm:
Inputting the initial data: How many hours and minutes does the clock show? Enter the
values of h and m.
Calculate how many minutes have passed since midnight:
min = h * 60 + m.
Calculate how many seconds have passed since midnight. There are two ways to do this:
sec = min * 60 (or sec = h * 3600 + m * 60)
The results are displayed on the screen in cout sentences*/

#include <iostream>

using namespace std;

void time_past_midnight(int h, int m)
{
    int min = h * 60 + m;
    int sec = h * 3600 + m * 60;

    cout << min << " minutes have passed since midnight" << endl << "That is" << endl;
    cout << sec << " seconds " << endl << "Thank you, Enjoy the rest of your hours :-)";
}

int main ()
{
    int h;
    int m;

    cout << "Please enter the current hour(s) and minutes on the 24-hour clock separated by a space : " << endl ;
    cin >> h >> m;
    if ((h >= 0 && h <= 24 ) && (m <= 60))
    {
         time_past_midnight (h, m);
    }
    else
    cout << "Invalid hours or minutes :-( ! Kindly write time according to the 24-hour clock, Please run program again" ;
   
    return 0;
}
