#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **p,**p1,**p2;//定义二重指针，既指针数组的指针
    int m,n,row,col;
    printf("please input array size m,n:\n");
    scanf("%d,%d",&m,&n);
    p = (int**)malloc(m*sizeof(int*));
    p1 = (int**)malloc(m*sizeof(int*));
    p2 = (int**)malloc(m*sizeof(int*));
    for (row=0;row<m;row++)
    {
        p[row] = (int*)malloc(n*sizeof(int));
        p1[row] = (int*)malloc(n*sizeof(int));
        p2[row] = (int*)malloc(n*sizeof(int));
        for (col=0;col<n;col++)
        {
                scanf("%d,%d",&p1[row][col],&p2[row][col]);
				p[row][col]=p1[row][col]+p2[row][col];

        }
    }
    printf("数组1：\n");
    for (row=0;row<m;row++)
    {
        for (col=0;col<n;col++)
        {
            printf("%d ",p1[row][col]);
        }
        printf("\n");
    }
    printf("数组2：\n");
	for (row=0;row<m;row++)
	{
		for(col=0;col<n;col++)
			printf("%d ",p2[row][col]);
		printf("\n");
	}
	printf("数组1+数组2：\n");
	for (row=0;row<m;row++)
	{
		for(col=0;col<n;col++)
			printf("%d ",p[row][col]);
		printf("\n");
	}
}
