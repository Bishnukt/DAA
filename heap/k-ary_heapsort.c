#include<stdio.h>
#include<stdlib.h>
#define child k*index+i 
int heap_sort(int *,int);
void max_heap(int *,int ,int);
void swap(int *,int *);
int k;
int main()
{
	int *arr,n;
	printf("Enter the value of k: ");
	scanf("%d",&k);
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	printf("Enter %d elments;\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	max_heap(arr,n-1,(n-2)/k);
	printf("Elements in the %d-ary are: ",k);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	heapsort(arr,n);
	printf("\nSorted elements are: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

void max_heap(int *arr, int size, int index)
{
	if(index>=0)
	{
		int i=1;
		while(i<=k && child<=size)
		{
			if(arr[child]>arr[index])
			{
				swap(&arr[child],&arr[index]);
				max_heap(arr,size,child);
			}
			i++;
		}
		//max_heap(arr,size,index-1);
	}
}

void heapsort(int *arr,int n)
{
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		max_heap(arr,i-1,0);
	}
}

void swap(int *a,int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

void heapify(int *arr,int size)
{
	for(int i=(n-2)/k;i>=0;i++)
	{
		max_heap(arr,
