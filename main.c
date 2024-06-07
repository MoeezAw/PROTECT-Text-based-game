#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int first_run = 0; // is this the first run of the program?

#define STD_STRING_LENGTH       25
#define INVENTORY_CAPACITY      6
#define ESC                     (27 - '0')
#define LOAD_ERROR              "Error: Could not load data file.\n"

typedef struct
{
    char name[STD_STRING_LENGTH];
    float heal;
    float damage_multiplier;
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

// save and load functions
int save(FILE* file);
int load(FILE* file);

// Main function
int main() {
    system("CHCP 65001"); // Set console to UTF-8
    printf("\033c");
    // Open data file
    FILE* dataFile = NULL;
    dataFile = fopen("data.txt", "r+");
    if ( NULL == dataFile ) {
        printf("%s", LOAD_ERROR);
        return EXIT_FAILURE;
    }
    plr.level = 1;
    plr.health = 100;
    strcpy(plr.location, locations[0]);
    for (int i = 0; i < INVENTORY_CAPACITY; i++)
    {
        strcpy(plr.inventory[i].name, "Empty");
        plr.inventory[i].heal = 0;
        plr.inventory[i].damage_multiplier = 0;
    }
    


    // Code to manage a first run of the program (game)
    if (first_run) {
        first_run_code();
    }
    // - [ MAIN MAIN CODE ] -
    int input = 0;
    main_menu();

    // Get and check input from user
    while ( (input < 1 || input > 2) && ESC != input) 
    {
        input = getInput();
    }
    
    switch (input)
    {
    case 1:
        // TODO: Load game data ( int load() )
        // Load data from file
        load(dataFile);
        // TODO: Implement game code
        break;
    
    case 2:
    case ESC:
        printf("Exiting...\n");
        save(dataFile);
        break;
    }

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
    first_run = 0;
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
    fseek(file, 0, SEEK_SET);
    fscanf(file, "%d", &plr.level);
    fscanf(file, "%d", &plr.health);
    fscanf(file, "%s", plr.location);

    for (int i = 0; i < INVENTORY_CAPACITY; i++) {
        fscanf(file, "%s", plr.inventory[i].name);
    }

    return 1;
}