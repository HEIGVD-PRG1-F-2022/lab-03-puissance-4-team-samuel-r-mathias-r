#include "game.h"
#include "display.h"
#include "limits"

using namespace std;

int randomAIMove(const vector<vector<caseContent>> &board) {
    srand(time(0));
    int rd = rand();
    rd %= (board.size() - 1);//find a random number between 0 and (board width - 1)
    return rd;
}

int
playAIMove(const vector<int> &lastPlayedCell, vector<vector<caseContent>> &board, settings &settings) {
    switch (settings.AIMode) {
        case 1:
            return smartAIMove(lastPlayedCell, board, settings);//Smart
        case 2:
            return randomAIMove(board);//Random
    }
    return 1;//Shouldn't happen... /shrug
}

int
smartAIMove(const vector<int> &lastPlayedCell, vector<vector<caseContent>> &board, settings &settings) {
    static vector<int> lastAIMove = (vector<int>) {-1, -1};
    if (lastAIMove != (vector<int>) {-1, -1}) {
        for (int i = 0; i < board[0].size(); ++i) {
            vector<int> testCoinCoordinates;
            for (int j = 0; j < board.size(); j++) {
                caseContent &cell = board[board.size() - j - 1][i];
                if (cell == EMPTY) {
                    testCoinCoordinates = vector<int>{j, i};
                }
            }
            if (hasWon(board, testCoinCoordinates) && isMoveValid(testCoinCoordinates[1], board)) {
                return testCoinCoordinates[1];
            }
            else
            {
                return lastPlayedCell[1];
            }
        }
    } else {
        return lastPlayedCell[1];
    }
    return {};
}

gameResult hasWon(const vector<vector<caseContent>> &board, const std::vector<int> &lastPlayedCell) {
    /*
     * Directions :
     *               North(+0)
     *   North-West(+-) |  North-East(++)
     *                 \|/
     *   West(0-)<------*------->East(0+)
     *                 /|\
     *   South-West(--) | South-East (-+)
     *               South(-0)
     */

    //Initializing all the cardinal variables to 0. North doesn't need to be used because the coins come from above
    unsigned short NW = 0, NE = 0, W = 0, E = 0, SE = 0, SW = 0, S = 0;
    //Initializing the offsets and the score to 0. The score is a temporary variable that is each time transfered to the cardinals
    int x, y, score = 0;
    //Get the content of the last played cell. We need to know which player has played...
    caseContent checkedPlayer = board[lastPlayedCell[0]][lastPlayedCell[1]];
    //Loop that iterates for each cardinals, starting from NE and going to NW clockwise
    for (int i = 0; i < 7; i++) {
        for (int depth = 1; depth <= 5; depth++) {
            //Sets the correct offset math to x and y
            switch (i) {
                case 0:
                    x = -depth;
                    y = depth;
                    break;
                case 1:
                    x = 0;
                    y = depth;
                    break;
                case 2:
                    x = depth;
                    y = depth;
                    break;
                case 3:
                    x = depth;
                    y = 0;
                    break;
                case 4:
                    x = depth;
                    y = -depth;
                    break;
                case 5:
                    x = 0;
                    y = -depth;
                    break;
                case 6:
                    x = -depth;
                    y = -depth;
                    break;
                default:
                    cout << "ERROR" << endl; //shouldn't happen
            }
            //first checks if we are IN the bounds of the board, then check the content of an offset cell from the center
            if ((lastPlayedCell[0] + x < board.size() &&
                 lastPlayedCell[1] + y < board[0].size() &&
                 lastPlayedCell[0] + x >= 0 &&
                 lastPlayedCell[1] + y >= 0) &&
                board[lastPlayedCell[0] + x][lastPlayedCell[1] + y] == checkedPlayer) {
                score++;
            } else {
                break;//If a cell is not the same as the center one, the "chain" of coins is cut, thus we leave the loop
            }
        }
        //Add the score of the current cardinal to one of the 4 cardinals.
        switch (i) {
            case 0:
            case 4:
                NE += score;
                break;
            case 1:
            case 5:
                E += score;
                break;
            case 2:
            case 6:
                SE = score;
                break;
            case 3:
                S = score;
                break;
            default:
                cout << "ERROR" << endl;
        }
        score = 0;
    }
    //Checks if there's a chain of coins of at least 4 of length
    if (NE >= 3 || S >= 3 || E >= 3 || SE >= 3) {
        return gameResult(checkedPlayer + 1); //returns the player who won
    }
    return NOT_FINISHED;//nobody won
}

bool isMoveValid(int column, vector<vector<caseContent>> &board) {
    return board[0][column] == EMPTY;
}

vector<int>
playMove(vector<vector<caseContent>> &board, settings &settings, vector<int> &lastPlayedCell,
         bool isAIPLaying) {
    static int moveIndex = -1;
    moveIndex++;
    if (moveIndex == board.size() * board[0].size()) return {};//Draw
    int playerIndex = (moveIndex % 2) + 1;
    int column;
    if (playerIndex == 1 || !isAIPLaying) {
        do {
            do {
                displayBoard(board, settings.colors);//display the final board before displaying the winner
                cout << "Player " << playerIndex << " turn: ";
                cin >> column;
                column--;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                clearScreen();
            } while (column < 0 || column > board[0].size());
        } while (!isMoveValid(column, board));
    } else {
        column = playAIMove(lastPlayedCell, board, settings);
    }
    for (int i = 0; i < board.size(); i++) {
        caseContent &cell = board[board.size() - i - 1][column];
        if (cell == EMPTY) {
            cell = playerIndex == 1 ? P1 : P2;
            return {(int) board.size() - i - 1, column};
        }
    }
    return {};//todo: refactor
}

gameResult playGame(bool isAIPlaying, settings &settings) {
    //Define our table
    vector<vector<caseContent>> board(settings.boardSize[0], vector<caseContent>(settings.boardSize[1], EMPTY));
    vector<int> lastPlayedCell;
    do {
        //Game loop
        lastPlayedCell = playMove(board, settings, lastPlayedCell, isAIPlaying);
    } while (hasWon(board, lastPlayedCell) == NOT_FINISHED);
    clearScreen();
    return hasWon(board, lastPlayedCell);
}