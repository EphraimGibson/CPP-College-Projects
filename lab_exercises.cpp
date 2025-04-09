#include <iostream>

using namespace std;

class Shoes
{
    string sneaker, name;
    int size, stock, quantity;
    
    public:

    Shoes()
    {
        cout << "    Default constructor called" << endl;

        sneaker = 0.0f;
        name =  0.0f;
        size = 0.0f;
        quantity = 0.0f;
        stock = 0.0f;

        cout << "No selection made\n" << "\nSneaker: " << sneaker 
        
        << "\nName:" << name << "\nsize: " << size << "\nquantity: " << quantity << "\nstock: " << stock << endl << endl;

    }

    Shoes(string Sneakertype, string Shoppersname, int shopperssize , int shoppersquantity)
    {
        cout << " constructor with parameters called" << endl;

        sneaker = Sneakertype;
        name =  Shoppersname;
        size = shopperssize;
        quantity = shoppersquantity;
        stock = 15;
    }

    void AnythingElse(string NewSneakertype)
    {
        cout << "yes! We have " << NewSneakertype << endl << endl;
                sneaker = NewSneakertype;

    }

   Shoes(const Shoes &s)
    {
        cout << "    Copy constructor called" << endl;

        sneaker = s.sneaker;
        name = s.name;
        size = s.size;
        quantity = s.quantity;
        stock = s.stock - 1;
    }

    bool CheckInventory()
    {

        if (size == 44 || size == 43 || size == 45 || size == 42 )
        {
            cout << "\nWe have that size in stock" << endl << endl << endl;
            stock -=1;
            return true;
        }
        else 
        {
                cout << "We do not have that size in stock" << endl << endl;
            return false;
        }
    }

    void print()
    {
        cout << name << " requested for " << sneaker << ", size: " << size << ", " << quantity << "pieces" << endl << endl;

        cout << "stock:" <<  stock << endl ;
    }
};


int main ()
{
    Shoes S1;

    Shoes S2("Air force", "Lush", 44 , 2);
    S2.print();
    
    
    if (!S2.CheckInventory())
  
    {
        string need;
        cout << "what do you want: "; cin >> need;

        S2.AnythingElse(need);
    }

    Shoes S3 = S2;
    S3.print();
       
return 0;

}