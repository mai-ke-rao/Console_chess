#ifndef PIECES_HPP_INCLUDED
#define PIECES_HPP_INCLUDED

#include <ctype.h>
#include <iostream>

using namespace std;

class Pieces {
private:
	bool color;
	char abvr;

public:
	Pieces()
	{
		abvr ='F';
		color = false;
	}
	Pieces(char abbreviation, bool clr) {
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


	void resolver(Pieces(&spaceMatrix)[8][8], char userInput[6])
	{
		if (userInput[1] != 'x')
		{
			int letter = (int)userInput[1] -95;
			//cout << "bare letter" << letter << endl;
			
			cout << "letter number: " << letter << " corresponiding char: " << userInput[1] << endl;
		}
		else
		{
			cout << "eating move" << endl;
		}
	}

};
#endif