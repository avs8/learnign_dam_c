#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void delete(void);
void print(void);


main() {
    char code;
    for (;;) {
        printf("Enter The opearation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n') /* skip to the new line */
            ;
        switch (code) {
            case 'i' : insert();
                break;
            case 's' : search();
                break;
            case 'u' : update();
                break;
            case 'p' : print();
                break;
            case 'd' : delete();
                break;
            case 'q' : return 0;
            default: printf("Illegal code\n");
        }
    }
}

struct part *find_part(int number) {
    /*
     * Looks up a part number in the inventory list. Returns a pointer
     * to the node containing the part number
     * if the part number not found return NULL.
     * */

    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p ->next);
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void) {
    /*
     * Prompts the user for information about a new part and then inserts the part
     * into the inventory list;
     * The list remains sorted by part number;
     * Prints an error message and returns prematurely if the part already exist
     * or space could not allocated for the part.
     * */

    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Data base is full; cant more parts.\n");
        return;
    }

    printf("Enter part number:  ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next);
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter Quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void) {
    /*
     * Prompts user to enter a part number, then looks up the part
     * in the database. if the part exists, print the name and quantity
     * on hand; if not then print error message
     * */

    int number;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else
        printf("Part not found.\n");
}

void update(void) {
    /*
     * Prompts user to enter a part number.
     * Prints an error message if the part doesnt exist
     * otherwise, promots the user to enter change in quantity
     * on hand and updates the database.
    */

    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p ->on_hand += change;
    } else
        printf("Part not found. \n");

}

void delete(void) {
    /*
     * Prompts user to enter a part number.
     * check if part number exits and not null.
     * if exist find the location of node and then swich the pointer to after that
     * free that node
     */
    int number;
    struct part *cur, *prev;
    printf("Enter part number to delete node: ");
    number = scanf("%d", &number);
    for (cur = find_part(number), prev = NULL;
         cur != NULL && cur->number != number;
            prev = cur, cur = cur->next);
    if (cur == NULL)
        return;
    if (prev == NULL)
        inventory = inventory ->next;
    else
        prev->next = cur->next;
        free(cur);
    return;

}

void print(void) {
    struct part *p;

    printf("Part Number  Part Name  Quantity on Hand\n");

    for (p = inventory; p != NULL; p = p->next)
        printf("%7d   %-25s  %11d\n", p->number, p->name, p->on_hand);
}
