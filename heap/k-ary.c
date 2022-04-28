#include<stdio.h>
#include<stdlib.h>
//#include"heap_helper.h"
//#define child(in,k,i) k*in+i
#define child k*index+i
void max_heap(int *,int,int);
void swap(int *,int *);
int k,cnt=0;
int main()
{
	int n;
	printf("Enter the value of k: ");
	scanf("%d",&k);
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	int *arr=(int *)calloc(n,sizeof(int));
	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	max_heap(arr,(n-2)/k,n-1);
	printf("Elements in the %d-ary heap are: ",k);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	//printf("\n%d\n",cnt);
	
	return 0;
}

void max_heap(int *arr,int index,int size)
{
	if(index>=0)
	{
	//	cnt++;
	int i=1;
	//int child=k*index+i;
	while(i<=k && child<=size)
	{
		if(arr[index]<arr[child])
		{
			swap(&arr[index],&arr[child]);
			max_heap(arr,child,size);
		}
		i++;
//		child=k*index+i;
//		child++;
	}
	max_heap(arr,index-1,size);
	}
}

void swap(int *a,int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
