// desna brojka je slovo, a leva broj. Beli imaju 0 i 1 a crni 6 i 7 pozicije
// turn: 1 (white) , turn: 0 (black)

//(PASS PIECE SPECIFIC FUNCTIONS AS OBJECT ATTRIBUTES SO YOU EVADE ADDITIONAL SWITCH CASE STATEMENT)
#include "pieces.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
bool white = true;
typedef int(*array2x2)[2];



void findPiece(string userIn, bool turn, Pieces(&spaceMatrix)[8][8], int position[2][2])
{
    cout << "cccchanges" << endl;
    char abvr = userIn[0];

    int accum = 0;
    
        for (int i = 0; i < 8; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (spaceMatrix[x][i].getAbvr() == abvr && spaceMatrix[x][i].getColor() == turn)
                {
                   // int temp[2] = { x, i };
                    position[accum][0] = x;
                    position[accum][1] = i;
                    //memcpy(position[accum], temp, sizeof(temp));
                    if (accum == 1)
                    {
                        cout << position[0][0] <<"successful entry 00" << endl;
                        cout << position[0][1] << "successful entry 01" << endl;
                        cout << position[1][0] << "successful entry 10" << endl;
                        cout << position[1][1] << "successful entry 11" << endl;
                        return;// position;
                    }
                    accum++;


                }
            }
        }
        return;
}
//WHAT I WANT IS MATRIX OF PIECES AND THEN JUST MANIPULATE THEM

     // desna brojka je slovo, a leva broj. Beli imaju 0 i 1 a crni 6 i 7 pozicije
int main()
{
  
    Pieces pawn(' ', true), rook('R', true), bishop('B', true), knight('N', true), king('K', true), queen('Q', true);
    Pieces pawnB(' ', false), rookB('R', false), bishopB('B', false), knightB('N', false), kingB('K', false), queenB('Q', false);
    Pieces vacant;
    Pieces dummy('O', false);

    // 
       // desna brojka je slovo, a leva broj. Beli imaju 0 i 1 a crni 6 i 7 pozicije
    Pieces spaceMatrix[8][8] = {};
    string userInput;
    //array2x2 position;
    int position[2][2];
    int mockPosition[2][2] = { -1 };
    //position calculation subroutine
 
    
    //INITIAL OCCUPATION
    

    //white pieces occupation


        for (int i = 0; i < 2; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (i == 1)
                {
                    spaceMatrix[i][x] = pawn;
                }
                else
                {
                    if (x == 0 || x == 7)
                    {
                        spaceMatrix[i][x] = rook;
                    }
                    else if (x == 1 || x == 6)
                    {
                        spaceMatrix[i][x] = knight;
                    }
                    else if (x == 2 || x == 5)
                    {
                        spaceMatrix[i][x] = bishop;
                    }
                    else if (x == 3)
                    {
                        spaceMatrix[i][x] = queen;
                    }
                    else
                    {
                        spaceMatrix[i][x] = king;
                    }
                }
            }
        }


        //empty spacces occupation
        for (int i = 2; i < 6; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                spaceMatrix[i][x] = vacant;
            }
        }

        //black pieces occupation 
        for (int i = 6; i < 8; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (i == 6)
                {
                    spaceMatrix[i][x] = pawnB;
                }
                else {
                    if (x == 0 || x == 7)
                    {
                        spaceMatrix[i][x] = rookB;
                    }
                    else if (x == 1 || x == 6)
                    {
                        spaceMatrix[i][x] = knightB;
                    }
                    else if (x == 2 || x == 5)
                    {
                        spaceMatrix[i][x] = bishopB;
                    }
                    else if (x == 3)
                    {
                        spaceMatrix[i][x] = queenB;
                    }
                    else {
                        spaceMatrix[i][x] = kingB;
                    }
                }
            }
        }

    
   
    while (userInput != "END")
    {
        bool whiteWon = true; //king apsence is assumed unless proven otherwise
        bool blackWon = true;
       
        cout << "field check: " << endl;
        cout << "  A  B  C  D  E  F  G  H" << endl;
        cout << "___________________________" << endl;
        for (int i = 7; i > -1; i--)
        {
            cout << i + 1<<"|";
            for (int x = 0; x < 8; x++)
            {
                cout << spaceMatrix[i][x].getAbvr() << spaceMatrix[i][x].getColor() << "|";
                if (spaceMatrix[i][x].getAbvr() == 'K')
                {
                    spaceMatrix[i][x].getColor() ? blackWon = false : whiteWon = false;
                }

            }
            cout <<i+1<< endl;
            cout << "____________________________" << endl;
        }
       
        cout << "  A  B  C  D  E  F  G  H" << endl;
        cout << " turn " << white << ": ";
        cin >> userInput;
        

            if (isupper(userInput[0]))
            {
                //make here some digests for resolver functions.
                switch (userInput[0])
                {
                case 'N':
                    //function for knight

                    findPiece(userInput, white, spaceMatrix, position);
                    if (white)
                    {
                        knight.resolver(spaceMatrix, userInput, white, knight, position);
              
                    }
                    else {
                        knightB.resolver(spaceMatrix, userInput, white, knightB, position);
                    }
                 //   knight.resolver(spaceMatrix, userInput, white, knight);
                    white = (!white);
                    break;
                case 'B':
                  findPiece(userInput, white, spaceMatrix, position);
                    //function for bishop
                    if (white)
                    {
                        bishop.resolver(spaceMatrix, userInput, white, bishop, position);
                        white = (!white);
                    }
                    else {
                        bishopB.resolver(spaceMatrix, userInput, white, bishopB, position);
                        white = (!white);
                    }
                    break;
                case 'Q':
                    findPiece(userInput, white, spaceMatrix, position);
                    //function for queen
                    if(white)
                    {
                     
                        queen.resolver(spaceMatrix, userInput, white, queen, position);

                    }
                    else {
                        queenB.resolver(spaceMatrix, userInput, white, queenB, position);
                    }
                    white = (!white);
                    break;
                case 'K':
                    findPiece(userInput, white, spaceMatrix, position);
                    //function for king
                    if (white)
                    {
                        king.resolver(spaceMatrix, userInput, white, king, position);
                    }
                    else
                    {
                        kingB.resolver(spaceMatrix, userInput, white, kingB, position);
                    }
                   // king.resolver(spaceMatrix, userInput, white, king);
                    white = (!white);
                    break;
                case 'R':
                    findPiece(userInput, white, spaceMatrix, position);
                    //function for rook
                    if (white) {
                        rook.resolver(spaceMatrix, userInput, white, rook, position);
                        white = (!white);
                    }
                    else {
                        rookB.resolver(spaceMatrix, userInput, white, rookB, position);
                        white = (!white);
                    }
                    break;
              /*  case 'O':
                    string tranzit = "R";
                    findPiece(tranzit, white, spaceMatrix, position);
                    if (white)
                    {
                        dummy()
                   }
                    //rockades
                    break;
                    */
                default:
                    cout << "wrong entry" << endl;
                    white = (!white);
                    break;
                }
            }
            else //its a pawn move
            {
                cout << "pawn move" << endl;
                if (white)
                {
                    pawn.resolver(spaceMatrix, userInput, white, pawn, mockPosition);
                }
                else {
                    pawnB.resolver(spaceMatrix, userInput, white, pawnB, mockPosition);
                }
                   bool temp = !white;  //compiler throws an exception
                 white = temp;
            }
        
    }
}
