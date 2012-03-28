#include <iostream>
#include <cstdlib>
using namespace std;

void printboard();
void makemove();
void names();
void next_turn();
int win_check();
bool catsgame();
void whos_turn();
void turn_end_check();
bool play_again();
void reset_values();
void move(int);
bool win_check_bool(int, int, int);

string p_one, p_two;
char empty = ' ';
char token[9];
bool p_one_turn;
string move_input = "--";
int move_count;
bool game_goes_on;

int main()
{
	do{
	reset_values();
	
	names();
		do
		{
			printboard();
			whos_turn();
			makemove();
			turn_end_check();
		}while(game_goes_on == true);
	}
	while(play_again() != false);
}

void reset_values()
{
	for(int i=0; i<=9; i++)
	{
		token[i] = empty;
	}
	move_count = 0;
	p_one_turn = true;
}

bool play_again()
{
	char again;
	cout << "Good Game! Would you like to play again? (Y/N)" << endl;
	cin >> again;
	
	if(again == 'Y' || again == 'y')
	{
		return true;
	}

	return false;
}

void turn_end_check()
{

	if(win_check() == 0)
	{
		move_count++;
		game_goes_on = true;
		next_turn();
	}
	else if (win_check() == 1)
	{
		printboard();
		cout << p_one << " wins in " << move_count << " moves!"
			 <<endl;
		game_goes_on = false;
	}
	else if (win_check() == 2)
	{
		printboard();
		cout << p_two << " wins in " << move_count << " moves!"
			<< endl;
		game_goes_on = false;
	}
	else if(win_check()==3)
	{
		cout << "There are no more available moves!" << endl;
		game_goes_on = false;
	}
	
}

void whos_turn()
{
	if(p_one_turn == true)
	{
		cout << "It is " << p_one << "'s turn" << endl;
	}
	else
	{
		cout << "It is " << p_two << "'s turn" << endl;
	}
}

bool catsgame()
{
	for(int i=0; i<=9; i++)
	{
		if (token[i] == empty)
		{
			return false;
		}
	}
	return true;
}

int winner(int spot)
{

	if (token[spot] == 'X')
	{
		return 1;
	}
//	else if(token[spot] == 'O')
//	{
		return 2;
//	}


}

bool win_check_bool(int first, int second, int third)
{
	return  ((token[first] == token[second])
		&&(token[second]==token[third])
		&&token[first]!=empty);
}

//
//win_check() goes through the board checking for winning combinations.
//It checks to see if the values in a row or column or diagonal are all the
// same, and that they are not equal to used. If it fills this conditions,
// it then checks to see what the values are equal to. If the values are 'X', 
// then it returns 1. If 'O', it returns 2. If it doesn't fill the conditions,
// it returns 0.
//
int win_check()
{
	int who_won;

	if(win_check_bool(0,1,2))
	{
		who_won = winner(0);
	}
	else if(win_check_bool(3,4,5))
	{
		who_won = winner(3);
	}
	else if(win_check_bool(6,7,8))
	{
		who_won = winner(6);
	}
	else if(win_check_bool(0,4,8))
	{
		who_won = winner(0);
	}
	else if(win_check_bool(2,4,6))
	{
		who_won = winner(2);
	}
	else if(win_check_bool(0,3,6))
	{
		who_won = winner(0);
	}
	else if(win_check_bool(1,4,7))
	{
		who_won = winner(1);
	}
	else if(win_check_bool(2,5,8))
	{
		who_won = winner(2);
	}
	else if(catsgame() == true)
	{
		return 3;
	}
	return who_won;
}

//
// next_turn() switches the value of p_on_turn every time it is called.
//
void next_turn()
{
	p_one_turn = !p_one_turn;
}

//
//names() initializes the names of the two players
//
void names()
{
	cout << "What is Player 1's Name?" << endl;
	cin >> p_one;

	cout << "What is Player 2's Name?" << endl;
	cin >> p_two;
	cout << endl;

	cout << "X: " << p_one << "   O: " << p_two << endl;
}

//
// printboard() prints out the board and its current values.
//
void printboard()
{
	cout << endl << endl;
	cout << "    1   2   3  " << endl;
	cout << "  -------------" << endl;
	cout << "A | " << token[0] << " | " << token[1] << " | " << token[2] << " | " << endl;
	cout << "  |---|---|---|" << endl;
	cout << "B | " << token[3] << " | " << token[4] << " | " << token[5] << " | " << endl;
	cout << "  |---|---|---|" << endl;
	cout << "C | " << token[6] << " | " << token[7] << " | " << token[8] << " | " << endl;
	cout << "  -------------" << endl;
}	

//
//makemove() 
//
void makemove()
{
	cout << "Where would you like to move?" << endl;
	cout << "Answer in Coordinates, i.e. A1" << endl;
	cin >> 	move_input;

	if(move_input == "a1" || move_input == "A1")
	{
		move(0);
	}
	else if(move_input == "a2" || move_input == "A2")
	{
		move(1);	
	}
	else if(move_input == "a3" || move_input == "A3")
	{
		move(2);	
	}

	else if(move_input == "b1" || move_input == "B1")
	{
		move(3);	
	}
	else if(move_input == "b2" || move_input == "B2")
	{
		move(4);
	}
	else if(move_input == "b3" || move_input == "B3")
	{
		move(5);
	}
	else if(move_input == "c1" || move_input == "C1")
	{
		move(6);	
	}
	else if(move_input == "c2" || move_input == "C2")
	{
		move(7);	
	}
	else if(move_input == "c3" || move_input == "C3")
	{
		move(8);
	}
	else
	{
		cout << "Sorry, That is not a valid position" << endl;
		makemove();
	}
}

void move(int spot)
{

	if(token[spot] != empty)
	{
		cout << "Sorry, that spot is taken" <<endl;
		makemove();
	}
	else if(p_one_turn == true)
	{
		token[spot] = 'X';
	}
	else if(p_one_turn == false)
	{
		token[spot] = 'O';
	}
}
