/**
 * @brief       Main file of PROTECT
 * @author      xMo (DISCORD: alexanderaugustus, GITHUB: xMo)
 * @date        07.06.2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "items.h"

#define STD_STRING_LENGTH       25
#define INVENTORY_CAPACITY      6
#define ESC                     (27 - '0')
#define LOAD_ERROR              "Error: Could not load data file.\n"

typedef struct
{
    char name[STD_STRING_LENGTH];
    float heal;
    float damage_multiplier;
    int uses;
    int uses_max;
}   item;

typedef struct
{
    int level;
    int health;
    char location[STD_STRING_LENGTH];
    item inventory[INVENTORY_CAPACITY]; // Inventory array
}   player;

player plr;

char locations[5][STD_STRING_LENGTH] = {
    "Home",
    "Forest",
    "Cave",
    "Castle",
    "Town"
};

// Function prototypes
void first_run_code();
void main_menu();
int getInput();
int isFirstRun();
void displayUI();
void getPossibleActions();
int getUses(char item_name[], int Index);

// save and load functions
int save(FILE* file);
int load(FILE* file);

// Main function
int main() {
    system("CHCP 65001"); // Set console to UTF-8
    printf("\033c");
    int first_run = isFirstRun(); // is this the first run of the program?
    int plrPlayed = 0; // did player play game or direclty exit?
    
    // Open data file
    FILE* dataFile = NULL;
    dataFile = fopen("files/data.txt", "r+");
    if ( NULL == dataFile ) {
        printf("%s", LOAD_ERROR);
        return EXIT_FAILURE;
    }

    // Code to manage a first run of the program (game)
    if (first_run) {
        first_run_code();
    }
    if (!first_run)
    {
        load(dataFile);
        for (int i = 0; i < 3; i++)
        {
            printf("Loading game data in %d seconds %s", 3 - i, (i == 0) ? "." : (i == 1) ? ".." : "...");
            Sleep(1000);
            printf("\033c");
        }
        Sleep(500);
    }
    
    int input = 0;

    // - [ MAIN MAIN CODE ] -
    printf("\033c");
    main_menu();
    do
    {
        input = 0;
        // Get and check input from user
        while ((input < 1 || input > 2) && ESC != input)
        {
            input = getInput();
        }

        printf("\033c");
        
        switch (input)
        { // MAIN GAME:
        case 1:
            // TODO: Implement game code
            displayUI();
            break;

        case 2:
        case ESC:
            printf("Exiting...\n");
            save(dataFile);
            printf("Saved game data.\n");
            break;
        }

    } while (input != 2 && input != ESC);

    // End of Program (Exit)
    fclose(dataFile);
    printf("\n");
    return EXIT_SUCCESS;
}

void main_menu() {
    printf("- - - - - - - - - - -\n");
    printf("┌─┐┬─┐┌─┐┌┬┐┌─┐┌─┐┌┬┐\n");
    printf("├─┘├┬┘│ │ │ ├┤ │   │ \n");
    printf("┴  ┴└─└─┘ ┴ └─┘└─┘ ┴ \n");
    printf("- - - - - - - - - - -\n");
    printf("[1]  Start\n");
    printf("[2]  Exit\n");
}

void first_run_code() {
    // TODO: Implement first run code (Play tutorial, give Info, etc.)
    // Set player data to default values:
    plr.level = 1;
    plr.health = 100;
    strcpy(plr.location, locations[0]);
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if (i == 0)
        {
            strcpy(plr.inventory[i].name, SWORD);
            plr.inventory[i].heal = SWORD_HEAL;
            plr.inventory[i].damage_multiplier = SWORD_DAMAGE;
        }
        else
        {
            strcpy(plr.inventory[i].name, EMPTY);
            plr.inventory[i].heal = EMPTY_HEAL;
            plr.inventory[i].damage_multiplier = EMPTY_DAMAGE;
        }
    }
    // Tutorial:
    printf("Hello, welcome to PROTECT!\n");
    printf("This is your first time playing the game, so let's get you started.\n");
    system("PAUSE");
    printf("\033c");
    printf("Please make sure to exit the game properly to save your progress.\n");
    printf("If you want to learn about the stats of items, please read the included README file.\n");
    system("PAUSE");
    printf("\033c");
    printf("Good luck and have fun!\n");
    printf("\033c");
    return;
}

int getInput() {
    int input;
    input = getch();

    return input - '0';
}

int save(FILE* file) {
    fseek(file, 0, SEEK_SET);

    // Save player data to file:
    fprintf(file, "%d\n", plr.level);
    fprintf(file, "%d\n", plr.health);
    fprintf(file, "%s\n", plr.location);
    
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        fprintf(file, "%s\n", plr.inventory[i].name);
    }

    return 1;
}

int load(FILE* file) {
    // Get player data from file:
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%d", &plr.level);
    fscanf(file, "%d", &plr.health);
    fscanf(file, "%s", plr.location);

    // Load inventory from file:
    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        fscanf(file, "%s", plr.inventory[i].name);
    }
    
    // Load inventory stats from file:
    // Open items file
    FILE* itemsFile = NULL;
    itemsFile = fopen("files/uses.txt", "r");
    if ( NULL == itemsFile ) {
        printf("%s", LOAD_ERROR);
        return 0;
    }
    // Load item stats from file:
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        if ( !(strcmp(plr.inventory[i].name, SWORD)) )
        {
            plr.inventory[i].heal = SWORD_HEAL;
            plr.inventory[i].damage_multiplier = SWORD_DAMAGE;
            plr.inventory[i].uses_max = SWORD_USES_MAX;
            // Load Uses
            getUses(SWORD, i);
            
        }
        else if (strcmp(plr.inventory[i].name, JUICE) == 0)
        {
            plr.inventory[i].heal = JUICE_HEAL;
            plr.inventory[i].damage_multiplier = JUICE_DAMAGE;
        }
        else if (strcmp(plr.inventory[i].name, BREAD) == 0)
        {
            plr.inventory[i].heal = BREAD_HEAL;
            plr.inventory[i].damage_multiplier = BREAD_DAMAGE;
        }
        else if (strcmp(plr.inventory[i].name, EMPTY) == 0)
        {
            plr.inventory[i].heal = EMPTY_HEAL;
            plr.inventory[i].damage_multiplier = EMPTY_DAMAGE;
        }
        
    }
    return 1;
}

int getUses(char item_name[], int Index) {
    // Open uses file
    FILE* usesFile = NULL;
    usesFile = fopen("files/uses.txt", "r");
    if ( NULL == usesFile ) {
        printf("%s", LOAD_ERROR);
        return 0;
    }
    // Load item uses from file:
    char tmp[STD_STRING_LENGTH];
    fseek(usesFile, 0, SEEK_SET);

    for (int i = 0; i < INVENTORY_CAPACITY * 2; i++)
    {
        char tmp[STD_STRING_LENGTH];
        fscanf(usesFile, "%s", tmp);
        if (!(strcmp(tmp, item_name)))
        {
            fscanf(usesFile, "%d", &plr.inventory[i].uses);
            break;
        }
    }
}

/**
 * @brief   Checks if it is the first run of the program.
 * @details if flag file found -> not first run | if flag file not found -> first run
 * @return 1 = First run, 0 = Not first run
 */
int isFirstRun() {
    FILE* flagFile = NULL;
    flagFile = fopen("files/first_run.flag", "r"); // Open file in read mode

    if (NULL == flagFile) { // if file not found, create it, = first run
        // printf("Flag-File not found\n");
        flagFile = fopen("files/first_run.flag", "w+");
        return 1;
    }
    else    // if file found, return 0, = not first run
    {
        // printf("Flag-File found\n");
        return 0;
    }
    fclose(flagFile);
}

void displayUI() {
    printf("[Level: %d]     [Health: %d]        [Location: %s]\n", plr.level, plr.health, plr.location);
    printf("Inventory: [%s] [%s] [%s] [%s] [%s] [%s]\n\n", plr.inventory[0].name, 
    plr.inventory[1].name, plr.inventory[2].name, plr.inventory[3].name, 
    plr.inventory[4].name, plr.inventory[5].name);
}

void getPossibleActions() {
    // TODO: Implement possible actions
    return;
}