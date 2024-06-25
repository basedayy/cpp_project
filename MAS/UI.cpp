//ayham AQ 
//Jan Fribus
//Vinzenz Schoch
//UI code
#include <iostream>
#include <stdlib.h>
#include "game.h"
#include <windows.h>
#include <conio.h>
#include "UI.h"
#include "saveload.h"


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
				men(false);		
				break;
				}
				
			case 3:
				{
				men(false);
				pause = false;	
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
		printf("\t Jan Fribus - \n \n");
		printf("\t Vinzenz schoch - \n \n");
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
	ioption = 0;
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
	
	
	scanf("%i",&ioption);
	
	
	//bool bpicked = false;
   // while(ioption < 1 || ioption > 4)
//	{
		
			switch(ioption)
		{
			case 1:
				int templen;
				printf("enter the value for color length ");
				scanf("%i", &templen);
				length = templen;
				templen = 0;
				settingsmen();
				break;
			case 2:
			int temptries;
				printf("Gibt die Maximale an Versuchen ein: ");
				scanf("%i", &temptries);
				max_tries = temptries;
				temptries = 0;
			settingsmen();	
			break;
			case 3:
				creds();
			//	bpicked = true;
			break;
			case 4:
				men(false);
				return;
			//	bpicked = true;
			break;
			default:
				printf("Falsch... Versuchs nochmal.");
				system("cls");
				printf("\n \n \n");
				printf("\t 1 - set game color length\n \n");
				printf("\t 2 - Max versuche eingebn\n \n ");
				printf("\t 3 - credits\n \n");
				printf("\t 4 - back\n \n");
				
			 	
			
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
	








