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
extern int ioption;



void men(){
	system("cls");
	//string print way dont forget
	printf(Title.c_str());
	printf("\n \n \n");
	printf("\t 1 - play\n \n");
	printf("\t 2 - options\n \n ");
	printf("\t 3 - Load Game\n \n")
	printf("\t 4 - credits\n \n");
	printf("\t 5 - quit\n \n");
	
	
	scanf("%i",&ioption);
	
	
	bool bpicked = false;
    while(bpicked = false)
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
			case 5:
				//LOAD GAME. fucking hell after 7 hours of coding straight i realized. kms
				
			break;
			default:
				printf("invalid... try again.");
			 	men();
			 	
			
			}
			
		
		
	}
			
	
	
	
	ioption = 0;
	
}



int main(int argc, char** argv) {
	system("color a");
	//cout << setw(55); //width. i used to center the text w it
	men();
	
	
	
	return 0;
}
