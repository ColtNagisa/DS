#include <stdio.h>
#include <stdlib.h>
#include "stackfunc.c"

int main(){
    SeqStack *s = Init_SStack();
    int num;
    char symbol;
    while (symbol!='!')
    {
        scanf("%d", &num);
        Push_SStack(s, num);
        symbol = getchar();
    }
    Pop_SStack(s);
    
    for (int i = 0; i < s->top;i++){
        printf("%d", s->data[i]);
    }
    system("pause");
    return 0; 
}
