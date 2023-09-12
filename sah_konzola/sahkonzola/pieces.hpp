#ifndef PIECES_HPP_INCLUDED
#define PIECES_HPP_INCLUDED

//failed attempt to make function member attribute that is passed to a constructor

#include <ctype.h>
#include <iostream>
#include <functional>
//#include <sahkonzola/sahkonzola.cpp>
using namespace std;
//Pawn logic work great without positionsfinder. maybe other are good too

class Pieces {
private:
	bool color;
	char abvr;
	//ovde samo trebas tipove da napises a ne znam koji mi je tip refernca na spacematrix

public:
	Pieces()
	{
		abvr = 'F';
		//I will go with color undefined in hope it wont break my code otherwise I will have to downgrade to enum.
		//color = false;
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
	// ako je potez bez jedenja onda samo proveiti da li su polja free, 
	// ako je potez sa jedenjem onda proveriti da li ima protivnik figuru tu izvrsiti funkciju i 
	//dodati figuru u listu pojedenih
	/**/

	// possible additional input: transformed user input to int.
	// possible subroutine: generic function that locates fields with desired piece. 

	//this function is called on already know type of piece.
    //knowledge of position is still debated. Initial idea was to first call .cpp's findpieces and then pass it here but it might be uneccessary
	void resolver(Pieces(&spaceMatrix)[8][8], string userInput, int(*position)[2] = 0x7ffdc94b6e5c, bool turn)
	{
		// 
		// case in whitch player had to specifiy which one of the two equivalent pices he decided to move.
		if ((char)userInput[3] != '+' && (char)userInput[1] != 'x' && userInput.size() == 4)
		{
			cout << "player specified which pieces will be used for move" << userInput << endl;
		}
		else { //first I want to check if I can access the pieces attributes using key word this and 
			// if empty field initialization worked
			char temp = this->abvr; //i dont get it why
			cout << "i was abble to access piece abrv: " << temp << endl;
			cout << "available pieces are at positions (N:L) " << endl;
			for (int i = 0; i < 2; i++)
			{
				int number = position[i][0];
				int letter = position[i][1];


				cout << number << ":" << letter << endl;

				//check if move is possible (piece specific)
				//if possible do it  if not iterate one more if again not possible return wrong move.
			}

			//switch case koji odreduje sve.
			switch (this->abvr) {
			case 'B':
				BlogicFunc(spaceMatrix, userInput, position);
				break;
			case ' ':
				PlogicFunc(spaceMatrix, userInput, turn);
			default:
				cout << "pieces switch case is defaulting";
				break;
			}

		}
	}

	};



#endif
};  
