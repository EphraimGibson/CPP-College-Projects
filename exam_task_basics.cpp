#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    
    char letters[5] = {'a', 'b', 'e', 'd', 'i'}; //constant array

    ofstream writeresult("results.txt"); // Open new file to write results

    int counter = 1; //

    for (int a = 0; a < 5; ++a)  // using nested loops to iterate through array
    {
        for (int b  = 0; b < 5; ++b)
        {
                for (int c = 0; c < 5; ++c) 
                    {
                        if (a != b && b != c && a != c) // comparing the three letter words to avoid repeat
                        {
                             cout << counter << ". " << letters[a] << letters[b] << letters[c] << endl;  // Output three letter words to screen

                            writeresult << counter << ". " << letters[a] << letters[b] << letters[c] << endl; // write result in result file

                            ++counter;
                        }
                    }
        }
    }
        writeresult.close(); // closes the newly opened result file

    return 0;
}