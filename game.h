#include <iostream>
#include <vector>

using namespace std;

struct settings{
    unsigned short AIMode = 0;
    vector<unsigned short> colors = vector<unsigned short>(8, 12);
    vector<unsigned short> boardSize = vector<unsigned short>(6, 7);
};


enum gameResult {
    NOT_FINISHED, DRAW, PLAYER1, PLAYER2
};

enum caseContent {
    EMPTY,
    P1,
    P2
};

gameResult hasWon(vector<vector<caseContent>> &board);
bool isMoveValid(int column, vector<vector<caseContent>> &board);
int playMove(int moveIndex, vector<vector<caseContent>> &board);
int playGame(std::vector<int> tableSize, bool isAIPlaying, settings settings);
