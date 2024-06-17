#include <vector>
#include <fstream> //file stream (datei ändern)
#include <iostream>
#include <string>
#include "saveload.h"



extern string savename;


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

 
