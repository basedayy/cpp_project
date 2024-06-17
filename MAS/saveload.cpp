//ayhamAQ
//save func

#include <vector> //vector ist eine dynamischer array
#include <fstream> //file stream (datei �ndern)
#include <iostream>
#include <string>
#include "saveload.h"
#include <conio.h>
#include <limits>



extern string filename;


void savegame(const player playerr,const string filename){
	ofstream file(filename.c_str(),ios::app);
	
	if (file.is_open()){
		file << playerr.name << endl;
		file << playerr.playerwinstreak << endl;
		
		file.close();
		cout << "game Saved!" << endl;
	}else{
		cerr << "unable to open file for saving." << endl;
	}
}

 
 
 //spieler auflisten von einer datei
 vector<player> loadallpls(string filename){
 	vector<player> players;
 	ifstream file(filename.c_str());
 	
 	
 	//op der datei offen ist
 	if(file.is_open()){
 		string name;
 		int winstreak;
 		
 		//jeden winstreak und name ziehen und aflisten auf command
 		while(file >> name >> winstreak){
 			players.push_back({name,winstreak});
		 }
		 file.close();
		 
		 cout << "loaded list" << endl;
 		
	 }else{
	 	
	 	cerr << "bad. didnt load" << endl;
	 	
	 	
	 }
	 return players;
 }
 
 //select players func
 player selpl(vector<player> players){
 	cout << "the players: " << endl;
 	
 	//durch alle spieler wiedeholen (scan players)
	for (size_t i = 0; i < players.size(); i++){
		cout << i + 1 << "- " << players[i].name << " winstreak: " << players[i].playerwinstreak << endl;
		
	}
	
	
	int playerselopt;
	bool plselected = false;
	//solange keinspieler w�rde genomen
	while(!plselected) {
		
		cout << "choose the player you want!" << endl;
		
		cin >> playerselopt;
		
		if(cin.fail() || playerselopt < 1 || playerselopt > static_cast<int>(players.size())){
			cin.clear();
			//ignoriert alle die �ber der spielerzahl oder unter 1 oder wenn es eine buchstabe w�re.
			
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			
			cout << "invalid choice. try again, please enter a number between 1 and " << players.size()<< "." << endl;
			
			
		}
		else {
			plselected = true;
			return players[playerselopt - 1];
			
			
		}
		
		
	}
 }

