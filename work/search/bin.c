#include <stdio.h>
#include "str.c"

int main(){
    Seqlist L;
    KeyType t;
    printf("输入大小\n");
    scanf("%d", &L.size);
    printf("输入值（顺序）\n");
    for (int i = 0; i < L.size;i++){
        scanf("%d", &L.list[i].key);
    }
    printf("输入要查找的元素\n");
    scanf("%d", &t.key);
    int k = SearchBin(L, t);
    if(k!=-1){
        printf("元素在%d\n", k + 1);
    }else{
        printf("不存在\n");
    }
    system("pause");
    return 0;
}

int SearchBin(Seqlist S,KeyType t){
    int mid, low = 0, high = S.size - 1;
    while (low<=high)
    {
        mid = (low + high) / 2;
        if(t.key==S.list[mid].key)
            return mid;
            else if(t.key>S.list[mid].key)
                low = mid + 1;
                else
                    high = mid - 1;
    }
    return -1;
}