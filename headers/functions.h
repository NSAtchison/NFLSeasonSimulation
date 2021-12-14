#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//Fill in data for the array tSet
void initializeTeams(Team tSet[]);

// Plays a game between 2 of the NFL teams
// Input tSet[] is the array of NFL teams, t1Num and t2Num play each other
// Updates the win and loss total for teams after the game has been played
// probability based on all-time Head to head data
void playRegSeasonGame(Team tSet[], int t1Num, int t2Num);

// Simulates an entire week of NFL games
// Input tSet[] is the array of NFL teams, currWeek is the current week in the season
// post: num_wins updated for each NFL team
void regSeasonWeek(Team tSet[], int currWeek);

// Prints results of a played game
// Input tSet[] is the array of NFL teams, t1 and t2 played each other
void printGameResults(int num, Team t1, Team t2);

// Prints if a team is on bye
// Input: tSet[] is the array of NFL teams, currWeek is the current week in the season
void printOnBye(Team tSet[], int currWeek);

// Resets each team so that they are seen as having not played
// Input: tSet[] is the array of NFL teams
// post: has_played updated to false for every team
void weeklyReset(Team tSet[]);

// Prints the division rankings at the end of the season and puts the division winners into the playoffs
// Input: tSet[] is the array of NFL teams
// Output: Division rankings
// post: division winners have made_playoffs set to true
void divRankings(Team tSet[]);

// Finds the team with the least amount of wins
// Input: divArr[] is an array containing the numbers correllating to the teams of the division currently being looked at
//        tSet[] is the array of NFL teams; used so we can compared win totals
// post: team with least amount of wins is placed in first position of divArr
void divLeastWins(int divArr[], Team tSet[]);

// Finds the team with the least amount of wins
// Input: divArr[] is an array containing the numbers correllating to the teams of the division currently being looked at.
//        At this point, the team with the least amount of wins has already been found.
//        tSet[] is the array of NFL teams; used so we can compared win totals
// post: team with most amount of wins is placed in fourth position of divArr
void divMostWins(int divArr[], Team tSet[]);

// Finds the correct ordering of the middle two teams within the division in terms of wins
// Input: divArr[] is an array containing the numbers correllating to the teams of the division currently being looked at.
//        At this point, the team with the least amount of wins and the team who won the division (most amount of wins) have already been found.
//        tSet[] is the array of NFL teams; used so we can compared win totals
// post: remaining two teams have been ordered correctly with the team with less wins placed at second positon of divArr and other placed at third position
//       of divArr.
void divMidWins(int divArr[], Team tSet[]);

// Sorts the NFL teams in divArr by the number of wins they have from least amount to greatest (left to right, position 1->4)
// Input: divArr[] is an array containing the numbers correllating to the teams of the division currently being looked at.
//        tSet[] is the array of NFL teams; used so we can compared win totals
// post:  divArr has been updated so that teams have been ordered by number of wins
void divSort(int divArr[], Team tSet[]);

// Prints out the division rankings after they have been sorted
// Input: divArr[] Is an array containing the number correllating to the teams of the division currently being looked at.
//        At this point, the array already should have been sorted from least amount of wins to greatest.
//        tSet[] Is the array of NFL teams; used to get the names of each team
void printDivision(int divArr[], Team tSet[]);

// Finds and seeds all the the teams that made the playoffs from 1-7
// Input: tSet[] is an array of NFL teams; used to get the names of each team as well as their win totals used for seeing if they made the playoffs
//        NFC[] is an array used to hold the playoff teams from the NFC Conference
//        AFC[] is an array used to hold the playoff teams from the AFC Conference
//  post: madePlayoffs for all playoff teams has been updated to true. NFC[] and AFC[] have been filled with all playoff teams
void playoffSeeding(Team tSet[], int NFC[], int AFC[]);

// Finds all the division winners for a conference and seeds them from 1-4
// Input: tSet[] is an array of NFL teams; used to get the names of each team as well as their win totals used for seeing if they made the playoffs
//        playoffArr[] is an array containing all of the playoff teams for a specific conference
//        conference an an integer indicating what conference is being seeded
//  post: playoffArr[] is updated in the first four indices
void seedDivWinners(Team tSet[], int playoffArr[], int conference);

// Finds the three remaining playoff teams for a conference and seeds them from 5-7
// Input: tSet[] is an array of NFL teams; used to get the names of each team as well as their win totals used for seeing if they made the playoffs
//        playoffArr[] is an array containing all of the playoff teams for a specific conference
//        conference an an integer indicating what conference is being seeded
//  post: playoffArr[] is updated in the final three indices
void seedWildcards(Team tSet[], int playoffArr[], int conference);

// Prints the both the AFC and NFC playoff teams in seeding order
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        playoffArr[] is an array containing all of the playoff teams for a specific conference
void printConfSeeding(Team tSet[], int playoffArr[]);

// Plays a playoff game between 2 of the NFL playoff teams
// Input: tSet[] is the array of NFL teams 
//        t1Num and t2Num are the teams who are playing each other
//  post: The winning team has their currPlayoffRound increased, indicating the move to the next round of the playoffs
void playPlayoffGame(Team tSet[], int t1Num, int t2Num);

// Simulates the entirety of the NFL Wildcard playoff round
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        NFC[] is an array of the NFC playoff teams
//        AFC[] is an array of the AFC playoff teams
// post: Winners of every wildcard game will have currPlayoffRound increased by 1
void simWildcard(Team tSet[], int NFC[], int AFC[]);

// Simulates the entirety of the NFL Divisional playoff round
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        NFC[] is an array of the NFC playoff teams
//        AFC[] is an array of the AFC playoff teams
// post: Winners of every divisional game will have currPlayoffRound increased by 1
void simDivisional(Team tSet[], int NFC[], int AFC[]);

// Simulates the divisional round for a single NFL conference
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        conference indicates the conference currently being simulated
// post: Winners of every divisional game will have currPlayoffRound increased by 1
void simConfDivsional(Team tSet[], int conference[]);

// Finds the two teams competing in a playoff match
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        conference[] is the array of a conferences playoff teams
//        teams[] is an array that will hold the teams playing in the current playoff game
//        currRound is the current round of the playoffs
//        currSeed is the first seed we check to see if they play in this game
//  post: teams[] is updated with the teams playing
void findPlayoffMatch(Team tSet[], int conference[], int teams[], int currRound, int currSeed);

// Simulates the conference championship round for both conferences
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        NFC[] is an array containing NFC conference playoff teams
//        AFC[] is an array containing AFC conference playoff teams 
// post: Winners of every championship game will have currPlayoffRound increased by 1
void simConfChampionship(Team tSet[], int NFC[], int AFC[]);

// Simulates the conference championship round for a single NFL conference
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        conference indicates the conference currently being simulated
// post: Winners of every championship game will have currPlayoffRound increased by 1
void simConfChampionship(Team tSet[], int conference[]);

// Simulates Superbowl 56
// Input: tSet[] is an array of NFL teams; used to get the names of each team and their current playoff round
// output: Winner of Super Bowl 56
void simSuperBowl(Team tSet[]);

// Simulates the 2021-22 NFL Playoffs
// Input: tSet[] is an array of NFL teams; used to get the names of each team
//        NFC[] is an array containing NFC conference playoff teams
//        AFC[] is an array containing AFC conference playoff teams 
//  post: currPlayoffRound increases with each playoff win. Final output is Super Bowl 56 Champion
void simPlayoffs(Team tSet[], int NFC[], int AFC[]);

#endif