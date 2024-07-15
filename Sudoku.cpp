#include<fstream>
#include<iostream>
#include<time.h>
#include<windows.h>
#include<string>

using namespace std;
int val;
int visual = 19;

char file1[10] = { "Save1.txt" };
char file2[10] = { "Save2.txt" };
char file3[10] = { "Save3.txt" };
bool ar_edit[9][9];
void line(int c)
{
	HANDLE line_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(line_color, c);
}
void mainmenu()
{
	line(3);
	cout << "\t\t\t\t\t\t**********" << endl << endl;
	cout << "\t\t\t\t\t\t**SUDOKU**" << endl << endl;
	cout << "\t\t\t\t\t\t**********" << endl << endl;

}
void instructions()
{
	system("cls");
	line(14);
	cout << "\t\t\t\t\tINSTRUCTIONS" << endl << endl << endl << endl;
	cout << "1- A number must be from 1 to 9. " << endl << endl;
	cout << "2- No number should repeat itself in any Column or Row or particular 3 by 3 Box/Matrix" << endl << endl;
	cout << "3- For quitting the game type -1 " << endl << endl;
	cout << "4- For saving the game press 0 " << endl << endl;
	Sleep(5000);
}
//char inttochar(int val)
//{
	//char x = val + 35;
	//return *x;
//}

int gen_number()
{

	int temp = ((rand() % 9) + 1);
	return temp;
}
bool rowcheck(int arr[9][9], int row, int val)
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == val)
		{
			return false;
		}
	}
	return true;
}
bool matcheck(int arr[9][9], int x, int y, int val)
{
	x = (x / 3) * 3;
	y = (y / 3) * 3;
	int i = 0;
	int j = 0;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			if (arr[x + i][y + j] == val)
			{
				return false;
			}
		}
	}
	return true;
}
bool colcheck(int arr[9][9], int col, int val)
{
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		if (arr[i][col] == val)
		{
			return false;
		}
	}
	return true;
}
void win(int ar[9][9], bool ar_edit[9][9]);
void dataarr(int ar[9][9], bool aredit[9][9])
{
	bool status = true;
	int i, j;
	for (int k = 0; k <= visual; k++)
	{
		Sleep(1);
		do
		{
			i = gen_number() - 1;
		} while (i < 0 || i>9);
		Sleep(1);
		do
		{
			j = gen_number() - 1;
		} while (j < 0 || j>9);
		do
		{
			val = gen_number();

		} while ((rowcheck(ar, i, val) == false) || (colcheck(ar, j, val) == false) || (matcheck(ar, i, j, val) == false));
		if (ar[i][j] == 0)
		{
			//inttochar(val);
			ar[i][j] = val;
			aredit[i][j] = false;

		}
		else
		{
			continue;
		}
	}
}

void sudokugrid(int ar[9][9])
{
	for (int i = 0; i <= 8; i++)
	{
		if (i == 0)
		{
			for (int a = 0; a <= 8; a++)
			{
				if (a == 0)
				{
					
					cout << "  ";
				}

				cout << "   ";
			}
			cout << endl;
			cout << "                              ";
			line(10);
			cout << " -------------------------------------------" << endl;
		}
		if (i == 3 || i == 6)
		{
			cout << "                              ";
			line(10);
			cout << " -------------------------------------------";
			cout << endl;

		}
		for (int j = 0; j <= 8; j++)
		{
			if (j == 0)
			{
				cout << "                              ";
				line(1);
				cout << " | ";
			}
			if (j == 3 || j == 6 || j == 9)
			{
				line(1);
				cout << " | ";
			}
			if (ar[i][j] == 0) 
			{
				line(4);
				cout << "#";
			}
			else
			{
				line(14);
				cout << ar[i][j];
			}
			line(1);
			cout << " | ";

		}
		cout << endl;
		cout << "                              ";
		line(10);
		cout << " -------------------------------------------" << endl;
	}
}
bool search(int ar[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ar[i][i] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void quit()
{
	system("cls");
	cout << endl << endl << endl << endl;
	line(14);
	cout << "\t\t\tSEE YOU NEXT TIME :) " << endl;
	Sleep(6000);
}
void savegame(char file[], int ar[9][9])
{
	ofstream fw;
	fw.open(file);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fw << ar[i][j] << " ";
		}
	}
	fw.close();
}
void loadgame(char file[], int ar[9][9])
{
	ifstream fr;
	fr.open(file);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fr >> ar[i][j];

		}
	}
	fr.close();
}
void inputgrid(int ar[][9], bool aredit[9][9]);
void pause(char file1[10], char file2[10], char file3[10], int ar[][9])
{
	char input;
	line(3);
	cout << "TO SAVE AND THEN QUIT THE GAME---> PRESS S" << endl << endl;
	cout << "TO QUIT THE GAME---> PRESS Q" << endl << endl;
	cout << "TO RETURN BACK TO GAME---> PRESS R" << endl;
	do
	{
		cin >> input;
		if (input != 's' && input != 'S' && input != 'Q' && input != 'q' && input != 'r' && input != 'R')
		{
			line(4);
			cout << "INVALID INPUT..INPUT AGAIN!!" << endl;
		}
	} while (input != 's' && input != 'S' && input != 'Q' && input != 'q' && input != 'r' && input != 'R');
	if (input == 'q' || input == 'Q')
	{
		quit();
	}
	else if (input == 's' || input == 'S')
	{
		line(9);
		cout << "SELECT THE SLOT TO SAVE YOUR FILE" << endl;
		cout << "a- Save1 " << endl << "b- Save2 " << endl << "c- Save3 " << endl;
		do
		{
			cin >> input;
			if (input != 'A'&& input != 'a'&& input != 'B'&& input != 'b'&& input != 'C'&& input != 'c')
			{
				line(4);
				cout << "INVALID SLOT" << endl;
			}
		} while (input != 'A'&& input != 'a'&& input != 'B'&& input != 'b'&& input != 'C'&& input != 'c');
		if (input == 'a' || input == 'A')
		{
			savegame(file1, ar);
		}
		else if (input == 'b' || input == 'B')
		{
			savegame(file2, ar);
		}
		else if (input == 'c' || input == 'C')
		{
			savegame(file3, ar);
		}
	}
	else if (input == 'r' || input == 'R')
	{
		inputgrid(ar, ar_edit);
	}
}
void inputgrid(int ar[][9], bool aredit[9][9])
{
	int row;
	int col;
	int num;
	char res;

	do
	{
		line(3);
		cout << "To pause-->Press P" << endl;
		cout << "To continue-->Press C" << endl;
		do
		{
			cin >> res;
			if (res != 'c' && res != 'C' && res != 'P' && res != 'p')
			{
				line(4);
	           cout << "Invalid input!!" << endl;
			}
		} while (res != 'c' && res != 'C' && res != 'P' && res != 'p');
		if (res == 'p' || res == 'P')
		{
			pause(file1, file2, file3, ar);
			break;
		}
		cout << "Enter the row in which you want to input no. : " << endl;
		bool status = false;
		do
		{
			cin >> row;
			status = cin.fail();
			if (status)
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
			{
				status = true;
			}
			if (row <= 0 || row >= 10)
			{
				line(4);
				cout << "Invalid....Please enter valid number. " << endl;
			}

		} while (row <= 0 || row >= 10);
		cout << "Enter the column in which you want to input no. : " << endl;
		do
		{
			cin >> col;
			status = cin.fail();
			if (status)
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
			{
				status = true;
			}
			if (col <= 0 || col >= 10)
			{
				line(4);
				cout << "Invalid....Please enter valid number. " << endl;
			}

		} while (col <= 0 || col >= 10);

		cout << "Enter the number : " << endl;
		do
		{
			cin >> num;
			status = cin.fail();
			if (status)
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
			{
				status = true;
			}
			if (num <= 0 || num >= 10)
			{
				line(4);
				cout << "Invalid....Please enter valid number. " << endl;
			}
		} while (num <= 0 || num >= 10);
		system("cls");
		if (rowcheck(ar, row - 1, num) == false || (colcheck(ar, col - 1, num) == false || matcheck(ar, row - 1, col - 1, num) == false))
		{
			cout << endl;
			line(4);
			cout << "Number already present in row " << row << endl;
		}
		else if (aredit[row - 1][col - 1] == true)
		{
			ar[row - 1][col - 1] = num;
		}
		else
		{
			line(4);
			cout << "You cannot change the value already generated." << endl;
		}

		sudokugrid(ar);
	} while (search(ar) == false);
	win(ar, aredit);
}

void aredit(bool ar_edit[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			ar_edit[i][j] = true;
		}
	}
}
void win(int ar[9][9], bool ar_edit[9][9])
{
	char input;
	if (search(ar) == true)
	{
		line(14);
		cout << endl << endl << "CONGRATULATIONS-----YOU WON " << endl;
	}
	line(3);
	cout<< endl << endl;
	cout << "TO QUIT THE GAME -->PRESS Q " << endl;
	do
	{
		cin >> input;
		if (input != 's'&&input != 'S'&&input != 'Q'&&input != 'q')
		{
			line(4);
			cout << "INVALID ENTRY" << endl;
		}
	} while (input != 's'&&input != 'S'&&input != 'q'&&input != 'Q');

    if (input == 'q' || input == 'Q')
	{
		quit();
	}
}
int main()
{
	system("cls");
	srand(time(NULL));
	int ar[9][9] = { 0 };
	aredit(ar_edit);
	mainmenu();
	char option;
	char file;

	cout << "A- Start Game" << endl << endl << "B- Load Game" << endl << endl << "C- Instructions " << endl << endl << "D- Quit Game";
	cout << "\n\nPRESS :" << endl;

	do
	{
		cin >> option;
		if ((option == 'a') || (option == 'A') || (option == 'b') || (option == 'B') || (option == 'c') || (option == 'C') || (option == 'd') || (option == 'D'))
		{
			break;
		}
		else
		{
			line(4);
			cout << "INVALID ENTRY.....PLEASE ENTER CORRECT OPTION. " << endl;
		}

	} while ((option != 'a') || (option != 'A') || (option != 'b') || (option != 'B') || (option != 'c') || (option != 'C') || (option != 'd') || (option != 'D'));
	if (option == 'a' || option == 'A')
	{
		dataarr(ar, ar_edit);
		system("cls");
		mainmenu();
		cout << endl << endl;
		line(2);
		cout << "1- For pausing the game press P before the start of every input for game." << endl;
		cout << "2- To save the game at any point first pause the game." << endl;
		cout << "3- For quitting the game type first pause the game.  " << endl;
	}
	else if (option == 'b' || option == 'B')
	{
		line(9);
		cout << "Please Select a Slot : " << endl;
		cout << "a- Save1 " << endl << "b- Save2 " << endl << "c- Save3 " << endl;
		do
		{
			cin >> file;
			if (file != 'A'&&file != 'a'&&file != 'B'&&file != 'b'&&file != 'C'&&file != 'c')
			{
				line(4);
				cout << "INVALID SLOT" << endl;
			}
		} while (file != 'A'&&file != 'a'&&file != 'B'&&file != 'b'&&file != 'C'&&file != 'c');
		if (file == 'a' || file == 'A')
		{
			loadgame(file1, ar);
		}
		else if (file == 'b' || file == 'B')
		{
			loadgame(file2, ar);
		}
		else if (file == 'c' || file == 'C')
		{
			loadgame(file3, ar);
		}
	}
	else if (option == 'c' || option == 'C')
	{
		instructions();
		main();
	}
	else if (option == 'd' || option == 'D')
	{
		quit();
		return 0;
	}
	sudokugrid(ar);
	inputgrid(ar, ar_edit);
	system("pause");
	return 0;
}

