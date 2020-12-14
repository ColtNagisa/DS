#include <stdio.h>
#include <stdlib.h>
#include "sqlist.c"

void Show(SqList *L);
void bubble_sort(SqList *L);

int main(){
    SqList *L = initSqList();
    printf("排序前：\n");
    Show(L);
    bubble_sort(L);
    printf("排序后：\n");
    Show(L);
    system("pause");
    return 0;
}

void bubble_sort(SqList *L) {
        int i, j, temp;
        for (i = 0; i < L->length - 1; i++)
                for (j = 0; j < L->length - 1 - i; j++)
                        if (L->R[j].key > L->R[j + 1].key) {
                                temp = L->R[j].key;
                                L->R[j].key = L->R[j + 1].key;
                                L->R[j + 1].key = temp;
                        }
}

void Show(SqList *L){
    for (int i = 0; i < L->length;i++){
        printf("%d\n", L->R[i].key);
    }
}