#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void changeTextColor(int color)//function to change text color
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayPlaneFront()
{
	cout << R"(  
		             |
                       --====|====--
                             |  

                         .-"""""-. 
                       .'_________'. 
                      /_/_|__|__|_\_\
                     ;'-._       _.-';
,--------------------|    `-. .-'    |--------------------,
 ``""--..__    ___   ;       '       ;   ___    __..--""``
           `"-// \\.._\             /_..// \\-"`
              \\_//    '._       _.'    \\_//
               `"`        ``---``        `"`)" << endl;
}
void displayMenu()
{
	cout << "------------------------------\n";
	cout << "\tMenu:\n";
	cout << "1. Make a Reservation\n";
	cout << "2. Cancel a Reservation\n";
	cout << "3. Print a Reservation List\n";
	cout << "4. Print total seats reserved\n";
	cout << "5. Print total empty seats\n";
	cout << "6. Exit\n";
	cout << "------------------------------";
	cout << endl;
}
void initializeArray(string names[8][11])
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			names[row][col] = " ";
		}
		cout << endl;
	}
}
bool isUserSeatInputValid(char seatchar, int seatnum)
{

	if ((seatchar == 'A' || seatchar == 'B' || seatchar == 'C' || seatchar == 'D') && (seatnum >= 1 && seatnum <= 10))
	{
		return true;
	}
	else
	{
		cout << "Please enter a valid seat reservation (ex. A5)\n";
		return false;
	}
}
void displaySeats(string names[8][11], string seats[8][11]);
void makeReservation(char seatchar, int seatnum, string name, string seats[8][11], string names[8][11])
{
	do
	{
		cout << "Choose your seat number, " << name << ": ";
		cin >> seatchar >> seatnum;

	} while (!isUserSeatInputValid(seatchar, seatnum) );

	for (int row = 0; row < 8; row++) //assign user's name into name array and seat coordinate into seat array
	{
		for (int col = 0; col < 11; col++)
		{
			names[seatchar - 'A' + 3][seatnum] = name;
			seats[seatchar - 'A' + 3][seatnum] = "  R  ";
		}
		cout << endl;
	}
	//system("cls");

	for (int row = 0; row < 8; row++) //show updated seat with reservation
	{
		for (int col = 0; col < 11; col++)
		{
			if (seats[row][col] == "  O  ")
			{
				changeTextColor(10);
				cout << seats[row][col];
				changeTextColor(15);
			}
			else if (seats[row][col] == "  R  ")
			{
				changeTextColor(12);
				cout << "  R  ";
				changeTextColor(15);
			}
			else
			{
				cout << seats[row][col];
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");
}

void displaySeats(string names[8][11], string seats[8][11])//display name and seat number
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (seats[row][col] == "  O  ")
			{
				changeTextColor(10);
				cout << "  O  ";
				changeTextColor(15);
			}
			else if (seats[row][col] == "  R  ")//reserved seats
			{
				changeTextColor(12);
				cout << "  R  ";
				changeTextColor(15);
			}
			else
			{
				cout << seats[row][col];
			}
		}
		cout << endl;
	}
}
void cancelReservation(char seatchar, int seatnum, string name, string names[8][11], string seats[8][11]) //cancel reservation
{
	cout << "Enter your name: ";
	cin >> name;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (names[row][col] == name)
			{
				seats[row][col] = "  O  ";
				names[row][col] = " ";
			}
		}
		cout << endl;
	}
	displaySeats(names, seats);
	system("pause");
}
void displayName(string names[8][11])
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (names[row][col] != " ")
			{
				if (row == 3)
				{
					cout << "A," << col << ": " << names[row][col] << endl;
				}
				else if (row == 4)
				{
					cout << "B," << col << ": " << names[row][col] << endl;
				}
				else if (row == 5)
				{
					cout << "C," << col << ": " << names[row][col] << endl;
				}
				else if (row == 6)
				{
					cout << "D," << col << ": " << names[row][col] << endl;
				}
			}
		}
		cout << endl;
	}
	system("pause");
}
int seatsReserved(string seats[8][11])
{
	int seatReserved = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (seats[row][col] == "  R  ")
			{
				seatReserved++; //increment seatReserved for every reservation
			}
		}
		cout << endl;
	}
	return seatReserved;
}
int seatsEmpty(string seats[8][11])
{
	int seatEmpty = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			if (seats[row][col] == "  O  ")
			{
				seatEmpty++; //increment seatReserved for every reservation
			}
		}
		cout << endl;
	}
	return seatEmpty;

}
void main()
{
	string names[8][11];
	string name;
	char seatchar = 'A';
	int seatnum = 1;

	string seats[8][11] = {
	{"-----","-----","-----","-----","-----","-----","-----","-----","-----","-----","-----",},
	{"  ","  1  ","  2  ","  3  ","  4  ","  5  ","  6  ","  7  ","  8  ","  9  ","  10  "},
	{"-----","-----","-----","-----","-----","-----","-----","-----","-----","-----","-----",},
	{"A:","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  "},
	{"B:","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  "},
	{"C:","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  "},
	{"D:","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  ","  O  "},
	{"-----","-----","-----","-----","-----","-----","-----","-----","-----","-----","-----",},
	};
	initializeArray(names);
	displayPlaneFront();
	cout << "Welcome to Emirates Airline!\n";
	system("pause");
	system("cls");

	int option = 1;

	while (option != 6)
	{
		displaySeats(names, seats);
		displayMenu();
		cout << "Choose your option: ";
		cin >> option;

		switch (option)
		{
		case 1://makeReservation
		{
			cout << "Enter your name: ";
			cin >> name;
			makeReservation(seatchar, seatnum, name, seats, names);
			break;
		}
		case 2://cancelReservation
		{
			cancelReservation(seatchar, seatnum, name, names, seats);
			break;
		}
		case 3://Print reservation list (name and seat number)
		{
			displayName(names);
			break;
		}
		case 4://print total number of seats reserved
		{
			cout << "The number of seats reserved: " << seatsReserved(seats) << endl;
			system("pause");
			break;
		}
		case 5: //print total number of empty seats
		{
			cout << "The number of empty seats: " << seatsEmpty(seats) << endl;
			system("pause");
			break;
		}
		}
		system("cls");
	}
	cout << "Thanks for flying with Emirates!" << endl;
}