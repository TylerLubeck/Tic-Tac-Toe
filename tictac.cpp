#include <iostream>
using namespace std;
void printboard();
void makemove();
void names();
void next_turn();
int win_check();

string p_one, p_two;
char token[9] = {'?', '?', '?', '?', '?', '?', '?', '?', '?'};
bool p_one_turn = true;
string move_input = "--";
int move_count = 0;
int main()
{
	names();
	while(1)
	{
		printboard();
		makemove();
		if(win_check() == 0)
		{
			cerr << "win_check == 0" << endl;
			move_count++;
			next_turn();
		}
		else if (win_check() == 1)
		{
			printboard();
			cout << p_one << " wins in " << move_count << " moves!"
				 <<endl;
			break;
		}
		else if (win_check() == 2)
		{
			printboard();
			cout << p_two << " wins in " << move_count << " moves!"
				<< endl;
			break;
		}
	}
}

int win_check()
{
	if((token[0] == token[1])&& (token[1] == token[2])&& token[0] != '?')
	{
		if (token[0] == 'X')
		{
			return 1;
		}
		else if(token[0] == 'O')
		{
			return 2;
		}
	}

	else if((token[3] == token[4])&& (token[4] == token[5])&&token[3]!= '?')
	{
		if (token[3] == 'X')
		{
			return 1;
		}
		else if(token[3] == 'O')
		{
			return 2;
		}
	}

	else if((token[6] == token[7])&& (token[7] == token[8])&&token[6]!='?')
	{
		if (token[6] == 'X')
		{
			return 1;
		}
		else if(token[6] == 'O')
		{
			return 2;
		}
	}

	else if((token[0] == token[4])&& (token[4] == token[8])&&token[0]!='?')
	{
		if (token[0] == 'X')
		{
			return 1;
		}
		else if(token[0] == 'O')
		{
			return 2;
		}
	}

	else if((token[2] == token[4])&& (token[4] == token[6])&&token[2]!='?')
	{
		if (token[2] == 'X')
		{
			return 1;
		}
		else if(token[2] == 'O')
		{
			return 2;
		}
	}
	
	else if((token[0] == token[3])&& (token[3] == token[6])&&token[0]!='?')
	{
		if (token[0] == 'X')
		{
			return 1;
		}
		else if(token[0] == 'O')
		{
			return 2;
		}
	}

	else if((token[1] == token[4])&& (token[4] == token[7])&&token[1]!='?')
	{
		if (token[1] == 'X')
		{
			return 1;
		}
		else if(token[1] == 'O')
		{
			return 2;
		}
	}

	else if((token[2] == token[5])&& (token[5] == token[8])&&token[2]!='?')
	{
		if (token[2] == 'X')
		{
			return 1;
		}
		else if(token[2] == 'O')
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
}

void next_turn()
{
	if(p_one_turn == false)
		{p_one_turn = true;}
	else if(p_one_turn == true)
		{p_one_turn = false;}
}

void names()
{
	cout << "What is Player 1's Name?" << endl;
	cin >> p_one;

	cout << "What is Player 2's Name?" << endl;
	cin >> p_two;
	cout << endl;

	cout << "X: " << p_one << "   O: " << p_two << endl;
}

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

void makemove()
{
	cout << "Where would you like to move?" << endl;
	cout << "Answer in Coordinates, i.e. A1" << endl;
	cin >> 	move_input;

	if(move_input == "a1" || move_input == "A1")
	{
		if(token[0] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		else if(p_one_turn == true)
		{
			token[0] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[0] = 'O';
		}
	}


	else if(move_input == "a2" || move_input == "A2")
	{
		
		if(token[1] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		else if(p_one_turn == true)
		{
			token[1] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[1] = 'O';
		}
	}

	else if(move_input == "a3" || move_input == "A3")
	{
		
		if(token[2] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		else if(p_one_turn == true)
		{
			token[2] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[2] = 'O';
		}
	}


	else if(move_input == "b1" || move_input == "B1")
	{
		
		if(token[3] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		else if(p_one_turn == true)
		{
			token[3] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[3] = 'O';
		}
	}


	else if(move_input == "b2" || move_input == "B2")
	{
		if(token[4] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		else if(p_one_turn == true)
		{
			token[4] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[4] = 'O';
		}
	}


	else if(move_input == "b3" || move_input == "B3")
	{
		if(token[5] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		if(p_one_turn == true)
		{
			token[5] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[5] = 'O';
		}
	}


	else if(move_input == "c1" || move_input == "C1")
	{
	
		if(token[6] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		if(p_one_turn == true)
		{
			token[6] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[6] = 'O';
		}
	}


	else if(move_input == "c2" || move_input == "C2")
	{
	
		if(token[7] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		if(p_one_turn == true)
		{
			token[7] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[7] = 'O';
		}
	}


	else if(move_input == "c3" || move_input == "C3")
	{

		if(token[8] != '?')
		{
			cout << "Sorry, that spot is taken" <<endl;
			makemove();
		}
		if(p_one_turn == true)
		{
			token[8] = 'X';
		}
		else if(p_one_turn == false)
		{
			token[8] = 'O';
		}
	}
	else
	{
		cout << "Sorry, That is not a valid position" << endl;
		makemove();
	}
}
