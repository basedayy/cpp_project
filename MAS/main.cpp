#include <iostream>
#include "UI.h"
#include <iomanip> //library für cmd ändern
#include "game.h"
#include <conio.h>
#include <fstream>
#include "saveload.h"
#include <vector>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

string cols[] = {"g - green","r - red","w - white","y - yellow","p - pink","m - magneta"};
int max_tries= 10;
int length= 3;
string Title = "\n \n \n \21 Wilkommen bei Mastermind";
char ioption;
int winstreak = 0;
struct player player; 
extern int playerselopt;
string filename = "save_game.txt";




void loadgame(){
	system("cls");
	printf("Laden....");
	vector<struct player> players = loadallpls(filename);
	
		if(!players.empty()){
					
				struct player seledpl =  selpl(players);
					
				cout << "Du hast ausgeweahlt: " << seledpl.name <<"\n with winstreak of " << seledpl.playerwinstreak << endl;
				getch();
				
				player.playerwinstreak = seledpl.playerwinstreak;
				player.name = seledpl.name;
				winstreak = seledpl.playerwinstreak;
			}
			 else{
				cout << "Kein Spieler Gefunden.." << endl;
				
				
			}
}


void men(){
	
	bool bpicked = false;
	//looping menu
	while(!bpicked)
	{
		system("cls");
		//string print way dont forget
		printf(Title.c_str());
		printf("\n \n \n");
		printf("\t 1 - p - Spielen\n \n");
		printf("\t 2 - o - Einstellungen\n \n ");
		printf("\t 3 - l - Spielstand laden\n \n");
		printf("\t 4 - c - credits\n \n");
		printf("\t 5 - q - Verlassen\n \n");
		
		if (player.name.empty()){
			cout << "Spieler nicht gefunden." << endl;
		} else{
			cout << endl << endl << "Name: " << player.name;
			cout << endl << "winstreak: " << player.playerwinstreak;	
		}
		
	
		ioption = getch();

		//ioption = 0;
		switch(ioption)
		{
			case '1':
			case 'p':
				printf("Spiel ist am Laden \n ");
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
				//LOAD GAME. fucking hell after 7 hours of coding straight i realized. kms
				
				loadgame();
				
				
			    break;
			case '4':
			case 'c':
				creds();
				bpicked = true;
			break;
			case '5':
			case 'q':
				printf("Verlassen...");
				exit(1);
				bpicked = true;
			break;
			
			default:
				printf("Falsch... Versuchs nochmal.");
			 	
			 	
			 	break;
			 	
			
		}
			
	}
		
}

int main(int argc, char** argv) {
	system("color a");
	//cout << setw(55); //width. i used to center the text w it
	men();
	
	
	
	return 0;
}
