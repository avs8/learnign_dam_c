#include <stdio.h>
#include <string.h>
#include "w1.h"

#define MAXROWS 8000
#define WLEN 25

static int value[MAXROWS];
static char word[MAXROWS][WLEN+1];
static int n_rows;
static int current_row;


void init_table () {
    n_rows = 0;
}

int in_table(char str[]) {
    int i = 0;
    while(strcmp(word[i++], str) == 0)
        return YES;
    return NO;
}


int insert( char str[], int val){
    if (n_rows == MAXROWS || strlen(str) > WLEN)
        return NO;
    strcpy(word[n_rows], str);
    value[n_rows++] = val;
    return YES;

}

int lookup(char str[]) {
    int pos;
    for (pos = 0; pos<n_rows; pos++)
        if (strcmp(word[pos], str) == 0)
            return value[pos];
    return 0;
}

int update(char str[], int val) {
    int pos;
    for (pos = 0; pos<n_rows; pos++)
        if (strcmp(word[pos], str) == 0) {
            value[pos] = val;
            return YES;
        }

    return NO;
}

char *firstword() {
    current_row = 0;
    return nextword();
}

char *nextword() {
  if (current_row >= n_rows)
      return NULL;
    return word[current_row++];
};