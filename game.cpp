#include "game.h"
#include <vector>

using namespace std;

enum CaseContent { EMPTY,
                   P1,
                   P2 };



int playGame(std::vector<int> tableSize, bool isAIPlaying) {
    //Define our table
	vector<vector<CaseContent>> board(tableSize[0], vector<CaseContent>(tableSize[1], EMPTY));

	//Game loop
	while(!hasWon()) {

	}

}