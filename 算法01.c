#include<stdio.h>
struct spot{
int x;
int y;
};
/*spot inter(spot p)
{
    printf("请输入点x,y坐标：\n");
    scanf("%d,%d",&p.x,&p.y);
    //printf("请输入点y坐标：\n");
    //scanf("%f",&p.y);
    return p;
}*/
int main()
{
    //spot inter(spot p);
    int chajif(int x0,int y0,int x1,int y1,int x2,int y2)
    spot p0,p1,p2;
    int chaji;
    scanf("%d%d%d%d%d%d",&p0.x,&p0.y,&p1.x,&p1.y,&p2.x,&p2.y);
    /*p0 = inter(q0);
    p1 = inter(q1);
    p2 = inter(q2);*/
    chaji = chajif(p0.x,p0.y,p1.x,p1.y,p2.x,p2.y);
    if(chaji>0)printf("右拐");
    else if(chaji<0)printf("左拐");
    else(chaji==0)printf("共线");
}
int chajif(int x0,int y0,int x1,int y1,int x2,int y2)
{
    int chaji;
    chaji = (x2-x0)*(y1-y0)-(y2-y0)*(x1-x0);
    return chaji;
}
