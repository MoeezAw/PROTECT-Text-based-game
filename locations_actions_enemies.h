#include <stdio.h>

#ifndef LOCATIONS_ACTIONS_ENEMIES_H
#define LOCATIONS_ACTIONS_ENEH

/*
01:    "Home",                 // Level 0 (Start)
02:    "Jallra (Town)",        // Level 0 (Start)
03:    "Cave",                 // Level 5
04:    "Forest",               // Level 10
05:    "Crimson Castle",       // Level 20
06:    "Desert Dungeon",       // Level 35
07:    "Underlands",           // Level 50
08:    "Conquerors Path",      // Level 65
09:    "Dunespecters Tunnel",  // Level 80
10:    "Hasmal"                // Level 100 (End)
*/

#define TRAVEL_IDX      4
#define AMT_LOCATIONS           10
#define MAX_POSSIBLE_ACTIONS    6
#define lastAction              "go back"
#define SLEN                    20

// Enemies:
// Struct:
typedef struct enemy
{
    char name[SLEN];
    int health;
    int damage;
    int XPDrop;
    // TODO: Implement Item Drop
}   enemy;

#define HP_FULL                 100

// Enemy Properties:
#define JA_BANDIT_NAME          "Bandit"
#define JA_BANDIT_BASEDMG       10
#define JA_BANDIT_XPDROP        20

#define CA_BAT_NAME             "Cave-Bat"
#define CA_BAT_BASEDMG          15
#define CA_BAT_XPDROP           30

#define FO_WOLF_NAME            "Wolf"
#define FO_WOLF_BASEDMG         20
#define FO_WOLF_XPDROP          40

// Crimson Castle: Knight:
#define CR_KNIGHT_NAME          "Knight"
#define CR_KNIGHT_BASEDMG       25
#define CR_KNIGHT_XPDROP        50

// Crimson Castle: Red Knight:
#define CR_RED_KNIGHT_NAME      "Red-Knight"
#define CR_RED_KNIGHT_BASEDMG   30
#define CR_RED_KNIGHT_XPDROP    60

// Desert Idea: Scorpion

typedef struct location_action {
    char location[SLEN];
    char actions[MAX_POSSIBLE_ACTIONS][SLEN];
} loc_act;

loc_act locs_acs[AMT_LOCATIONS] = {
    { "Home",                   { "Sleep", "repair-equipment", "eat", "paint-east-wall", ">Jallra", lastAction,} },
    { "Jallra",                 { "find-Enemy", "visit Shop", "0", "0", ">cave", lastAction} },
    { "Cave",                   { "find-Creature", "seek crystal", "0", "0", ">forest", lastAction} },
    { "Forest",                 { "find-Creature", "0", "0", "0", ">Crimson-Castle", lastAction} },
    { "Crimson-Castle",         { "find-Enemy", "0", "0", "0", ">Desert-Dungeon", lastAction} },
    { "Desert-Dungeon",         { "find-Creature", "0", "0", "0", ">Underlands", lastAction} },
    { "Underlands",             { "find-Creature", "0", "0", "0", ">Conquerors-Path", lastAction} },
    { "Conquerors-Path",        { "find-Cryptids", "seek Conqueror", "0", "0", ">Dunespecters-Tunnel", lastAction} },
    { "Dunespecters-Tunnel",    { "find-Scoridrae", "seek Dunespecter", "0", "0", ">Hasmal", lastAction} },
    { "Hasmal",                 { "find-Hasmari", "seek Azumos", "conquer-Hasmal", "0", "0", lastAction} }
};

#endif // LOCATIONS_ACTIONS_ENEMIES_H