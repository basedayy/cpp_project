#include <iostream>
#include <vector>
using namespace std;

struct player{
	string name;
	int playerwinstreak;
	bool ingame;
	int currtries;
	string cur_gameletters;
};

void savegame(const player playerr,const string filename,bool ingame,int currtries,string cur_gameletters);

vector<player> loadallpls(string filename);
 
player selpl(vector<struct player> players);



