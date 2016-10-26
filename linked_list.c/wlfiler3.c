#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "w1.h"

/* Data structures for this unit : One array of struct */

struct entry {
    char *word;
    int value;
};

#define MAXROWS 8000 /* room in table*/

struct entry table[MAXROWS];
int n_rows;
int current_row;

void init_table(){
    n_rows = 0;
}

int in_table(char str []) {
    int i = 0;
    while (i<n_rows) {
        if (strcmp(table[i++].word, str) == 0)
            return YES;
        return NO;
    }

}

int insert(char str[], int val) {
    char *newstr;

    if (n_rows == MAXROWS)
        return NO;
    newstr = malloc(1 + strlen(str));
    if (newstr == NULL)
        return NO;
    table[n_rows].word = newstr;
    table[n_rows++].value = val;
    return YES;
}

int lookup(char str[]) {
    int pos;
    for (pos = 0; pos<n_rows; pos++)
        if (strcmp(table[pos].word, str) == 0)
            return table[pos].value;
    return 0;
}

int update(char str[], int val) {

    int pos;

    for (pos = 0; pos<n_rows; pos++)
        if (strcmp(table[pos].word, str) == 0) {
            table[pos].value = val;
            return YES;
        }
    return NO;
}

char *firstword() {
    current_row = 0;
    nextword();
}

char *nextword() {
    if (current_row >= n_rows)
        return NULL;
    return table[current_row++].word;

}

