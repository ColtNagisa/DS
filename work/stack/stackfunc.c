#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int top;
}SeqStack;

//初始化栈
SeqStack *Init_SStack(){
    SeqStack *s;
    s = malloc(sizeof(SeqStack));
    if(s)
        s->top = -1;
    return s;
}
//判栈空
int Empty_SStack(SeqStack *s){
    if(s->top == -1)
        return 1;
        else
            return 0;
}
//入栈
int Push_SStack(SeqStack *s, int e){
    if(s->top==MAXSIZE-1)
        return 0;
        else{
            s->top++;
            s->data[s->top] = e;
            return 1;
        }
        
}
//出栈
int Pop_SStack(SeqStack *s){
    if(Empty_SStack(s))
        return 0;
        else
        {
            s->top--;
            return 1;
        }
}
