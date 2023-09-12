//META: findpiece is in cpp, logic func is in hpp.
// sahkonzola.cpp : This file contains the 'main' function. Program execution begins and ends there.
//PASS PIECE SPECIFIC FUNCTIONS AS OBJECT ATTRIBUTES SO YOU EVADE ADDITIONAL SWITCH CASE STATEMENT
#include "pieces.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
bool white = true;
typedef int(*array2x2)[2];


void BlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{
    int iLetter;
    int iNumber;

    if (userInput.size() == 3)
    {
        char dLetter = (char)userInput[1];
        char dNumber = (char)userInput[2];

        //this part singles in on a single bishop based on even odd black white coincidence.
        if ((dLetter + dNumber) % 2 == 0)
        {
            if ((position[0][0] + position[0][1]) % 2 == 0)
            {
                iNumber = position[0][0];
                iLetter = position[0][1];
            }
            else
            {
                iNumber = position[1][0];
                iLetter = position[1][1];
            }
        }
        else {
            if ((position[0][0] + position[0][1]) % 2 == 0)
            {
                iNumber = position[1][0];
                iLetter = position[1][1];
            }
            else
            {
                iNumber = position[0][0];
                iLetter = position[0][1];
            }
        }
        int tLetter = iLetter;
        int tNumber = iNumber;
        int sideStep;
        int lineStep;

        // check if all fields are free

        while (tLetter = !dLetter)
        {
            int Sdistance = dLetter - iLetter;
            sideStep = Sdistance / abs(Sdistance);
            int Ldistance = dNumber - iNumber;
            lineStep = Ldistance / abs(Ldistance);
            for (int i = 0; i < abs(Sdistance); i++)
            {
                tLetter += sideStep;
                tNumber += lineStep;
                if (spaceMatrix[tNumber][tLetter].getAbvr() != 'F')
                {
                    cout << "Invalid move" << endl;
                    return;
                }
            }
            cout << userInput << endl;

        }

        return;


    }

}
void PlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, bool turn)  //I NEED TURN VARIABLE 
//SPECIAL CASE QUEEN RESCUE HAS NOT BEEN INTRODUCED
{
    //eating move
    if (userInput.size() > 2)
    {
        //cout << "spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn check: " << spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn << endl;
        if (spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn && (spaceMatrix[(int)userInput[0]][(int)userInput[2] - 1].abvr = ' ' && turn)
        {
            spaceMatrix[(int)userInput[3]][(int)userInput[2]] = pawn;
                spaceMatrix[(int)userInput[0]][(int)userInput[2] - 1] = vacant;
                cout << userInput << " ";//HERE I WANT TO ADD MOVE COUNTER
                return;

        }
        else if (spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn && (spaceMatrix[(int)userInput[0]][(int)userInput[2] + 1].abvr = ' ' && !turn)
        {
            spaceMatrix[(int)userInput[3]][(int)userInput[2]] = pawnB;
                spaceMatrix[(int)userInput[0]][(int)userInput[2] + 1] = vacant;
                cout << userInput << endl;
                return;
        }
    }
    //moving move
    else
    {
        //special case turn true: number 4    turn false: number 5
        if (userInput[1] == 4 && spaceMatrix[(int)userInput[1] - 2][(int)userInput[0]].abvr == ' ' && turn && spaceMatrix[(int)userInput[1] - 1][(int)userInput[0]].abvr == 'F' && spaceMatrix[(int)userInput[1]][(int)userInput[0]].abvr == 'F')
        {
            spaceMatrix[(int)userInput[1]][(int)userInput[0]] = pawn;
            spaceMatrix[(int)userInput[1] - 2][(int)userInput[0]] = vacant;
            cout << userInput << " ";//HERE I WANT TO ADD MOVE COUNTER
            return;
        }
        else if ((userInput[1] == 5 && spaceMatrix[(int)userInput[1] + 2][(int)userInput[0]].abvr == ' ' && !turn && spaceMatrix[(int)userInput[1] + 1][(int)userInput[0]].abvr == 'F' && spaceMatrix[(int)userInput[1]][(int)userInput[0]].abvr == 'F')
        {
            spaceMatrix[(int)userInput[1]][(int)userInput[0]] = pawnB;
                spaceMatrix[(int)userInput[1] + 2][(int)userInput[0]] = vacant;
                cout << userInput << endl;
                return;
        }
        else if (spaceMatrix[(int)userInput[1]][(int)userInput[0]].abvr == 'F' && (spaceMatrix[(int)userInput[1] - 1][(int)userInput[0]].abvr == ' ' && turn)
        {

            spaceMatrix[(int)userInput[1]][(int)userInput[0]] = pawn;
                spaceMatrix[(int)userInput[1] - 1][(int)userInput[0]] = vacant;
                cout << userInput << " ";//HERE I WANT TO ADD MOVE COUNTER
                return;
        }
        else if (spaceMatrix[(int)userInput[1]][(int)userInput[0]].abvr == 'F' && (spaceMatrix[(int)userInput[1] + 1][(int)userInput[0]].abvr == ' ' && !turn)
        {
            spaceMatrix[(int)userInput[1]][(int)userInput[0]] = pawnB;
                spaceMatrix[(int)userInput[1] + 1][(int)userInput[0]] = vacant;
                cout << userInput << endl;
                return;

        }
        else {
            cout << "invl move" << endl;
                return;
        }
    }
}

//all of this functions should reside inside pieces.hpp

void KLogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{
    
}
void NlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{

}
// difference between int(*arrayName)[2] and int(&arrayName)[2][2]

void QlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{

}
void RlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{

}
void OKlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{

}
void OQlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2])
{

}

//THIS FUNCTION IS NOT OPTMISED, you should search for piece based on user move choice. Same logic functions defined in pieces.hpp 
//with modification of trying to find its origin position.
array2x2 findPiece(string userIn, bool turn, Pieces(&spaceMatrix)[8][8])
{
    char abvr = userIn[0];
    //two for two pieces and two for letters and numbers
    int position[2][2] = { -1 };
    //pawn positions
    int accum = 0;
    if (abvr == 'B') {
        for (int i = 0; i < 8; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (spaceMatrix[x][i].getAbvr() == abvr && spaceMatrix[x][i].getColor() == turn)
                {
                    int temp[2] = { x, i };
                    memcpy(position[accum], temp, sizeof(temp));
                    if (accum == 1)
                    {
                        return position;
                    }
                    accum++;


                }
            }
        }
    }
    else
    {
        //switch case abvr and use piece specific pinpointing algorithm
    }
    return position;
}
//WHAT I WANT IS MATRIX OF PIECES AND THEN JUST MANIPULATE THEM

     // desna brojka je slovo, a leva broj. Beli imaju 0 i 1 a crni 6 i 7 pozicije
int main()
{
    Pieces pawn(' ', true), rook('R', true), bishop('B', true), knight('N', true), king('K', true), queen('Q', true);
    Pieces pawnB(' ', false), rookB('R', false), bishopB('B', false), knightB('N', false), kingB('K', false), queenB('Q', false);
    Pieces vacant;

    // 
       // desna brojka je slovo, a leva broj. Beli imaju 0 i 1 a crni 6 i 7 pozicije
    Pieces spaceMatrix[8][8] = {};
    string userInput;
    array2x2 position;
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

    
   
    if (white)
    {
        cout << "white turn: ";
        cin >> userInput;
        cout << endl << userInput << " : This was user input" << endl;
       
        cout << "user input length: " << userInput.size() << endl;

        cout << "this is inital setup space matrix:" << endl;

        cout<<"field check: "<< endl;

        for (int i = 0; i < 8; i++)
        {
            for (int x = 0; x < 8; x++)
            {
                cout << spaceMatrix[i][x].getAbvr()<<" "<< spaceMatrix[i][x].getColor()<< endl;

            }
        }

        //non pawn move.
        if (isupper(userInput[0]))
        {
            //make here some digests for resolver functions.
            switch (userInput[0])
            {
            case 'N':
                //function for knight
                
                 position = findPiece(userInput, white, spaceMatrix);

                knight.resolver(spaceMatrix, userInput, position);
                break;
            case 'B':
               position = findPiece(userInput, white, spaceMatrix);
                //function for bishop
                bishop.resolver(spaceMatrix, userInput, position);
                break;
            case 'Q':
                 position = findPiece(userInput, white, spaceMatrix);
                //function for queen
                queen.resolver(spaceMatrix, userInput, position);
                break;
            case 'K':
                 position = findPiece(userInput, white, spaceMatrix);
                //function for king
                king.resolver(spaceMatrix, userInput, position);
                break;
            case 'R':
                 position = findPiece(userInput, white, spaceMatrix);
                //function for rook
                rook.resolver(spaceMatrix, userInput, position);
                break;
            case 'O':
                 position = findPiece(userInput, white, spaceMatrix);
                //rockades
            default:
                cout << "piece type is defaulting" << endl;
                break;
            }
        }
        else //its a pawn move
        {
            pawn.resolver(spaceMatrix, userInput, white)
        }
    }
}
