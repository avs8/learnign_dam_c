#define BUFLEN 512
#define YES 1
#define NO 0
#define TABLELEN 26
#define CHARBASE 'a'
#define LINK table[ARRAY_SIZE]


void init_table();
int in_table(char []);
int insert(char [], int);
int lookup(char []);
int update(char [], int);
int delete_word(char []);
char *firstword();
char *nextword();
show_table();

