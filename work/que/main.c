#include <stdio.h>
#include <stdlib.h>
#include "quefunc.c"

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