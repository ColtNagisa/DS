#include <stdio.h>
#include <stdlib.h>
#include "bithrfunc.c"

int main() {
    BiThrTree t;
    printf("输入前序二叉树:\n");
    CreateTree(&t);
    InThreading(t);
    printf("输出中序序列:\n");
    InOrderThraverse_Thr(t);
    system("pause");
    return 0;
}

