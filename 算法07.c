#include<stdio.h>
/*void main()
{
    int a[2][3]={1,2,3,4,5,6},i,j;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
        printf("第a[%d][%d]元素=%d,其地址为：%d\n",i,j,a[i][j],&a[i][j]);
    printf("a=%d\ta[0]=%d\ta[1]=%d\n",a,a[0],a[1]);
}*/

void main()
{
    int a[2][3]={{1,2,3},{4,5,6}};
    int b[3][2],i,j;
    printf("array a:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
    {
        printf("%5d",a[i][j]);
        b[j][i]=a[i][j];
    }printf("\n");}
    /*for(i;i<2;i++)
    {
        for(j;j<3;j++)
        {
            printf("%5d",a[i][j]);
            b[j][i]=a[i][j];
        }
        printf("\n");
    }
    printf("array b:\n");
     for(i=0;i<3;i++)
        {
            for(j=0;j<2;j++)
                {
                    printf("%d",b[i][j]);
                }
            printf("\n");
        }*/

}
/*void main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int i=0,j=0;
    int temp=a[0][0],row=0,colum=0;
    for(i;i<3;i++)
        for(j;j<4;j++)
        {
            if(a[i][j]>temp){temp=a[i][j];row=i;colum=j;}
        }
    printf("max=%d,row=%d;colum=%d",temp,row,colum);
}
*/
