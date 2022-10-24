#include "display.h"
#include "game.h"
#include "iomanip"
#include "string"
#include <vector>
//Code taken from https://stackoverflow.com/a/15481700
#ifdef _WIN32
#define CLEARCMD "cls"
#else//In any other OS
#define CLEARCMD "clear"
#endif

using namespace std;

//Display a coin with a given color
void displayCoin(const caseContent &caseContent, vector<unsigned short> colorsSettings) {
    if (caseContent == EMPTY) {
        cout << "⚫";
    } else {
        int color = colorsSettings[caseContent == P1 ? 0 : 1] + 30;//colors from 31 to 36

        string escapedColoredString = "\033[33;" + to_string(color) + "m";

        escapedColoredString += "\u2B24";//big filled circle (UTF8 code is 2B24)

        escapedColoredString += "\033[0m";
        cout << escapedColoredString << " ";//colored coins needs a space after them to have a proper display
    }
}

void displayBoard(const std::vector<std::vector<caseContent>> &board, vector<unsigned short> colorsSettings) {
    //Erase the screen
    clearScreen();

    //Display the first line of case numbers (numbers from 0 to 99 supported)
    for (int i = 1; i <= board[0].size(); i++) {
        cout << setw(4) << i << " ";
    }
    cout << endl;

    //Display a line of 2 chars bottom triangles (actually this is an association of 2 triangles of 1 char width)
    for (int j = 0; j < board[0].size(); j++) {
#ifdef _WIN32
        cout << "  \/ ";
#else
        cout << "  ◥◤ ";
#endif
    }
    cout << endl
         << endl;

    //Display the board with empty or filled coins
    for (int line = 0; line < board.size(); line++) {
        for (int col = 0; col < board[0].size(); col++) {
            cout << "| ";
            displayCoin(board[line][col], colorsSettings);//display the coin (empty or filled)
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void clearScreen() {
    system(CLEARCMD);
}