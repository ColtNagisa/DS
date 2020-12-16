#include <stdio.h>
#include <stdlib.h>
#include "seqfunc.c"

int main()
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
system("pause");
return 0;
}
