#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "w1.h"

/*
 data structures for this unit: two arrays
    an array of ints for the counts
    an array of pointers to dynamically allocated strings

 */

#define MAXROWS  8000 /* room in table */

int value[MAXROWS];
char *word[MAXROWS];
int n_rows;
int current_row;

void
init_table() {
    n_rows = 0;
}

int in_table(char str []) {
    int i = 0;
    while (i < n_rows)
        if (strcmp(word[i++], str) == 0)
            return YES;
    return NO;
}

int insert(char str[], int val) {
    char *newstr;
    if (n_rows == MAXROWS)
        return NO;
    newstr = malloc(1 + strlen(str)); /* get enough memory*/
    if (newstr == NULL)
        return NO;
    strcpy(newstr, str);
    word[n_rows] = newstr;
    value[n_rows++] = val;
    return YES;
}

int lookup(char str[]) {
    int pos;
    for (pos = 0; pos < n_rows; pos++)
        if (strcmp(word[pos], str) == 0)
            return value[pos];
    return 0;

}

int update(char str[], int val){
    int pos;
    for ( pos = 0; pos < n_rows, pos++; )
        if (strcmp(word[pos], str) == 0) {
            value[pos] = val;
            return YES;
        }
    return NO;

}

char *firstword() {
    current_row = 0;
    nextword();
}

char *nextword(){
    if (current_row >= n_rows)
        return NULL;
    return word[current_row++];
}
