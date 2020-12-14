#include <stdio.h>
#include <stdlib.h>
#include "randnum.c"
#define MAXNUM 100

typedef struct{
    int key;
} KeyType;

typedef struct{
    int length;
    KeyType R[MAXNUM];
} SqList;

SqList* initSqList(){
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    printf("输入元素长度\n");
    scanf("%d", &L->length);
    for (int i = 1; i <= L->length;i++)
        L->R[i].key = Rand();
    return L;
}