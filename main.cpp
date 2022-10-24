/*
 * This project was made during as a school project of the HEIG-Vd.
 * Authors : Samuel R. & Mathias R.
 * Created : 10.18.22
 */

#include "display.h"
#include "game.h"
#include "limits"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

void changeAIModeMenu(settings &settings) {
    int choice;
    do {
        clearScreen();
        cout << "AI mode:" << endl
             << "1. Smart" << endl
             << "2. Random" << endl
             << "3. Back" << endl;
        cout << "Your choice: ";
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

void changeBoardSizeMenu(settings &settings) {
    int height, width;
    do {
        clearScreen();
        cout << "New board height (3-80): ";
        cin >> height;
        cout << endl;
        cout << "New board width (3-80): ";
        cin >> width;
    } while (height > 80 || height < 3 || width > 80 || width < 3);
    settings.boardSize[0] = height;
    settings.boardSize[1] = height;
}

void changeColorsMenu(settings settings) {
    int choice;
}

void changeSettings(settings &settings) {
    int choice;
    do {
        clearScreen();
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
        case 1://AI mode
            changeAIModeMenu(settings);
            break;
        case 2://Board size
            changeBoardSizeMenu(settings);
            break;
        case 3://Colors
            changeColorsMenu(settings);
            break;
        case 4://Exit
            return;
        default:
            throw invalid_argument("This case shouldn't happen!");
    }
}

void gameMenu(settings &settings) {
    bool isQuitting = false;
    gameResult whoWon = NOT_FINISHED;
    clearScreen();
    while (!isQuitting) {
        cout << "Welcome to *Connect Four*!" << endl
             << "Current settings:"
             << "\n  - Board size (width*height): " << settings.boardSize[1] << " * " << settings.boardSize[0]
             << "\n  - Coin colors: " << settings.colors[0] << ", " << settings.colors[1]
             << "\n  - AI Mode: " << (settings.AIMode == 0 ? "Smart" : "Random")
             << endl
             << endl;

        cout << "1. Player vs AI" << endl
             << "2. Player vs Player" << endl
             << "3. Settings" << endl
             << "4. Exit" << endl
             << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                whoWon = playGame(false, settings);
                break;
            case 2:
                whoWon = playGame(true, settings);
                break;
            case 3:
                changeSettings(settings);
                clearScreen();
                break;
            case 4:
                isQuitting = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        // clearScreen();
        if (whoWon != NOT_FINISHED) {
            switch (whoWon) {
                case DRAW:
                    cout << "It's a draw!" << endl;
                    break;
                case PLAYER1:
                case PLAYER2:
                    cout << "Player " << (whoWon == PLAYER1 ? 1 : 2) << " won! GG!" << endl;
                    break;
                default:
                    cout << "ERROR!" << endl;
                    break;
            }
            cout << "Would you like continue and return to the menu? [y/n] " << endl;
            string continueOrQuit;
            cin >> continueOrQuit;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (continueOrQuit == "n") {
                return;
            }
            clearScreen();
        }
    }
}

int main() {
    settings settings;
    gameMenu(settings);
    cout << "Bye bye !" << endl;
    return EXIT_SUCCESS;
}