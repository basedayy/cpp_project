#include <iostream>
#include "UI.h"
#include <iomanip>
#include "game.h"
#include <conio.h>
#include <fstream>
#include "saveload.h"
#include <vector>

using namespace std;

string cols[] = {"g - green","r - red","w - white","y - yellow","p - pink","m - magneta"};
int max_tries = 10;
int length = 3;

string Title = "\n"
    " __       __                        __                                        __                  __ \n"
    "|  \\     /  \\                      |  \\                                      |  \\                |  \\\n"
    "| $$\\   /  $$  ______    _______  _| $$_     ______    ______   ______ ____   \\$$ _______    ____| $$\n"
    "| $$$\\ /  $$$ |      \\  /       \\|   $$ \\   /      \\  /      \\ |      \\    \\ |  \\|       \\  /      $$\n"
    "| $$$$\\  $$$$  \\$$$$$$\\|  $$$$$$$ \\$$$$$$  |  $$$$$$\\|  $$$$$$\\| $$$$$$\\$$$$\\| $$| $$$$$$$\\|  $$$$$$$\n"
    "| $$\\$$ $$ $$ /      $$ \\$$    \\   | $$ __ | $$    $$| $$   \\$$| $$ | $$ | $$| $$| $$  | $$| $$  | $$\n"
    "| $$ \\$$$| $$|  $$$$$$$ _\\$$$$$$\\  | $$|  \\| $$$$$$$$| $$      | $$ | $$ | $$| $$| $$  | $$| $$__| $$\n"
    "| $$  \\$ | $$ \\$$    $$|       $$   \\$$  $$ \\$$     \\| $$      | $$ | $$ | $$| $$| $$  | $$ \\$$    $$\n"
    " \\$$      \\$$  \\$$$$$$$ \\$$$$$$$     \\$$$$   \\$$$$$$$ \\$$       \\$$  \\$$  \\$$ \\$$ \\$$   \\$$  \\$$$$$$$\n"
    "                                                                                                     \n";

char ioption;
int winstreak = 0;
struct player player; 
extern int playerselopt;
string filename = "save_game.txt";

void loadgame() {
    system("cls");
    printf("Laden....");
    vector<struct player> players = loadallpls(filename);

    if (!players.empty()) {
        struct player seledpl = selpl(players);
        cout << "Du hast ausgeweahlt: " << seledpl.name << "\n with winstreak of " << seledpl.playerwinstreak << endl;
        getch();

        player.playerwinstreak = seledpl.playerwinstreak;
        player.name = seledpl.name;
        winstreak = seledpl.playerwinstreak;
    } else {
        cout << "Kein Spieler Gefunden.." << endl;
    }
}

void men(bool firsttime) {
    bool bpicked = false;
    bool prntonce = false;
    prntonce = !firsttime;
    while (!bpicked) {
        system("cls");
        if(!prntonce){
        	
        	prntcrtxt(Title, 400);
        	prntonce = true;
		} else {
			prntcrtxt(Title,  0);
		}
        stclr(3);
        cout << "\n \n \n";
        cout << "\t 1 - p - Spielen\n \n";
        stclr(10);
        cout << "\t 2 - o - Einstellungen\n \n ";
        stclr(9);
        cout << "\t 3 - l - Spielstand laden\n \n";
        stclr(7);
        cout << "\t 4 - c - credits\n \n";
        stclr(4);
        cout << "\t 5 - q - Verlassen\n \n";
        stclr(15);

        if (player.name.empty()) {
            cout << "Spieler nicht gefunden." << endl;
        } else {
        	stclr(4);
            cout << endl << endl << "Name: " << player.name;
            stclr(4);
            cout << endl << "winstreak: " << player.playerwinstreak;
			stclr(15); 
        }

        ioption = getch();

        switch (ioption) {
            case '1':
            case 'p':
                cout << "Spiel ist am Laden \n ";
                playy();
                bpicked = true;
                break;
            case '2':
            case 'o':
                settingsmen();
                bpicked = true;
                break;
            case '3':
            case 'l':
                loadgame();
                break;
            case '4':
            case 'c':
                creds();
                bpicked = true;
                break;
            case '5':
            case 'q':
                cout << "Verlassen..." << endl;
                exit(1);
                bpicked = true;
                break;
            default:
                cout << "Falsch... Versuchs nochmal." << endl;
                break;
        }
    }
}

int main(int argc, char** argv) {
    system("color a");
    
    men(true);
    return 0;
}

