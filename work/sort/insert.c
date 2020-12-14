#include <stdio.h>
#include <stdlib.h>
#include "sqlist.c"

int LT(int a, int b);
void Show(SqList *L);
void InsertSort(SqList *L);

int main(){
    SqList *L = initSqList();
    printf("排序前：\n");
    Show(L);
    InsertSort(L);
    printf("排序后：\n");
    Show(L);
    system("pause");
    return 0;
}

void InsertSort(SqList *L){
    int i, j;
    for (i = 2; i <= L->length;i++){
        L->R[0] = L->R[i];
        j = i - 1;
        while(LT(L->R[0].key,L->R[j].key)){
            L->R[j + 1] = L->R[j];
            j--;
        }
        L->R[j + 1] = L->R[0];
    }
}

void Show(SqList *L){
    for (int i = 1; i <= L->length;i++){
        printf("%d\n", L->R[i].key);
    }
}

int LT(int a,int b){
    if(a < b)
        return 1;
        else
            return 0;
}