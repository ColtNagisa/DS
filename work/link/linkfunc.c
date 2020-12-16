#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}LNode, * LinkList;

//头插法
LinkList Creath_LinkList() {
    LinkList L = NULL;
    LNode* s = NULL;
    int e;
    scanf("%d", &e);
    while (e != 9999) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        scanf("%d", &e);
    }
    return L;
}

//查找
LNode* Get_LinkList(LinkList L, int i) {
    LNode* p = L;
    int j = 0;
    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (j == i)
        return p;
    else
        return NULL;
}
//插入
int Insert_LinkList(LinkList L, int i, int e) {
    LNode* p, * s;
    p = Get_LinkList(L, i - 1);
    if (p == NULL) {
        printf("位置错");
        return 0;
    }
    else
    {
        s =(LNode*) malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}
//删除
int Del_LinkList(LinkList L, int i) {
    LinkList p, s;
    p = Get_LinkList(L, i - 1);
    if (p == NULL)
    {
        printf("i-1不存在");
        return 0;
    }
    else if (p->next == NULL)
    {
        printf("i不存在");
        return 0;
    }
    else
    {
        s = p->next;
        p->next = s->next;
        free(s);
        return 1;
    }

}
//输出
int Output_LinkList(LinkList L, int i) {
    int e;
    LNode* p;
    p = Get_LinkList(L, i);
    e = p->data;
    return e;
}

void reverseList(LinkList h){
    LNode *p, *q;
    p = h->next;
    h->next = NULL;
    while(p){
        q = p;
        p = p->next;
        q->next = h->next;
        h->next = q;
    }
}