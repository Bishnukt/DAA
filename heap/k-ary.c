//Program to create max or min k-ary heap

#include<stdio.h>
#include<stdlib.h>
#define child (k*index+i)

void max_heap(int *,int,int);
void min_heap(int *,int,int);
void swap(int *,int *);
void input(int *,int);
int *mem_alloc(int );
void display(int *,int);
int k;

int main(int argc,char *argv[])
{
	int n;
	if(argc>1)
		k=atoi(argv[1]);
	else
	{
		printf("Enter the value of k: ");
		scanf("%d",&k);
	}
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	int *arr=mem_alloc(n);
	printf("Enter %d elements:\n",n);
	input(arr,n);
	int choice;

here:	printf("1.Create K-ary Max heap.\n2.Create K-ary Min heap.\nEnter choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: max_heap(arr,(n-2)/k,n-1);
			break;
		case 2: min_heap(arr,(n-2)/k,n-1);
			break;
		default: printf("Invalid choice, try again.\n");goto here;
	}
	printf("Elements in the %d-ary heap are: ",k);
	display(arr,n);	
	return 0;
}

void max_heap(int *arr,int index,int size)
{
	if(index>=0)
	{
		int i=1;
		int max=index;
		while(i<=k && child<=size)
		{
			if(arr[max]<arr[child])
			max=child;
			i++;
		}
		if(arr[index]<arr[max])
		{
			swap(&arr[index],&arr[max]);
			max_heap(arr,max,size);
		}
		max_heap(arr,index-1,size);
	}
}

void min_heap(int *arr,int index,int size)
{
	if(index>=0)
	{
		int i=1;
		int min=index;
		while(i<=k && child<=size)
		{
			if(arr[min]>arr[child])
				min=child;
			i++;
		}
		
		if(arr[index]>arr[min])
		{
			swap(&arr[index],&arr[min]);
			min_heap(arr,min,size);
		}

		min_heap(arr,index-1,size);
	}
}

void swap(int *a,int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int *mem_alloc(int n)
{
	return (int *)calloc(n,sizeof(int));
}

void input(int *arr,int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
}


/*
Output:

Enter the value of k: 4
Enter the no. of elements: 10
Enter 10 elements:
76 12 43 33 11 98 55 17 87 10
1.Create K-ary Max heap.
2.Create K-ary Min heap.
Enter choice: 1
Elements in the 4-ary heap are: 98 87 43 33 11 12 55 17 76 10 

Enter the value of k: 4 
Enter the no. of elements: 10
Enter 10 elements:
76 12 43 33 11 98 55 17 87 10
1.Create K-ary Max heap.
2.Create K-ary Min heap.
Enter choice: 2
Elements in the 4-ary heap are: 10 12 43 33 11 98 55 17 87 76 

*/
