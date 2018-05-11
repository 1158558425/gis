#include<stdio.h>
#include<math.h>
typedef struct {
float x;
float y;
}spot;
spot polycentroid(int n );
spot input(spot p)
{
   //printf("输入点：\n");
   scanf("%f%f",&p.x,&p.y);
   return p;
}
spot polycentroid(int n )
{
    int i,j;
    spot p[n];
    if(n<3)printf("不是多边形！");
    printf("输入多边形顶点！\n");
    for(i=0;i<n;i++)
    {
        p[i]=input(p[i]);
    }
    spot centroid;
    float area;
    float ai,atmp=0,xtmp=0,ytmp=0;
    for(i=n-1,j=0;j<n;i=j,j++)
    {
        ai = p[i].x*p[j].y-p[j].x*p[i].y;
        atmp += ai;
        xtmp += (p[j].x+p[i].x)*ai;
        ytmp += (p[j].y+p[i].y)*ai;
    }
    area =atmp/2;
    if(atmp!=0)
    {
        centroid.x =xtmp/(3*atmp);
        centroid.y =ytmp/(3*atmp);
    }
    return centroid;

}
int main()
{
    int num,i;
    spot centroid;
    printf("多边形为有几个顶点\n");
    scanf("%d",&num);
    centroid = polycentroid(num );
    printf("中心点x坐标：%f 中心点y坐标：%f",centroid.x,centroid.y);

}

