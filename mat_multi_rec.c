#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int , int);
void multi(int **, int ** ,int **,int ,int);
void display(int **,int ,int );
void input(int **, int ,int);

int main()
{
	int **arr1,**arr2,r1,r2,c1,c2;
	do{
	printf("Enter row and column of 1st matrix: ");
	scanf("%d%d",&r1,&c1);
	printf("Enter row and column of 2nd matrix: ");
	scanf("%d%d",&r2,&c2);
	}while(r2!=c1);

	arr1=mem_alloc(r1,c1);
	arr2=mem_alloc(r2,c2);

	printf("Enter %d*%d elements in 1st matrix:\n",r1,c1);
	input(arr1,r1,c1);
	printf("Enter %d*%d elements in 2nd matrix:\n",r2,c2);
	input(arr2,r2,c2);
	
	printf("Matrix A: \n");
	display(arr1,r1,c1);

	printf("Matrix B: \n");
	display(arr2,r2,c2);

	return 0;
}

//void multi(int **a,int **b,int **c)
//{
//}

int **mem_alloc(int r,int c)
{
	int i,j;
	int **temp;
	temp=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
		temp[i]=(int *)calloc(c,sizeof(int));
	return temp;
}

void input(int **arr,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	scanf("%d",&arr[i][j]);
}


void display(int **arr,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
