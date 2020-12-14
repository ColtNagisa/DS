#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct
{  int data[MAXSIZE];
   int len;
}SeqList;
//生成顺序表
SeqList* Init_SeqList()
{ SeqList *L;
  L= malloc(sizeof(SeqList));
  L->len=-1;
  return L;
}
//插入
int Insert_SeqList(SeqList *L,int i,int e)
{ int j;
  if(L->len == MAXSIZE-1)
  {
   printf("表满溢出");
   return -1;
  }
  if(i<1||i>L->len+2)
  {
   printf("位置错");
   return 0;
  }
  for(j=L->len;j>=i-1;j--)
  
    L->data[j+1]=L->data[j];
      L->data[i-1]=e;
      L->len++;
    
    return 1;
}
//删除
int Delete_SeqList(SeqList *L,int i)
{ int j;
if(L->len==-1)
{printf("表空溢出");
 return -1;}
if(i<1 || i>L->len+1)
{printf("不存在第一个元素");
 return 0;
}
for(j=i;j<=L->len;j++)
L->data[j-1]=L->data[j];
L->len--;

return 1;
}
//查询
int Locate_SeqList(SeqList *L,int e)
{ int i=0;
while (i<=L->len&&L->data[i]!=e)
i++;
if(i>L->len) return -1;
else return i+1;
}
//输出
int Get_SeqList(SeqList*L,int i)
{if (i<1 || i>L->len+1)
{printf("不存在第i个元素");
 return 0;}
else return L->data[i-1];
}

void main()
{
int a,b;
SeqList *L = NULL;
L = Init_SeqList();
for (a = 0; a < 5;a++){
    scanf("%d", &L->data[a]);
    L->len++;
}
    scanf("%d,%d", &a, &b);
Insert_SeqList(L, a, b);

printf("选择删除第几个数");
scanf("%d", &a);
Delete_SeqList(L, a);

printf("选择查找");
scanf("%d", &b);
printf("%d\n",Locate_SeqList(L, b));

printf("选择输出");
scanf("%d", &a);
int num = Get_SeqList(L, a);
printf("%d\n", num);
printf("\n");
printf("修改后的顺序表\n");
for (a = 0; a < 5;a++)
    printf("%d\n", L->data[a]);
}
