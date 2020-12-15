#include <stdio.h>
#include "str.h"

int SearchSeq(Seqlist S, KeyType t);

int main(){
    Seqlist L;
    KeyType t;
    printf("输入大小\n");
    scanf("%d", &L.size);
    printf("输入值\n");
    for (int i = 0; i < L.size;i++){
        scanf("%d", &L.list[i].key);
    }
    printf("输入要查找的元素\n");
    scanf("%d", &t.key);
    int k = SearchSeq(L, t);
    if(k!=-1){
        printf("元素位置在%d\n", k+1);
    }else{
        printf("未找到\n");
    }
    system("pause");
    return 0;
}

int SearchSeq(Seqlist S,KeyType t){
    int i;
    for (i = 0; i < S.size;i++){
        if(t.key==S.list[i].key){
            return i;
            break;
        }
    }
    if(i==S.size)
        return -1;
}
