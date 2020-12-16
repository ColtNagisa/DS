#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringfunc.c"

int main(){
    char *s = Init_SeqString();
    char *t = Init_SeqString();
    //int num = BF_StrIndex(s, t);//BF
    int num2 = KMP(s, t);//KMP
    //printf("%d", num);
    printf("%d", num2);
    system("pause");
    return 0;
}