/*
 * This project was made during as a school project of the HEIG-Vd.
 * Authors : Samuel R. & Mathias R.
 * Created : 10.18.22
 */

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "game.h"

using namespace std;

void changeAIModeMenu(settings &settings) {
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
        case 1:
        case 2:
            settings.AIMode = choice;
        case 3:
            return;
        default:
            throw invalid_argument("This case shouldn't happen!");
    }
}

void changeBoardSizeMenu() {
    int choice;

}

void changeColorsMenu() {
    int choice;
}

void changeSettings(settings &settings) {
    int choice;
    do {
        system("cls");
        cout << "What settings would you like to change?" << endl
             << "1. AI mode" << endl
             << "2. Board size" << endl
             << "3. Colors" << endl
             << "4. Exit" << endl
             << "Your choice: ";
        cin >> choice;
        if (choice > 4 || choice < 1) cout << "Please enter a valid input!";
    } while (choice > 4 || choice < 1);

    switch (choice) {
        case 1: //AI mode
            changeAIModeMenu(settings);
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
            throw invalid_argument("This case shouldn't happen!");
    }
}

void gameMenu(settings &settings) {
    bool isQuitting = false;
    while (!isQuitting) {
        cout << "Welcome to *Connect Four*!" << endl
             << "1. Player vs AI" << endl
             << "2. Player vs Player" << endl
             << "3. Settings" << endl
             << "4. Exit" << endl
             << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                playGame({6, 7}, false, settings);
                break;
            case 2:
                playGame({6, 7}, true, settings);
                break;
            case 3:
                changeSettings(settings);
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
    settings settings;
    gameMenu(settings);
    return EXIT_SUCCESS;
}