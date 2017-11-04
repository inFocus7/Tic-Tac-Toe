//Tic tac toe lab.  Topics:  2D arrays, classes.
#include <iostream>
using namespace std;
// Part 1
//Implement the following specifications for a tic tac toe game object:

class tictactoeGame
{
public:

	char boardConfig[3][3];   // two dimensional array stores current board configuration    

							  // Constructor:
							  // set  boardConfig[i][j] to be ' ' (the space character)
							  // for 0<= i <= 2, 0<= j <= 2   
	tictactoeGame() {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				boardConfig[i][j] = ' ';
			}
		}
	}

	//put an 'X' character at the given location          
	bool placeX(int x, int y) {
		boardConfig[x][y] = 'X';
		return true;
	}

	//put an 'O' character at the given location         
	bool placeO(int x, int y) {
		boardConfig[x][y] = 'O';
		return true;
	}

	//set all positions to character ' '.
	void clear() {
		tictactoeGame();
	};

	// Return true if there are 3 'X' marks placed in a single
	// column, row, or diagnol.  Return false otherwise.
	bool xWins() {
		bool xwin = false;
		for (int i = 0; i < 3; i++)
		{
			if (boardConfig[i][0] == 'X' && boardConfig[i][1] == 'X' && boardConfig[i][2] == 'X')
				xwin = true;
			if (boardConfig[0][i] == 'X' && boardConfig[1][i] == 'X' && boardConfig[2][i] == 'X')
				xwin = true;
			if (boardConfig[0][0] == 'X' && boardConfig[1][1] == 'X' && boardConfig[2][2] == 'X')
				xwin = true;
			if (boardConfig[2][0] == 'X' && boardConfig[1][1] == 'X' && boardConfig[0][2] == 'X')
				xwin = true;
		}
		return xwin;
	}

	// Return true if there are 3 'O' marks placed in a single
	// column, row, or diagnol.  Return false otherwise.      
	bool oWins() {
		bool owin = false;
		for (int i = 0; i < 3; i++)
		{
			if (boardConfig[i][0] == 'O' && boardConfig[i][1] == 'O' && boardConfig[i][2] == 'O')
				owin = true;
			if (boardConfig[0][i] == 'O' && boardConfig[1][i] == 'O' && boardConfig[2][i] == 'O')
				owin = true;
			if (boardConfig[0][0] == 'O' && boardConfig[1][1] == 'O' && boardConfig[2][2] == 'O')
				owin = true;
			if (boardConfig[2][0] == 'O' && boardConfig[1][1] == 'O' && boardConfig[0][2] == 'O')
				owin = true;
		}
		return owin;
	}

	// Return true if there are either 3 'X' marks or 3 'O' marks
	// placed in a single column, row, or diagnol, or if the board is full.
	// Return false otherwise.
	bool gameOver() {
		if (oWins() == true || xWins() == true)
			return true;
		else
			return false;
	}

	// cout a nice looking picture of the board configuration 
	void display() {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << boardConfig[i][j];
				if(j == 1 || j == 0)
					cout << "|";
			}
			cout << endl;
			if (i == 1 || i == 0)
				cout << "-----" << endl;
		}
	}

	//MY ADDITION.
	bool badPlacement(int i, int j) {
		if (boardConfig[i][j] == 'X' || boardConfig[i][j] == 'O')
			return true;
		else if (i < 0 || i > 2 || j < 0 || j > 2)
			return true;
		else
			return false;
	}


};


//Here is an example main program to give an idea how the above class is supposed to work.
/*
int main()
{
	tictactoeGame mygame;

	mygame.placeX(1, 1);
	mygame.placeO(2, 1);
	mygame.placeX(0, 2);
	mygame.placeO(2, 2);

	mygame.display();



	return 0;
}

This should display something like:
   |   | X
-----------
   | X |
-----------
   | O | O
*/

// Part 2
//Once you have implemented the tictactoeGame class, write a main program that uses a tictactoeGame to implement a game in which two players (you and a friend) take turns placing X’s and O’s onto the board.  After each turn, the current board configuration should be displayed, and once a player connects three of a kind, the game should end declaring that player the winner.
int main()
{
	bool ending, badplacement = false;
	int moves = 9;
	int xmove, ymove;
	tictactoeGame multiplay;
	do {
		ending = false;
		for (int i = 0; i < moves; i++)
		{
			if (i % 2 == 0)
			{
				cout << "Player One [X]: ";
				cin >> xmove >> ymove;
				if (multiplay.badPlacement(xmove, ymove) == true)
				{
					do {
						cout << "Placement Error. Something Is Probably Already There Or You Are Out Of Bounds." << endl;
						cout << "Player One [X]: ";
						cin >> xmove >> ymove;
					} while (multiplay.badPlacement(xmove, ymove) == true);
				}
				multiplay.placeX(xmove, ymove);
			}
			else
			{
				cout << "Player Two [O]: ";
				cin >> xmove >> ymove;
				if (multiplay.badPlacement(xmove, ymove) == true)
				{
					do {
						cout << "Placement Error. Something Is Already There Or You Are Out Of Bounds." << endl;
						cout << "Player Two [O]: ";
						cin >> xmove >> ymove;
					} while (multiplay.badPlacement(xmove, ymove) == true);
				}
				multiplay.placeO(xmove, ymove);
			}
			system("cls");
			multiplay.display();

			//check wins
			if (multiplay.xWins() == true)
			{
				cout << "X WON!" << endl;
				ending = true;
				return 0;
			}
			else if (multiplay.oWins() == true)
			{
				cout << "O WON!" << endl;
				ending = true;
				return 0;
			}
			else if ((i+1) == moves)
			{
				cout << "IT'S A TIE!" << endl;
				ending = true;
				return 0;
			}
		}
	} while(ending != true); //when it is over, then stops

	return 0;
}