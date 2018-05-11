#include<stdio.h>
#include<stdlib.h>
typedef int BOOL;//类似于给类型起名字
struct player{
    int position;
    BOOL can[6];//can成员的顺序根据场地而定
}Player[6];//定义结构体，每个队员由号码position和每个位置的bool值组成
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
    Player[0].can[4]=0;//1号不在后排
    Player[0].can[5]=0;
    Player[1].can[4]=0;//2号不是二传手
    Player[2].can[1]=0;//3号不是二传手
    Player[2].can[4]=0;
    Player[4].can[2]=0;//5号不是副攻手
    Player[4].can[5]=0;
    Player[5].can[0]=0;//6号不在后排
    Player[5].can[4]=0;
    Player[5].can[2]=0;//6号不是副攻手
}//此函数初始化结构体属性
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
            //第4个队员时，不能与第3个队员在一排
            if(i==3){
                if(p[2].position!=3)//第3个队员在第4个位置，前排
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
            else{//恢复第4个人的初始状态
                p[3].can[0]=1;
                p[3].can[4]=1;
                p[3].can[5]=1;
                p[3].can[1]=1;
                p[3].can[2]=1;
            }
            if(p[i].can[j]!=0&&judge[j]==0)
                {
                p[i].position=j;
                judge[j]=1;//can[j]以被占用
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
    init_player(Player);//结构体初始化
    select(Player);//结构体操作
    printf("player number :1 2 3 4 5 6\n");
    for(i=0;i<6;i++){
        printf("%d",Player[i].position+1);
    }
    printf("\n");
    return 0;


}
