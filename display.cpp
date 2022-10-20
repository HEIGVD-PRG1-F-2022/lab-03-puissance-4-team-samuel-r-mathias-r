#include "display.h"
//Code taken from https://stackoverflow.com/a/15481700
#ifdef _WIN32
#define CLEARCMD "cls"
#else //In any other OS
#define CLEARCMD "clear"
#endif

using namespace std;

void displayBoard(const std::vector<std::vector<caseContent>> &board) {
    for (int line = 0; line < board.size(); line++) {
        for (int col = 0; col < board[0].size(); col++) {
            cout << "|" << (board[line][col] == EMPTY ? " " : (board[line][col] == P1 ? "X" : "O"));
        }
        cout << "|" << endl;
    }
}

void clearScreen() {
    system(CLEARCMD);
}