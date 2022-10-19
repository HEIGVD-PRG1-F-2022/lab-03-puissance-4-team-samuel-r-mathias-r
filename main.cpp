/*
 * This project was made during as a school project of the HEIG-Vd.
 * Authors : Samuel R. & Mathias R.
 * Created : 10.18.22
 */

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "game.h"

using namespace std;

void changeAIModeMenu(){
    int choice;
    do {
        system("cls");
        cout << "AI mode :" << endl
             << "1. Smart" << endl
             << "2. Random" << endl
             << "3. Back" << endl;
        cin >> choice;
        if (choice > 3 || choice < 1) cout << "Please enter a valid input!";
    } while (choice > 3 || choice < 1);
    switch (choice) {
        case 1: //SetAIModeTo(0); break;
        case 2: //SetAIModeTo(1); break;
        case 3: return;
        default:
            throw invalid_argument ("This case shouldn't happen!");
    }
}

void changeBoardSizeMenu(){
    int choice;

}

void changeColorsMenu(){
    int choice;
}

void changeSettings() {
    int choice;
    do {
        system("cls");
        cout << "What settings would you like to change?" << endl
             << "1. AI mode" << endl
             << "2. Board size" << endl
             << "3. Colors" << endl;
        cin >> choice;
        if (choice > 4 || choice < 1) cout << "Please enter a valid input!";
    } while (choice > 4 || choice < 1);

    switch (choice) {
        case 1: //AI mode
            changeAIModeMenu();
            break;
        case 2: //Board size
            changeBoardSizeMenu();
            break;
        case 3: //Colors
            changeColorsMenu();
            break;
        case 4: //Exit
            return;
        default:
            throw invalid_argument ("This case shouldn't happen!");
    }
}

void gameMenu() {
    bool isQuitting = false;
    while(!isQuitting){
        cout << "Welcome to *Connect Four*!" << endl
             << "1. Player vs AI" << endl
             << "2. Player vs Player" << endl
             << "3. Settings" << endl
             << "4. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                playGame(vector<int>(6,7), false);
                break;
            case 2:
                playGame(vector<int>(6,7), true);
                break;
            case 3:
                changeSettings();
                break;
            case 4:
                isQuitting = true;
                break;
            default :
                cout << "Invalid choice" << endl;
        }
    }
}

int main() {
    gameMenu();
    return EXIT_SUCCESS;
}