#ifndef ARRAYS_H
#define ARRAYS_H

// Historic Head-to-Head win percentages as of November 21, 2021
// Entries represent the probability that first team beating the second team
const float TEAM_WIN_PERCENTAGE[32][32];

// Current Schudule for the upcoming season (In this case used 2021)
// Entries represent who that person is going to play in the week (i.e. if entry is 31 in row 1, they play team 31 in week 1)
// Entry of -1 indicates that the team is currently on their bye week
const int TEAM_SCHEDULE[18][32];


#endif


