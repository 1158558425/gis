#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int *arr;
    int num;
}Array;
void InitArray(int num,int *arr)
{
    arr = (int*)malloc(sizeof(int*)*num);
    int i;
    if(!arr){printf("分配失败！");exit(0);}
    printf("输入数组元素：\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",arr[i]);

    }
    //printf("%d",num);
   // printf("%d",arr[0]);
}
void OutputArray(Array Arrtemp)
{
    int i;
    printf("%d",Arrtemp.arr[0]);
    /*for(i=0;i<Arrtemp.num;i++)
    {
        printf("%d",Arrtemp.arr[i]);

    }*/
}
void main()
{
    Array arr1;
    printf("please input the number of element:");
    scanf("%d",&arr1.num);
    InitArray(arr1.num,arr1.arr);
    //OutputArray(arr1);
    //printf("%d",arr1.arr[0]);
    printf("%d",arr1.num);


}
/*#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
void main()
{
	/*int *array = NULL, num;
	printf("please input the number of element: ");
	scanf("%d", &num);
	// 申请一维动态数组使用的内存块
//	array = (int *)malloc(sizeof(int)*num);
	array = (int *)calloc(sizeof(int),num);
	if (array == 0)             // 内存申请失败,提示退出
   {
         printf("内存分配失败！\n");
         exit(0);             // 终止程序运行,返回操作系统
	}
	printf("请输入数组元素:\n ");
	for(int i=0;i<num;i++)
	//	scanf("%d",&array[i]);
		scanf("%d",array+i);
	printf("输出的数组为: \n");
	for( i=0;i<num;i++)
		//printf("%d\n",array[i]);
		printf("%d\n",*(array+i));*/
	/*int *array1 = NULL,*array2 = NULL,*array3 = NULL,num;
	printf("please input the number of element: ");
	scanf("%d", &num);
	// 申请一维动态数组使用的内存块
	array1 = (int *)malloc(sizeof(int)*num);
	array2 = (int *)calloc(sizeof(int),num);
	array3 = (int *)calloc(sizeof(int),num);

	printf("请输入数组1:\n ");
	for(int i=0;i<num;i++)
		scanf("%d",&array1[i]);
	printf("请输入数组2:\n ");
	for( i=0;i<num;i++)
		scanf("%d",&array2[i]);
	for( i=0;i<num;i++)
		array3[i]=array1[i]+array2[i];
/*	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&array1[i],&array2[i]);
		array3[i]=array1[i]+array2[i];
	}*/
	/*printf("数组1+数组2为:\n ");
	for( i=0;i<num;i++)
		printf("%d\n",array3[i]);
}
