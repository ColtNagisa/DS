#include <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEX_NUM 20//最大顶点个数
#define  VertexType int//顶点数据的类型

typedef struct ArcNode{
    int adjvex;//邻接点在数组中的位置下标
    struct ArcNode * nextarc;//指向下一个邻接点的指针
    VertexType dut; //边信息
}ArcNode;
typedef struct VNode{
    VertexType data;//顶点的数据域
    ArcNode * firstarc;//指向邻接点的指针
}VNode,AdjList[MAX_VERTEX_NUM];//存储各链表头结点的数组
typedef struct {
    AdjList vertices;//图中顶点及各邻接点数组
    int vexnum,arcnum;//记录图中顶点数和边或弧数
}ALGraph;