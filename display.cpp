#include "display.h"
#include "iomanip"
#include "string"
//Code taken from https://stackoverflow.com/a/15481700
#ifdef _WIN32
#define CLEARCMD "cls"
#else//In any other OS
#define CLEARCMD "clear"
#endif

using namespace std;

void displayCoin(int color) {
    string escapedColoredString = "\033[33;" + to_string(color) + "m";

    escapedColoredString += "●";//big filled circle (UTF8 code is 11044)

    escapedColoredString += "\033[0m";
    cout << escapedColoredString;
}

void displayBoard(const std::vector<std::vector<caseContent>> &board) {
    for (int i = 1; i <= board[0].size(); i++) {
        cout << setw(3) << i;
        cout << " ";
    }
    cout << " " << endl;
    for (int j = 0; j < board[0].size(); j++) {
        cout << "  ▼";
        // cout << setw(4) << "v";
        cout << " ";
    }
    cout << endl
         << endl;

    for (int line = 0; line < board.size(); line++) {
        for (int col = 0; col < board[0].size(); col++) {
            cout << "| ";
            if (board[line][col] == EMPTY) {
                cout << "◌";
            } else {
                displayCoin(board[line][col] == P1 ? 34 : 32);
                // cout << " ";
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void clearScreen() {
    system(CLEARCMD);
}