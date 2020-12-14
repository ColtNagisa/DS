#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
    int num;
}c_SEqQue;

c_SEqQue *Init_SeqQue();
int Empty_SeqQue(c_SEqQue *q);
int In_SeqQue(c_SEqQue *q, int e);
int Out_SeqQue(c_SEqQue *q);

 int main(){
    c_SEqQue *q = Init_SeqQue();
    int e;
    while (e!=9999)
    {
        scanf("%d", &e);
        In_SeqQue(q, e);
    }
    Out_SeqQue(q);
    Out_SeqQue(q);//两次出队
    
    if((q->rear)%MAXSIZE > (q->front)%MAXSIZE){
        for (int i = (q->front)%MAXSIZE+1; i <= (q->rear)%MAXSIZE;i++){
            printf("%d\n", q->data[i]);
        }
    } //rear大于front时
    if((q->rear)%MAXSIZE < (q->front)%MAXSIZE){
        for (int i = q->front+1; i <= q->rear;i++){
            i = i % MAXSIZE;
            printf("%d", q->data[i]);
        }
    } //rear小于front时

    system("pause");
    return 0;
}

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