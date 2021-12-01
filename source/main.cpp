#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include "..\headers\arrays.h"
#include "..\headers\team.h"
using namespace std;

void initializeTeams(Team tSet[]);

int main() {


}

//SIDE NOTE WILL FIND RIGHT PLACE LATE
// NFC - 2, AFC - 1
// AFC North - 1, AFC East - 2, AFC South - 3, AFC West - 4
// NFC North - 5, NFC East - 6, NFC South - 7, NFC West - 8
void initializeTeams(Team tSet[]) {
    tSet[0]  = Team("Arizona Cardinals"       ,  0, 8, 2);
    tSet[1]  = Team("Atlanta Falcons"         ,  1, 7, 2);
    tSet[2]  = Team("Baltimore Ravens"        ,  2, 1, 1);
    tSet[3]  = Team("Buffalo Bills"           ,  3, 2, 1);
    tSet[4]  = Team("Carolina Panthers"       ,  4, 7, 2);
    tSet[5]  = Team("Chicago Bears"           ,  5, 5, 2);
    tSet[6]  = Team("Cincinnati Bengals"      ,  6, 1, 1);
    tSet[7]  = Team("Cleveland Browns"        ,  7, 1, 1);
    tSet[8]  = Team("Dallas Cowboys"          ,  8, 6, 2);
    tSet[9]  = Team("Denver Broncos"          ,  9, 4, 1);
    tSet[10] = Team("Detroit Lions"           , 10, 5, 2);
    tSet[11] = Team("Green Bay Packers"       , 11, 5, 2);
    tSet[12] = Team("Houston Texans"          , 12, 3, 1);
    tSet[13] = Team("Indianapolis Colts"      , 13, 3, 1);
    tSet[14] = Team("Jacksonville Jaguars"    , 14, 3, 1);
    tSet[15] = Team("Kansas City Chiefs"      , 15, 4, 1);
    tSet[16] = Team("Las Vegas Raiders"       , 16, 4, 1);
    tSet[17] = Team("Los Angeles Chargers"    , 17, 4, 1);
    tSet[18] = Team("Los Angeles Rams"        , 18, 8, 2);
    tSet[19] = Team("Miami Dolphins"          , 19, 2, 1);
    tSet[20] = Team("Minnesota Vikings"       , 20, 5, 2);
    tSet[21] = Team("New England Patriots"    , 21, 2, 1);
    tSet[22] = Team("New Orleans Saints"      , 22, 7, 2);
    tSet[23] = Team("New York Giants"         , 23, 6, 2);
    tSet[24] = Team("New York Jets"           , 24, 2, 1);
    tSet[25] = Team("Philadelphia Eagles"     , 25, 6, 2);
    tSet[26] = Team("Pittsburgh Steelers"     , 26, 1, 1);
    tSet[27] = Team("San Francisco 49ers"     , 27, 8, 2);
    tSet[28] = Team("Seattle Seahawks"        , 28, 8, 2);
    tSet[29] = Team("Tampa Bay Buccaneers"    , 29, 7, 2);
    tSet[30] = Team("Tennessee Titans"        , 30, 3, 1);
    tSet[31] = Team("Washington Football Team", 31, 6, 2);
}

//WIP SEEDING FUNCTION

// void topFourSeeding(Team tSet[]) {
//     int currTeamNum = 0; int numSeedsFound = 0;
//     int seedArray[4] = {0, 0, 0, 0};
//     for(int i = 1; i <= 2; i++) {
//         for (int j = 1; j <= 4; j++) {
//             bool foundSeed = false;
//             int currTeamNum = 0;
//                 while(foundSeed == false) {
//                     if(tSet[currTeamNum].madePlayoffs == true && tSet[currTeamNum].playoffSeed == 0 && tSet[currTeamNum].team_conf == i) {
//                         seedArray[numSeedsFound] = currTeamNum;
//                     }
//                 }
//         }
//     }
// }