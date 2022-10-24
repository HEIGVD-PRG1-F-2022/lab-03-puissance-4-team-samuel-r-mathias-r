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

//Display a coin with a given color
void displayCoin(int color) {
    if (color != 0) {
        string escapedColoredString = "\033[33;" + to_string(color) + "m";

        escapedColoredString += "⬤";//big filled circle (UTF8 code is 11044)

        escapedColoredString += "\033[0m";
        cout << escapedColoredString;
    } else {
        cout << "⚫";
    }
}

void displayBoard(const std::vector<std::vector<caseContent>> &board) {
    //Display the first line of case numbers (numbers from 0 to 99 supported)
    for (int i = 1; i <= board[0].size(); i++) {
        cout << setw(4) << i << " ";
    }
    cout << endl;

    //Display a line of 2 chars bottom triangles (actually this is an association of 2 triangles of 1 char width)
    for (int j = 0; j < board[0].size(); j++) {
        cout << "  ◥◤ ";
    }
    cout << endl
         << endl;

    //Display the board with empty or filled coins
    for (int line = 0; line < board.size(); line++) {
        for (int col = 0; col < board[0].size(); col++) {
            cout << "| ";
            if (board[line][col] == EMPTY) {
                displayCoin(0);//display empty coin
            } else {
                displayCoin(board[line][col] == P1 ? 34 : 32);
                cout << " ";//colored coins needs a space after them to have a proper display
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