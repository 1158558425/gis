#include<stdio.h>
#include<math.h>
typedef struct {
float x;
float y;
}spot;
spot input(spot p)
{
   //printf("����㣺\n");
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
    printf("�������߶�L0�������˵�p1��p2\n");
    p1=input(p1);
    p2=input(p2);
    printf("�������߶�L1�������˵�q1��q2\n");
    q1=input(q1);
    q2=input(q2);
    printf("�������߶�L1���߶λ���ֱ������1Ϊ�߶�2Ϊֱ�ߣ�\n");
    scanf("%d",&type);
    //�ж��Ƿ��ཻ������ʵ��
    float temp2,temp1;
    temp2 = (p2.x-q1.x)*(q2.y-q1.y)-(p2.y-q1.y)*(q2.x-q1.x);//(p2-q1)(q2-q1)
    temp1 = (p1.x-q1.x)*(q2.y-q1.y)-(p1.y-q1.y)*(q2.x-q1.x);//(p1-q1)(q2-q1)
    //printf("%f,%f",temp1,temp2);
    if((temp1==0)&&(temp2!=0))//p1��q1q2����
        {
            if(type==2)printf("ֻ��һ��������Ϊp1����%f,%f��",p1.x,p1.y);
            else{if(p1.x>max(q1.x,q2.x)||p1.x<min(q1.x,q2.x))printf("�޽���");
                 else printf("ֻ��һ��������Ϊp1����%f,%f��",p1.x,p1.y);}
        }
    else if((temp1!=0)&&(temp2==0))//p2��q1q2����
        {
            if(type==2)printf("ֻ��һ��������Ϊp2����%f,%f��",p2.x,p2.y);
            else{if(p2.x>max(q1.x,q2.x)||p2.x<min(q1.x,q2.x))printf("�޽���");
                 else printf("ֻ��һ��������Ϊp1����%f,%f��",p2.x,p2.y);}
        }
    else if((temp1==0)&&(temp2==0))//p1p2��q1q2������
            {
                if(type==2)printf("������������\");
                else {if(min(p1.x,p2.x)>max(q1.x,q2.x)||max(p1.x,p2.x)<min(q1.x,q2.x))printf("�޽���");
                      else if(min(p1.x,p2.x)==max(q1.x,q2.x))printf("ֻ��һ��������Ϊp����%f,%f��",max(q1.x,q2.x),max(q1.y,q2.y));
                      else if(max(p1.x,p2.x)==min(q1.x,q2.x))printf("ֻ��һ��������Ϊp����%f,%f��",min(q1.x,q2.x),min(q1.y,q2.y));
                      else printf("�����������㣩");}
            }
    else if(temp1*temp2>0)printf("�߲��ཻ�޽��㣩");//p1p2��q1q2ͬһ���޽���
    else if(temp1*temp2<0)//�н����Ҳ����ߣ��ɽ�L0��L1������ֱ�߿���
        {
            //�ų�б��Ϊ0����б�ʲ����ڵ������Ϊ������б���ų�bug
            if(p1.x==p2.x){
                    k1 = (q2.y-q1.y)/(q2.x-q2.x);
                    b1 = q1.y-k1*q1.x;
                    printf("ֻ��һ��������Ϊp����%f,%f��",p1.x,(k1*p1.x+b1));}
            if(q1.x==q2.x){
                    k0 = (p2.y-p1.y)/(p2.x-p2.x);
                    b0 = p1.y-k1*p1.x;
                    printf("ֻ��һ��������Ϊp����%f,%f��",q1.x,(k0*q1.x+b0));}
            if(p1.y==p2.y){
                    k1 = (q2.y-q1.y)/(q2.x-q2.x);
                    b1 = q1.y-k1*q1.x;
                    printf("ֻ��һ��������Ϊp����%f,%f��",((p1.y-b1)/k1),p1.y);}
            if(q1.y==q2.y){
                    k0 = (p2.y-p1.y)/(p2.x-p2.x);
                    b0 = p1.y-k1*p1.x;
                    printf("ֻ��һ��������Ϊp����%f,%f��",((q1.y-b0)/k0),q1.y);}
            k0 = (p2.y-p1.y)/(p2.x-p1.x);
            b0 = p1.y-k0*p1.x;
            k1 = (q2.y-q1.y)/(q2.x-q1.x);
            b1 = q1.y-k1*q1.x;
            printf("%f,%f",k0,b0);
            float x ,y;
            x = (b1-b0)/(k0-k1);
            y = x*k0+b0;
            printf("ֻ��һ��������Ϊp����%f,%f��",x,y);

        }

}
