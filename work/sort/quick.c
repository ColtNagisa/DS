#include <stdio.h>
#include <stdlib.h>
#include "randnum.c"

#define MAX 10

typedef struct{
    int key;
} KeyType;

typedef struct{
    KeyType data[MAX];
} RecType;

int main(){
    RecType *a = (RecType*) malloc(sizeof(RecType));
    int first, end;
    for (int i = 0; i < MAX;i++){
        a->data[i].key = Rand();
    }
    printf("排序前：\n");
    show(a);
    printf("输入起始与终止\n");
    scanf("%d,%d", &first, &end);
    quicksort(a, first, end);
    printf("排序后：\n");
    show(a);
    system("pause");
    return 0;
}

void quicksort(RecType *a,int first,int end){
   int i = first;
   int j = end;
   KeyType temp = a->data[i];

   while(i<j){
       while(i<j && temp.key<=a->data[j].key)
           j--;
       a->data[i] = a->data[j];
       while(i<j && a->data[i].key<=temp.key)
           i++;
       a->data[j] = a->data[i];
   }
   a->data[i] = temp;
    if(first<i-1)
        quicksort(a, first, i - 1);
    if(i+1<end)
        quicksort(a, i + 1, end);
}

void show(RecType *a){
    for (int i = 0; i < MAX;i++){
        printf("%d\n", a->data[i].key);
    }
}