#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "version.h"

using namespace std;

char F[10];

void multiplayer();
bool checkFull();
char inputalternate(bool x);
void singelplayer();
void KI(int);


void menu() {
	while (true) {
		resetField();
		char inputmenu;
		welcome();
		cout << "\n\n";
		cout << "MENU\n\n";
		cout << "1: Singelplayer\n";
		cout << "2: Multiplayer\n";
		cout << "3: Help\n";
		cout << "4: Quit\n\n\n";
		cout << "Input: ";
		cin >> inputmenu;
		if (inputmenu == '1') {
			singelplayer();
		}
		else if (inputmenu == '2') {
			multiplayer();
		}
		else if (inputmenu == '3') {
			help();
		}
		else if (inputmenu == '4' || inputmenu == 'q') {
			return;
		}
		else {
			clearConsole(); cout << "\nInvalid Input!";
		}
	}
}

void multiplayer()
{
	char input = ' ';
	//bool true für erster spieler false dan 2er spieler
	bool player1Turn = true;
	while (true) {
		Feld();
		// wir geben checkwin den wert nach dem er suchen soll 
		if (checkWin('X')) {
			cout << "\nPlayer1 has won\n\n";
			return;
		}
		else if (checkWin('O')) {
			cout << "\n Player2 has won\n\n";
			return;
		}
		if (checkFull()) {
			cout << "Tie\n\n";
			multiplayer();
		}
		input = inputalternate(player1Turn);
		if (input == 'q') {
			return;
		}
		//nach input von spieler eins wird die boolische variable negiert und so kann ich in einer anderen funkton abwechselnd die spieler spielen lassen
		player1Turn = !player1Turn;
	}
}



char inputalternate(bool x) {
	while (true) {
		cout << "\n\nInput: ";
		char input = ' ';
		cin >> input;
		// - '0' so das man eine char variable zu einer int variable machen kann
		int inputNumber = input - '0';
		if (inputNumber > 9 or inputNumber < 1) {
			cout << "Invalid Input \n";
		}
		else if (F[inputNumber] != ' ') {
			cout << "\nThis field is already used";
		}
		else {
			if (x) {
				F[inputNumber] = 'X';
			}
			else {
				F[inputNumber] = 'O';
			}
			return input;
		}
	}
}


void KI(int diff) {
	if (checkFull()) {
		cout << "Gleichstant\n";
		//singelplayer();
		return;
	}
	// ki bassiert auf zufahl
	if (diff == 1) {

		int N = rand() % 3;
		// 66 % das es 1 ist
		if (N != 1) {
			for (int i = 1; i < 10; i++) {
				if (F[i] == ' ') {
					F[i] = 'O';
					/*überprüfen ob man mit O gewinnen kann wenn nicht zuweise ich ihm nicht das feld lehr ist das sieht der nutzer
					aber ncht ki überprüft nur ob man da gewinnen kan*/
					if (checkWin('O')) {
						return;
					}
					else {
						F[i] = ' ';
					}
				}
			}
		}
		else if (N != 2) {
			for (int i = 1; i < 10; i++) {
				if (F[i] == ' ') {
					F[i] = 'X';
					if (checkWin('X')) {
						F[i] = 'O';
						return;
					}
					else {
						F[i] = ' ';
					}
				}
			}
		}
		while (true) {
			srand(time(NULL));
			int i = rand() % 9 + 1;
			if (F[i] == ' ') {
				F[i] = 'O';
				return;
			}
		}
		return;
	}
	else if (diff == 2) {
		int N = rand() % 5 + 1;
		if (N != 3) {
			for (int i = 1; i < 10; i++) {
				if (F[i] == ' ') {
					F[i] = 'O';
					if (checkWin('O')) {
						return;
					}
					else {
						F[i] = ' ';
					}
				}
			}
		}
		else if (N != 2) {
			for (int i = 1; i < 10; i++) {
				if (F[i] == ' ') {
					F[i] = 'X';
					if (checkWin('X')) {
						F[i] = 'O';
						return;
					}
					else {
						F[i] = ' ';
					}
				}
			}
		}
		while (true) {
			srand(time(NULL));
			int i = rand() % 9 + 1;
			if (F[i] == ' ') {
				F[i] = 'O';
				return;
			}
		}
		return;
	}
	else if (diff == 3) {
		//hard | schaue ob ki gewinnen kann
		for (int i = 1; i < 10; i++) {
			if (F[i] == ' ') {
				F[i] = 'O';
				/*überprüfen ob man mit O gewinnen kann wenn nicht zuweise ich ihm nicht das feld lehr ist das sieht der nutzer
				aber ncht ki überprüft nur ob man da gewinnen kann*/
				if (checkWin('O')) {
					return;
				}
				else {
					F[i] = ' ';
				}
			}
		}
		//wenn nicht dan check ob spieler gewinnen kann
		for (int i = 1; i < 10; i++) {
			if (F[i] == ' ') {
				F[i] = 'X';
				// überprüfen ob spieler gewinnen kann
				if (checkWin('X')) {
					F[i] = 'O';
					return;
				}
				else {
					F[i] = ' ';
				}
			}
		}
		//und stoppen ihn | schauen ob feld in der mitte frei ist 
		// erstelle eine random variable nicht grösser as 4 und wenn es anders als 1 ist also 2 3 oder 4  ist dan setzt ehr auf feld numer 5 also mitte so das ehr nicht immer auf die mitte setzt wenn feld frei ist
		int mitte = rand() % 4;
		if (F[5] == ' ' and mitte != 1) {
			F[5] = 'O';
			return;
		}
		//wenn nichts mehr hilf dan random feld auswehlen
		while (true) {
			srand(time(NULL));
			int i = rand() % 9 + 1;
			if (F[i] == ' ') {
				F[i] = 'O';
				return;
			}
		}
	}
	else {

		return;
	}
}

void singelplayer() {
	clearConsole();
	resetField();
	cout << "Difficulty\n\n" << "1: Easy\n" << "2: Medium\n" << "3: Hard\n\n";
	char inputDiff;
	int difficulty = 0;
	cin >> inputDiff;
	if (inputDiff == '1') {
		difficulty = 1;
	}
	else if (inputDiff == '2') {
		difficulty = 2;
	}
	else if (inputDiff == '3') {
		difficulty = 3;
	}
	else {
		cout << "Error\n\n";
		menu();
	}
	while (true) {
		Feld();
		if (checkWin('O')) {
			cout << "\n Computer has won\n\n";
			return;
		}
		if (checkFull()) {
			cout << "Tie\n\n";
			return;
		}
		inputDiff = inputalternate(true);
		Feld();
		if (checkWin('X')) {
			cout << "Player has won\n";
			return;
		}
		KI(difficulty);
	}
}


int main() {
	srand(time(NULL));
	menu();


	return 0;
}