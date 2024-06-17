#include <iostream>
#include <vector>
using namespace std;

struct player{
	string name;
	int playerwinstreak;
};

void savegame(const player playerr,const string filename);

vector<player> loadallpls(const string filename);


player selpl(const vector<player>& players);
