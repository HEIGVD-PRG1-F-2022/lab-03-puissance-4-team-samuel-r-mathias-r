#include "game.h"
#include "display.h"
#include "limits"

using namespace std;

gameResult hasWon(const vector<vector<caseContent>> &board, const std::vector<int> &lastPlayedCell) {
    /*
     * Directions :
     *           North(+0)
     *  North-West |  North-East(++)
     *            \|/
     *  West<------*------->East(0+)
     *            /|\
     *  South-West | South-East (--)
     *           South(-0)
     */
    unsigned short NW = 0, NE = 0, W = 0, E = 0, SE = 0, SW = 0, S = 0;
    int x = 1;
    int y = 1;
    int score = 0;
    caseContent checkedPlayer = board[lastPlayedCell[0]][lastPlayedCell[1]];
    for(int i = 0; i <7;i++)
    {
        switch(i){
            case 0: x = i; y = i; break;
            case 1: x = 0; y = i; break;
            case 2: x = i*-1; y = i*-1; break;
            case 3: x = i*-1; y = 0; break;
            case 4: x = i*-1; y = i*-1; break;
            case 5: x = 0; y = i*-1; break;
            case 6: x = i; y = i; break;
            default: cout << "ERROR" << endl;
        }
        if((lastPlayedCell[0]+x >= board.size() ||
            lastPlayedCell[1]+y >= board[0].size() ||
            lastPlayedCell[0]+x < 0 ||
            lastPlayedCell[1]+y < 0) &&
            board[lastPlayedCell[0]+x][lastPlayedCell[1]+y] == checkedPlayer){
                score++;
        }
        else{
            switch(i){
                case 0: NE = score; break;
                case 1: E  = score; break;
                case 2: SE = score; break;
                case 3: S  = score; break;
                case 4: SW = score; break;
                case 5: W  = score; break;
                case 6: NW = score; break;
                default: cout << "ERROR" << endl;
            }
            score = 0;
        }
    }
    if(NE + SW >= 3 || S >= 3 || E + W >= 3 || NW + SE >= 3) return gameResult(checkedPlayer + 1);

    return NOT_FINISHED;
}

bool isMoveValid(int column, vector<vector<caseContent>> &board) {
    return board[0][column] == EMPTY;
}

vector<int> playMove(int moveIndex, vector<vector<caseContent>> &board) {
    if(moveIndex == board.size() * board[0].size()) return DRAW;
    int playerIndex = (moveIndex % 2) + 1;
    int column;
    do {
        do {
            cout << "Player " << playerIndex << " turn: ";
            cin >> column;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (column < 1 || column - 1 > board[0].size());
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

int playGame(bool isAIPlaying, settings settings) {
    //Define our table
    vector<vector<caseContent>> board(settings.boardSize[0], vector<caseContent>(settings.boardSize[1], EMPTY));
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