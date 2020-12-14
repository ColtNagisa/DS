#include <stdio.h>
#include <stdlib.h>
#include "quewithoutmain.c"
#define MAXVERNUM 100 //最大顶点数
#define TRUE 1
#define FALSE 0

typedef int visited[MAXVERNUM];
typedef char VerType; //设定点类型为字符型
typedef int ArcType; //设边的权值为整型
typedef struct{ //邻接矩阵
    VerType vexs[MAXVERNUM]; //顶点表
    ArcType arcs[MAXVERNUM][MAXVERNUM]; //邻接矩阵
    int vexnum, arcnum; //顶点数和边数
} MGragh;

typedef struct node{ //边表节点
    int adjvex; //邻接点域
    struct node *nextadj; //指向下一个邻接点的指针域
} EdgeNode;

typedef struct vnode{ //顶点表节点
    VerType vertex;  //顶点域
    EdgeNode *firstedge;  //边表头指针
} VerNode;

typedef VerNode AdjList[MAXVERNUM];

typedef struct{
    AdjList adjilst; //邻接表
    int vexnum, arcnum; //顶点数和边数
} ALGraph;

void CreateMGraph(MGragh *G);
void CreatALGraph(ALGraph *G);
void DFSAL(ALGraph *G, int j);
void DFSTraverseAL(ALGraph *G);
void BFSM(MGragh *G, int m);
void BFSTraverM(MGragh *G);

int main(){
    MGragh *K;
    ALGraph *M;
    K = (MGragh *)malloc(sizeof(MGragh));
    M = (ALGraph *)malloc(sizeof(ALGraph));
    CreateMGraph(K);
    CreatALGraph(M);
    BFSTraverM(K);
    DFSTraverseAL(M);
    system("pause");
    return 0;
}

//无向图邻接矩阵
void CreateMGraph(MGragh *G){
    int i, j, k, w;
    char ch;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));
    printf("请输入顶点信息:\n");
    for (i = 0; i < G->vexnum;i++)
        scanf(" %c", &(G->vexs[i]));
    for (i = 0; i < G->vexnum;i++)
        for (j = 0; j < G->vexnum;j++)
            G->arcs[i][j] = 0;
    printf("输入每条边对应的两个顶点的序号:\n");
    for (k = 0; k < G->arcnum;k++){
        scanf("\n %d,%d", &i, &j);
        G->arcs[i][j] = 1;
    }
}
//有向图邻接表
void CreatALGraph(ALGraph *G){
    int i, j, k;
    EdgeNode *s;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum)); //读顶点数和边数
    printf("输入顶点信息:\n");
    for (i = 0; i < G->vexnum;i++){  //建立有G->vexnum个顶点的顶点表
        scanf("\n%c", &(G->adjilst[i].vertex)); //读入顶点信息
        G->adjilst[i].firstedge = NULL; //顶点的边表头指针为空
    }
    printf("输入边的信息:\n");
    for (k = 0; k < G->arcnum;k++){ //采用头插法建立边表
        scanf("\n%d,%d", &i, &j); //读入<vi,vj>的顶点对应的序号
        s = (EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex = j; //邻接点序号为j
        s->nextadj = G->adjilst[i].firstedge; //将新边表节点s插入vi的邻接表头部
        G->adjilst[i].firstedge = s;
    }
}
//深度遍历
void DFSAL(ALGraph *G,int j){
    //以j为出发点对邻接表存储的图G进行DFS搜索
    visited visit;
    EdgeNode *p;
    printf("visit vertex:v%c\n", G->adjilst[j].vertex); //访问顶点vj
    visit[j] = TRUE;
    p = G->adjilst[j].firstedge;
    while(p){
        if(!visit[p->adjvex])
            DFSAL(G, p->adjvex);
        p = p->nextadj;
    }
}

void DFSTraverseAL(ALGraph *G){
    //深度优先搜索以邻接表存储的图G
    int i;
    visited visit;
    for (i = 0; i < G->vexnum;i++)
        visit[i] = FALSE;    //访问标志数组初始化
    for (i = 0; i < G->vexnum;i++) 
        if(!visit[i])
        DFSAL(G, i);
}

//广度遍历
 void BFSM(MGragh *G,int m){
     int i, j;
     visited visit;
     c_SEqQue *Q;
     Q = Init_SeqQue();
     printf("visit vertex:v%c\n", G->vexs[m]);
     visit[m] = TRUE;
     In_SeqQue(Q, m);
     while (!Empty_SeqQue(Q))
     {
         i = Out_SeqQue(Q);
         for (j = 0; j < G->vexnum;j++){
             if(G->arcs[i][j] == 1 && !visit[j]){
             printf("visit vertex:v%c\n", G->vexs[j]);
             visit[j] = TRUE;
             In_SeqQue(Q, j);
             }
         }
     }
}

void BFSTraverM(MGragh *G){
    int i;
    visited visit;
    for (i = 0; i < G->vexnum;i++)
        visit[i] = FALSE;
    for (i = 0; i < G->vexnum;i++)
    if(!visit[i])
        BFSM(G, i);
}
