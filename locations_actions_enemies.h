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

#define TRAVEL_IDX              4
#define AMT_LOCATIONS           10
#define MAX_POSSIBLE_ACTIONS    6
#define lastAction              "go back"
#define SLEN                    20
#define DBG                     printf("####################\n");

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
#define CR_KNIGHT_BASEDMG       20
#define CR_KNIGHT_XPDROP        50

// Crimson Castle: Red Knight:
#define CR_RED_KNIGHT_NAME      "Red-Knight"
#define CR_RED_KNIGHT_BASEDMG   25
#define CR_RED_KNIGHT_XPDROP    60

// Desert Dungeon: Scorpion:
#define DE_SCORPION_NAME        "Scorpion"
#define DE_SCORPION_BASEDMG     35
#define DE_SCORPION_XPDROP      100

// Underlands: GoGolen:
#define UN_GOGOLEN_NAME         "GoGolen"
#define UN_GOGOLEN_BASEDMG      40
#define UN_GOGOLEN_XPDROP       150

// Conquerors Path: Cryptid:
#define CO_CRYPTID_NAME         "Cryptid"
#define CO_CRYPTID_BASEDMG      50
#define CO_CRYPTID_XPDROP       300

// Dunespecters Tunnel: Scoridrae:
#define DU_SCORIDRAE_NAME       "Scoridrae"
#define DU_SCORIDRAE_BASEDMG    75
#define DU_SCORIDRAE_XPDROP     500

// Hasmal: Hasmari:
#define HA_HASMARI_NAME         "Hasmari"
#define HA_HASMARI_BASEDMG      80
#define HA_HASMARI_XPDROP       1000

// Bosses:
// Hasmal: Azumos:
#define HA_AZUMOS_NAME          "Azumos"
#define HA_AZUMOS_BASEDMG       100
#define HA_AZUMOS_XPDROP        5000

// Dunespecters Tunnel: Dunespecter:
#define DU_DUNESPECTER_NAME     "Dunespecter"
#define DU_DUNESPECTER_BASEDMG  80
#define DU_DUNESPECTER_XPDROP   2000

// Conquerors Path: Conqueror:
#define CO_CONQUEROR_NAME       "Conqueror"
#define CO_CONQUEROR_BASEDMG    60
#define CO_CONQUEROR_XPDROP     1000


typedef struct location_action {
    char location[SLEN];
    char actions[MAX_POSSIBLE_ACTIONS][SLEN];
}   loc_act;

loc_act locs_acs[AMT_LOCATIONS] = {
    { "Home",                   { "Sleep", "repair-equipment", "eat", "paint-east-wall", ">Jallra", lastAction,} },
    { "Jallra",                 { "find-Enemy", "visit Shop", "0", "0", ">cave", lastAction} },
    { "Cave",                   { "find-Creature", "collect-crystal", "0", "0", ">forest", lastAction} },
    { "Forest",                 { "find-Creature", "collect-truffle", "0", "0", ">Crimson-Castle", lastAction} },
    { "Crimson-Castle",         { "find-Enemy", "collect-artwork", "-", "0", ">Desert-Dungeon", lastAction} },
    { "Desert-Dungeon",         { "find-Creature", "collect-fossil", "-", "0", ">Underlands", lastAction} },
    { "Underlands",             { "find-Creature", "collect-inscription", "0", "0", ">Conquerors-Path", lastAction} },
    { "Conquerors-Path",        { "find-Cryptids", "seek-Conqueror", "0", "0", ">Dunespecters-Tunnel", lastAction} },
    { "Dunespecters-Tunnel",    { "find-Scoridrae", "seek-Dunespecter", "0", "0", ">Hasmal", lastAction} },
    { "Hasmal",                 { "find-Hasmari", "seek-Azumos", "conquer-Hasmal", "0", "0", lastAction} }
};

#endif /* LOCATIONS_ACTIONS_ENEMIES_H */