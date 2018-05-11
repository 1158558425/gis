#include<stdio.h>
#include<math.h>
typedef struct {
int x;
int y;
}spot;
typedef struct{
spot o;
float r;
}yuan;
int panduandian(spot o,float r,spot p);
spot input(spot p);
void panduanzhexian(spot o,float r);
spot input(spot p)
{
   //printf("输入点：\n");
   scanf("%d%d",&p.x,&p.y);
   return p;
}
int panduandian(spot o,float r,spot p)
{
    //spot p;
    float d,m;
    //printf("输入判断点：\n");
    //p = input(p);
    m = (p.x-o.x)*(p.x-o.x)+(p.y-o.y)*(p.y-o.y);//加乘号
    d = sqrt(m);
    if(d<r){printf("在圆内！\n");return 1;}
    else if(d==r){printf("在圆上！\n");return 1;}
    else {printf("不在圆上！\n");return 0;}
}
void panduanyuan(spot o,float r)
{
    spot o2;
    float r2,d,m;
    printf("输入判断圆的圆心：\n");
    o2 = input(o2);
    printf("输入判断圆半径：\n");
    scanf("%f",&r2);
    if(r2>r)printf("不在！\n");
    else{
        d = sqrt((o2.x-o.x)*(o2.x-o.x)+(o2.y-o.y)*(o2.y-o.y));
        m=r-r2;
        if(d>m)printf("不在！\n");
        else printf ("在！\n");
    }
}
void panduanzhexian(spot o,float r)
{
    int num,i,count=0;
    printf("需判断的折线有几个端点：\n");
    scanf("%d",&num);
    spot p[num];
    for(i=0;i<num;i++)
    {
        printf("输入折线端点：\n");
        p[i] = input(p[i]);
    }
    for(i=0;i<num;i++)
    {
        if(panduandian(o,r,p[i]))count++;
    }
    if(count==num)printf("线段，折线，多边形在");
    else printf("线段，折线，多边形不在");
}

void main()
{
    spot o1,p;
    float r1;
    printf("输入圆心：\n");
    o1 = input(o1);
    printf("输入半径：\n");
    scanf("%f",&r1);
    printf("输入判断点：\n");
    p = input(p);
    panduandian(o1,r1,p);
    panduanyuan(o1,r1);
    panduanzhexian(o1,r1);


}
