#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "UI.h"
#include <iterator>
#include <vector>
#include <conio.h>
#include "saveload.h"

using namespace std;

extern string cols[];
extern int max_tries;
extern int length;
extern int winstreak;
int arrlength = 6;
int randindex = 0;
string playerguess;
int gameopt;
string gameletters;
bool win = false;
string losstext[] = {"you lost, what a shame... \n try again?", "you lost. try again?", "whoops, tough luck...\n again?", "what a disappointment. again?","damn what a luck. again?", "are you a 5yo? or can you prove me wrong? \n try again?"};
string wintext[] = {"nice one, again?", "well done, again?", "nicely done, wanna play again", "you seem to be up for a challenge. again?", "hell yeah!, thats what im talking about. again"};
string relquest = "y or 1 for yes, n or 2 for no";

extern string filename;

//randomize
//mit der fisher-yates algorithmus kann ich die strings mischen. mit der srand time 0 kann ich real-time seed als generator nutzen
void shuffle(string cols[],int length){
	srand(time(0));
	string temp;
	
	for (int i=0; i < length; i++){
		randindex = rand() % (i+1);
		temp = cols[i];
		cols[i]= cols[randindex];
		cols[randindex] = temp;
	}
	
}






void grabfirstletterofarray(string colors[]){
	
	for(int i = 0; i < length;i++){
		//cout << colors[i].substr(0,2) << endl;
		
		gameletters = gameletters + colors[i].substr(0,1);
		
		
	}


}

poss(){
	if(playerguess == gameletters){
		win = true;
		printf("\n you WIN!");
		
		} else if (playerguess != gameletters){
			printf("\n false\n");
		}
		
		vector<bool> matched(playerguess.size(), false);
		//l�nge von der wort holen ( also wie viele buchstaben.)
	int len = min(gameletters.size(),playerguess.size());
	//neue string f�r die results (alles falsch wird nicht markiert)
	string result(len, ' ');
	
	//erste schritt. filter alle richtige mit =
	for (int i = 0; i < len; ++i){
		if(gameletters[i] == playerguess[i]){
			result[i] = '=';
			
		}
	}
	
	
	//markiere alles mit tilde wenn es richtige farbe aber in falscher position
	for (int i = 0; i < len; ++i){
		//n�r f�r die leere stellen die nicht korrigiert sind pr�fen 
		if (result[i] == ' '){
			
			for(int c = 0; c < len; ++c){
				//wenn irgendwelche charactere von spieler passen f�r des rechner
				if (!matched[c]&&gameletters[i]==playerguess[c]){
					result[c] = '~';
					matched[c]= true;
					break;
				}
			}
		}
	}
	
	//den antwort dr�cken aber mit ~ =
	cout << "\n" << result << endl;
	
}


void playy(){
	
	
	shuffle(cols,arrlength);
	//gleiche wie maximal, �nderbar in main
	int cur_tries = max_tries;
	
	
	//Rules
	system("cls");
	printf("you got 10 retrys. if you fail you lose. GO!\n");
	printf("\n tip: \n - = bedeutet das der farbe an richtiger stelle ist");
	printf("\n - ~ bedeutet das der farbe gibt, aber in falscher stelle.");
	printf("\n use color codes for as answer (rgbp): ");
	
	grabfirstletterofarray(cols);
	
	printf("\n");
	
	cout << gameletters;
	//solange es ist nicht 0
	while(cur_tries != 0){
		char tmp[length];
		scanf("%s", tmp);
		playerguess = tmp;
	
		//printf(playerguess.c_str());
		
		gameletters.c_str();
		
		
		
	
		poss();
		
			if(win){
			break;
		}
		
		cout << cur_tries << " left." << endl;	
		cur_tries--;
		
	}
		
	
	
	//wenns verloren
	if (!win){
		
	
		
		//reset
		winstreak= 0;
		cur_tries = max_tries;
		gameletters = "";
		//optionen
		int randtext = rand() % 5;
		cout << "you lost your streak. your streak is: " << winstreak << endl;
		cout << losstext[randtext] << endl;
		cout << relquest;
		char gameopt = getch();
		bool selected;
	
		while(gameopt != '1' ||gameopt!= '2'){
			if (gameopt == '1'||gameopt == 'y'){
			playy();
		}
		else if(gameopt == '2'||gameopt == 'n'){
			men();
			
		}
		else{
			system("cls");
			cout << "invalid...";
			cout << "again";
			gameopt = 0;
			gameopt = getch();
			
		}	
		
	}
	
	} else if (win) {
		
		winstreak = winstreak + 1;
		
		
		gameletters = "";
		int randtext = rand() % 5;
		cout << wintext[randtext] << endl;
		cout << "your streak is : " << winstreak << endl;
		cout << relquest;
			char gameopt = getch();
		bool selected;
	
		
		while(gameopt != '1'|| gameopt != '2'){
			if (gameopt == '1'||gameopt == 'y'){
			win = false;
			playy();
			selected = true;
			
		}
		else if(gameopt == '2'||gameopt == 'n'){
			win = false;
			cout << "save game?";
			char savereq = getch();
			if(savereq == 'y' ||savereq == '1'){
				cout << "\n enter your name: ";
				string nametemp;
				cin >> nametemp;
				player player = {nametemp,winstreak};
				
				savegame(player,filename);
				men();
			} else if(savereq == 'n'||savereq == '2'){
				men();
			}
			
			selected = true;
			
		}
		else{
			system("cls");
			cout << "invalid...";
			cout << "again";
			gameopt = 0;
			gameopt = getch();
			
		}
		
			
			
		}	
		
	}
}
	
	
	//for(int i = 0; i < length; i++){
	//	cout << cols[i] << endl;
	//}
	
	

