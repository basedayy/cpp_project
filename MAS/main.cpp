#include <iostream>
#include "UI.h"
#include <iomanip> //library für cmd ändern
#include "game.h"
#include <conio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

string cols[] = {"g - green","r - red","w - white","y - yellow","p - pink","m - magneta"};
int max_tries= 10;
int length= 3;
string Title = "\n \n \n \21 Welcome to mastermind";
char ioption;
int winstreak = 0;



void men(){
	
	bool bpicked = false;
	//looping menu
	while(!bpicked)
	{
		system("cls");
		//string print way dont forget
		printf(Title.c_str());
		printf("\n \n \n");
		printf("\t 1 - p - play\n \n");
		printf("\t 2 - o - options\n \n ");
		printf("\t 3 - l - Loaddd Game\n \n");
		printf("\t 4 - c - credits\n \n");
		printf("\t 5 - q - quit\n \n");
	
	
		ioption = getch();
	
	 
		
    
		//ioption = 0;
		switch(ioption)
		{
			case '1':
			case 'p':
				printf("going in game \n ");
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
				printf("loading....");
			break;
			
			case '4':
			case 'c':
				creds();
				bpicked = true;
			break;
			case '5':
			case 'q':
				printf("exiting...");
				exit(1);
				bpicked = true;
			break;
			
			default:
				printf("invalid... try again.");
			 	
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
