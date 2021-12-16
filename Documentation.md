**What are was our projects purpose**

The overall idea of our project was to run a full season simulation from the beginning of Week 1 through Superbowl 56. For the regular season, our function would find every team playing for a single week, simulate their games with their opponents, then update their wins and losses accordingly. We would do this for all 18 weeks of the regular season as each team would play 17 total games with a singular bye week between the weeks 6 and 14. After the completion of the regular season, we would print out the division rankings from first to last. Next we found all of our playoff teams and seeded them from 1 to 7 for both the AFC and the NFC conferences by first seeding the division winners, then find and seeding the wildcard teams accordingly. Finally, our function simulated the 2021-22 NFL Playoffs with the 14 teams (7 from each conference) that made the playoffs, finally deciding the Superbowl 56 champion.

**What assumptions did we make?**
There are two primary assumptions in the construction of this program. The first of which being that the win chance of each team against each other is static, previous results within the program doesn't alter future matches against the same team. Furthermore, this win chance is from the team's life time win-loss record against all the other teams, thereby having the quality of the players on the team and coaching staff of that team not play a factor in how the teams ability to perform within the simulation. The second assumption is that tiebreakers for seeding isn't in this simulation, if there is a tie for win-loss for being seeded as a wildcard it comes down to which team comes first in the alphabet due to how the teams were initilized. 

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
The NFL season is very linear in how it progresses, as it has the regular season of games with the top ranking of division and then conference moving up to eventually find the champion at the end of the playoff season. This simulation emulates that to the best of the developers current know how, capabilities, and time constraints.
The easiest way, and one that best fits the short time span of the project, for determining the winning team was by life time records and win percentages against each other team. While player data and statistics would provide a more accurate result for win percentages, the scope of designing how each player of each team, and each play from each team and how they all interact with one another with the time constraint and the developers know how was just not feasible. Therefore, in terms of reasonability and simplicity life time win percentages was the best available option.
The printing of division rankings and the winners and losers of each game, allowed for not only ease of double checking to make sure the results are accurate for who progresses into the playoff season and how the playoff season is progressing properly,but also for allowing the user to see the flow of how the simulation progresses over time.
Another tool used for ease of life for coding was the use of arrays for position within the conference for playoffs rather than having it be an atrribute of the team. While both are feasible options, arrays were the most intuitive for the developers in how we would implement and use for seeding the teams for playoffs. Arrays also provided the additional benefit of passing by reference so we never needed to return a value and all our manipulations can be easily found and managed without additional time spent on creating new variables and resources.
The NFL official schedule array was a nice tool as it provided a convient way to progress through the season, see who the played was correct, and make sure that each team was getting the proper amount of games played and correct number of bye weeks.
The array of all thirty-two NFL teams connecting to the Teams Class which held access to their pertainant information such as: if they made it to the playoffs, which round in the playoffs did they make it to, access to the array to check their win percentage against the other teams, and so forth. Therby making it easy to access and progress them throughout the entirety of the simulation. 

**Works Cited**

**Resources used:**

Bracket Example 2 from final Project: Accessed multiple times for several functions. https://whitgit.whitworth.edu/2021/fall/CS-171-3/Group_Projects/CS1_Final_Project/CS1_Final_Project_Edgewood.git

LM8 code: Accessed time for divRankings function. https://whitgit.whitworth.edu/2021/fall/CS-171-3/natchison25/LM8_Passing_By_Reference.git

LM9 code: Accessed one time for playoffSeeding function. https://whitgit.whitworth.edu/2021/fall/CS-171-3/natchison25/LM9_Arrays.git

Pro Football Reference: Accessed one time for historical head-to-head information. https://www.pro-football-reference.com/

NFL Website: Accessed one time for 2021-22 NFL Regular Season Schedule. https://www.nfl.com/

**Libraries used:**

iostream

string

ctime

random
