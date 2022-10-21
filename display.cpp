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

void displayBoard(const std::vector<std::vector<caseContent>> &board) {
    //cout << " ";
    for (int i = 1; i <= board[0].size(); i++) {
        cout << setw(3) << i;
        cout << " ";
    }
    cout << " " << endl;
    for (int j = 0; j < board[0].size(); j++) {
        //cout << "  \u25BC ";
        cout << setw(3) << "v";
        cout << " ";
    }
    cout << endl
         << endl;

    for (int line = 0; line < board.size(); line++) {
        for (int col = 0; col < board[0].size(); col++) {
            cout << "|" << (board[line][col] == EMPTY ? "   " : (board[line][col] == P1 ? " X " : " O "));
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void clearScreen() {
    system(CLEARCMD);
}