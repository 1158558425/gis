#include<stdio.h>
#include<math.h>
typedef struct {
int x;
int y;
}spot;
spot input(spot p)
{
   //printf("输入点：\n");
   scanf("%d%d",&p.x,&p.y);
   return p;
}
int max(int x,int y)
{
    return (x>y)?x:y;
}
int min(int x,int y)
{
    return (x>y)?y:x;
}
int main()
{
    spot D1[2],D2[2];
    int i;
    printf("输入共线线段D1:\n");
    for(i=0;i<2;i++){D1[i]=input(D1[i]);}
    printf("输入共线线段D2:\n");
    for(i=0;i<2;i++){D2[i]=input(D2[i]);}
    if (max(D1[0].x,D1[1].x)<min(D2[0].x,D2[1].x)||max(D1[0].y,D1[1].y)<min(D2[0].y,D2[1].y)||max(D2[0].x,D2[1].x)<min(D1[0].x,D1[1].x)||max(D2[0].y,D2[1].y)<min(D1[0].y,D1[1].y))printf("没有交点！");
    else if (max(D1[0].x,D1[1].x)==min(D2[0].x,D2[1].x)||max(D1[0].y,D1[1].y)==min(D2[0].y,D2[1].y)||max(D2[0].x,D2[1].x)==min(D1[0].x,D1[1].x)||max(D2[0].y,D2[1].y)==min(D1[0].y,D1[1].y))printf("一个交点！");
    else printf("重合无数交点");



}
