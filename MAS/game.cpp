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
int cur_tries = 10;
string gameletters;
string currentgameletters;
bool win = false;
bool pause = false;
string losstext[] = {"Du hasst leider Verloren... \n try again?", "Du hasst Verloren, willst du es nochmal prbieren ?", "whoops, Das wars...\n Noch ein Versuch?"};
string wintext[] = {"Gut gemacht, Noch mal?", "Gute Arbeit, Noch ein Versuch?", "Gute arbeit, willst du es noch einmal versuchen?"};
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

void poss(){
	
	if(playerguess == currentgameletters){
		win = true;
		printf("\n Du hasst Gewonnen!");
		
		} else if (playerguess != currentgameletters){
			printf("\n false\n");
		}
		
		vector<bool> matched(playerguess.size(), false);
		//l�nge von der wort holen ( also wie viele buchstaben.)
	int len = min(currentgameletters.size(),playerguess.size());
	//neue string f�r die results (alles falsch wird nicht markiert)
	string result(len, ' ');
	
	//erste schritt. filter alle richtige mit =
	for (int i = 0; i < len; ++i){
		if(currentgameletters[i] == playerguess[i]){
			result[i] = '+';
			
		} else if (playerguess[i] == '.'){
			cout << ". IS DETECTED \n";
			pause = true;
			
		}
	}
	
	
	//markiere alles mit tilde wenn es richtige farbe aber in falscher position
	for (int i = 0; i < len; ++i){
		//n�r f�r die leere stellen die nicht korrigiert sind pr�fen 
		if (result[i] == ' '){
			
			for(int c = 0; c < len; ++c){
				//wenn irgendwelche charactere von spieler passen f�r des rechner
				if (!matched[c]&&currentgameletters[i]==playerguess[c]){
					result[c] = '-';
					matched[c]= true;
					break;
				}
			}
		}
	}
	
	//den antwort dr�cken aber mit ~ =
	cout << "\n" << result << endl;
	
}


void playy(bool newg,bool loadgletters){
	
	string availablecols;
	
	player pl;
	
	//Rules
	system("cls");
	
	
	if(newg){
		
		shuffle(cols,arrlength);
	//gleiche wie maximal, �nderbar in main
	
	
	effect("Du hast 10 Versuche. Solltest du es nicht schaffen Verlierst du. GO!\n"  
	"\n tip: \n + bedeutet das die Farbe an richtiger stelle ist"
	"\n - bedeutet das es die Farbe gibt, aber an falscher stelle."
	"\n use color codes for as answer (rgbp): ", 300);
	
	grabfirstletterofarray(cols);
	
	//cout << availablecols;
	
	printf("\n");
	cout << currentgameletters;
	
	
	}else{
	printf("Du hast 10 Versuche. Solltest du es nicht schaffen Verlierst du. GO!\n");
	printf("\n tip: \n + bedeutet das die Farbe an richtiger stelle ist");
	printf("\n - bedeutet das es die Farbe gibt, aber an falscher stelle.");
	printf("\n use color codes for as answer (rgbp): ");
	grabfirstletterofarray(cols);
	
	
	printf("\n");

	//cout << availablecols;
	//cout << currentgameletters;
	}
	
	if(currentgameletters.empty()){
		
		
		currentgameletters = gameletters;
	} 
	cout << currentgameletters;
	
	
	
	
	
	//solange es ist nicht 0
	while(cur_tries != 0){
		char tmp[length];
		scanf("%s", tmp);
		playerguess = tmp;
	
		//printf(playerguess.c_str());
		
		currentgameletters.c_str();
		
	
		
	
		poss();
		
		if(win){
			break;
		}
		
		if(pause){
			pausemen();
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
		currentgameletters = "";
		//optionen
		int randtext = rand() % 3; //same size as the array of the losstext
		cout << "Du hasst deine Streak Verloren. Deine Jetzige streak lautet: " << winstreak << endl;
		cout << losstext[randtext] << endl;
		cout << relquest;
		char gameopt = getch();
		bool selected;
	
		while(gameopt != '1' ||gameopt!= '2'){
			if (gameopt == '1'||gameopt == 'y'){
			playy(true,false);
		}
		else if(gameopt == '2'||gameopt == 'n'){
			men(false);
			
		}
		else{
			system("cls");
			cout << "Falsch...";
			cout << "Nochmalch";
			gameopt = 0;
			gameopt = getch();
			
		}	
		
	}
	
	} else if (win) {
		
		winstreak = winstreak + 1;
		
		
		gameletters = "";
		currentgameletters = "";
		int randtext = rand() % 3;//same size as the array of the wintext
		cout << wintext[randtext] << endl;
		cout << "Deine Streak lautet : " << winstreak << endl;
		cout << relquest;
			char gameopt = getch();
		bool selected;
	
		
		while(gameopt != '1'|| gameopt != '2'){
			if (gameopt == '1'||gameopt == 'y'){
			win = false;
			playy(true,false);
			selected = true;
			
		}
		else if(gameopt == '2'||gameopt == 'n'){
			win = false;
			currentgameletters = "";
			cout << "Spiel Speichern??";
			
			bool save = false;
			
			while (!save){
				char savereq = getch();
				
				switch(savereq)
				{
				case 'y':
				case '1':
				{
						cout << "\n gib dein nutzername ein: ";
				string nametemp;
				cin >> nametemp;
				player player = {nametemp,winstreak,cur_tries};
				
				savegame(player,filename,false,cur_tries,currentgameletters);
				save = true;
				winstreak = 0;
				men(false);
				break;
			}
				case 'n': case '2':
					{
						men(false);
					save = true;
					break;
					}
					
				default:
				   {
				   	save = false;
				   	
				break;
				   	
				   }
				
				
			}
			
			selected = true;
				
			}
			
			
		}
		else{
			system("cls");
			cout << "Falsch...";
			cout << "Versuchs nochmal\n";
			cout << relquest;
			gameopt = 0;
			gameopt = getch();
			
		}
		
			
			
		}	
		
	}
}
	
	
	//for(int i = 0; i < length; i++){
	//	cout << cols[i] << endl;
	//}
	
	

