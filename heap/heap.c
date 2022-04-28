#include<stdio.h>
#include<stdlib.h>

#define max 100

void insert(int *,int *,int);
void display(int *,int);

int main()
{
	int val,size,choice,x;
	int *arr=(int *)calloc(max,sizeof(int));
	size=0;
	while(1)
	{
		printf("1.Add\n2.Display\n3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Number of elements to be inserted: ");
				scanf("%d",&x);
				printf("Enter %d elements:\n",x);
				while(x--)
				{
				scanf("%d",&val);
				insert(arr,&size,val);
				}
				break;
			
			case 2: display(arr,size);
				printf("\n");
				break;

			case 3: exit(0);

			default: printf("Wrong choice, try again.\n");
		}
	}
	return 0;
}

void insert(int *arr,int *size,int val)
{
	arr[*size]=val;
	int par= (*size-1)>>1;
	int temp=*size;
	while(par>=0)
	{
		if(arr[par]<arr[temp])
		{
			int tmp=arr[par];
			arr[par]=arr[temp];
			arr[temp]=tmp;
		}
		temp=par;
		par=(temp-1)>>1;
	}
	++*size;
}

void display(int *arr,int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
