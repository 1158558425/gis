#include<stdio.h>
#include<stdlib.h>
typedef int BOOL;//�����ڸ�����������
struct player{
    int position;
    BOOL can[6];//can��Ա��˳����ݳ��ض���
}Player[6];//����ṹ�壬ÿ����Ա�ɺ���position��ÿ��λ�õ�boolֵ���
void init_player(struct player Player[])
{
    int i=0,j=0;
    for(i;i<6;i++)
    {
        j=0;
        Player[i].position=i;
        for(j;j<6;j++)
        {
            if(j==i){Player[i].can[j]=0;}
            else{Player[i].can[j]=1;}
        }
        //Player[i].position=i;
    }
    Player[0].can[4]=0;//1�Ų��ں���
    Player[0].can[5]=0;
    Player[1].can[4]=0;//2�Ų��Ƕ�����
    Player[2].can[1]=0;//3�Ų��Ƕ�����
    Player[2].can[4]=0;
    Player[4].can[2]=0;//5�Ų��Ǹ�����
    Player[4].can[5]=0;
    Player[5].can[0]=0;//6�Ų��ں���
    Player[5].can[4]=0;
    Player[5].can[2]=0;//6�Ų��Ǹ�����
}//�˺�����ʼ���ṹ������
int select(struct player p[])
{
    BOOL judge[6];
    int i,j;
    for(i=0;i<6;i++)
    judge[i]=0;
    i=0;
    //for(i;i<6;i++)
    while(i<6)
    {
        j=0;
        //for(j;j<6;j++)
        while(j<6)
        {
            //��4����Աʱ���������3����Ա��һ��
            if(i==3){
                if(p[2].position!=3)//��3����Ա�ڵ�4��λ�ã�ǰ��
                {
                    p[3].can[0]=0;
                    p[3].can[4]=0;
                    p[3].can[5]=0;
                }
                else{
                    p[3].can[1]=0;
                    p[3].can[2]=0;
                }

            }
            else{//�ָ���4���˵ĳ�ʼ״̬
                p[3].can[0]=1;
                p[3].can[4]=1;
                p[3].can[5]=1;
                p[3].can[1]=1;
                p[3].can[2]=1;
            }
            if(p[i].can[j]!=0&&judge[j]==0)
                {
                p[i].position=j;
                judge[j]=1;//can[j]�Ա�ռ��
                i++;
                break;
                }
            else{j++;}
            while(j==6){
                i--;
                j=p[i].position+1;
                judge[j-1]=0;
            }

        }
    }
    return 0;

}

int main(/*int argc,char **argv*/)
{
    int i;
    init_player(Player);//�ṹ���ʼ��
    select(Player);//�ṹ�����
    printf("player number :1 2 3 4 5 6\n");
    for(i=0;i<6;i++){
        printf("%d",Player[i].position+1);
    }
    printf("\n");
    return 0;


}
