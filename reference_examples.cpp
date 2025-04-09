#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
// "constants" used in program
/** SETTINGS **/
#define ARRAY 20
#define MAX_VALUE 5
#define MIN_VALUE 0

/** main "program" (actually it is main function :) **/
int main()
{
  srand(time(NULL)); // initialise random number generator
  int arr[ARRAY]; // create array
  clog << "Array has "<< ARRAY << " elements." << endl;
  clog << "Generated array:"<< endl;
  for(short i = 0; i<ARRAY; i++)
  { // generate random value on desired range
    arr[i] = MIN_VALUE + rand()%(MAX_VALUE-MIN_VALUE+1);
    clog << arr[i] << '\t';
  }
  clog << endl;

  cout << "Enter number: ";
  int n;
  cin >> n;
  unsigned found = 0; // counter variable
  cout << "\nNumbers in an array that are greater than " << n << endl;
  for(short i = 0; i<ARRAY; i++)
  {
    if(arr[i] > n) // looking for values that are greater than given number n
    {
      cout << arr[i] << '\t';
      found++; // increase counter
    }
  }
  cout << endl;
  cout << "There is " << found << " elements in array that are greater than " << n << endl;
  return 0;
}


#include <iostream>
using namespace std;

#define signPC 'X'
#define signUSR 'O'
#define EMPTY ' '

char field[3][3];

// Additional function that helps to decide where to move 
/** INCOMPLETE **/
bool whereTo(char symbol, int &x, int &y) // returns false if there is no move to make
{
  bool haveCoordinates=false;
  /**********ATTACK/DEFENSE**********/
  // top left [0][0]
  if(field[0][1]==symbol && field[0][2]==symbol ||
     field[1][0]==symbol && field[2][0]==symbol ||
     field[1][1]==symbol && field[2][2]==symbol
     ){ x=0; y=0; haveCoordinates=true;}
  else //  top middle [0][1]
  if(field[0][0]==symbol && field[0][2]==symbol ||
     field[1][1]==symbol && field[2][1]==symbol){ x=0; y=0; haveCoordinates=true;}
  else
  // top right [0][2]
  if(field[0][0]==symbol && field[0][1]==symbol ||
     field[1][1]==symbol && field[2][0]==symbol ||
     field[1][2]==symbol && field[2][2]==symbol
     ){ x=0; y=0; haveCoordinates=true;}
  
  /// CONTINUE ....
  return haveCoordinates;
}

// main function that returns PC's decision
bool pcMove(int &x, int &y){ // returns false if there is no move to make
  bool haveCoordinates=false;
  // check for wining (attack)
  if(whereTo(signPC, x, y))
    haveCoordinates = true;
  else
  // check for defense
  if(whereTo(signUSR, x, y))
    haveCoordinates = true;
  else
  // take center
  if(field[1][1] == EMPTY ){
      x=1; y=1;
      haveCoordinates=true;
  }
  else
  // take corner
  if(field[0][0]==EMPTY || // check if there is empty corner
     field[0][2]==EMPTY ||
     field[2][0]==EMPTY ||
     field[2][2]==EMPTY){
     do{
      int cornerN = rand()%4;
      switch(cornerN){
      case 0:
        x = 0; y = 0; break;
      case 1:
        x = 2; y = 0; break;
      case 2:
        x = 0; y = 2; break;
      case 3:
        x = 2; y = 2; break;
      }
    }while( field[y][x] != EMPTY );
    haveCoordinates=true;
  }
  else
  // any other (not corner)
  if(field[0][1]==EMPTY || // check if there is empty corner
       field[1][0]==EMPTY ||
       field[1][2]==EMPTY ||
       field[2][1]==EMPTY){
        do{
          int cornerN = rand()%4;
          switch(cornerN){
          case 0:
            x = 1; y = 0; break;
          case 1:
            x = 0; y = 1; break;
          case 2:
            x = 2; y = 1; break;
          case 3:
            x = 1; y = 2; break;
          }
        }while( field[y][x] != EMPTY );
        haveCoordinates=true;
      }
   return haveCoordinates; 
}

int main()
{
  return 0;
}

#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>

using namespace std;

#define PL1 'X'
#define PL2 'O'
#define EMPTY 32

char field[3][3];
int mainMenu();
void gameOn();

int main()
{
    cout << "\n\t\tTIC-TAC-TOE\n";

    char toDo;

    do
    { 
        toDo = mainMenu(); 

    switch(toDo)
    {
        case 1:
            system("clear");
            gameOn();
            return 0;
        case 9:
            system("clear");
            cout << "\tGoodBye!!" << endl;
            break;
        default:
            system("clear");;
            cout << "\n\t\tTIC-TAC-TOE\n";
            cout<< "\ninvalid selection. select 1 to start or 9 to end game";
        
    }
    }
    while (toDo != 9);
    return 0;
}

int mainMenu()                          // returns users selection as number(1-play,9-quit)
{
    string selection;
    cout << "\n\tchoose selection\n" << endl;
    cout << "\t1. Start Game" << endl;
    cout << "\t9. End Game" << endl << "==> ";
    cin >>    selection;

    if (selection.length() != 1)
        return 2;
    if (selection[0] == '1' )
    return 1;
    else if (selection[0] == '9')
    return 9;
    return 0;
}

//functions for GAME-PLAY

void CoordinateBoard()
{
    char cordinatefield[3][3];    
    int i,j;
    for (i = 0; i < 3; i++)
    {
        cout << "-------------\n";
        for (j = 0; j < 3; j++)
        {
            cout << "|" << i << "," << j;
        }
        if (j == 3)
        cout << "|\n";
    }
    cout << "-------------\n";
}

void ClearGameField() // this displays a new game field 
{
    cout << " \n\t\tNew game\n"; 
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            field[i][j] = EMPTY;
            cout << field[i][j];
            cout << "  |";
        }
        if (i < 2)
        cout << "\n--------------\n";
    }
}

bool isUserStartsFirst() // checks if user wants to start 
{
    string option;
    
    do 
    {
        cout << "\nDo you want to start? (Y/N): ";
         cin >> option;
            if (option.length() != 1)
                cout << "Invalid selection. Please enter 'Y' or 'N'.\n";  
            else if (!(option[0] == 'Y' || option[0] == 'y' || option[0] == 'N' || option[0] == 'n')) 
                cout << "Invalid selection. Please enter 'Y' or 'N'.\n";                // making sure for only yes or no answer
            else 
                break;
    }
    while(true);
    return (option[0] == 'Y' || option[0] == 'y');
}

bool checkIfGamecancontinue() 
{
    int i,j;
    for (i = 0; i < 3; i++ )  // loops through the whole array
    {
        for (j = 0; j < 3; j++)
        {
            if (field[i][j] == EMPTY)
            return true;
        }
    }
    return false;
}

bool check4Win()
{
    for (short i = 0; i < 3; i++)
    {
        
        if(field[i][0] == field[i][1] && field[i][1] == field[i][2]  && field[i][1] != EMPTY)
        // checking rows
            return true; 
         else if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[2][i] != EMPTY )
           // checking columns
            return true;
    }
    if ((field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[1][1] != EMPTY) || // checking for diagonals
        (field[2][0] == field[1][1] && field[1][1] == field[0][2] && field[1][1] != EMPTY))
        return true; 
    return false;
}

bool CanPcWin(char PCcharacter)
{
    for (short i = 1; i < 3; i++)
    {
        if (field[i][0] == PCcharacter && field[i][1] == PCcharacter && field[i][2] == EMPTY)   // checking rows to win for pc
        {
            field[i][2] = PCcharacter;
            return true;
        }
        if (field[i][2] ==PCcharacter && field[i][1] == PCcharacter && field[i][0] == EMPTY)  // checking rows from right-side to win for pc
        {
            field[i][0] = PCcharacter;
            return true;
        }  
        if (field[2][i] == PCcharacter && field[1][i] == PCcharacter && field[0][i] == EMPTY)  // checking columns to win for pc
        {
            field[0][i] = PCcharacter;
            return true;
        }  
        if (field[0][i] == PCcharacter && field[1][i] == PCcharacter && field[2][i] == EMPTY)  // checking columns top-side to win for pc
        {
            field[2][i] = PCcharacter;
            return true;
        }  
        if (field[i][0] == PCcharacter && field[i][2] == PCcharacter && field[i][1] == EMPTY )     // checking rows for pc-win by securing the middle of two characters
        {
            field[i][1] = PCcharacter;
            return true;
        }
        if (field[0][i] == PCcharacter && field[2][i] == PCcharacter && field[1][i] == EMPTY) // checking columns for pc-win by playing middle
        {
            field[1][i] = PCcharacter;
            return true;
        }  
    }
    return false;
}

bool ComputerDefense(char character)
{
    for (short i = 0; i < 3; i++)
    {
        if ((field[i][0] == field[i][1] && field[i][1] != EMPTY ) && field[i][2] == EMPTY)   // checking rows to counter player
        {
            if (CanPcWin(character))
                return true;
            else 
            {
                field[i][2] = character;
                return true;
            }
        }
        if (field[i][2] == field[i][1] && field[i][1] != EMPTY && field[i][0] == EMPTY)     // checking rows from right-side to counter player
        {
            if (CanPcWin(character))
                return true;
            else
            {
                field[i][0] = character;
                return true;
            }
        }
        if (field[0][i] == field[1][i] && field[1][i] != EMPTY  && field[2][i] == EMPTY)  // checking columns to counter player
        {
            if (CanPcWin(character))
                return true;
            else
            {
                field[2][i] = character;
                return true;
            }
        }  
        if (field[2][i] == field[1][i] && field[1][i] != EMPTY  && field[0][i] == EMPTY) // checking columns from end of columns to counter player
        {
            if (CanPcWin(character))
                return true;
            else
            {
                field[0][i] = character;
                return true;
            }
        }  
        if ((field[i][0] == field[i][2] && field[i][2] != EMPTY) && field[i][1] == EMPTY )     // checking rows to counter player by securing the middle of two characters
        {
            if (CanPcWin(character))
                return true;
            else
            {
                field[i][1] = character;
                return true;
            }
        }
        if (field[0][i] == field[2][i] && field[2][i] != EMPTY  && field[1][i] == EMPTY) // checking columns to counter player by playing middle
        {
            field[1][i] = character;
            return true;
        }  
    }
    if (field[0][0] == field[1][1] && field[1][1] != EMPTY && field[2][2] == EMPTY) //checking diagonal from top left to counter player
        {
            field[2][2] = character;
            return true;
        }
    if (field[2][0] == field[1][1] && field[1][1] != EMPTY && field[0][2] == EMPTY) //checking diagonal from bottom left to counter player
        {
            field[0][2] = character;
            return true;
        }
    if (field[2][2] == field[1][1] && field[1][1] != EMPTY && field[0][0] == EMPTY) //checking diagonal from bottom right to counter player
        {
            field[0][0] = character;
            return true;
        }
    if (field[0][2] == field[1][1] && field[1][1] != EMPTY && field[2][0] == EMPTY) //checking diagonal from top right to counter player
        {
            field[2][0] = character;
            return true;
        }
    if (field[0][0] == field[2][2] && field[2][2] != EMPTY && field[1][1] == EMPTY) //checking diagonal from top left to secure middle to counter player
        {
            field[1][1] = character;
            return true;
        }
    if (field[2][0] == field[0][2] && field[0][2] != EMPTY && field[1][1] == EMPTY) //checking diagonal from bottom left to secure middle to counter player
        {
            field[1][1] = character;
            return true;
        }
    if ((field[0][0] != EMPTY || field[2][0] != EMPTY || field[2][2] != EMPTY || field[0][2] != EMPTY) && field[1][1] == EMPTY) // secures the centre for a double attack from user
        {
            field[1][1] = character;
            return true;
        }
    if ((field[1][1] != EMPTY && field[1][1] != character) && (field[0][0] == EMPTY || field[0][2] == EMPTY || field[2][0] == EMPTY || field[2][2] == EMPTY)) // counters possible user strategy, when user starts from centre
        {
            if (field[0][0] == EMPTY)
                field[0][0] = character;
            else if(field[0][2] == EMPTY)
                field[0][2] = character;
            else if (field[2][0] == EMPTY)
                field[2][0] = character;
            else
                field[2][2] = character;
            return true;
        }
if (field[0][0] != EMPTY && field[1][1] == character && field[1][2] == EMPTY) // counter possible user strategy involving corners of the board
        {
            field[1][2] = character;
            return true;
        }
    if (field[0][2] != EMPTY && field[1][1] == character && field[1][0] == EMPTY )
        {
            field[1][0] = character;
            return true;
        }
    if (field[2][0] != EMPTY && field[1][1] == character && field[0][1] == EMPTY)
        {
            field[0][1] = character;
            return true;
        }
    if (field[2][2] != EMPTY && field[1][1] == character && field[1][0] == EMPTY)
        {
            field[1][0] = character;
            return true;
        }
    if (field[0][0] == character && field[2][2] == character && (field[2][0] == EMPTY || field[0][2] == EMPTY) ) // tries to get a double win for computer by securing three corners
        {
            if (field[2][0] == EMPTY)
                field[2][0] = character;
            else if (field[0][2] == EMPTY)
                field[0][2] = character;
                return true;
        }
     if (field[0][2] == character && field[2][0] == character && (field[0][0] == EMPTY || field[2][2] == EMPTY) ) // tries to get a double win for computer by securing three corners
        {
            if (field[0][0] == EMPTY)
                field[0][0] = character;
            else if (field[2][2] == EMPTY)
                field[2][2] = character;
                return true;
        }  
    return false; 
}
    
void moveUser(short playeroption)
{
  
    string row, col;

   char playerIs; // variable to store character if player is X or O
    
    do
    {
        if( playeroption != 1)              //Checks if user selected to start or not
        {
            playerIs = PL2;

        }
        else
            playerIs = PL1;

       
    do {
        cout << "Player " << playerIs << ", Enter your position for your move: " << endl;
        cout << "Row:  ";
        cin >> row;

        if (row.length() != 1)
            cout << "Invalid input; enter number from 0 - 2 for rows-axis" << endl << endl;
        else if (row[0] < '0' || row[0] > '2')
            cout << "Invalid input; enter number from 0 - 2 for rows-axis" << endl << endl;
        else
            break;
    } while (true);
    do {
        cout << "Column:  ";
        cin >> col;

        if (col.length() != 1) 
            cout << "Invalid input; enter number from 0 - 2 for column-axis" << endl << endl;
        else if (col[0] < '0' || col[0] > '2')
            cout << "Invalid input; enter number from 0 - 2 for column-axis" << endl << endl;
        else
            break;
    } while (true);
        int ROW = row[0] - 48;
        int COL = col[0] - 48;

        if (field[ROW][COL] == EMPTY)
        {
            if(!(check4Win()))
            system("clear");
            field[ROW][COL] = playerIs;
            break;
        }
         if (field[ROW][COL] != EMPTY)
            cout << "You cannot play there\n" << endl;
    } 
    while (true);
        
}

void movePC(short playeroption)
{
    unsigned short min = 0;
    unsigned short max = 2;
    short i,j;
    char ComputerIs;        // variable to store character if computer is X or O
    
    if (playeroption != 1)                          //Checks if user selected to start or not
        ComputerIs = PL1;
    else
        ComputerIs = PL2;

    srand(time(NULL));
    do
    {
        i = min + rand() % (max - min + 1);
        j = min + rand() % (max - min + 1);

           if (ComputerDefense(ComputerIs))
            {
                break;
            }

            else if ( field[i][j] == EMPTY)
            {         
                field[i][j] = ComputerIs;
                break;
            }
        
    }
    while (true);
}

void animate() // fullstop animaition
{
    cout << endl;
    for (short x = 0; x < 5; x++)
    {
        
        cout << '.';
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300)); 
    }
    cout <<  "........." << endl << endl;
}

void displayField() 
{
     for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout <<  field[i][j];
            cout << " | ";
        }
        if (i < 2)
        cout << "\n------------\n";
    }
    cout << endl;
}

void gameOn()
{
    short whoStarts = 0;            // helps when the user chooses to starts or not.

    ClearGameField();
    bool userStarts = isUserStartsFirst();    
    if(userStarts) 
    {
        system("clear");
        CoordinateBoard();
        do
        {
            whoStarts = 1;             // intialized to 1 because user chose to start
            moveUser(whoStarts);
            displayField();
            if (!(checkIfGamecancontinue()))
            {
                cout << endl << "It is a Draw!" << endl;
                return;
            }
                if (check4Win())
                {
                    cout << "\nYOU WIN!";
                    return;
                }
            movePC(whoStarts);
            animate();
            displayField();
                if (check4Win())
                {
                    cout << "\nYOU LOST!";
                    return;
                }
        }
        while (checkIfGamecancontinue());  
    }
    else
    {
        do
        {
                whoStarts = 0;
                movePC(whoStarts);
                animate();
                displayField();
                if (check4Win())
                {
                        cout << "\nYOU LOST!";
                        return;
                }
                if (checkIfGamecancontinue())
                {
                    moveUser(whoStarts);
                    displayField();
                    if (check4Win())
                    {
                        cout << "\nYOU WIN!";
                        return;
                    }
                }
        }
        while (checkIfGamecancontinue());
    }
    if (!(checkIfGamecancontinue()))
        cout << endl << "It is a Draw!" << endl;
}

