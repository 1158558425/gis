#include<stdio.h>
#include<math.h>
typedef struct {
float x;
float y;
}spot;
spot input(spot p)
{
   //printf("输入点：\n");
   scanf("%f%f",&p.x,&p.y);
   return p;
}
float max(float x,float y)
{
    return (x>y)?x:y;
}
float min(float x,float y)
{
    return (x>y)?y:x;
}
int main()
{
    spot p1,p2,q1,q2;
    int type;
    float k0,k1,b0,b1;
    printf("请输入线段L0的两个端点p1，p2\n");
    p1=input(p1);
    p2=input(p2);
    printf("请输入线段L1的两个端点q1，q2\n");
    q1=input(q1);
    q2=input(q2);
    printf("请输入线段L1是线段还是直线输入1为线段2为直线：\n");
    scanf("%d",&type);
    //判断是否相交，跨立实验
    float temp2,temp1;
    temp2 = (p2.x-q1.x)*(q2.y-q1.y)-(p2.y-q1.y)*(q2.x-q1.x);//(p2-q1)(q2-q1)
    temp1 = (p1.x-q1.x)*(q2.y-q1.y)-(p1.y-q1.y)*(q2.x-q1.x);//(p1-q1)(q2-q1)
    //printf("%f,%f",temp1,temp2);
    if((temp1==0)&&(temp2!=0))//p1在q1q2方向
        {
            if(type==2)printf("只有一个交点且为p1：（%f,%f）",p1.x,p1.y);
            else{if(p1.x>max(q1.x,q2.x)||p1.x<min(q1.x,q2.x))printf("无交点");
                 else printf("只有一个交点且为p1：（%f,%f）",p1.x,p1.y);}
        }
    else if((temp1!=0)&&(temp2==0))//p2在q1q2方向
        {
            if(type==2)printf("只有一个交点且为p2：（%f,%f）",p2.x,p2.y);
            else{if(p2.x>max(q1.x,q2.x)||p2.x<min(q1.x,q2.x))printf("无交点");
                 else printf("只有一个交点且为p1：（%f,%f）",p2.x,p2.y);}
        }
    else if((temp1==0)&&(temp2==0))//p1p2在q1q2方向共线
            {
                if(type==2)printf("共线无数交点\");
                else {if(min(p1.x,p2.x)>max(q1.x,q2.x)||max(p1.x,p2.x)<min(q1.x,q2.x))printf("无交点");
                      else if(min(p1.x,p2.x)==max(q1.x,q2.x))printf("只有一个交点且为p：（%f,%f）",max(q1.x,q2.x),max(q1.y,q2.y));
                      else if(max(p1.x,p2.x)==min(q1.x,q2.x))printf("只有一个交点且为p：（%f,%f）",min(q1.x,q2.x),min(q1.y,q2.y));
                      else printf("共线无数交点）");}
            }
    else if(temp1*temp2>0)printf("线不相交无交点）");//p1p2在q1q2同一侧无交点
    else if(temp1*temp2<0)//有交点且不共线，可将L0，L1都当成直线看了
        {
            //排除斜率为0，和斜率不存在的情况，为后面求斜率排除bug
            if(p1.x==p2.x){
                    k1 = (q2.y-q1.y)/(q2.x-q2.x);
                    b1 = q1.y-k1*q1.x;
                    printf("只有一个交点且为p：（%f,%f）",p1.x,(k1*p1.x+b1));}
            if(q1.x==q2.x){
                    k0 = (p2.y-p1.y)/(p2.x-p2.x);
                    b0 = p1.y-k1*p1.x;
                    printf("只有一个交点且为p：（%f,%f）",q1.x,(k0*q1.x+b0));}
            if(p1.y==p2.y){
                    k1 = (q2.y-q1.y)/(q2.x-q2.x);
                    b1 = q1.y-k1*q1.x;
                    printf("只有一个交点且为p：（%f,%f）",((p1.y-b1)/k1),p1.y);}
            if(q1.y==q2.y){
                    k0 = (p2.y-p1.y)/(p2.x-p2.x);
                    b0 = p1.y-k1*p1.x;
                    printf("只有一个交点且为p：（%f,%f）",((q1.y-b0)/k0),q1.y);}
            k0 = (p2.y-p1.y)/(p2.x-p1.x);
            b0 = p1.y-k0*p1.x;
            k1 = (q2.y-q1.y)/(q2.x-q1.x);
            b1 = q1.y-k1*q1.x;
            printf("%f,%f",k0,b0);
            float x ,y;
            x = (b1-b0)/(k0-k1);
            y = x*k0+b0;
            printf("只有一个交点且为p：（%f,%f）",x,y);

        }

}
