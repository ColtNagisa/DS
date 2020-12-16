#include <stdio.h>
#include <stdlib.h>
#include "loopfunc.c"

int main(){
    LinkList L = Creatr_LinkList();
    LinkList h = ReverseList(L);
    printf("\n");
    for (int i = 0; i < 10;i++){
        int num;
        h = h->next;
        num = h->data;
        printf("%d", num);
    }
    system("pause");
}