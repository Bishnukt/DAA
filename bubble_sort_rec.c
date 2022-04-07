#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *,int );
void input(int *,int);
void display(int *,int);

int main()
{
	int n;
	printf("Enter the no. of elements to be sorted: ");
	scanf("%d",&n);

	int *arr=(int *)malloc(n*sizeof(int));

	printf("Enter %d elements to sort: ",n);
	input(arr,n);

	bubble_sort(arr,n);

	printf("Sorted elements are: ");
	display(arr,n);

	return 0;
}

void bubble_sort(int *arr,int n)
{
	int i,swapped=0,temp;
	for(i=0;i<n;i++)
	{
		if(arr[i]>arr[i+1])
		{
			temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
			swapped=1;
		}
	}
	if(swapped)
		bubble_sort(arr,n-1);
	return;
}

void input(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
}

void display(int *arr,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
