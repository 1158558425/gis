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
   //printf("����㣺\n");
   scanf("%d%d",&p.x,&p.y);
   return p;
}
int panduandian(spot o,float r,spot p)
{
    //spot p;
    float d,m;
    //printf("�����жϵ㣺\n");
    //p = input(p);
    m = (p.x-o.x)*(p.x-o.x)+(p.y-o.y)*(p.y-o.y);//�ӳ˺�
    d = sqrt(m);
    if(d<r){printf("��Բ�ڣ�\n");return 1;}
    else if(d==r){printf("��Բ�ϣ�\n");return 1;}
    else {printf("����Բ�ϣ�\n");return 0;}
}
void panduanyuan(spot o,float r)
{
    spot o2;
    float r2,d,m;
    printf("�����ж�Բ��Բ�ģ�\n");
    o2 = input(o2);
    printf("�����ж�Բ�뾶��\n");
    scanf("%f",&r2);
    if(r2>r)printf("���ڣ�\n");
    else{
        d = sqrt((o2.x-o.x)*(o2.x-o.x)+(o2.y-o.y)*(o2.y-o.y));
        m=r-r2;
        if(d>m)printf("���ڣ�\n");
        else printf ("�ڣ�\n");
    }
}
void panduanzhexian(spot o,float r)
{
    int num,i,count=0;
    printf("���жϵ������м����˵㣺\n");
    scanf("%d",&num);
    spot p[num];
    for(i=0;i<num;i++)
    {
        printf("�������߶˵㣺\n");
        p[i] = input(p[i]);
    }
    for(i=0;i<num;i++)
    {
        if(panduandian(o,r,p[i]))count++;
    }
    if(count==num)printf("�߶Σ����ߣ��������");
    else printf("�߶Σ����ߣ�����β���");
}

void main()
{
    spot o1,p;
    float r1;
    printf("����Բ�ģ�\n");
    o1 = input(o1);
    printf("����뾶��\n");
    scanf("%f",&r1);
    printf("�����жϵ㣺\n");
    p = input(p);
    panduandian(o1,r1,p);
    panduanyuan(o1,r1);
    panduanzhexian(o1,r1);


}
