#include <iostream>
#include "UI.h"
#include <iomanip> //library für cmd ändern
#include "game.h"
#include <conio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

string cols[] = {"g - green","r - red","w - white","y - yellow","p - pink"};
int max_tries= 10;
int length= 3;
string Title = "\n \n \n \21 Welcome to mastermind";
char ioption;





void men(){
	
	
	bool bpicked = false;
	
	while(!bpicked)
	{
		system("cls");
		//string print way dont forget
		printf(Title.c_str());
		printf("\n \n \n");
		printf("\t 1 - play\n \n");
		printf("\t 2 - options\n \n ");
		printf("\t 3 - Load Game\n \n");
		printf("\t 4 - credits\n \n");
		printf("\t 5 - quit\n \n");
	
	
		ioption = getch();
	
	
	
    
		
		switch(ioption)
		{
			case '1':
				printf("going in game \n ");
				playy();
				
				bpicked = true;
				break;
			case '2':
				settingsmen();
				bpicked = true;
				break;
			case '3':
		    case 'l':
			//LOAD GAME. fucking hell after 7 hours of coding straight i realized. km
			cout << "loading game";
				
			break;
			case '4':
			case 'c':
				creds();
				bpicked = true;
			break;
			case '5':
				
				printf("exiting...");
				exit(0);
			
				
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
