#include "version.h"

void welcome() {
	cout << "\t\t\t\t -----------------\n"
		<< "\t\t\t\t|    TicTacToe    |\n"
		<< "\t\t\t\t -----------------\n";
}

void clearConsole() {
	system("cls");
}

void resetField() {
	for (int i = 0; i < 10; i++) {
		F[i] = ' ';
	}
}

void help() {
	clearConsole();
	cout << "\n\n\nHELP\n\nSingleplayer:\nIn Singleplayermode you play against the Computer\n\nMultiplayer:\nIn Multiplayermode you play against a second player. Input switches between X and O. You can also play this mode if you want to test new tactics or just want to play against yourself.\n\nControls:\nTo choose a field you must enter a number between 1 and 9. The first field is in the top left. the second right next to it etc.\n\n";
	system("pause");
	return;
}

bool checkWin(char sign) {
	if (F[1] == sign and F[2] == sign and F[3] == sign or F[1] == sign and F[4] == sign and F[7] == sign or F[1] == sign and F[5] == sign and F[9] == sign or F[2] == sign and F[5] == sign and F[8] == sign or F[3] == sign and F[6] == sign and F[9] == sign or F[3] == sign and F[5] == sign and F[7] == sign or F[4] == sign and F[5] == sign and F[6] == sign or F[7] == sign and F[8] == sign and F[9] == sign) {
		return true;
	}
	return false;
}

bool checkFull() {
	for (int i = 1; i <= 9; i++) {
		if (F[i] == ' ') {
			return false;
		}
	}
	return true;
}

void Feld() {
	clearConsole();
	cout << "\n\n\n";
	cout << "     " << F[1] << " | " << F[2] << " | " << F[3] << endl;
	cout << "    ---|---|---" << endl;
	cout << "     " << F[4] << " | " << F[5] << " | " << F[6] << endl;
	cout << "    ---|---|---" << endl;
	cout << "     " << F[7] << " | " << F[8] << " | " << F[9] << endl;
}