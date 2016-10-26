#include	<stdio.h>
#include	<stdlib.h>
#include "w1.h"

main() {
 char buf[BUFLEN], *wordptr;
    init_table();

    while (scanf("%s", buf) == 1)
        if ( in_table(buf) == YES)
            update(buf, 1 + lookup (buf));
        else if (insert (buf, 1) == NO) {
            fprintf(stderr, "wordfreq: out of memory\n" );
            exit(1);
        }

    for (wordptr = firstword(); wordptr != NULL; wordptr = nextword())
        printf("%d; %s\n", lookup(wordptr), wordptr);

}
