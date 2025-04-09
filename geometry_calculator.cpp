/*The coordinates of the vertices of the triangle are given. Calculate
the area and perimeter of the triangle.
Write a function whose input parameters are the coordinates of the
vertices of a triangle and whose output parameters are the area and
perimeter of the triangle.
Function required to return two values!*/


#include <iostream>
#include <cmath>

using namespace std;

void a_pcalculator(double a[2], double b[2], double c[2], double &x, double &y)
{   
    //area
    int j =((a[0]*(b[1]-c[1]))+ (b[0]*(c[1]-a[1])) + (c[0]*(a[1]-b[1])));

    x = 0.5 * abs(j);

    double a2b = sqrt(pow(b[0]-a[0], 2) + pow (b[1]-a[1], 2));
    double b2c = sqrt(pow(c[0]-b[0],2) + pow(c[1]-b[1],2));
    double c2a = sqrt(pow(a[0]-c[0],2) + pow(a[1]-c[1],2));

    y = a2b + b2c + c2a; 
}
int main()
{
    double e[2], f[2], g[2], x,y;

   cout << "enter cordinates of first vertice"<< endl;
   cin >> e[0] >> e[1];

    cout << "enter cordinates of second vertice"<< endl;
   cin >> f[0] >> f[1];

    cout << "enter cordinates of third vertice"<< endl;
   cin >> g[0] >> g[1];

   a_pcalculator(e,f,g,x,y );

   cout << "Area is: " << x << endl << "Perimeter is:  " << y << endl;

}