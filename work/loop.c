#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode, * LinkList;

LinkList Creatr_LinkList();
LinkList ReverseList(LinkList L);

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

LinkList Creatr_LinkList(){
    LinkList L = NULL;
    LNode *s, *r = NULL;
    int e;
    scanf("%d", &e);
    while (e!=9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        if(L==NULL)
            L = s;
        else
        r->next = s;
        r = s;
        scanf("%d", &e);
    }
    if(r!=L)
        r->next = L;
    return L;
}

//倒置
LinkList ReverseList(LinkList L){
if(!L||!(L->next))
return L;
LinkList h = NULL; 
LNode* h1 = L;
while(L){
    h1 = L->next;
    L->next = h;
    h = L;
    L = h1; //L指向h 不能用L=L->next
}
return h;
}