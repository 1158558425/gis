#include<stdio.h>
typedef struct {
int x;
int y;
}spot;
spot input(spot p);
int panduan(spot p0,spot p1,spot p2);
int max(int x,int y);
int min(int x,int y);
void point(spot p0,spot p1,spot p2);
spot input(spot p)
{
   printf("����㣺\n");
   scanf("%d%d",&p.x,&p.y);
   return p;
}
int panduan(spot p0,spot p1,spot p2)
{
    int ymax,ymin,xmax,xmin,z;
    xmax = max(p1.x,p2.x);
    xmin = min(p1.x,p2.x);
    ymax = max(p1.y,p2.y);
    ymin = min(p1.y,p2.y);
    if((p0.x>=xmin)&&(p0.x<xmax)&&(p0.y>=ymin)&&(p0.y<ymax))return 1;
    else return 0;
}
int max(int x,int y)
{
    return (x>y)?x:y;
}
int min(int x,int y)
{
    return (x>y)?y:x;
}
void point(spot p0,spot p1,spot p2)
{
    int z;
    z = panduan(p0,p1,p2);
    if(z == 1)printf("���ھ����ڣ�");
    else printf("�㲻�ھ����ڣ�");
}
void main()
{
    spot p0,p1,p2;
    printf("������ε�һ������");
    p1 = input(p1);
    printf("������ε���һ������");
    p2 = input(p2);
    const int NUM = 2;
    spot p[NUM];
    int i;
    for(i=0;i<NUM;i++)
    {
        p[i] = input(p[i]);
    }
    int count=0;
    for(i=0;i<NUM;i++)
    {
        if(panduan(p[i],p1,p2))count++;
    }
    if(count==NUM)printf("�߶Σ����ߣ��������");
    else printf("�߶Σ����ߣ�����β���");
    /*printf("�����жϵ�");
    p0 = input(p0);
    point(p0,p1,p2);*/
}
