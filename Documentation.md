**What are was our projects purpose**

The overall idea of our project was to run a full season simulation from the beginning of Week 1 through Superbowl 56. For the regular season, our function would find every team playing for a single week, simulate their games with their opponents, then update their wins and losses accordingly. We would do this for all 18 weeks of the regular season as each team would play 17 total games with a singular bye week between the weeks 6 and 14. After the completion of the regular season, we would print out the division rankings from first to last. Next we found all of our playoff teams and seeded them from 1 to 7 for both the AFC and the NFC conferences by first seeding the division winners, then find and seeding the wildcard teams accordingly. Finally, our function simulated the 2021-22 NFL Playoffs with the 14 teams (7 from each conference) that made the playoffs, finally deciding the Superbowl 56 champion.

**What assumptions did we make?**

1. Historical head-to-head is indicative of a team's performance in this current season regardless of the 
   team's current players and coaching staff.
2. Teams were assigned a number at the beginning and that number correlated to who they were.
3. Win percentage is static throughout the entire season.
4. Tiebreakers don't exist in our simulation, so seeding comes down to who comes first in the alphabet

**Flowchart of Functions** 
NOTE: Arrows indicate what functions are in other functions on a single lines (i.e in line 24, printOnBye is in the function regSeasonWeek. Vertical arrows indicate progress through a function (i.e. in lines 37-49, those four functions progress in that order within simPlayoffs). If the statement "data used" is in a line, it indicates that the information of the right or above was found earlier and used in the function that is being pointed at. The most central column of functions (initalizeTeams->regSeasonWeek, etc.) is the functions within our main function.

                                   initializeTeams
                                        |
                                        |
                                        V
    printOnBye ----------------> regSeasonWeek <---------------- playRegSeasonGame <---------------- printGameResults
                                        |                               |
                                        | Runs 18 Times                 |
                                        |                               |
                                        V           data used           V                    
       divSort ---------------->   DivRankings <----------------Update team win totals
         |                              |                                       |
         |                              |                                       | data used
         V                              V     Runs once for each conference     V
    printDivision                 playoffSeeding <---------------- seedDivWinners + seedWildcards -------------> printConfSeeding
                                        |                                         |
                                        |                                         |
                                        V              data used                  V
    simWildcard ----------------> simPlayoffs <-------------------------  NFC[] & AFC[]
        |
        |
        V
    simDivisional
        |
        |
        V
    simConfChampionship
        |
        |
        V
    simSuperBowl                             

**Analysis, Overview, and Justification of Design**
1. NFL Season is a linear progression
2. Simplest way of deciding games was head-to-head data
3. playoff rounds allow us to indicate who's still in playoffs
4. printing division rankings allowed us to easily find division winners
5. using arrays rather than a attribute for Teams allowed us to easily simulate playoffs
6. Having a schedule array allowed us to easily find teams who played each other

**Works Cited**
Resources used:

Bracket Example 2 from final Project: Accessed multiple times for several functions. https://whitgit.whitworth.edu/2021/fall/CS-171-3/Group_Projects/CS1_Final_Project/CS1_Final_Project_Edgewood.git
LM8 code: Accessed time for divRankings function. https://whitgit.whitworth.edu/2021/fall/CS-171-3/natchison25/LM8_Passing_By_Reference.git
LM9 code: Accessed one time for playoffSeeding function. https://whitgit.whitworth.edu/2021/fall/CS-171-3/natchison25/LM9_Arrays.git
Pro Football Reference: Accessed one time for historical head-to-head information. https://www.pro-football-reference.com/
NFL Website: Accessed one time for 2021-22 NFL Regular Season Schedule. https://www.nfl.com/

Libraries used

<iostream>
<string>
<ctime>
<random>
