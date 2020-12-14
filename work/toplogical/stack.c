#include <stdio.h>
#include <stdlib.h>

//结构体定义栈结构
typedef struct stack{
    VertexType data;
    struct stack * next;
}stack;

//初始化栈结构
void initStack(stack* *S){
    (*S)=(stack*)malloc(sizeof(stack));
    (*S)->next=NULL;
}
//判断栈是否为空
int StackEmpty(stack S){
    if (S.next==NULL) {
        return 1;
    }
    return 0;
}
//进栈，以头插法将新结点插入到链表中
void push(stack *S,VertexType u){
    stack *p=(stack*)malloc(sizeof(stack));
    p->data=u;
    p->next=NULL;
    p->next=S->next;
    S->next=p;
}
//弹栈函数，删除链表首元结点的同时，释放该空间，并将该结点中的数据域通过地址传值给变量i;
void pop(stack *S,VertexType *i){
    stack *p=S->next;
    *i=p->data;
    S->next=S->next->next;
    free(p);
}