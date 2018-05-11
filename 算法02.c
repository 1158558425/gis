#include<stdio.h>
typedef struct {
int x;
int y;
}spot;
spot input(spot p)
{
   printf("输入点：\n");
   scanf("%d%d",&p.x,&p.y);
   return p;
}
int main()
{
    spot input(spot p);
    int chajif(spot p0,spot p1,spot p2);
    spot p0,p1,p2;
    p0 = input(p0);
    p1 = input(p1);
    p2 = input(p2);
    guaixiang(p0,p1, p2);
    return 0;

}
int chajif(spot p0,spot p1,spot p2)
{
  return (p2.x-p0.x)*(p1.y-p0.y)-
		(p2.y-p0.y)*(p1.x-p0.x);
}
void guaixiang(spot p0,spot p1, spot p2)
{
	int chaji;
	chaji=chajif(p0,p1,p2);
	if(chaji>0)		printf("右拐");
	else if(chaji==0)		printf("共线");
	else		printf("左拐");
}
