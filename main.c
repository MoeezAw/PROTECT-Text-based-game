#include <stdio.h>

int first_run = 1;

int main() {
    printf("\033c");
    if (first_run) first_run = 0;

    return 0;
}