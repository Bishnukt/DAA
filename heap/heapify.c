#include<stdio.h>
#include<stdlib.h>
#define left (index*2+1)
#define right (index*2+2)

void heapify(int *,int ,int);
void swap(int *,int *);

int main()
{
	int n,*arr;
	printf("Enter size of heap: ");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	printf("Enter %d elements: \n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapify(arr,n-1,n-1);
	printf("\nHeap elements are: ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;

}

void heapify(int *arr,int index,int size)
{
	if(index>=0)
	{
//		int left=index*2+1;
//		int right=index*2+2;
		if(left<=size)
		{
			if(arr[left]>arr[index])
			{
				swap(&arr[left],&arr[index]);
				heapify(arr,left,size);
			}
		}
		if(right<=size)
		{
			if(arr[right]>arr[index])
			{
				swap(&arr[right],&arr[index]);
				heapify(arr,right,size);
			}
		}
		heapify(arr,index-1,size);
	}
}

void swap(int *a,int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
