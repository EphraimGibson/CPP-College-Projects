/*
Create a menu that allows you to select and execute following "programs".
1.The program informs whether the entered number is positive or negative.
2.The age of the person is entered (as a integer number). The program identifies the age group, e.g. 0-10 - child, 11-17 - teenager, 18-25 - young person, 26-...(120?) - adult.
3.Three positive integers are entered. The program should inform whether it is possible to form a triangle with the lengths of the sides being the numbers entered. 
If it is possible, it should provide information on whether the triangle is equilateral, isosceles or scalene triangle (see wiki), and the area of the triangle.
Wiki: Triangle
4.A rectangle/triangle area calculator: the program "asks" for the area of the triangle or rectangle the user wants to calculate, then it asks:
In the case of a rectangle, enter the lengths of the sides, followed by the result;
In the case of a triangle, enter the lengths of the three sides, followed by the r
5.We want to check in which quarter of the coordinate plane (or coordinate axis) a point (x, y) is located. Write a program to solve this problem.
Upload main.cpp with program code.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char selected;

    cout << "            PROGRAM MENU       " << endl;
    cout << "1. Positive or Negative number analyser." << endl;
    cout << "2. Age group identifier." << endl;
    cout << "3. Triangle Checker." << endl;
    cout << "4. Area of shape calculator" << endl;
    cout << "5. Quadrant Checker. " << endl;
    cout << "6/Q/X: Quit. " << endl;
    cout << endl << "enter number of desired program: " ;
    cin >>  selected;

    switch (selected)
    {
        case '1':
        {
            int num;

            cout << "enter number: ";
            cin >> num;
            if (num < 0)
                cout << "number is negative" ;
            else 
                cout << "number is positive" ; 
        }
        break;

        case '2':
        {
            int age;

            cout << "Enter your age: ";
            cin >>  age;
			if (age <= 0)
				cout << "Your age is invalid. ";
			else if (age > 0 && age <= 10)
				cout << "You are a child. ";
			else if (age >= 11 && age <= 17)
				cout << "You are a teenager. ";
			else if (age >= 18 && age <= 25)
				cout << "You are a Young person. ";
			else if (age >= 26 && age <= 120)
				cout << "You are an Adult. ";
			else
			    cout << "CONGRATULATIONS!! " << endl << "You have lived very long! " ;

        }
        break;

        case '3':
        {
            double a, b, c;
			
			cout << "enter three positive integers below " << endl;
            
            cout << " enter length of first side: " ;
            cin >> a ;
            cout << " enter length of second side: " ;
            cin >> b ;
            cout << " enter length of third side: " ;
            cin >> c ;

            if(a < b + c && b < a + c && c < b + a  && a > 0 && b > 0 && c > 0)
            {
                if( a == b && b == c )
                     cout << " triangle is equilateral" << endl;
                else if  (a == b || b == c || c == a)
                     cout << " triangle is isosceles " << endl;
                else
                    cout << "triangle is scalene" << endl;
    
                // formula for area with all lengths: Area (A) = sqrt(s * (s - a) * (s - b) * (s - c)), where s is the semi- perimeter.
               // formula for semi-perimeter: s = (a + b + c) / 2.

                double s, A;

                s = (a + b + c) / 2;
                A = sqrt(s * (s - a) * (s - b) * (s - c));
                cout << "Area of the triangle : " << A ;
            }
            else 
                cout << "Triangle not possible with given lengths";
        }
        break;

        case '4':
        {
            char shape;

            cout << "Which shape do you want to find area for?" << endl << "1. Rectangle " << endl << "2. Triangle " << endl << "==> ";
            cin >>  shape ;

            switch (shape)
            {
                case '1' :
                {
                    double length, width, Area ;

                    cout << "enter length of rectangle: ";
                    cin >> length;
                    cout << "enter width of rectangle: ";
                    cin >> width;
                    if (length >= 0 && width >= 0)
                    {
                        // Area of rectangle = Length * Width
                        Area = length * width;
                        cout << "The Area of the rectangle is: " << Area ;
                    }
                    else
                    cout << "A rectangle cannot have negative sides, Please enter a positive number." ;
                }
                break;
                case '2':
                {   
                    double a, b, c;

                    cout << " enter length of first side: " ;
                    cin >> a ;
                    cout <<" enter length of second side: " ;
                    cin >> b ;
                    cout << " enter length of third side: " ;
                    cin >> c ;

                    if( (a < b + c && b < a + c && c < b + a ) && (a > 0 && b > 0 && c > 0))
                    {
                        double s, A;
        				
						s = (a + b + c) / 2;
                       	A = sqrt(s * (s - a) * (s - b) * (s - c));
                        	cout << "Area of the triangle is : " << A ;
                    }
                    else 
                    	cout << "invalid lengths for triangle";
                }
                break;
                default:
                cout << "Invalid input. Enter 1 or 2 to make a selection.";
            }
        }
        break;

        case '5':
        {
			int x, y;

            cout << "We are checking for the quadrant of the point (x,y) in the standard Cartesian coordinate system." << endl ;
			cout << "Please enter Value for x: " ; cin >> x ;
			cout << "Please enter value for y: " ; cin >> y ;

			if (x == 0 && y == 0)
				cout << "The point (0, 0) is at the origin of the Cartesian coordinate system";
			else if (x == 0 && y != 0)
				cout << "The point is on the y-axis at y = " << y;
			else if (x != 0 && y == 0)
				cout << "The point is on the x-axis at x = " << x;
			else if (x > 0 && y > 0)
				cout << "The point (" << x << ", " << y << ") is located in Quadrant I"; 
			else if (x < 0 && y > 0)
				cout << "The point (" << x << ", " << y << ") is located in Quadrant II";
			else if (x < 0 && y < 0)
				cout << "The point (" << x << ", " << y << ") is located in Quadrant III";
			else
				cout << "The point (" << x << ", " << y << ") is located in Quadrant IV";
        }
        break;

        case 'o':
        case 'O':
        case 'X':
        case 'x':
        case 'Q':
        case 'q':{return 0;}
            break;

        default:
        cout << "Invalid selection. Please enter a number between 1 and 5" << endl;
    }
    return 0;
}