#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

char *Init_SeqString();
int BF_StrIndex(char *s, char *t);
void Next(char *T, int *next);
int KMP(char *S, char *T);


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

//初始化
char *Init_SeqString(){
    char *s = (char*)malloc(sizeof(char) * MAXSIZE);
    scanf("%s", s);
    return s;
}
//BF
int BF_StrIndex(char * s,char *t){
    int i=0,j=0;
    while (i<strlen(s) && j<strlen(t)) {
        if (s[i]==t[j]) {
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if (j==strlen(t)) {
        return i-strlen(t)+1;
    }
    return 0;
}
//KMP NEXT
void Next(char*T,int *next){
    int i=1;
    next[1]=0;
    int j=0;
    while (i<strlen(T)) {
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
//KMP
int KMP(char * S,char * T){
    int next[10];
    Next(T,next);
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) {
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if (j>strlen(T)) {
        return i-(int)strlen(T);
    }
    return -1;
}