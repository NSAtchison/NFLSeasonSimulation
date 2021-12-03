#include "..\headers\team.h" 
#include <iostream>
using namespace std;

    
Team::Team() {
    team_name = "No Team";
    team_num = 0;
    team_div = 0;
    team_conf = 0;
    numWins = 0;
    numGamesPlayed = 0;
    hasPlayed = false;
    madePlayoffs = false;
    playoffSeed = 0;
}

//variable constructor
Team::Team(string name, int digit, int divNum, int confNum) {
    team_name = name;
    team_num = digit;
    team_div = divNum;
    team_conf = confNum;
    numWins = 0;
    numGamesPlayed = 0;
    hasPlayed = false;
    madePlayoffs = false;
    playoffSeed = 0;
}

//Print function
void Team::print() {
    string winString = to_string(numWins);
    int numLosses = numGamesPlayed - numWins;
    string lossString = to_string(numLosses);
    cout << team_name + "(" + winString + "-" + lossString + ")";
}