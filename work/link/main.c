#include <stdio.h>
#include <stdlib.h>
#include "linkfunc.c"

int main() {
    int a, b, num;
    LNode* c;
    LinkList L = Creath_LinkList();
    
    printf("插入数\n");
    scanf("%d,%d", &a, &b);
    Insert_LinkList(L, a, b);
    
    printf("删除数\n");
    scanf("%d", &a);
    Del_LinkList(L, a);
  
    printf("输出数\n");
    scanf("%d", &a);
    num = Output_LinkList(L, a);
    printf("%d\n", num);
    reverseList(L);
    printf("\n\n");
    for (int i = 0; i < 10; i++) {
        int e = L->data;
        L = L->next;
        printf("%d\n", e);
    }
    system("pause");
    return 0;

}