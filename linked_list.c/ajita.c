#include <stdio.h>
#include <stdlib.h>

typedef struct node_list {
    char *word;
    int *count;
    struct node_list *next;
} node;
typedef struct node_list *list;

main() {
    list head, temp;
    int *i = 0;
    head = NULL;
    char buf[512];
    scanf("%s", buf);
    temp = (list) malloc(sizeof(node));
    temp->word = buf;
    temp->count = i;
    temp ->next = head;
    head = temp;

    while (temp != NULL){
        printf("%s %d", temp->word, temp->count);
        temp = temp->next;
    }

}