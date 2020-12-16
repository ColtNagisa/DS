#include <stdio.h>
#include <stdlib.h>
#include "bitreefunc.c"

int main(){
    BITree t = CreateBITree();
    printf("前序\n");
    PreOrderF(t);
    printf("\n中序\n");
    PreOrderM(t);
    printf("\n后序\n");
    PreOrderB(t);
    printf("\n层次\n");
    LeveOrder(t);
    system("pause");
    return 0;
}
