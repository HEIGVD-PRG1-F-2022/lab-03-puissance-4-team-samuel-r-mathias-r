/*
 * This project was made during as a school project of the HEIG-Vd.
 * Authors : Samuel R. & Mathias R.
 * Created : 10.18.22
 */

#include <iostream>
#include <iomanip>

using namespace std;

void changeSettings()
{
    system("cls");
    cout << "What settings would you like to change?" << endl << "1. AI mode" << endl << "2. Board size" << endl << "3. Colors" << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
            system("cls");
            cout << "AI mode :" << endl << "1. Smart" << endl << "2. Random" << endl;
            cin >> choice;
            choice == 1 ? 1 : 2;
            if(choice > 2 || choice < 1) cout << "ERREUR!";
            break;
        case 2: playerVSAI(); break;
        case 3: break;
    }
}

void gameMenu()
{
    cout << "Welcome to *Connect Four*!" << endl << "1. Player vs AI" << endl << "2. Player vs Player" << endl << "3. Settings" << endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1: playerVSplayer(); break;
        case 2: playerVSAI(); break;
        case 3: break;
    }
}

int main(){

    return 0;
}