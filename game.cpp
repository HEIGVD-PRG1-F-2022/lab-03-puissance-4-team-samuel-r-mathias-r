#include "game.h"
#include "display.h"

using namespace std;

gameResult hasWon(const vector<vector<caseContent>> &board, const std::vector<int> lastPlayedCell) {
    //to implement
    return NOT_FINISHED;
}

bool isMoveValid(int column, vector<vector<caseContent>> &board) {
    return board[0][column] == EMPTY;
}

vector<int> playMove(int moveIndex, vector<vector<caseContent>> &board) {
    int playerIndex = (moveIndex % 2) + 1;
    int column;
    do {
        do {
            cout << "Player " << playerIndex << " turn: ";
            cin >> column;
        } while (column < 1 || column > 7);
    } while (!isMoveValid(column, board));

    for (int i = 0; i < board.size(); i++) {
        caseContent &cell = board[board.size() - i - 1][column - 1];
        if (cell == EMPTY) {
            cell = playerIndex == 1 ? P1 : P2;
            return {(int) board.size() - i - 1, column - 1};
        }
    }
    return {};//todo: refactor
}

int playGame(std::vector<int> tableSize, bool isAIPlaying, settings settings) {
    //Define our table
    vector<vector<caseContent>> board(tableSize[0], vector<caseContent>(tableSize[1], EMPTY));
    int moveIndex = 0;
    vector<int> lastPlayedCell;
    do {
        //Game loop
        clearScreen();
        displayBoard(board);
        lastPlayedCell = playMove(moveIndex, board);
        ++moveIndex;
    } while (hasWon(board, lastPlayedCell) == NOT_FINISHED);

    return 0;
}