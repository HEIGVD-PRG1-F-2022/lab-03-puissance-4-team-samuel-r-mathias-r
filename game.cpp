#include "game.h"
#include "display.h"

using namespace std;

gameResult hasWon(vector<vector<caseContent>> &board) {
 return NOT_FINISHED;
}

bool isMoveValid(int column, vector<vector<caseContent>> &board) {
    return board[0][column] == EMPTY;
}

int playMove(int moveIndex, vector<vector<caseContent>> &board) {
    int playerIndex = (moveIndex % 2) + 1;
    int column = -1;
    do {
        do {
            cout << "Player " << playerIndex << " turn: ";
            cin >> column;
        } while (column < 1 || column > 7);
    } while (isMoveValid(column, board));

    return column;
}

int playGame(std::vector<int> tableSize, bool isAIPlaying, settings settings) {
    //Define our table
    vector<vector<caseContent>> board(tableSize[0], vector<caseContent>(tableSize[1], EMPTY));
    int moveIndex = 0;
    //Game loop
    while (hasWon(board) == NOT_FINISHED) {
        playMove(moveIndex, board);
        ++moveIndex;
		clearScreen();
		displayTable(board);
    }

    return 0;
}