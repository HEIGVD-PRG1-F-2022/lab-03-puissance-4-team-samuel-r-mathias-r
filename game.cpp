#include "game.h"

using namespace std;

gameResult hasWon(vector<vector<caseContent>> &board) {

}

int playMove(int moveIndex) {
    int playerIndex = (moveIndex % 2) + 1;
    int column = -1;
    do {
        cout << "Player " << playerIndex << " turn: ";
        cin >> column;
    } while (column < 1 || column > 7);

    return column;
}

int playGame(std::vector<int> tableSize, bool isAIPlaying) {
    //Define our table
    vector<vector<caseContent>> board(tableSize[0], vector<caseContent>(tableSize[1], EMPTY));
    int moveIndex;
    //Game loop
    while (hasWon(board) == NOT_FINISHED) {
        playMove(moveIndex);
        ++moveIndex;
    }
}