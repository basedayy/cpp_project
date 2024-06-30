//ayham AQ 
//Jan Fribus
//Vinzenz Schoch
//UI code

// WARNING: RELEASE VERSION. DONT MESS WITH IT. KONTAKTIER DEVS FÜR FRAGEN
#include <iostream>
#include <stdlib.h>
#include "game.h"
#include <windows.h>
#include <conio.h>
#include "UI.h"
#include "saveload.h"
#pragma comment(lib,"winmm.lib")

using namespace std;
extern char ioption;
extern int length;
extern int max_tries;
extern bool pause;
extern string filename;
extern int cur_tries;
extern int winstreak;
extern string currentgameletters;
//string Title = "\n \n \n \21 Welcome to mastermind";


void pss(LPCSTR soundloc){
	PlaySoundA(soundloc,NULL,SND_FILENAME | SND_ASYNC);
}
void sts(){
	PlaySound(NULL,NULL,0);
}


void pausemen(){
	
	while(pause)
	{
		
	int iopt;
	string name;
	system("cls");
	printf("\n \n \n PAUSE MENU\n \n");
	stclr(2);
	printf("\t 1 - back to game\n \n");
	stclr(3);
	printf("\t 2 - speichern\n \n");
	stclr(4);
	printf("\t 3 - quit\n \n");
	stclr(15);
	
	cin >> iopt;
	
		switch(iopt){
			case 1: 
			{
				cur_tries = cur_tries + 1;	
				pause = false;		
				playy(false,false);
				
				break;
			}
			case 2:
				{
					cout << "please enter your name: ";
				cin >> name;
				player player = {name,winstreak,cur_tries};
				
				savegame(player,filename,true,cur_tries,currentgameletters);	
				pause = false;	
				cur_tries = max_tries;
				men(false);		
				break;
				}
				
			case 3:
				{
				cur_tries = max_tries;
				pause = false;	
				men(false);
				
				break;
				}

			default:
				cout << "invalid... try again";
			
			
			
			
			
		}
	
		
		
	}
	
}


void stclr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void prntcrtxt(string text, int Ms = 400) {
    int colors[] = {1, 2, 3, 4, 5, 6}; // Colors for Chroma effect
    int colorIndex = 0;

	//loop to color 
    for (size_t i = 0; i < text.length(); ++i) {
        stclr(colors[colorIndex]);
        cout << text[i];
        colorIndex = (colorIndex + 1) % 6;
        // printing effect.
        if (text[i] == '\n') {
            Sleep(Ms); // Adds a small delay to create the effect (using Windows Sleep)
        }
    }
    stclr(7); // Reset to default color
}


void effect(string text,int Ms){
	for (size_t i = 0; i < text.length(); ++i) {
        cout << text[i];
        // printing effect.
        if (text[i] == '\n') {
            Sleep(Ms); // Adds a small delay to create the effect (using Windows Sleep)
        }
    }
}

void creds(){
	bool notexited = true;
	char exit; 
	while (notexited){
		
		system("cls");
		printf("\n \n \n \n \n \n this application was proudly done by:\n \n");
		cout << "\t Ayham AQ - coding\n \n "<< endl;
		printf("\t Jan Fribus - coding and design\n \n");
		printf("\t Vinzenz schoch - Documentation\n \n");
		printf("\t Nicht vergessen. wir alle haben gleich Zusammen gearbeitet\n \n");
		Sleep(100);
		printf("drucken sie eine beliebige taste...");
		
		exit = getch();
		
		if(exit){
			men(false);
			notexited = false;
		}
		
		
		
	}
	system("cls");
	printf("\n \n \n \n \n \n this application was proudly done by:\n \n");
	cout << "\t Ayham AQ - coding\n \n "<< endl;
	printf("\t Jan Fribus - \n \n");
	printf("\t Vinzenz schoch - \n \n");
	
	
	
}

void settingsmen(){
	
	bool optpick = false;
    while(!optpick)
	{
		 
		char option;
		system("cls");
		printf("\n \n \n");
		stclr(2);
		printf("\t 1 - set game color length\n \n");
		stclr(3);
		printf("\t 2 - Maximale Versuche\n \n ");
		stclr(5);
		printf("\t 3 - credits\n \n");
		stclr(4);
		printf("\t 4 - back\n \n");
		stclr(15);
	
	
		scanf("%s",&option);
		
			switch(option)
		{
			case '1':
				int templen;
				printf("enter the value for color length from 1 to 6");
				scanf("%i", &templen);
				if (templen < 7 && templen > 0){
				length = templen;
				pss("sound/clicksfx.wav");
				} else {
					cout << "falsche eingabe";
					option = 1;
					pss("sounds/error.wav");
				}
				
			
				break;
			case '2':
			int temptries;
				printf("Gibt die Maximale an Versuchen ein: ");
				scanf("%i", &temptries);
				if(temptries <1){
					
				}else {
					max_tries = temptries;
					pss("sounds/error.wav");
				}
				option = 1;
				
				temptries = 0;
			//settingsmen();	
			break;
			case '3':
				creds();
			//	bpicked = true;
			break;
			case '4':
				optpick = true;
				men(false);
				return;
			//	bpicked = true;
			break;
			default:
				printf("Falsch... Versuchs nochmal.");
				break;
			 	
			
		}
	}
}



	
			
		
/**void men(){
	string print way dont forget
	printf(Title.c_str());
	printf("\n \n \n");
	printf("\t 1 - play\n \n");
	printf("\t 2 - options\n \n ");
	printf("\t 3 - credits\n \n");
	printf("\t 4 - quit\n \n");
	
	
	scanf("%i",&ioption);
	
	
	//bool bpicked = false;
   // while(ioption < 1 || ioption > 4)
	{
		//ioption = 0;
		switch(ioption)
		{
			case 1:
				printf("going in game \n ");
				playy();
				
				//bpicked = true;
				break;
			case 2:
				settingsmen();
			//	bpicked = true;
			break;
			case 3:
				creds();
			//	bpicked = true;
			break;
			case 4:
				printf("exiting...");
				exit(1);
			//	bpicked = true;
			break;
			default:
				printf("invalid... try again.");
			 	
			
			}
			
		
		
//	}
			
	
	
	
	ioption = 0;
	
}**/
	








