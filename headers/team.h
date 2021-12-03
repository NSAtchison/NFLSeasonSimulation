#ifndef TEAM_H
#define TEAM_H
#include <iostream>
using namespace std;

class Team {
    public:
    //Attributes
        string team_name;
        int team_num;
        int team_div;
        int team_conf;
        int numWins;
        int numGamesPlayed;
        bool hasPlayed;
        bool madePlayoffs;
        int playoffSeed;

    //Behaviors
    //default constructor
        Team();

        //variable constructor
        Team(string name, int digit, int divNum, int confNum);

        //Print function
        void print();
};

#endif