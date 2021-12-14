// Nathan Atchison & John Twutchell
// December 18, 2021
// CS-171-3
// License: Copyright 2021 Nathan Atchison & John Twitchell

#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include "..\headers\team.h"
#include "functions.h"
using namespace std;


int main() {
    srand(time(NULL)); //Random seed for game simulations

    Team nflTeams[32];
    int NFCPlayoffTeams[7] = {-1, -1, -1, -1, -1, -1, -1}; //Intilized to -1 as to have a value not representing a team
    int AFCPlayoffTeams[7] = {-1, -1, -1, -1, -1, -1, -1}; //Intilized to -1 as to have a value not representing a team
    initializeTeams(nflTeams);
    for(int week = 0; week < 18; week++) { //Runs for every week of the NFL regular season
        weeklyReset(nflTeams);
        regSeasonWeek(nflTeams, week);
    }
    divRankings(nflTeams);
    playoffSeeding(nflTeams, NFCPlayoffTeams, AFCPlayoffTeams);
    simPlayoffs(nflTeams, NFCPlayoffTeams, AFCPlayoffTeams);
}


