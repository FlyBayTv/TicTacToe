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
		cout << "1: Singleplayer\n";
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
	bool player1Turn = true;
	while (true) {
		Feld();
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
		player1Turn = !player1Turn;
	}
}



char inputalternate(bool x) {
	while (true) {
		cout << "\n\nInput: ";
		char input = ' ';
		cin >> input;
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
		return;
	}
	if (diff == 1) {

		int N = rand() % 3;
		if (N != 1) {
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
		
		int mitte = rand() % 4;
		if (F[5] == ' ' and mitte != 1) {
			F[5] = 'O';
			return;
		}
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
