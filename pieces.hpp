#ifndef PIECES_HPP_INCLUDED
#define PIECES_HPP_INCLUDED
//RETROFIT PROGRAMM TO NOT EXCEPT COLOR TO BE UNDEFINED
//failed attempt to make function member attribute that is passed to a constructor

#include <ctype.h>
#include <iostream>
#include <functional>
#include<string>
//#include <sahkonzola/sahkonzola.cpp>

using namespace std;


class Pieces {
private:
    bool color;
    char abvr;

    //unhandled exception
  //  Pieces* vacant = new Pieces();
    // I will give up on struct and go wiht induivduak varables

public:/*
    vacantReplica.abvr = "F";
    vacantReplica.color = "false";
*/

    static struct figure {
        char abvr;
        bool color;
    }vacantReplica;

    Pieces()
    {
        abvr = 'F';
        //I will go with color undefined in hope it wont break my code otherwise I will have to downgrade to enum.
        color = false;
    }
    Pieces(char abbreviation, bool clr)
    {
        abvr = abbreviation;
        color = clr;
    }
    char getAbvr()
    {
        return abvr;
    }
    bool getColor()
    {
        return color;
    }

    //this resolver should not take position parametar, but maybe i should keep it since bishop logic is sound
    //bool turn wont do cuz free space aint true nor false?
    void resolver(Pieces(&spaceMatrix)[8][8], string userInput, bool turn, Pieces Piece, int(*position)[2])
    {

        if (false) {
            /*if ((char)userInput[3] != '+' && (char)userInput[1] != 'x' && userInput.size() == 4)
            {
                cout << "case in whitch player had to specifiy which one of the two equivalent pices he decided to move" << userInput << endl;
            }*/

        }
        else { //first I want to check if I can access the pieces attributes using key word this and 
            // if empty field initialization worked
            cout << "inside else";
         char temp = this->abvr; //i dont get it why
            cout << "i was abble to access piece abrv: " << temp << endl;

            //this was for earlier implemenation with position subroutine

            //switch case koji odreduje sve.
            switch (this->abvr) {
            case 'B':
                 BlogicFunc(spaceMatrix, userInput, position, Piece);
                break;
            case ' ':
                cout << "about to call PlogicFunc";
                PlogicFunc(spaceMatrix, userInput, turn, Piece);
                break;
            case 'R':
                cout << "calling rook func " << endl;
                RlogicFunc(spaceMatrix, userInput, position, Piece, turn);
                break;
            case 'N':
                cout << "calling knight func" << endl;
                NlogicFunc(spaceMatrix, userInput, position, Piece, turn);
                    break;
            case 'Q':
                cout << "calling quien logic func" << endl;
                QlogicFunc(spaceMatrix, userInput, position, Piece, turn);
                break;
            case 'K':
                cout << "calling king logic func" << endl;
                KlogicFunc(spaceMatrix, userInput, position, Piece, turn);
                break;
            default:
                cout << "pieces switch case is defaulting";
                break;
            }

        }

    }
   
   /* void Rocade(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece, bool turn)
    {

    }*/
    //king end game check mate shit not implemented yet
    void KlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece, bool turn) {
        cout << position[0][0] << "successful entry 00" << endl;
        cout << position[0][1] << "successful entry 01" << endl;
        //here errors might occur
        cout << position[1][0] << "successful entry 10" << endl;
        cout << position[1][1] << "successful entry 11" << endl;

        int iLetter = position[0][1];
        int iNumber = position[0][0];
        int dLetter;
        int dNumber;
        if (userInput.size() == 3)
        {  //regular move
            cout << "im inside moving func" << endl;
            dLetter = (int)userInput[1] - 'a';
            dNumber = (int)userInput[2] - '0' - 1;
            //to be countinued
        }
        else if (userInput.size() == 4)
        {  //regular eating move
            cout << "im inside eating func" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;
            //to be countinued
        }
        if (abs(iLetter - dLetter) <= 1 && abs(iNumber - dNumber) <= 1)
        {
            if (spaceMatrix[dNumber][dLetter].abvr != 'F' && spaceMatrix[dNumber][dLetter].color == turn)
            {
                cout << "invalid move" << endl;
                return;
            }
            spaceMatrix[dNumber][dLetter] = Piece;

            spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
            spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
            return;
        }
        else {
            cout << "invalid move" << endl;
            return;
        }
    }
    
    //I wont do, two or more quenns cases.
    void QlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece, bool turn) {
        

        int iLetter = position[0][1];
        int iNumber = position[0][0];
        int dLetter;
        int dNumber;

        if (userInput.size() == 3)
        {  //regular move
            cout << "im inside moving func" << endl;
            dLetter = (int)userInput[1] - 'a';
            dNumber = (int)userInput[2] - '0' - 1;
      //to be countinued
        }
        else if (userInput.size() == 4)
        {  //regular eating move
            cout << "im inside eating func" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;
       //to be countinued
         }
        //in case its rook like move we just use rookresolver, simple
        if ((dLetter == iLetter) || (dNumber == iNumber))
        {  //rook resolver comes extra handy
            rookResolver(iNumber, iLetter, dNumber, dLetter, userInput, spaceMatrix, Piece);
        }
        else if (abs(dLetter - iLetter) == abs(dNumber - iNumber))
        {
            int tLetter = iLetter;
            int tNumber = iNumber;
            int sideStep;
            int lineStep;

            // check if all fields are free

            while (tLetter != dLetter)
            {
                int Sdistance = dLetter - iLetter;
                sideStep = Sdistance / abs(Sdistance);
                int Ldistance = dNumber - iNumber;
                lineStep = Ldistance / abs(Ldistance);
                for (int i = 0; i < abs(Sdistance); i++)
                {
                    tLetter += sideStep;
                    tNumber += lineStep;
                    cout << "tnum , tlet: " << tNumber << tLetter << endl;
                    if (spaceMatrix[tNumber][tLetter].getAbvr() != 'F')
                    {
                        if (userInput.size() == 4 && spaceMatrix[iNumber][iLetter].color != spaceMatrix[dNumber][dLetter].color && tNumber == dNumber && tLetter == dLetter)
                        {
                            spaceMatrix[dNumber][dLetter] = Piece;

                            spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                            spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                            cout << userInput << " is success " << endl;
                            return;
                        }
                        cout << "Invalid move" << endl;
                        return;
                    }
                }
                cout << userInput << " is success " << endl;
                spaceMatrix[dNumber][dLetter] = Piece;

                spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                return;
            }

            return;
        }
        else {
            cout << "invalid move" << endl;
        }




    }
    //i didnt do unambigous moves. And I didnt even test it adhoc.
    void NlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece, bool turn)
    {
        
        int iLetter;
        int iNumber;
        int dLetter;
        int dNumber;



        if (userInput.size() == 3)
        {  //regular move
            cout << "im inside moving func" << endl;
            dLetter = (int)userInput[1] - 'a';
            dNumber = (int)userInput[2] - '0' - 1;
        }
        else if (userInput.size() == 4)
        {  //regular eating move
            cout << "im inside eating func" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;
        }
            if ( ((dNumber == position[0][0] + 1  || dNumber == position[0][0] - 1) && (dLetter == position[0][1] - 2 || dLetter == position[0][1] + 2)) || 
                ((dNumber == position[0][0] + 2 || dNumber == position[0][0] - 2) && (dLetter == position[0][1] - 1 || dLetter == position[0][1] + 1)))
            {
                iNumber = position[0][0];
                iLetter = position[0][1];
                cout << userInput << " operation success " << endl;
                if (spaceMatrix[dNumber][dLetter].color == turn && spaceMatrix[dNumber][dLetter].abvr != 'F')
                {
                    cout << "invalid move" <<endl;
                    return;
                }
                
                spaceMatrix[dNumber][dLetter] = Piece;
                spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                return;
            }
            else if (((dNumber == position[1][0] + 1 || dNumber == position[1][0] - 1) && (dLetter == position[1][1] - 2 || dLetter == position[1][1] + 2)) ||
                ((dNumber == position[1][0] + 2 || dNumber == position[1][0] -2) && (dLetter == position[1][1] - 1 || dLetter == position[1][1] + 1)))
            {
                iNumber = position[1][0];
                iLetter = position[1][1];
                cout << userInput << " operation success " << endl;
                if (spaceMatrix[dNumber][dLetter].color == turn && spaceMatrix[dNumber][dLetter].abvr != 'F')
                {
                    cout << "invalid move" << endl;
                    return;
                }

                spaceMatrix[dNumber][dLetter] = Piece;
                spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                return;
            }


        
        else if (userInput.size() == 4 && userInput[1] != 'x')
        {  // unambigues move
            cout << "im ambigues move" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;

        }
      
        else if (userInput.size() == 5)
        {  //unambigues eating move
            cout << "im inside ambigues eating func" << endl;
            dLetter = (int)userInput[3] - 'a';
            dNumber = (int)userInput[4] - '0' - 1;
        }
        //single ining on a rook

    }

    void RlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece, bool turn)
    {
        
        int iLetter;
        int iNumber;
        int dLetter;
        int dNumber;

 

        if (userInput.size() == 3)
        {  //regular move
            cout << "im inside moving func" << endl;
            dLetter = (int)userInput[1] - 'a';
            dNumber = (int)userInput[2] - '0' - 1;
       
            if (dNumber == position[0][0] || dLetter == position[0][1])
            {
                iNumber = position[0][0];
                iLetter = position[0][1];
                rookResolver(iNumber, iLetter, dNumber, dLetter, userInput, spaceMatrix, Piece);

            }
            else if (dNumber == position[1][0] || dLetter == position[1][1])
            {
                iNumber = position[1][0];
                iLetter = position[1][1];
                rookResolver(iNumber, iLetter, dNumber, dLetter, userInput, spaceMatrix, Piece);
            }
       

        }
        else if (userInput.size() == 4 && userInput[1] != 'x')
        {  // unambigues move
            cout << "im ambigues move" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;

        }
        else if (userInput.size() == 4)
        {  //regular eating move
            cout << "im inside eating func" << endl;
            dLetter = (int)userInput[2] - 'a';
            dNumber = (int)userInput[3] - '0' - 1;
            if (dNumber == position[0][0] || dLetter == position[0][1])
            {
                iNumber = position[0][0];
                iLetter = position[0][1];
                rookResolver(iNumber, iLetter, dNumber, dLetter, userInput, spaceMatrix, Piece);

            }
            else if (dNumber == position[1][0] || dLetter == position[1][1])
            {
                iNumber = position[1][0];
                iLetter = position[1][1];
                rookResolver(iNumber, iLetter, dNumber, dLetter, userInput, spaceMatrix, Piece);
            }
           
        }
        else if (userInput.size() == 5)
        {  //unambigues eating move
            cout << "im inside ambigues eating func" << endl;
            dLetter = (int)userInput[3] - 'a';
            dNumber = (int)userInput[4] - '0' - 1;
        }
        //single ining on a rook


    }
    void BlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, int position[2][2], Pieces Piece)
    {
        
        int iLetter;
        int iNumber;
        int dLetter;
        int dNumber;
        //d as in designated, i as in initial, t as in temporary
        if (userInput.size() == 3)
        {
            cout << "im inside blogicfunc" << endl;
             dLetter = (int)userInput[1] - 'a';
             dNumber = (int)userInput[2] - '0' - 1;
        }
        else if (userInput.size() == 4)
        {
            cout << "im inside blogicfunc eating" << endl;
             dLetter = (int)userInput[2] - 'a';
             dNumber = (int)userInput[3] - '0' - 1;
        }
            //this part singles in on a single bishop based on even odd black white coincidence.
            if ((dLetter + dNumber) % 2 == 0)
            {
                cout << "even sum black lane bishop" << endl;
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
                cout << "odd sum white lane bishop" << endl;
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
            
            while (tLetter != dLetter)
            {    
                int Sdistance = dLetter - iLetter;
                sideStep = Sdistance / abs(Sdistance);
                int Ldistance = dNumber - iNumber;
                lineStep = Ldistance / abs(Ldistance);
                for (int i = 0; i < abs(Sdistance); i++)
                {
                    tLetter += sideStep;
                    tNumber += lineStep;
                    cout << "tnum , tlet: " << tNumber << tLetter<<endl;
                    if (spaceMatrix[tNumber][tLetter].getAbvr() != 'F')
                    {
                        if (userInput.size() == 4 && spaceMatrix[iNumber][iLetter].color != spaceMatrix[dNumber][dLetter].color && tNumber == dNumber && tLetter == dLetter)
                        {
                            spaceMatrix[dNumber][dLetter] = Piece;

                                spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                                spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                                cout << userInput << " is success " << endl;
                                return;
                        }
                        cout << "Invalid move" << endl;
                        return;
                    }
                }
                cout << userInput << " is success " << endl;
                spaceMatrix[dNumber][dLetter] = Piece;
               
                spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                return;
            }

            return;

    }
    
    //  pawn abvr is ' '
    void PlogicFunc(Pieces(&spaceMatrix)[8][8], string userInput, bool turn, Pieces Piece)
    {  //QUINN RESCUE AND CUT EAT MOVE SPECIAL CASES NOT RESOLVED
        
        //eating move
        if (userInput.size() > 2)
        {
            userInput[3] -= 1;
            //cout << "spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn check: " << spaceMatrix[(int)userInput[3]][(int)userInput[2]].color != turn << endl;
            if (turn && spaceMatrix[(int)userInput[3] - (int)'0'][(int)userInput[2] - (int)'a'].color != turn && spaceMatrix[(int)userInput[3] - 1 -(int)'0'][(int)userInput[0] - (int)'a'].abvr == ' ')
            {
                spaceMatrix[(int)userInput[3]  - (int)'0'][(int)userInput[2] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[3] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[3] - 1 -  (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout <<"white eating piece color that should be places:  "<<Piece.color;//HERE I WANT TO ADD MOVE COUNTER
                return;

            }
            else if (!turn && spaceMatrix[(int)userInput[3] - (int)'0'][(int)userInput[2] - (int)'a'].color != turn && (spaceMatrix[(int)userInput[3] + 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == ' '))
            {
                spaceMatrix[(int)userInput[3] - (int)'0'][(int)userInput[2] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[3] +1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[3] +1 - (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout << "black eating" << endl;
                return;
            }
            cout << " invalid move ";
            return;
        }
        //moving move
        else
        {
            userInput[1] -= 1;
            //special case (two fields per move) turn true: number 4    turn false: number 5
            if (turn && ((int)userInput[1] - (int)'0') == 3 && spaceMatrix[(int)userInput[1] - 2 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == ' ' && spaceMatrix[(int)userInput[1] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F' && spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F')
            {
                spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[1] - 2 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[1] - 2 - (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout << userInput << "here move counter should be";//HERE I WANT TO ADD MOVE COUNTER
       
            }
            else if (!turn && ((userInput[1] - (int)'0') == 4 && spaceMatrix[(int)userInput[1] + 2 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == ' ') && spaceMatrix[(int)userInput[1] + 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F' && spaceMatrix[(int)userInput[1]-(int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F')
            {
                
                spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[1] + 2 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[1] + 2 - (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout << userInput << endl;
                return;
            }
            else if (turn && spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F' && (spaceMatrix[(int)userInput[1] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == ' '))
            {

                spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[1] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[1] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout << userInput << " ";//HERE I WANT TO ADD MOVE COUNTER
                return;
            }
            else if (!turn && spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'].abvr == 'F' && (spaceMatrix[(int)userInput[1] + 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr == ' '))
            {
                spaceMatrix[(int)userInput[1] - (int)'0'][(int)userInput[0] - (int)'a'] = Piece;
                spaceMatrix[(int)userInput[1] + 1 - (int)'0'][(int)userInput[0] - (int)'a'].abvr = vacantReplica.abvr;
                spaceMatrix[(int)userInput[1] + 1 - (int)'0'][(int)userInput[0] - (int)'a'].color = vacantReplica.color;
                cout << userInput << endl;
                return;

            }
            else {
                cout << " invalid moses: " << endl;
                cout << (int)userInput[1] - (int)'0' << endl;
     
                    cout <<"initial place: "<< spaceMatrix[(int)userInput[1] - 2 - (int)'0'][(int)userInput[0] - (int)'a'].getAbvr() << endl;
                    cout << "turn: "<<turn << endl;
                    cout <<"one step behind "<< spaceMatrix[(int)userInput[1] - 1 - (int)'0'][(int)userInput[0] - (int)'a'].getAbvr() << endl;
                    cout <<"designated place "<< spaceMatrix[(int)userInput[1] - 0 - (int)'0'][(int)userInput[0] - (int)'a'].abvr << endl;
                    
                return;
            }
            return;
        }
    }
	
    void rookResolver(int iNumber, int iLetter, int dNumber, int dLetter, string userInput, Pieces(&spaceMatrix)[8][8], Pieces Piece)
    {
        int difference, direction;
        int tNumber = iNumber;
        int tLetter = iLetter;
        bool numbersCoincide = (iNumber == dNumber);

        difference = numbersCoincide ? dLetter - tLetter :dNumber - tNumber;
        direction = difference / abs(difference);
        while (numbersCoincide ? tLetter != dLetter : tNumber != dNumber)
        {
            numbersCoincide ? tLetter += direction : tNumber += direction;
          
            if (spaceMatrix[tNumber][tLetter].abvr != 'F')
            {
                if (userInput.size() == 4 && spaceMatrix[dNumber][dLetter].color != spaceMatrix[iNumber][iLetter].color && dLetter == tLetter && tNumber == dNumber)
                {
                    cout << userInput << " operation success " << endl;
                    spaceMatrix[dNumber][dLetter] = Piece;
                    spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
                    spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
                }
                //we will see which cases we can and want to include here
                cout << " invalid move " << endl;
                return;
            }
        }
        cout << userInput << " operation success " << endl;
        spaceMatrix[dNumber][dLetter] = Piece;
        spaceMatrix[iNumber][iLetter].abvr = vacantReplica.abvr;
        spaceMatrix[iNumber][iLetter].color = vacantReplica.color;
    }
	

	};



    
#endif

