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
#ifdef _WIN32
#include "windows.h"
#endif
using namespace std;

//Menu to change the AI mode (random or smart)
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

//Menu to change size of the board
void changeBoardSizeMenu(settings &settings) {
    int height, width;
    const int MAX_BOARD_SIZE = 80;
    const int MIN_BOARD_SIZE = 3;
    do {
        clearScreen();
        cout << "New board height (3-80): ";
        cin >> height;
        cout << "New board width (3-80): ";
        cin >> width;
    } while (height > MAX_BOARD_SIZE || height < MIN_BOARD_SIZE || width > MAX_BOARD_SIZE || width < MIN_BOARD_SIZE);
    settings.boardSize[0] = height;
    settings.boardSize[1] = width;
}

//Menu to change the colors of the coins
void changeColorsMenu(settings &settings) {
    int color1, color2;
    const int MAX_COLOR_INDEX = 6;
    const int MIN_COLOR_INDEX = 1;

    do {
        clearScreen();
        cout << "Change the colors of the coins. Available colors:"
             << "\n1: Red"
             << "\n2: Green"
             << "\n3: Yellow"
             << "\n4: Blue"
             << "\n5: Magenta"
             << "\n6: Cyan\n";
        cout << "New coin color for player 1: ";
        cin >> color1;
        cout << "New coin color for player 2: ";
        cin >> color2;
    } while (color1 > MAX_COLOR_INDEX || color1 < MIN_COLOR_INDEX || color2 > MAX_COLOR_INDEX || color2 < MIN_COLOR_INDEX);
    settings.colors[0] = color1;
    settings.colors[1] = color2;
}

//Menu for the different settings
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

//Show the rules of the game
void showHelp() {
    clearScreen();
    string help = "Rules of Connect Four"
                  "\nThe first player that can align 4 coins vertically, horizonzally, or diagonally win the game ! "
                  "\nIf you are alone, you can play against the computer, with a smart AI or a random AI..."
                  "\nThat's it, you know how to play now :)";
    cout << help << endl;
    cout << endl
         << "Press a key and enter to leave ";
    string quit;
    cin >> quit;
}

//Run several rounds of the game
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
             << "4. Show help" << endl
             << "5. Exit" << endl
             << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                whoWon = playGame(true, settings);
                break;
            case 2:
                whoWon = playGame(false, settings);
                break;
            case 3:
                changeSettings(settings);
                clearScreen();
                break;
            case 4:
                showHelp();
                clearScreen();
                break;
            case 5:
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
#ifdef _WIN32
    system(("chcp 65001 "s + to_string(CP_UTF8)).c_str());
    SetConsoleOutputCP(CP_UTF8);
#endif
    settings settings;
    gameMenu(settings);
    cout << "Bye bye !" << endl;
    return EXIT_SUCCESS;
}