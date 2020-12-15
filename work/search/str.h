#include <stdio.h>
#define MAXSIZE 100

typedef struct{
    int key;
} KeyType;

typedef struct{
    KeyType list[MAXSIZE];
    int size;
} Seqlist;