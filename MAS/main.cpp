// AYHAM AQ, JAN FRIBUS, VINZ SCHOCH
//MAIN CODE

// WARNING: RELEASE VERSION. DONT MESS WITH IT. KONTAKTIER DEVS FÜR FRAGEN

#include <iostream>
#include <ctime>
#include "UI.h"
#include <iomanip>
#include "game.h"
#include <conio.h>
#include <fstream>
#include "saveload.h"
#include <vector>

using namespace std;
//variablen
string cols[] = {"g - green","r - red","w - white","y - yellow","p - pink","m - magneta"};
int max_tries = 10;
int length = 3;
int luckynum = 3;
int roul;

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
extern int cur_tries;
extern string currentgameletters;
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
        if(seledpl.currtries != 10){
        	cur_tries = seledpl.currtries;
        	currentgameletters= seledpl.cur_gameletters;
        	
        	playy(true,true);
		}
        

        player.playerwinstreak = seledpl.playerwinstreak;
        player.name = seledpl.name;
        winstreak = seledpl.playerwinstreak;
    } else {
        cout << endl << "Kein Spieler Gefunden.." << endl;
        cout << "druecken sie bitte eine beliebige taste.." << endl;
        getch();
    }
}

void men(bool firsttime) {
	srand(time(0));
	roul = rand() % 10;
	
	bool play;
    bool bpicked = false;
    bool prntonce = false;
    prntonce = !firsttime;
    while (!bpicked) {
        system("cls");
        if(!prntonce){
        	
        	prntcrtxt(Title, 400);
        	prntonce = true;
        	
        	if(roul < 2){
		pss("sounds/test.wav");
			play =true;
		}
		
		} else {
			prntcrtxt(Title,  0);
			
		}
        stclr(3);
        cout << "\n \n \n";
        
        setw(70);
        stclr(15);
        cout << setw(62) << "\t##########################\n";
         cout << setw(62) <<"\t# 1 - p - Spielen        #\n";
        cout << setw(62) <<"\t##########################\n\n";
        stclr(10);
         cout << setw(62) << "\t##########################\n";
         cout << setw(62) << "\t# 2 - o - Einstellungen  #\n";
         cout << setw(62) << "\t##########################\n\n";
        stclr(9);
         cout << setw(62) << "\t##########################\n";
         cout << setw(62) << "\t#3 - l - Spielstand laden#\n";
         cout << setw(62) << "\t##########################\n\n";
        stclr(7);
         cout << setw(62) << "\t##########################\n";
         cout << setw(62) << "\t# 4 - c - credits        #\n";
         cout << setw(62) << "\t##########################\n\n";
        stclr(4);
         cout << setw(62) << "\t##########################\n";
         cout << setw(62) << "\t# 5 - q - Verlassen      #\n";
         cout << setw(62) << "\t##########################\n\n";
        stclr(15);
       

        if (player.name.empty()) {
            cout << "Spieler nicht gefunden." << endl;
        } else {
        	stclr(4);
            cout << endl << endl << "Name: " << player.name;
            stclr(4);
            cout << endl << "winstreak: " << player.playerwinstreak;
            cout << endl << "currtries: " << player.currtries;
			stclr(15); 
        }
        
		if (!play){
			pss("sounds/menufort.wav");
			
		} 

        ioption = getch();

        switch (ioption) {
            case '1':
            case 'p':
                cout << "Spiel ist am Laden \n ";
                sts();
                pss("sounds/clicksfx.wav");
                playy(true,false);
                bpicked = true;
                break;
            case '2':
            case 'o':
            	pss("sounds/clicksfx.wav");
                settingsmen();
                
                bpicked = true;
                break;
            case '3':
            case 'l':
            	sts();
                pss("sounds/clicksfx.wav");
                loadgame();
                
                
                break;
            case '4':
            case 'c':
            	pss("sounds/clicksfx.wav");
                creds();
                
                bpicked = true;
                break;
            case '5':
            case 'q':
                cout << "Verlassen..." << endl;
                sts();
                pss("sounds/clicksfx.wav");
                exit(1);
                bpicked = true;
                break;
            default:
                cout << "Falsch... Versuchs nochmal." << endl;
                pss("sounds/error.wav");
                break;
        }
    }
}

int main(int argc, char** argv) {
    system("color a");
    
    men(true);
    return 0;
}

