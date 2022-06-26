//Radix sort in c using queue

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
	int data;
	struct node *next;
}*queue[10]={NULL};

struct node *enqueue(struct node *,int);
int dequeue(int);
void queue_to_arr(int *);
int *mem_alloc(int);
void radix_sort(int *,int);
int max_el(int *,int);
int input(int *,int);
int display(int *,int);

int main(int argc,char *argv[])
{
		  int n;
		  if(argc>1)
			 n=atoi(argv[1]);
		  else
		  {
			 printf("Enter the number of elements: ");
			 scanf("%d",&n);
		  }
		  int *arr=mem_alloc(n);
		  printf("Enter %d elements: ",n);
		  input(arr,n);
		  printf("\nGiven elements are: ");
		  display(arr,n);
		  printf("Sorted elements are: ");
		  radix_sort(arr,n);
		  display(arr,n);
		  return 0;
}

void radix_sort(int *arr,int n)
{
		  int max=max_el(arr,n);
		  int div=10;
		  int count=1;
		  while(div<=max)
		  {
			  for(int i=0;i<n;i++)
			  {
				if(count>1)
				{
					int ind=(arr[i]/div)%10;
					queue[ind]=enqueue(queue[ind],arr[i]);
				}
				else
				{
					int ind=arr[i]%10;
					queue[ind]=enqueue(queue[ind],arr[i]);
				}
			  }
			  queue_to_arr(arr);
			  count++;
			  div*=10;
		  }
}

struct node *enqueue(struct node *front,int n)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=n;
	tmp->next=NULL;
	if(front==NULL)
		return tmp;
	struct node *ptr=front;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=tmp;
	return front;
}

int dequeue(int i)
{
	struct node *front=queue[i];
	if(front==NULL)
		return INT_MIN;
	struct node *tmp=front;
	int res=front->data;
	front=front->next;
	queue[i]=front;
	free(tmp);
	return res;
}

void queue_to_arr(int *arr)
{
	int j=0;
	for(int i=0;i<10;i++)
	{
		int el=dequeue(i);
		while(el!=INT_MIN)
		{
			arr[j]=el;
			j++;
			el=dequeue(i);
		}
	}
}

int *mem_alloc(int n)
{
	return (int *)malloc(sizeof(int)*n);
}

int input(int *arr,int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
}

int display(int *arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int max_el(int *arr,int n)
{
	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
