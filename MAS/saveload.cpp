//ayhamAQ
//save func

#include <vector> //vector ist eine dynamischer array
#include <fstream> //file stream (datei ändern)
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
		cout << "Spiel gespeichert!" << endl;
	}else{
		cerr << "Gepeicherter Spielstand konnte nicht Geoeffnet werden." << endl;
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
		 
		 cout << "Geladene Liste" << endl;
 		
	 }else{
	 	
	 	cerr << "Schlecht. hat nicht geladen" << endl;
	 	
	 	
	 }
	 return players;
 }
 
 //select players func
 player selpl(vector<player> players){
 	cout << "Der Spieler: " << endl;
 	
 	//durch alle spieler wiedeholen (scan players)
	for (size_t i = 0; i < players.size(); i++){
		cout << i + 1 << "- " << players[i].name << " winstreak: " << players[i].playerwinstreak << endl;
		
	}
	
	
	int playerselopt;
	bool plselected = false;
	//solange keinspieler würde genomen
	while(!plselected) {
		
		cout << "Spieler auswahl!" << endl;
		
		cin >> playerselopt;
		
		if(cin.fail() || playerselopt < 1 || playerselopt > static_cast<int>(players.size())){
			cin.clear();
			//ignoriert alle die über der spielerzahl oder unter 1 oder wenn es eine buchstabe wäre.
			
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			
			cout << "Falsche Auswahl. Versuche es nochmal, Bitte gib eine Nummer zwischen 1 und " << players.size()<< "." << endl;
			
			
		}
		else {
			plselected = true;
			return players[playerselopt - 1];
			
			
		}
		
		
	}
 }

