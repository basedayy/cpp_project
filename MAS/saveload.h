#include <iostream>
#include <vector>
using namespace std;

struct player{
	string name;
	int playerwinstreak;
};

void savegame(const player playerr,const string filename);

vector<player> loadallpls(string filename);
 
player selpl(vector<struct player> players);



