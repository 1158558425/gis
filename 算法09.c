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
    if(!arr){printf("����ʧ�ܣ�");exit(0);}
    printf("��������Ԫ�أ�\n");
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
	// ����һά��̬����ʹ�õ��ڴ��
//	array = (int *)malloc(sizeof(int)*num);
	array = (int *)calloc(sizeof(int),num);
	if (array == 0)             // �ڴ�����ʧ��,��ʾ�˳�
   {
         printf("�ڴ����ʧ�ܣ�\n");
         exit(0);             // ��ֹ��������,���ز���ϵͳ
	}
	printf("����������Ԫ��:\n ");
	for(int i=0;i<num;i++)
	//	scanf("%d",&array[i]);
		scanf("%d",array+i);
	printf("���������Ϊ: \n");
	for( i=0;i<num;i++)
		//printf("%d\n",array[i]);
		printf("%d\n",*(array+i));*/
	/*int *array1 = NULL,*array2 = NULL,*array3 = NULL,num;
	printf("please input the number of element: ");
	scanf("%d", &num);
	// ����һά��̬����ʹ�õ��ڴ��
	array1 = (int *)malloc(sizeof(int)*num);
	array2 = (int *)calloc(sizeof(int),num);
	array3 = (int *)calloc(sizeof(int),num);

	printf("����������1:\n ");
	for(int i=0;i<num;i++)
		scanf("%d",&array1[i]);
	printf("����������2:\n ");
	for( i=0;i<num;i++)
		scanf("%d",&array2[i]);
	for( i=0;i<num;i++)
		array3[i]=array1[i]+array2[i];
/*	for(int i=0;i<num;i++)
	{
		scanf("%d %d",&array1[i],&array2[i]);
		array3[i]=array1[i]+array2[i];
	}*/
	/*printf("����1+����2Ϊ:\n ");
	for( i=0;i<num;i++)
		printf("%d\n",array3[i]);
}
