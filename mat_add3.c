#include<stdio.h>
//#include<stdlib.h>
#include"helper.h"

void mat_add(int **,int **,int **,int ,int ,int ,int);
int main()
{
	int **a,**b,**c;
	int n;
	printf("Enter the number of rows and columns in two matrices: ");
	scanf("%d",&n);
	
	a=mem_alloc(n,n);
	b=mem_alloc(n,n);
	c=mem_alloc(n,n);
	
	printf("Enter %d*%d elements in first matris: \n",n,n);
	input(a,n,n);
	printf("Enter %d*%d elements in second matrix: \b",n,n);
	input(b,n,n);
	printf("\nMatrix A:\n");
	display(a,n,n);
	printf("\nMatrix B:\n");
	display(b,n,n);
	
	mat_add(a,b,c,0,n,0,n);
//	free(a);
//	free(b);
	printf("\nMatrix A + Matrix B: \n");
	display(c,n,n);
	
	freeall(a,n);
	freeall(b,n);
	freeall(c,n);

	return 0;
}

void mat_add(int **a,int **b,int **c, int rs,int re,int cs,int ce)
{
	if(re-rs==1)
		c[rs][cs]=a[rs][cs]+b[rs][cs];
	else
	{
		mat_add(a,b,c,rs,(rs+re)/2,cs,(cs+ce)/2);
		mat_add(a,b,c,rs,(rs+re)/2,(cs+ce)/2,ce);
		mat_add(a,b,c,(rs+re)/2,re,cs,(cs+ce)/2);
		mat_add(a,b,c,(rs+re)/2,re,(cs+ce)/2,ce);
	}
}
