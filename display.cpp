#include "display.h"

using namespace std;

void displayTable(const std::vector<std::vector<caseContent>> &table) {
    for (int line = 0; line < table.size(); line++) {
        for (int col = 0; col < table[0].size(); col++) {
            cout << "|" << (table[line][col] == EMPTY ? "X" : "");
        }
        cout << "|" << endl;
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}