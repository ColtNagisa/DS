#include <stdio.h>
#include <stdlib.h>
#define MAXWEIGHT 10000
#define MAXLEAF 40
#define MAXNODE MAXLEAF*2-1
#define MAXCODE 20

typedef struct {
    int code[MAXCODE];
    int start;
} HCodeType;

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HNode;

void HuffmanTree(HNode HuffmanNode[]){
    int i, j, a1, a2, b1, b2, n;
    scanf("%d", &n);
    for (i = 0; i < 2 * n - 1;i++){ //初始化所有节点
        HuffmanNode[i].weight = 0;
        HuffmanNode[i].parent = -1;
        HuffmanNode[i].lchild = -1;
        HuffmanNode[i].rchild = -1;
    }
    for (i = 0; i < n;i++){
        scanf("%d", &HuffmanNode[i].weight); //赋值叶子节点
    }
    for (i = 0; i < n - 1;i++){
        a1 = a2 = MAXWEIGHT;
        b1 = b2 = 0;
        for (j = 0; j < n + i;j++){
            if(HuffmanNode[j].weight<a1 && HuffmanNode[j].parent==-1){
                a2 = a1;
                b2 = b1;
                a1 = HuffmanNode[j].weight;
                b1 = j;
            }
            else if(HuffmanNode[j].weight<a2 && HuffmanNode[j].parent==-1){
                a2 = HuffmanNode[j].weight;
                b2 = j;
            }
        }
        HuffmanNode[b1].parent = n + i;
        HuffmanNode[b2].parent = n + i;
        HuffmanNode[n + i].weight = HuffmanNode[b1].weight + HuffmanNode[b2].weight;
        HuffmanNode[n + i].lchild = b1;
        HuffmanNode[n + i].rchild = b2;
    }
}

void HuffmanCode(){
    HNode HuffmanNode[MAXNODE];
    HCodeType HuffmanCode[MAXLEAF], cd;
    int i, j, a, p,n;
    HuffmanTree(HuffmanNode);
    scanf("%d", &n);
    for (i = 0; i < n;i++){
        cd.start = n - 1;
        a = i;
        p = HuffmanNode[a].parent;
        while (p!=0)
        {
            if(HuffmanNode[p].lchild==a)
                cd.code[cd.start] = 0;
                else
                    cd.code[cd.start] = 1;
                cd.start--;
                a = p;
                p = HuffmanNode[a].parent;
        }
        for (j = cd.start + 1; j < n;j++)
            HuffmanCode[i].code[j] = cd.code[j];
            HuffmanCode[i].start = cd.start;
        
    }
        printf("\n");
        for (i = 0; i < n;i++){
            for (j = HuffmanCode[i].start + 1; j < n;j++)
                printf("%ld", HuffmanCode[i].code[j]);
                printf("\n");
            }
}