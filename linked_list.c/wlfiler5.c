#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "w1.h"

/*  now i am going to use linked list*/


struct link {
    char *word; /* the string to stre */
    int value; /* the counter */
    struct link *next; /* pointer to next */
};

struct link head;
struct link *current_link;

void init_table() {
    head.next = NULL;
};

int in_table(char str[]) {
    struct link *linkp = head.next;
    while (linkp != NULL)
        if (strcmp(linkp -> word, str) == 0)
            return YES;
        else
            linkp = linkp -> next;
    return NO;
}

int insert(char str[], int val) {

    char *newstr;
    struct link *newlink;

    newstr = malloc(1 + strlen(str));
    if (newstr == NULL)
        return NO;
    newlink = malloc(sizeof(struct link));
    if (newlink == NULL)
        return NO;
    newlink->word = newstr;
    newlink->value = val;
    newlink->next = newlink;
    show_table();
    return YES;
}

int lookup(char str[]) {
    struct link *linkp;
    for (linkp = head.next; linkp; linkp = linkp -> next )
        if (strcmp(linkp ->word, str) == 0)
            return linkp ->value;
    return 0;
}

int update(char str[], int val) {
    struct link *linkp;
    for (linkp = head.next; linkp; linkp = linkp -> next )
        if (strcmp(linkp -> word, str)==0) {
            linkp->value = val;
            show_table();
            return YES;
        }
    return 0;
}

char * firstword() {
    current_link = head.next;
    return nextword();
}

char *nextword() {
    char *ret_val;
    if (current_link == NULL)
        return NULL;
    ret_val = current_link -> word;
    current_link = current_link -> value;
    return ret_val;

}

show_table() {

    int row;
    struct link *lp;

    for (row = 0; row < TABLELEN; row++)
        printf("%3d [%c] [ | ]", row, CHARBASE+row );
        for (lp=head.next; lp; lp = lp ->next)
            printf("[%s | %d]->", lp->word, lp->value);
        printf("NULL\n");

}