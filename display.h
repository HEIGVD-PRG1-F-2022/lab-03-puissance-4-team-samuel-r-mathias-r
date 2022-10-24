#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h"
#include <vector>

#endif

void displayCoin(const caseContent &caseContent, std::vector<unsigned short> colorsSettings);
void displayBoard(const std::vector<std::vector<caseContent>> &board, std::vector<unsigned short> colorsSettings);
void clearScreen();