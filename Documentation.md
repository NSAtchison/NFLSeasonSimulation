What are we doing?

Our project is attempting to completely simulate the 2021-22 NFL Season from Week 1 through Super Bowl 56.
Our project will use historical head-to-head win percentages between teams to determine who wins all games
for a single week during the regular season. Once the regular season ends, our project finds the 7 playoff 
teams for each conference, seeds them from 1-7, then does a simulation of the playoffs using the previously
mentioned head-to-head data. After completing the simulation, the project will then print who is the Super
Bowl 56 champion.

What assumptions did we make?

1. Historical head-to-head is indicative of a team's performance in this current season regardless of the 
   team's current players and coaching staff.
2. Teams were assigned a number at the beginning and that number correlated to who they were.
3. Win percentage is static throughout the entire season.
4. Tiebreakers don't exist in our simulation, so seeding comes down to who comes first in the alphabet

Flowchart of Algorithms

                        Initialize Teams
                                |
                                |
                                V
                          regSeasonWeek
                                |
                                | Runs 18 Times
                                |
                                V
                            DivRankings
                                |
                                |
                                V
                            playoffSeeding
                                |
                                |
                                V
                            simPlayoffs


Analysis, Overview, and Justification of Design
1. NFL Season is a linear progression
2. Simplest way of deciding games was head-to-head data
3. playoff rounds allow us to indicate who's still in playoffs
4. printing division rankings allowed us to easily find division winners
5. using arrays rather than a attribute for Teams allowed us to easily simulate playoffs
6. Having a schedule array allowed us to easily find teams who played each other

Works Cited
Example 2 from final project
LM8
LM9
Pro Football Reference - Head-to-head percentages
NFL.com - Schedule

Libraries used

iostream
string
ctime
random
