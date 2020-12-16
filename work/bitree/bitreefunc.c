#include <stdio.h>
#include <stdlib.h>
int rear, front = -1;

typedef struct BTNode{
    int data;
    struct BTNode *lchild, *rchild;
} BTNode, *BITree;

//生成树
BITree CreateBITree(){
    BITree t;
    int e;
    scanf("%d", &e);
    if(e==0)
        t = NULL;
        else
        {
            t = malloc(sizeof(BTNode));
            t->data = e;
            t->lchild = CreateBITree();
            t->rchild = CreateBITree();
        }
    return t;
}

//递归前序
void PreOrderF(BITree bt){
    if(bt==NULL)
        return NULL;
    printf("%d", bt->data);
    PreOrderF(bt->lchild);
    PreOrderF(bt->rchild);
}
//递归中序
void PreOrderM(BITree bt){
    if(bt==NULL)
        return NULL;
    PreOrderM(bt->lchild);
    printf("%d", bt->data);
    PreOrderM(bt->rchild);
}
//递归后序
void PreOrderB(BITree bt){
    if(bt==NULL)
        return NULL;
    PreOrderB(bt->lchild);
    PreOrderB(bt->rchild);
    printf("%d", bt->data);
}
//层次遍历
void LeveOrder(BITree t){
    BITree Que[20];
    int front, rear;
    if(t==NULL)
        return 1;
    front = -1;
    rear = 0;
    Que[rear] = t;
    while(front != rear){
        front++;
        printf("%d", Que[front]->data);
        if(Que[front]->data!=NULL){
            rear++;
            Que[rear] = Que[front]->lchild;
        }
        if(Que[front]->rchild!=NULL){
            rear++;
            Que[rear] = Que[front]->rchild;
        }
    }
}