//ayham AQ 
//UI code
#include <iostream>
#include <stdlib.h>
#include "game.h"


using namespace std;
int ioption;
extern int length;
extern int max_tries;

//string Title = "\n \n \n \21 Welcome to mastermind";






void creds(){
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
	printf("\t 1 - set game color length\n \n");
	printf("\t 2 - set max tries\n \n ");
	printf("\t 3 - credits\n \n");
	printf("\t 4 - back\n \n");
	
	
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
				printf("enter the value for max tries: ");
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
				men();
				return;
			//	bpicked = true;
			break;
			default:
				printf("invalid... try again.");
				system("cls");
				printf("\n \n \n");
				printf("\t 1 - set game color length\n \n");
				printf("\t 2 - set max tries\n \n ");
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
	








