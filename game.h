#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

struct settings {
    unsigned short AIMode = 0;
    std::vector<unsigned short> boardSize = std::vector<unsigned short>{6, 7};
    std::vector<unsigned short> colors = std::vector<unsigned short>{2, 4};
};

enum gameResult {
    NOT_FINISHED,
    DRAW,
    PLAYER1,
    PLAYER2
};

enum caseContent {
    EMPTY,
    P1,
    P2
};
#endif


gameResult hasWon(const std::vector<std::vector<caseContent>> &board, const std::vector<int> &lastPlayedCell);

bool isMoveValid(int column, std::vector<std::vector<caseContent>> &board);

std::vector<int> playMove(int moveIndex, std::vector<std::vector<caseContent>> &board, settings &settings);

gameResult playGame(bool isAIPlaying, settings &settings, std::vector<int> &lastPlayedCell);

int randomAIMove(const std::vector<std::vector<caseContent>> &board);
int
smartAIMove(const std::vector<int> &lastPlayedCell, std::vector<std::vector<caseContent>> &board, settings &settings);

int
playAIMove(const std::vector<int> &lastPlayedCell, std::vector<std::vector<caseContent>> &board, settings &settings);