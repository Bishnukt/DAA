//k-ary heapsort ascending and descending


#include <stdio.h>
#include <stdlib.h>

#define child k *index + i

void heapsort(int *, int,int);
void max_heap(int *, int, int);
void min_heap(int *,int,int);
void swap(int *, int *);
void heapify(int *, int,int);
int *mem_alloc(int);
void input(int *,int);
void display(int *,int);

int k;

int main(int argc,char *argv[])
{
	int *arr,n,choice;
	if(argc>1)
		k=atoi(argv[1]);
	else
	{
		printf("Enter the value of k: ");
		scanf("%d", &k);
	}

	printf("Enter no. of elements: ");
	scanf("%d", &n);

	arr = mem_alloc(n); 

	printf("Enter %d elments;\n", n);
	input(arr,n);
	
here:	printf("1.K-ary sort ascending.\n2.K-ary sort descending.\nEnter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			heapify(arr,n,0);
			printf("\nElements in the %d-ary heap are: ", k);
			display(arr,n);
			heapsort(arr, n,0);
			printf("\nSorted elements are: ");
			display(arr,n);
			break;
		case 2:
			heapify(arr,n,1);
			printf("\nElements in the %d-ary heap are: ",k);
			display(arr,n);
			heapsort(arr,n,1);
			printf("\nSorted elements are: ");
			display(arr,n);
			break;

		default: printf("Invalid choice, try again.\n");goto here;
	}
	return 0;
}

void max_heap(int *arr, int size, int index)
{
	if (index >= 0)
	{
		int i = 1;
		while (i <= k && child <= size)
		{
			if (arr[child] > arr[index])
			{
				swap(&arr[child], &arr[index]);
				max_heap(arr, size, child);
			}
			i++;
		}
	}
}

void min_heap(int *arr, int size, int index)
{
	if (index >= 0)
	{
		int i = 1;
		while (i <= k && child <= size)
		{
			if (arr[child] < arr[index])
			{
				swap(&arr[child], &arr[index]);
				min_heap(arr, size, child);
			}
			i++;
		}
	}
}


void heapsort(int *arr, int n,int ch)
{
	if(ch==0)
	{
	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		max_heap(arr, i - 1, 0);
	}
	}
	else
	{
		for(int i=n-1;i>0;i--)
		{
			swap(&arr[0],&arr[i]);
			min_heap(arr,i-1,0);
		}
	}
}

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void heapify(int *arr, int size, int ch)
{
	if(ch==0)
	{
		for (int i = (size - 2) / k; i >= 0; i--)
			max_heap(arr, size - 1, i);
	}
	else
	{
		for(int i=(size-2)/k; i>=0; i--)
			min_heap(arr,size-1,i);
	}
}

int *mem_alloc(int n)
{
	return (int *)calloc(n, sizeof(int));
}

void input(int *arr,int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
}

void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
