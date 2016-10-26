#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "w1.h"

/*
 * data structures for this unit is to dynamically resized array of structs
*/

struct entry {
    char *word;
    int value;
};

#define DEBUG
#define CHUNKSIZE 20 /* allocation increment*/

struct entry *table = NULL;
int table_len;
int n_rows;
int current_rows;

void init_table() {
    n_rows = 0;
    table = NULL;
    current_rows = 0;
}

int in_table(char str[]) {
    int i = 0;
    while (i < n_rows){
        if (strcmp(table[i++].word, str) == 0)
            return YES;
    }
    return NO;
}

int insert(char str[], int val) {
    char *newstr;

    if (n_rows == table_len)
        if (expand_table() == NO)
            return NO;
    newstr = malloc(1 + strlen(str));
    if (newstr == NULL)
        return NO;
    strcpy(newstr, str);
    table[n_rows].word = newstr;
    table[n_rows++].value = val;
    return YES;
}

int lookup(char str[]) {
    int pos = 0;
    for (pos; pos<n_rows; pos++;)
        if (strcmp(table[pos].word, str)==0)
            return table[pos].value;
    return NO;
}

int update(char str[], int val) {
    int pos = 0;
    for (pos; pos<n_rows; pos++)
        if (strcmp(table[pos].word, str) == 0)
            table[pos].value = val;
            return YES;
    return NO;
}

char *firstword() {
    current_rows = 0;
    nextword();
}

char *nextword() {
    if (current_rows >= n_rows)
        return NULL;
    return table[current_rows++].word;

}


/*
 * expand table- increase the size of table by one index
 */

int expand_table() {
    table_len += CHUNKSIZE;
#ifdef DEBUG
    fprintf(stderr, "expanding table to %d entries\n", table_len);
#endif
    table = (struct entry*)realloc(table, table_len*sizeof(struct entry));
    return (table == NULL ? NO: YES);
}




