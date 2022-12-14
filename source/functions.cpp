#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include "..\headers\team.h"
#include "..\headers\functions.h"
using namespace std;

const int NUM_TEAMS = 32;

// Historic Head-to-Head win percentages as of November 21, 2021
// Entries represent the probability that first team beats the second team (col represents team 1, row represents team 2)
const float TEAM_WIN_PERCENTAGE[32][32] = {
//0      1      2      3      4      5      6      7      8      9      10     11     12     13     14     15     16     17     18     19     20     21     22     23     24     25     26     27     28     29     30     31
 {0.000, 0.484, 0.714, 0.583, 0.750, 0.667, 0.500, 0.663, 0.635, 0.864, 0.557, 0.653, 0.400, 0.500, 0.333, 0.731, 0.600, 0.714, 0.540, 0.769, 0.556, 0.533, 0.500, 0.636, 0.600, 0.492, 0.592, 0.525, 0.511, 0.476, 0.333, 0.619}, //Team 0 playing Team x
 {0.516, 0.000, 0.667, 0.417, 0.377, 0.536, 0.643, 0.800, 0.607, 0.533, 0.658, 0.548, 0.600, 0.882, 0.429, 0.700, 0.467, 0.273, 0.628, 0.643, 0.633, 0.600, 0.490, 0.440, 0.385, 0.561, 0.853, 0.596, 0.667, 0.500, 0.533, 0.596}, //Team 1 playing Team x
 {0.286, 0.333, 0.000, 0.333, 0.667, 0.667, 0.471, 0.250, 0.167, 0.462, 0.167, 0.667, 0.182, 0.571, 0.545, 0.636, 0.333, 0.385, 0.286, 0.467, 0.429, 0.818, 0.286, 0.333, 0.182, 0.417, 0.540, 0.333, 0.500, 0.333, 0.524, 0.429}, // 2
 {0.417, 0.583, 0.667, 0.000, 0.286, 0.615, 0.433, 0.571, 0.545, 0.423, 0.409, 0.385, 0.500, 0.464, 0.438, 0.457, 0.525, 0.676, 0.385, 0.540, 0.571, 0.624, 0.636, 0.462, 0.463, 0.571, 0.600, 0.462, 0.571, 0.636, 0.630, 0.333}, // 3
 {0.250, 0.623, 0.333, 0.714, 0.000, 0.700, 0.417, 0.333, 0.769, 0.833, 0.300, 0.625, 0.333, 0.286, 0.429, 0.714, 0.571, 0.143, 0.429, 0.667, 0.625, 0.429, 0.509, 0.455, 0.375, 0.667, 0.857, 0.381, 0.727, 0.415, 0.500, 0.562}, // 4
 {0.333, 0.464, 0.333, 0.385, 0.300, 0.000, 0.500, 0.588, 0.520, 0.500, 0.423, 0.517, 0.800, 0.558, 0.375, 0.462, 0.500, 0.462, 0.420, 0.692, 0.521, 0.769, 0.567, 0.415, 0.250, 0.314, 0.304, 0.500, 0.688, 0.344, 0.538, 0.511}, // 5
 {0.500, 0.357, 0.529, 0.567, 0.583, 0.500, 0.000, 0.469, 0.692, 0.688, 0.231, 0.500, 0.545, 0.600, 0.542, 0.483, 0.633, 0.600, 0.429, 0.708, 0.500, 0.654, 0.500, 0.455, 0.615, 0.286, 0.637, 0.714, 0.500, 0.583, 0.540, 0.500}, // 6
 {0.337, 0.200, 0.750, 0.429, 0.667, 0.412, 0.531, 0.000, 0.448, 0.750, 0.800, 0.632, 0.583, 0.500, 0.667, 0.556, 0.583, 0.661, 0.571, 0.500, 0.688, 0.520, 0.278, 0.440, 0.481, 0.350, 0.558, 0.357, 0.684, 0.400, 0.463, 0.266}, // 7
 {0.365, 0.393, 0.833, 0.455, 0.231, 0.480, 0.308, 0.552, 0.000, 0.692, 0.423, 0.552, 0.400, 0.375, 0.429, 0.364, 0.500, 0.417, 0.481, 0.500, 0.462, 0.429, 0.433, 0.398, 0.417, 0.438, 0.467, 0.517, 0.474, 0.278, 0.467, 0.383}, // 8
 {0.136, 0.467, 0.538, 0.577, 0.167, 0.500, 0.312, 0.250, 0.308, 0.000, 0.385, 0.536, 0.375, 0.440, 0.500, 0.554, 0.557, 0.439, 0.643, 0.658, 0.533, 0.449, 0.250, 0.462, 0.434, 0.643, 0.404, 0.500, 0.352, 0.300, 0.588, 0.429}, // 9
 {0.443, 0.342, 0.833, 0.591, 0.700, 0.577, 0.769, 0.200, 0.577, 0.615, 0.000, 0.585, 0.800, 0.535, 0.429, 0.643, 0.538, 0.583, 0.529, 0.583, 0.667, 0.583, 0.519, 0.478, 0.500, 0.514, 0.545, 0.583, 0.643, 0.475, 0.769, 0.651}, // 10
 {0.347, 0.452, 0.333, 0.615, 0.375, 0.483, 0.500, 0.368, 0.448, 0.464, 0.415, 0.000, 0.200, 0.534, 0.286, 0.654, 0.385, 0.167, 0.505, 0.667, 0.466, 0.545, 0.370, 0.444, 0.615, 0.349, 0.457, 0.452, 0.400, 0.409, 0.538, 0.431}, // 11
 {0.600, 0.400, 0.818, 0.500, 0.667, 0.200, 0.455, 0.417, 0.600, 0.625, 0.200, 0.800, 0.000, 0.769, 0.333, 0.545, 0.364, 0.714, 0.800, 0.200, 1.000, 0.750, 0.600, 0.800, 0.625, 1.000, 0.714, 0.750, 0.750, 0.200, 0.553, 0.400}, // 12
 {0.500, 0.118, 0.429, 0.536, 0.714, 0.442, 0.400, 0.500, 0.625, 0.560, 0.465, 0.466, 0.231, 0.000, 0.366, 0.409, 0.529, 0.630, 0.467, 0.622, 0.300, 0.632, 0.615, 0.375, 0.403, 0.474, 0.769, 0.400, 0.462, 0.429, 0.352, 0.323}, // 13
 {0.667, 0.571, 0.455, 0.562, 0.571, 0.625, 0.458, 0.333, 0.571, 0.500, 0.571, 0.714, 0.667, 0.634, 0.000, 0.538, 0.444, 0.750, 0.800, 0.500, 0.857, 0.875, 0.714, 0.429, 0.429, 0.500, 0.520, 0.600, 0.667, 0.429, 0.604, 0.857}, // 14
 {0.269, 0.300, 0.364, 0.543, 0.286, 0.538, 0.517, 0.444, 0.636, 0.446, 0.357, 0.346, 0.455, 0.591, 0.462, 0.000, 0.443, 0.471, 0.417, 0.464, 0.417, 0.419, 0.417, 0.733, 0.487, 0.444, 0.667, 0.538, 0.365, 0.538, 0.471, 0.091}, // 15
 {0.400, 0.533, 0.667, 0.475, 0.429, 0.500, 0.367, 0.417, 0.500, 0.443, 0.462, 0.615, 0.636, 0.471, 0.556, 0.557, 0.000, 0.463, 0.429, 0.500, 0.400, 0.561, 0.464, 0.429, 0.432, 0.538, 0.417, 0.500, 0.472, 0.300, 0.447, 0.462}, // 16
 {0.286, 0.727, 0.615, 0.324, 0.857, 0.538, 0.400, 0.339, 0.583, 0.561, 0.417, 0.833, 0.286, 0.370, 0.250, 0.529, 0.537, 0.000, 0.583, 0.548, 0.571, 0.625, 0.462, 0.417, 0.347, 0.385, 0.742, 0.429, 0.510, 0.333, 0.360, 0.583}, // 17
 {0.460, 0.372, 0.714, 0.615, 0.571, 0.580, 0.571, 0.429, 0.519, 0.357, 0.471, 0.495, 0.200, 0.533, 0.200, 0.583, 0.571, 0.417, 0.000, 0.857, 0.590, 0.538, 0.440, 0.364, 0.333, 0.537, 0.385, 0.521, 0.543, 0.360, 0.462, 0.662}, // 18
 {0.231, 0.357, 0.533, 0.460, 0.333, 0.308, 0.292, 0.500, 0.500, 0.342, 0.417, 0.333, 0.800, 0.378, 0.500, 0.536, 0.500, 0.452, 0.143, 0.000, 0.417, 0.477, 0.500, 0.778, 0.505, 0.400, 0.542, 0.385, 0.385, 0.583, 0.432, 0.385}, // 19
 {0.444, 0.367, 0.571, 0.429, 0.375, 0.479, 0.500, 0.312, 0.538, 0.467, 0.333, 0.534, 0.000, 0.700, 0.143, 0.583, 0.600, 0.429, 0.410, 0.583, 0.000, 0.692, 0.387, 0.385, 0.727, 0.400, 0.471, 0.464, 0.667, 0.411, 0.357, 0.455}, // 20
 {0.467, 0.400, 0.182, 0.376, 0.571, 0.231, 0.346, 0.480, 0.571, 0.551, 0.417, 0.455, 0.250, 0.368, 0.125, 0.581, 0.439, 0.375, 0.462, 0.523, 0.308, 0.000, 0.333, 0.364, 0.435, 0.538, 0.536, 0.643, 0.556, 0.300, 0.412, 0.545}, // 21
 {0.500, 0.510, 0.714, 0.364, 0.491, 0.433, 0.500, 0.722, 0.567, 0.750, 0.481, 0.630, 0.400, 0.385, 0.286, 0.583, 0.536, 0.538, 0.560, 0.500, 0.613, 0.667, 0.000, 0.548, 0.462, 0.586, 0.438, 0.636, 0.400, 0.356, 0.594, 0.607}, // 22
 {0.364, 0.560, 0.667, 0.538, 0.545, 0.585, 0.545, 0.560, 0.602, 0.538, 0.522, 0.556, 0.200, 0.625, 0.571, 0.267, 0.571, 0.583, 0.636, 0.222, 0.615, 0.636, 0.452, 0.000, 0.429, 0.506, 0.417, 0.500, 0.474, 0.348, 0.500, 0.401}, // 23
 {0.400, 0.615, 0.818, 0.537, 0.625, 0.750, 0.385, 0.519, 0.583, 0.566, 0.500, 0.385, 0.375, 0.597, 0.571, 0.513, 0.568, 0.653, 0.667, 0.495, 0.273, 0.565, 0.538, 0.571, 0.000, 1.000, 0.750, 0.786, 0.600, 0.167, 0.544, 0.667}, // 24
 {0.508, 0.439, 0.583, 0.429, 0.333, 0.686, 0.714, 0.650, 0.562, 0.357, 0.486, 0.651, 0.000, 0.526, 0.500, 0.556, 0.462, 0.615, 0.463, 0.600, 0.600, 0.462, 0.414, 0.494, 0.000, 0.000, 0.386, 0.574, 0.611, 0.500, 0.417, 0.520}, // 25
 {0.408, 0.147, 0.460, 0.400, 0.143, 0.696, 0.363, 0.442, 0.533, 0.596, 0.455, 0.543, 0.286, 0.231, 0.480, 0.333, 0.583, 0.258, 0.615, 0.458, 0.529, 0.464, 0.562, 0.583, 0.250, 0.614, 0.000, 0.545, 0.526, 0.182, 0.413, 0.563}, // 26
 {0.475, 0.404, 0.667, 0.538, 0.619, 0.500, 0.286, 0.643, 0.483, 0.500, 0.417, 0.548, 0.250, 0.600, 0.400, 0.462, 0.500, 0.571, 0.479, 0.615, 0.536, 0.357, 0.364, 0.500, 0.214, 0.426, 0.455, 0.000, 0.622, 0.250, 0.357, 0.383}, // 27
 {0.489, 0.333, 0.500, 0.429, 0.273, 0.312, 0.500, 0.316, 0.526, 0.648, 0.357, 0.600, 0.250, 0.538, 0.333, 0.635, 0.528, 0.490, 0.457, 0.615, 0.333, 0.444, 0.600, 0.526, 0.400, 0.389, 0.474, 0.378, 0.000, 0.357, 0.412, 0.667}, // 28
 {0.524, 0.500, 0.667, 0.364, 0.585, 0.656, 0.417, 0.600, 0.722, 0.700, 0.525, 0.591, 0.800, 0.571, 0.571, 0.462, 0.700, 0.667, 0.640, 0.417, 0.589, 0.700, 0.644, 0.652, 0.833, 0.500, 0.818, 0.750, 0.643, 0.000, 0.833, 0.545}, // 29
 {0.667, 0.467, 0.476, 0.370, 0.500, 0.462, 0.460, 0.537, 0.533, 0.412, 0.231, 0.462, 0.447, 0.648, 0.396, 0.529, 0.553, 0.640, 0.538, 0.568, 0.643, 0.588, 0.406, 0.500, 0.456, 0.583, 0.587, 0.643, 0.588, 0.167, 0.000, 0.462}, // 30
 {0.381, 0.404, 0.571, 0.667, 0.438, 0.489, 0.500, 0.734, 0.617, 0.571, 0.349, 0.569, 0.600, 0.677, 0.143, 0.909, 0.538, 0.417, 0.338, 0.615, 0.545, 0.455, 0.393, 0.599, 0.333, 0.480, 0.437, 0.617, 0.333, 0.455, 0.538, 0.000}, // 31
};

// Current Schudule for the upcoming season (In this case used 2021)
// Entries represent who that person is going to play in the week (i.e. if entry is 31 in row 1, they play team 31 in week 1)
// Entry of -1 indicates that the team is currently on their bye week
const int TEAM_SCHEDULE[18][32] {
 //0  1  2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31
{30, 25, 16, 26, 24, 18, 20, 15, 29, 23, 27, 22, 14, 28, 12,  7,  2, 31,  5, 21,  6, 19, 11,  9,  4,  1,  3, 10, 13,  8,  0, 17}, //Week 1
{20, 29, 15, 19, 22,  6,  5, 12, 17, 14, 11, 10,  7, 18,  9,  2, 26,  8, 13,  3,  0, 24,  4, 31, 21, 27, 16, 25, 30,  1, 28, 23}, //Week 2
{14, 23, 10, 31, 12,  7, 26,  5, 25, 24,  2, 27,  4, 30,  0, 17, 19, 15, 29, 16, 28, 22, 21,  1,  9,  8,  6, 11, 20, 18, 13,  3}, //Week 3
{18, 31,  9, 12,  8, 10, 14, 20,  4,  2,  5, 26,  3, 19,  6, 25, 17, 16,  0, 13,  7, 29, 23, 21, 30, 15, 11, 28, 27, 21, 24,  1}, //Week 4
{27, 24, 13, 15, 25, 16, 11, 17, 23, 26, 20,  6, 21,  2, 30,  3,  5,  7, 28, 29, 10, 12, 31,  8,  1,  4,  9,  0, 18, 19, 14, 22}, //Week 5
{ 7, -1, 17, 30, 20, 11, 10,  0, 21, 16,  6,  5, 13, 12, 19, 31,  9,  2, 23, 14,  4,  8, -1, 18, -1, 29, 28, -1, 26, 25,  3, 15}, //Week 6
{12, 19,  6, -1, 23, 29,  2,  9, -1,  7, 18, 31,  0, 27, -1, 30, 25, -1, 10,  1, -1, 24, 28,  4, 21, 16, -1, 13, 22,  5, 15, 11}, //Week 7
{11,  4, -1, 19,  1, 27, 24, 26, 20, 31, 25,  0, 18, 30, 28, 23, -1, 21, 12,  3,  8, 17, 29, 15,  6, 10,  7,  5, 14, 22, 13,  9}, //Week 8
{27, 22, 20, 14, 21, 26,  7,  6,  9,  8, -1, 15, 19, 24,  3, 11, 23, 25, 30, 12,  2,  4,  1, 16, 13, 17,  5,  0, -1, -1, 18, -1}, //Week 9
{ 4,  8, 19, 24,  0, -1, -1, 21,  1, 25, 26, 28, -1, 14, 13, 16, 15, 20, 27,  2, 17,  7, 30, -1,  3,  9, 10, 18, 11, 31, 22, 29}, //Week 10
{28, 21,  5, 13, 31,  2, 16, 10, 15, -1,  7, 20, 30,  3, 27,  8,  6, 26, -1, 24, 11,  1, 25, 29, 19, 22, 17, 14,  0, 23, 12,  4}, //Week 11
{-1, 14,  7, 22, 19, 10, 26,  2, 16, 17,  5, 18, 24, 29,  1, -1,  8,  9, 11,  4, 27, 30,  3, 25, 12, 23,  6, 20, 31, 13, 21, 28}, //Week 12
{ 5, 29, 26, 21, -1,  0, 17, -1, 22, 15, 20, -1, 13, 12, 18,  9, 31,  6, 14, 23, 10,  3,  8, 19, 25, 24,  2, 28, 27,  1, -1, 16}, //Week 13
{18,  4,  7, 29,  1, 11, 27,  2, 31, 10,  9,  5, 28, -1, 30, 16, 15, 23,  0, -1, 26, -1, 24, 17, 21, -1, 20,  6, 12,  3, 14,  8}, //Week 14
{10, 27, 11,  4,  3, 20,  9, 16, 23,  6,  0,  2, 14, 21, 12, 17,  7, 15, 28, 24,  7, 13, 29,  8, 19, 31, 30,  1, 18, 22, 26, 25}, //Week 15
{13, 10,  6, 21, 29, 28,  2, 11, 31, 16,  1,  7, 17,  0, 24, 26,  9, 12, 20, 22, 18,  3, 19, 25, 14, 23, 15, 30,  5,  4, 27,  8}, //Week 16
{ 8,  3, 18,  1, 22, 23, 15, 26,  0, 17, 28, 20, 27, 16, 21,  6, 13,  9,  2, 30, 11, 14,  4,  5, 29, 31,  7, 12, 10, 24, 19, 25}, //Week 17
{28, 22, 26, 24, 29, 20,  7,  6, 25, 15, 11, 10, 30, 14, 13,  9, 17, 16, 27, 21,  5, 19,  1, 31,  3,  8,  2, 18,  0,  4, 12, 23}, //Week 18
};
    
// Conference Relation:
// NFC - 2, AFC - 1
// Division Relation:
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

void playRegSeasonGame(Team tSet[], int t1Num, int t2Num) {
    float probability = TEAM_WIN_PERCENTAGE[t2Num][t1Num]; //Finds win percentage for Team 1 over Team 2
    float num = (rand() % 1001) / 1000.0;
    int winNum;
    if(num <= probability) { //Team 1 wins
        tSet[t1Num].numWins++;
        winNum = 1;
    } else { //Team 2 wins
        tSet[t2Num].numWins++;
        winNum = 2;
    }
    tSet[t1Num].numGamesPlayed++;
    tSet[t1Num].hasPlayed = true;
    tSet[t2Num].numGamesPlayed++;
    tSet[t2Num].hasPlayed = true;
    printGameResults(winNum, tSet[t1Num], tSet[t2Num]);
    cout << endl;
}

void regSeasonWeek(Team tSet[], int currWeek) {
    int opponentNum;
    cout << "WEEK " << currWeek + 1 << endl << endl;
    for(int i = 0; i < NUM_TEAMS; i++) { //Runs for every team
        if(tSet[i].hasPlayed == false && TEAM_SCHEDULE[currWeek][i] != -1) { //Checks if team has not played and is not on bye
            opponentNum = TEAM_SCHEDULE[currWeek][i]; //Finds opponent
            playRegSeasonGame(tSet, i, opponentNum); //Plays game
        }
    }
    printOnBye(tSet, currWeek);

    cout << endl;
}

void printGameResults(int num, Team t1, Team t2) {
    if (num == 1) {
        t1.print();
        cout << " (W) vs ";
        t2.print();
    } else {
        t1.print();
        cout << " vs ";
        t2.print();
        cout << " (W)";
    }
    
}

void printOnBye(Team tSet[], int currWeek) {
    for(int i = 0; i < NUM_TEAMS; i++) { //Runs for every team
        if(TEAM_SCHEDULE[currWeek][i] == -1) { //Checks if current team on bye
            cout << tSet[i].team_name << " are on their bye week. ";
        }
    }
    cout << endl;
}

void weeklyReset(Team tSet[]) {
    for(int i = 0; i < NUM_TEAMS; i++) { //Runs for every team
        tSet[i].hasPlayed = false;
    }
}

void divRankings(Team tSet[]) {
    int divArr[4] = {-1, -1, -1, -1}; //Initialize array to hold 4 teams for current division
    int numTeamsFound = 0;
    for (int i = 1; i < 9; i++) { //Runs for all 8 divisions
    numTeamsFound = 0;
        for (int j = 0; j < NUM_TEAMS; j++) { //Checks every team
            if(tSet[j].team_div == i) { //Tests if current team is in current division being looked at
                divArr[numTeamsFound] = j;
                numTeamsFound++;
            }
        }
    divSort(divArr, tSet);
    printDivision(divArr, tSet);
    tSet[divArr[3]].madePlayoffs = true;
    }
}

void divLeastWins(int divArr[], Team tSet[]) {
    int tempNum = divArr[0]; //Holds team in the first position, which will be position of team with lowest number of wins
    if (tSet[divArr[1]].numWins <= tSet[divArr[0]].numWins && tSet[divArr[1]].numWins <= tSet[divArr[2]].numWins && tSet[divArr[1]].numWins <= tSet[divArr[3]].numWins) { //Team who started in position 2 placed last in division
        divArr[0] = divArr[1];  
        divArr[1] = tempNum; 
    } else if (tSet[divArr[2]].numWins <= tSet[divArr[0]].numWins && tSet[divArr[2]].numWins <= tSet[divArr[1]].numWins && tSet[divArr[2]].numWins <= tSet[divArr[3]].numWins) { //Team who started in position 3 placed last in division
        divArr[0] = divArr[2]; 
        divArr[2] = tempNum; 
    } else if (tSet[divArr[3]].numWins <= tSet[divArr[0]].numWins && tSet[divArr[3]].numWins <= tSet[divArr[1]].numWins && tSet[divArr[3]].numWins <= tSet[divArr[2]].numWins) { //Team who started in position 4 placed last in division
        divArr[0] = divArr[3]; 
        divArr[3] = tempNum; 
    }
}

void divMostWins(int divArr[], Team tSet[]) {
    int tempNum = divArr[3]; //Holds team in fourth position, which will be position of team who won the division
    if (tSet[divArr[1]].numWins >= tSet[divArr[2]].numWins && tSet[divArr[1]].numWins >= tSet[divArr[3]].numWins) { //Team who is currently is 2nd positon won the division!
        divArr[3] = divArr[1]; 
        divArr[1] = tempNum; 
    } else if (tSet[divArr[2]].numWins >= tSet[divArr[1]].numWins && tSet[divArr[2]].numWins >= tSet[divArr[3]].numWins) { //Team who is currently in 3 position won the division!
        divArr[3] = divArr[2]; 
        divArr[2] = tempNum; 
    }
}

void divMidWins(int divArr[], Team tSet[]) {
    int tempNum = divArr[2]; //Holds team in third position, which will be position of team who placed 2nd in division
    if (tSet[divArr[1]].numWins >= tSet[divArr[2]].numWins) { //Team who is currently in 2nd positions placed 2nd overall in the division
        divArr[2] = divArr[1]; 
        divArr[1] = tempNum; 
    }
}

void divSort(int divArr[], Team tSet[]) {
    divLeastWins(divArr, tSet); 
    divMostWins(divArr, tSet); 
    divMidWins(divArr, tSet); 
}

void printDivision(int divArr[], Team tSet[]) {
    for(int i = 3; i >= 0; i--) {
        tSet[divArr[i]].print();
        cout << endl;
    }
    cout << endl;
}

void playoffSeeding(Team tSet[], int NFC[], int AFC[]) {
    cout << "NFC SEEDING" << endl;
    seedDivWinners(tSet, NFC, 2);
    seedWildcards(tSet, NFC, 2);
    printConfSeeding(tSet, NFC);
    cout << endl << "AFC SEEDING" << endl;
    seedDivWinners(tSet, AFC, 1);
    seedWildcards(tSet, AFC, 1);
    printConfSeeding(tSet, AFC);
}

void seedDivWinners(Team tSet[], int playoffArr[], int conference) {
int numTeamsSeeded = 0; bool currTeamSeeded;
    for(int i = 0; i < NUM_TEAMS; i++) { //Runs for every NFL team
        if(tSet[i].madePlayoffs == true && tSet[i].team_conf == conference) { // Checks if the current team made the playoffs & is in the conference we are looking at
            currTeamSeeded = false;
            if(numTeamsSeeded == 0) { //Checks if any of the divisional winners have been seeded
                playoffArr[numTeamsSeeded] = i;
                currTeamSeeded = true;
            } else if(numTeamsSeeded != 0) { //Division winners past the first found
                for(int j = 0; j < numTeamsSeeded; j++) { //Checks all teams already seeded
                    if(tSet[i].numWins > tSet[playoffArr[j]].numWins) { //Checks if current division winner has more wins than an already seeded division winner
                        for(int k = 3; k > j; k--) { //Runs for how many teams have less wins than current team we are looking at
                            playoffArr[k] = playoffArr[k-1]; //Shifts team one to the right in array
                        }
                    playoffArr[j] = i;
                    currTeamSeeded = true;
                    }
                    if (currTeamSeeded == true) { //Breaks from loop if team has been seeded
                        break;
                    }
                }
                if (currTeamSeeded == false) { //Division winner has least amount of wins among already found division winners
                    playoffArr[numTeamsSeeded] = i;
                }

            }
            numTeamsSeeded++;
        }
    }
    tSet[playoffArr[0]].currPlayoffRound = 1;
}


void seedWildcards(Team tSet[], int playoffArr[], int conference) {
    int mostWinTeam; bool foundFirstTeam = false;
    for(int currSeed = 4; currSeed < 7; currSeed++) { //Runs for each of wildcard Seeds
        foundFirstTeam = false; //Resets to finding first team for current seed
        for(int currTeam = 0; currTeam < NUM_TEAMS; currTeam++) { //Runs for every team
            if(tSet[currTeam].madePlayoffs == false && tSet[currTeam].team_conf == conference) { //Checking if current team is not in playoffs and is in current conference
                if(foundFirstTeam == false) { //Checks if this is the first found playoff team for this seed
                    mostWinTeam = currTeam;
                    foundFirstTeam = true;
                } else { //Playoff team has already been found
                    if(tSet[currTeam].numWins > tSet[mostWinTeam].numWins) {
                        mostWinTeam = currTeam;
                    }
                }
            }
            tSet[mostWinTeam].madePlayoffs = true; //Team getting ready to be seeded has made the playoffs!
            playoffArr[currSeed] = mostWinTeam; //Team with most wins is set to highest remaining seed
        }
    }
}

void printConfSeeding(Team tSet[], int playoffArr[]) {
    for(int i = 0; i < 7; i++) {
        cout << i + 1 << ". ";
        tSet[playoffArr[i]].print();
        cout << endl;
    }
}

void playPlayoffGame(Team tSet[], int t1Num, int t2Num) {
    float probability = TEAM_WIN_PERCENTAGE[t2Num][t1Num]; //Finds win percentage for Team 1 over Team 2
    float num = (rand() % 1001) / 1000.0;
    int winNum;
    if(num <= probability) { //Team 1 wins
        tSet[t1Num].currPlayoffRound++;
        winNum = 1;
    } else { //Team 2 wins
        tSet[t2Num].currPlayoffRound++;
        winNum = 2;
    }   
    printGameResults(winNum, tSet[t1Num], tSet[t2Num]);
    cout << endl;
}

void simWildcard(Team tSet[], int NFC[], int AFC[]) {
    cout << "NFC WILDCARD ROUND" << endl; //Next three lines simulate NFC Wildcard games
    playPlayoffGame(tSet, NFC[1], NFC[6]);
    playPlayoffGame(tSet, NFC[2], NFC[5]);
    playPlayoffGame(tSet, NFC[3], NFC[4]);
    cout << endl << "AFC WILDCARD ROUND" << endl; //Next three lines simulate AFC Wildcard games
    playPlayoffGame(tSet, AFC[1], AFC[6]);
    playPlayoffGame(tSet, AFC[2], AFC[5]);
    playPlayoffGame(tSet, AFC[3], AFC[4]);
    cout << endl;
}

void simDivisional(Team tSet[], int NFC[], int AFC[]) {
    cout << "NFC DIVISIONAL ROUND" << endl;
    simConfDivsional(tSet, NFC);
    cout << endl << "AFC DIVISIONAL ROUND" << endl;
    simConfDivsional(tSet, AFC);
    cout << endl;
}

void simConfDivsional(Team tSet[], int conference[]) {
    bool foundLowestSeed = false; int currSeed = 6; int match2[2] = {-1, -1};
    while(foundLowestSeed == false) { //Runs until we find lowest remaining seed for this conference
        if(tSet[conference[currSeed]].currPlayoffRound == 1) { //Checks if the current team we are looking at is in the Divisional round
            playPlayoffGame(tSet, conference[0], conference[currSeed]);
            foundLowestSeed = true;
        }
        currSeed--; //Decriments down to next highest seed
    }
    findPlayoffMatch(tSet, conference, match2, 1, currSeed);
    playPlayoffGame(tSet, match2[1], match2[0]);
}

void simConfChampionship(Team tSet[], int NFC[], int AFC[]) {
    cout << "NFC CONFERENCE CHAMPIONSHIP" << endl;
    simConfChampionship(tSet, NFC);
    cout << endl << "AFC CONFERENCE CHAMPIONSHIP" << endl;
    simConfChampionship(tSet, AFC);
    cout << endl;
}

void simConfChampionship(Team tSet[], int conference[]) {
    int match[2] = {-1, -1}; int currSeed = 6;
    findPlayoffMatch(tSet, conference, match, 2, currSeed);
    playPlayoffGame(tSet, match[1], match[0]);
}

void findPlayoffMatch(Team tSet[], int conference[], int teams[], int currRound, int currSeed) {
    int foundTeams = 0;
    while (foundTeams != 2) { //Runs until we find other 2 teams playing in the current round
        if(tSet[conference[currSeed]].currPlayoffRound == currRound) { //Checks if current team is in the current round
            teams[foundTeams] = conference[currSeed]; //Sets one opponent
            foundTeams++; //We have found one more team in this game
        }
        currSeed--; //Moves to next highest seed
    }
}

void simSuperBowl(Team tSet[]) {
    int match[2] = {-1, -1}; int foundTeams = 0;
    for(int i = 0; i < NUM_TEAMS; i++) { //Runs through every NFL team
        if(tSet[i].currPlayoffRound == 3) { //Checks if they are in the superbowl
            match[foundTeams] = i;
            foundTeams++;
        }
        if(foundTeams == 2) { //Breaks when we find our two teams
            break;
        }
    }
    cout << "SUPER BOWL 56" << endl;
    playPlayoffGame(tSet, match[1], match[0]);
    if(tSet[match[0]].currPlayoffRound == 4) { //Finds our winner for printing reasons
        cout << "The " << tSet[match[0]].team_name << " are your Super Bowl 56 Champions!!!";
    } else {
        cout << "The " << tSet[match[1]].team_name << " are your Super Bowl 56 Champions!!!";
    }
}

void simPlayoffs(Team tSet[], int NFC[], int AFC[]) {
    cout << endl; //Gap for printing purposes
    simWildcard(tSet, NFC, AFC);
    simDivisional(tSet, NFC, AFC);
    simConfChampionship(tSet, NFC, AFC);
    simSuperBowl(tSet);
}