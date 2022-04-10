#include"dhelper.h"
//#include<stdio.h>
//#include<stdlib.h>
double det(double **,int );
void swap_row(double **,int,int);

int main()
{
	double **arr,res;
	int n;
	printf("**Square Matrix**\n");
	printf("Enter the no. of rows & columns: ");
	scanf("%d",&n);

	arr=mem_alloc(n,n);

	printf("Enter %d*%d elements:\n",n,n);
	input(arr,n,n);
	
	printf("\nGiven Matrix:\n");
	display(arr,n,n);

	res=det(arr,n);
	
	freeall(arr,n);
	printf("\nDeterminant of the given matrix is: %.2lf\n",res);
	return 0;
}

double det(double **arr,int n)
{
	double res=1;
	for(int i=0;i<n;i++)
	{
		if(arr[i][i]==0)
		{
			swap_row(arr,n,i);
			res=(-1)*res;
		}
		for(int j=i+1;j<n;j++)
		{
			double diff=arr[j][i]/arr[i][i];
			if(arr[j][i]!=0)
			{
				for(int k=0;k<n;k++)
					arr[j][k]=arr[j][k]-diff*arr[i][k];
			}
		}
	}

	for(int i=0;i<n;i++)
		res*=arr[i][i];
	
	return res;
}

void swap_row(double **arr,int n,int x)
{
	for(int i=x+1;i<n;i++)
	{
		if(arr[i][x]!=0)
		{
			//for(int j=0;j<n;j++)
			//{
			//	double temp=arr[i][j];
			//	arr[i][j]=arr[x][j];
			//	arr[x][j]=temp;
			//}
			//break;
			
			double *temp=arr[i];
			arr[i]=arr[x];
			arr[x]=temp;
			break;
		}
	}
}


				
