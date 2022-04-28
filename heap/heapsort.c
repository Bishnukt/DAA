#include<stdio.h>
#include<stdlib.h>
#include"heap_helper.h"
void heapsort(int *,int);
void display(int *,int);
int main()
{
	int n;
	printf("Enter the size of heap: ");
	scanf("%d",&n);
	int *arr=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	max_heap(arr,n-1,n-1);	
	printf("Heap elements are: ");
	display(arr,n);
	heapsort(arr,n);
	printf("Heap elements after sorting are : ");
	display(arr,n);
	return 0;
}

void heapsort(int *arr,int n)
{
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[i],&arr[0]);
		heapify(arr,0,i-1);
	}
}
 
void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
