#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 40000

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
    int num;
}c_SEqQue;

//初始化队列
c_SEqQue *Init_SeqQue(){
    c_SEqQue *q = malloc(sizeof(c_SEqQue));
    q->rear = q->front = -1;
    q->num = 0;
    return q;
}
//判队空
int Empty_SeqQue(c_SEqQue *q){
    if(q->num == 0)
        return 1;
        else
            return 0;
}
//入队
int In_SeqQue(c_SEqQue *q, int e){
    if (q->num==MAXSIZE)
    {
        printf("队满");
        return -1;
    }else
    {
        q->rear = (q->rear + 1) % MAXSIZE;
        q->data[(q->rear)] = e;
        q->num++;
        return 1;
    }
}
//出队
int Out_SeqQue(c_SEqQue *q){
    if (q->num==0)
    {
        printf("队空");
        return -1;
    }else
    {
        q->front = (q->front + 1) % MAXSIZE;
        q->num--;
        return 1;
    }
}