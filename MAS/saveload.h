#include <iostream>
#include <vector>
using namespace std;

struct player{
	string name;
	int playerwinstreak;
};

void savegame(const player playerr,const string filename);

vector<player> loadallgames(const string filename);


player selectplayer(const vector<player> players);
