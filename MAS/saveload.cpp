//ay AQ
//save func


// WARNING: RELEASE VERSION. DONT MESS WITH IT. KONTAKTIER DEVS FÜR FRAGEN
#include <vector> //vector ist eine dynamischer array
#include <fstream> //file stream (datei ändern)
#include <iostream>
#include <string>
#include "saveload.h"
#include <conio.h>
#include <limits>


using namespace std;
extern string filename;



void savegame(const player playerr,const string filename,bool ingame,int currtries, string cur_gameletters){
	ofstream file(filename.c_str(),ios::app);
	
	if (file.is_open()){
		file << playerr.name << endl;
		file << playerr.playerwinstreak << endl;
		file << ingame << endl;
		file << currtries << endl;
		file << cur_gameletters << endl;
		
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
 		bool ingame;
 		int currtries;
 		string currentgameletters;
 		
 		string winstreakstr,ingamestr,currtriesstr;
 		
 		
 		//jeden winstreak und name ziehen und aflisten auf command
 		
 		while(getline(file,name)) {
 			if(!getline(file,winstreakstr)) break;
 			if(!getline(file,ingamestr)) break;
 			if(!getline(file,currtriesstr)) break;
 			
 			getline(file,currentgameletters);
 			
 			
 			winstreak = stoi(winstreakstr);
 			ingame = stoi(ingamestr);
 			currtries = stoi(currtriesstr);
 			
 			players.push_back({name,winstreak,ingame,currtries,currentgameletters});
 			
 			
		 }
 		/**while(file >> name >> winstreak >> ingame >> currtries){	
 			if (!currentgameletters.empty()){
 				players.push_back({name,winstreak,ingame,currtries,currentgameletters});
			} else{
				players.push_back({name,winstreak,ingame,currtries,"none"});
			 
			}
			
			 
		 }
		 
		 **/
		 file.close();
		 
		 cout << "Geladene Liste" << endl;
 		
	 }else{
	 	
	 	cerr << endl << "Schlecht. hat nicht geladen" << endl;
	 	
	 	
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

