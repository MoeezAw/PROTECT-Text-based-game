#include <stdio.h>

#ifndef NAMES_H
#define NAMES_H

#define FISTDAMAGE      10
#define SLEN            20
#define AMT_ITEMS       5

typedef struct items {
    char name[SLEN];
    float heal;
    float damage;
    int max_uses;
    int cost;
}   items_l;

#define EMPTY           "Empty"
#define EMPTY_HEAL      1
#define EMPTY_DAMAGE    1

#define JUICE           "Juice"
#define JUICE_HEAL      1.2
#define JUICE_DAMAGE    1.5
#define JUICE_USES_MAX  1
#define JUICE_COST      60

#define BREAD           "Bread"
#define BREAD_HEAL      1.5
#define BREAD_DAMAGE    1.8
#define BREAD_USES_MAX  5
#define BREAD_COST      30

#define SWORD           "Sword"
#define SWORD_HEAL      1
#define SWORD_DAMAGE    1.5
#define SWORD_USES_MAX  150
#define SWORD_COST      50

// collectibles:
#define CRYSTAL_WORTH   1
#define TRUFFLE_WORTH   5
#define ARTWORK_WORTH   20
#define FOSSIL_WORTH    50
#define INSCRIPTION_WORTH 100

items_l itemslist[AMT_ITEMS] = {
    { EMPTY, EMPTY_HEAL, EMPTY_DAMAGE, INT_MAX, 0 },
    { JUICE, JUICE_HEAL, JUICE_DAMAGE, JUICE_USES_MAX, JUICE_COST },
    { BREAD, BREAD_HEAL, BREAD_DAMAGE, BREAD_USES_MAX, BREAD_COST },
    { SWORD, SWORD_HEAL, SWORD_DAMAGE, SWORD_USES_MAX, SWORD_COST },
    {"Cock", 1.1, 1.5, 150, 50000}
};

#endif